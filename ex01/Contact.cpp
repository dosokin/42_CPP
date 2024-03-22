#include "Contact.hpp"
#include <iostream>
#include <iomanip>

static void    manage_element(std::string element)
{
    static int x = 0;

    if (x == 4)
    {
        x = 0;
        if (element.size() > 10)
            std::cout << element.substr(0, 9) << ".";
        else
            std::cout << std::setw(10) << element;
        return ;
    }
    if (element.size() > 10)
        std::cout << element.substr(0, 9) << ".|";
    else
        std::cout << std::setw(10) << element << "|";
    x++;
    return ;
}

bool    Contact::isContactInited() const
{
    if (this->_first_name.size())
        return true;
    return false;
}


void    Contact::quickDisplay(int index) const
{
    std::cout << "[" << index << "]" ;
    manage_element(this->_first_name);
    manage_element(this->_last_name);
    manage_element(this->_nickname);
    manage_element(this->_phone_num);
    manage_element(this->_darkest_secret);
    std::cout << std::endl;
}

void    Contact::displayFullContactData() const
{
    std::cout << "\033[1;33mFirst Name: \033[0m";
    std::cout << "\033[1;94m" << this->_first_name << "\033[0m" << std::endl;
    std::cout << "\033[1;33mLast Name: \033[0m";
    std::cout << "\033[1;94m" << this->_last_name << "\033[0m" << std::endl;
    std::cout << "\033[1;33mNickname: \033[0m";
    std::cout << "\033[1;94m" << this->_nickname << "\033[0m" << std::endl;
    std::cout << "\033[1;33mPhone number: \033[0m";
    std::cout << "\033[1;94m" << this->_phone_num << "\033[0m" << std::endl;
    std::cout << "\033[1;33mDarkest secret: \033[0m";
    std::cout << "\033[1;94m" << this->_darkest_secret << "\033[0m" << std::endl;
}

std::string    ask_user_for_data(std::string data_type)
{
    std::string input;

    while (1)
    {
        std::cout << data_type;
        getline(std::cin, input);
        if (input == "EXIT")
        {
            std::cout << "\033[1;36mContact creation cancelled\033[0m" << std::endl;
            return ("EXIT");
        }
        if (input.size())
            return (input);
        else
            std::cerr << "\033[1;31mContact data cant be empty, if you wanna cancel the contact creation type: EXIT\033[0m" << std::endl;
    }
    return ("EXIT");
}

int    Contact::addDataToContact()
{
    this->_first_name = ask_user_for_data("\033[1;33mFirst Name: \033[0m");
    if (this->_first_name == "EXIT")
        return (1);
    this->_last_name = ask_user_for_data("\033[1;33mLast Name: \033[0m");
    if (this->_last_name == "EXIT")
        return (1);
    this->_nickname = ask_user_for_data("\033[1;33mNickname: \033[0m");
    if (this->_nickname == "EXIT")
        return (1);
    this->_phone_num = ask_user_for_data("\033[1;33mPhone number: \033[0m");
    if (this->_phone_num == "EXIT")
        return (1);
    this->_darkest_secret = ask_user_for_data("\033[1;33mDarkest secret: \033[0m");
    if (this->_darkest_secret == "EXIT")
        return (1);
    return (0);
}