#include "RPN.hpp"

double stod(const char c)
{
    double exchangeRate;
    std::string s = std::string(1, c);
    std::stringstream ss(s);
    ss >> exchangeRate;
    return exchangeRate;
}

bool isCalculValid(const std::string& calcul)
{
    //check emptieness and invalid character
    if (calcul.empty() || calcul.find_first_not_of("0123456789+-/* ") != std::string::npos){
        std::cerr << "Error: Invalid calcul syntax" << std::endl;
        return false;
    }


    //check amount of numbers / operators
    int digit = 0, operators = 0;

    for (std::string::const_iterator it = calcul.begin(); it != calcul.end(); it++)
    {
        if (*it == ' ')
            continue;
        else if (isdigit(*it))
        {
            digit++;
            if (it + 1 == calcul.end())
                continue ;
            if (isdigit(*(it + 1)))
            {
                std::cerr << "Error: [0:10] range allowed" << std::endl;
                return false;
            }
        }
        else
            operators++;
    }

    if (int count = (digit - 1) - operators)
    {
        if (count > 0)
            std::cerr << "Error: Invalid calcul missing operators" << std::endl;
        else
            std::cerr << "Error: Invalid calcul missing numbers" << std::endl;
        return false;
    }


    //check if operators not misplaced
    if (calcul.find_last_of("0123456789") > calcul.find_last_of("+-/*")){
        std::cerr << "Error: Invalid calcul syntax" << std::endl;
        return false;
    }
    if (calcul.find_first_of("+-/*") < calcul.find_first_of("0123456789",calcul.find_first_of("0123456789"))){
        std::cerr << "Error: Invalid calcul syntax" << std::endl;
        return false;
    }

    return true;
}

double makeOperation(const double& a, const double& b, const char& op){
    //std::cout << a << op << b;
    switch (op) {
        case '+':
            return (a + b);
        case '-':
            return (a - b);
        case '/':
            if (b == 0)
                throw std::logic_error("Error: Division by 0 invalid");
            return (a / b);
        case '*':
            return (a * b);
        default :
            return (-1);
    }
}

void executeCalcul(const std::string& calcul)
{
    std::stack<double> stack;

    for (std::string::const_iterator it = calcul.begin(); it != calcul.end(); it++)
    {
        if (*it == ' ')
            continue;
        else if (isdigit(*it))
            stack.push(stod(*it));
        else
        {
            if (stack.size() < 2)
                throw std::logic_error("Error: Invalid calcul syntax");
            double b = stack.top();
            stack.pop();
            double a = stack.top();
            stack.pop();
            double result = makeOperation(a, b, *it);
            stack.push(result);

            //std::cout << " = " << result << std::endl;
        }
    }
    std::cout << stack.top() << std::endl;
}