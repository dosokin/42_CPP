#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>

void    lets_add(PhoneBook& Book)
{
    Contact NewContact;

    if (NewContact.addDataToContact())
        return;
    Book.add(NewContact);
}

void    lets_search(PhoneBook Book)
{
    std::string contact_to_display;
    int         contact_id;
    bool        searched = false;

    if (Book.displayContacts())
        return ;
    while (!searched)
    {
        std::cout << "\033[1;32mWhich contact do you wanna display? \033[0m";
        getline(std::cin, contact_to_display);
        try{
            std::istringstream strom(contact_to_display);
            strom >> contact_id;
            if (!strom.eof())
                throw std::invalid_argument("\033[1;31mPlease only input one valid number [1:8]\033[0m");
            if (Book.displayOneContact(contact_id) == 0)
                searched = true;
        }
        catch (std::invalid_argument& e){
            std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;
        }
        catch(...){
            std::cerr << "\033[1;31mPlease input a valid number\033[0m" << std::endl;
        }
    }
    return ;
}

int main()
{
    PhoneBook   Book;
    std::string instruction;

    system("clear");
    std::cout << "\033[1;32mWelcome in the bipbipboup\033[0m\n" << std::endl;
    while (1)
    {
        std::cout << "\033[1;32mType ADD to add a new contact\n"
           << "Type SEARCH to search for a contact\nType EXIT to quit\033[0m" << std::endl;
        getline(std::cin, instruction);
        if (instruction == "ADD")
            lets_add(Book);
        else if (instruction == "SEARCH")
            lets_search(Book);
        else if (instruction == "EXIT")
            break;
        else
        {
            std::cerr << "\033[1;31mThis is not a valid instruction\033[1;32m" << std::endl;
            continue ;
        }
    }
    return (0);
}