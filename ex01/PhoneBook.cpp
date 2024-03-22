#include "PhoneBook.hpp"
#include <iostream>

void    PhoneBook::add(const Contact& NewContact)
{
    static int contactId = 0;

    if (contactId > 7)
        contactId = 0;
    if (this->_index <= 7)
        this->_index++;
    this->_Contacts[contactId] = NewContact;
    contactId++;
}

int    PhoneBook::displayContacts()
{
    int contact_id = 1;

    if (!this->_index)
    {
        std::cerr << "\033[1;31mYour phonebook is empty, please add a contact first\033[0m" << std::endl;
        return (1);
    } 
    for (size_t i = 0; i < this->_index; i++)
    {
        _Contacts[i].quickDisplay(contact_id);
        contact_id++;
    }
    return (0);
}

int    PhoneBook::displayOneContact(int contact_id) const
{
    if (contact_id == 999)
        return (0);
    if (contact_id < 1 || contact_id > this->_index)
    {
        std::cerr << "\033[1;31mThis contact doesnt exist, try again or type 999 to exit\033[0m" << std::endl;
        return (1);
    }
    this->_Contacts[contact_id - 1].displayFullContactData();
    return (0);
}

PhoneBook::PhoneBook()
{
    this->_index = 0;
}

PhoneBook::~PhoneBook()
{
}