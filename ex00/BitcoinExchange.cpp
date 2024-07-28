#include "BitcoinExchange.hpp"

#define CORRUPTED(a) ("Error: " + std::string(a) + " file corrupted")

bool isDouble(const std::string& value)
{
    if (value.empty())
        return false;

    size_t pos = value.find_last_of('-');
    if (pos == 0)
    {
        if (value.find_first_not_of("0123456789.", 1) != std::string::npos)
            return false;
    }
    else if (value.find_first_not_of("0123456789.") != std::string::npos)
        return false;

    pos = value.find_last_of('.');
    if (pos != std::string::npos && (pos == 0 || pos == value.size() - 1))
        return false;
    if (value.find_first_of('.') != value.find_last_of('.'))
        return false;

    return true;
}

double stod(std::string& s)
{
    double exchangeRate;
    if (s == "-0")
        s = "0";
    if (!isDouble(s))
        throw std::logic_error("unable to convert to double");

    std::stringstream ss(s);
    ss >> exchangeRate;
    return exchangeRate;
}

void openFile(const std::string& filename, std::ifstream& infile)
{
    infile.open(filename.c_str());
    if (!infile.is_open())
        throw std::logic_error("Error opening " + filename);
}

unsigned int encodeDate(const std::string& date)
{
    struct tm extracted, corrected;
    std::memset(&extracted,0, sizeof (extracted));
    std::memset(&corrected,0, sizeof (corrected));

    //convert date string to numeric values stored in a tm struct
    extracted.tm_year = std::atoi(date.substr(0, 4).c_str()) - 1900; //years since 1900
    if (extracted.tm_year < 0)
        throw std::logic_error("unable to treat years before 1900");

    extracted.tm_mon = std::atoi(date.substr(5, 2).c_str()) - 1; //months since january
    extracted.tm_mday = std::atoi(date.substr(8).c_str()); //days of the month

    corrected = extracted;

    //using mktime function to "format" the extracted date
    mktime(&corrected);

    //compare the extracted date to the formatted one by mktime, if different it means the extracted date doesnt exists
    if (extracted.tm_year != corrected.tm_year || \
        extracted.tm_mon != corrected.tm_mon || \
        extracted.tm_mday != corrected.tm_mday)
            throw std::logic_error("specified date doesnt exist");

    // converting the date to numbers of day since 1900
    unsigned int daysSince1900 = corrected.tm_year * 365 + corrected.tm_yday + static_cast<int>(corrected.tm_year / 4);
    return (daysSince1900);
}


unsigned int extractDate(const std::string& date)
{
    // preliminary global verification of date validity
    if (date.empty())
        throw std::logic_error("missing date");

    if (date.length() != 10)
        throw std::logic_error("wrong date format");

    if (date.find_first_not_of("0123456789-") != std::string::npos)
        throw std::logic_error("wrong date format");

    for (size_t i = 0; i < 10; i++)
    {
        if (i == 4 || i == 7){
            if (date.at(i) != '-')
                throw std::logic_error("wrong date format");
        }
        else{
            if (!isdigit(date.at(i)))
                throw std::logic_error("wrong date format");
        }
    }
    try {
        unsigned int encodedDate = encodeDate(date);
        return encodedDate;
    }
    catch (std::logic_error& e){
        throw e;
    }
}

void parseDataFile(std::map<unsigned int, double>& data)
{
    std::ifstream infile;
    openFile("data.csv", infile);

    //check valid csv columns headers (date,exchange_rate)
    std::string line;
    std::getline(infile, line);
    if (line != "date,exchange_rate")
        throw std::logic_error(CORRUPTED("data.csv") + (std::string)"\nmissing header");

    //extract and check each line of data
    while (getline(infile, line))
    {
        size_t pos = line.find(',');
        if (pos == std::string::npos)
            throw std::logic_error(CORRUPTED("data.csv") + (std::string)"\nsyntax error");

        std::string date = line.substr(0, pos);
        std::string exchange = line.substr(pos + 1);

        if (!isDouble(exchange))
            throw std::logic_error(CORRUPTED("data.csv"));

        try
        {
            unsigned int encodedDate = extractDate(date);
            double exchangeRate = stod(exchange);
            if (exchangeRate < 0)
                throw std::logic_error(CORRUPTED("data.csv") + (std::string)"\nexchange rate cannot be negative");
            data.insert(std::make_pair(encodedDate, exchangeRate));
        }
        catch (std::exception& e)
        {
            infile.close();
            throw std::logic_error(CORRUPTED("data.csv") + (std::string)("\n") + e.what());
        }
    }
    infile.close();
}

//from an encoded date, return the value of btc at this date
double getMatchingExchangeValue(const std::map<unsigned int, double>& data, unsigned int date)
{
    try
    {
        return data.at(date);
    }
    catch (std::exception &e)
    {
        std::map<unsigned int, double>::const_iterator it = data.lower_bound(date);
        if (it == data.begin())
            throw std::logic_error("Error: no matching date in data.csv file");
        --it;
        return (it->second);
    }
}

//parse input file and return an output line by line
void treatInputFile(const std::map<unsigned int, double>& data, const std::string& filename)
{
    std::ifstream infile;
    openFile(filename, infile);

    //check valid input file header
    std::string line;
    getline(infile, line);
    if (line != "date | value")
        throw std::logic_error(CORRUPTED(filename) + (std::string)"\nmissing header");

    //parse and treat each line
    while (getline(infile, line))
    {
        size_t pos = line.find(" | ");
        if (pos == std::string::npos || line.size() <= pos + 3)
        {
            std::cerr << "Error: bad input => [" << line << "]" << std::endl;
            continue ;
        }

        std::string date = line.substr(0, pos);
        std::string value = line.substr(pos + 3);

        double btcAmount, exchangeValue;

        try {
            size_t p = value.find_first_of("123456789");
            if (p != std::string::npos && value.size() - p > 14)
            {
                std::cerr << "Error: not a valid value => " << value << std::endl;
                continue;
            }
            btcAmount = stod(value);
        }
        catch (std::logic_error &e){
            std::cerr << "Error: not a valid value => " << value << std::endl;
            continue;
        }

        //verify value validity
        if (btcAmount < 0)
        {
            std::cerr << "Error: not a positive number => " << value << std::endl;
            continue ;
        }
        if (btcAmount > 1000)
        {
            std::cerr << "Error: too large value => " << value << std::endl;
            continue ;
        }

        try {
            unsigned int encodedDate = extractDate(date);
            exchangeValue = getMatchingExchangeValue(data, encodedDate);
        }
        catch (std::exception &e){
            std::cerr << "Error: " << e.what() << " => " << date << std::endl;
            continue;
        }

        //output any valid result
        std::cout << date << " => " << value << " = " << exchangeValue * btcAmount << std::endl;
    }
    infile.close();
}
