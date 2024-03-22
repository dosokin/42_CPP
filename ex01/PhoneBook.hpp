#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <string>
#include <vector>
#include "Contact.hpp"

class   PhoneBook
{
public:
    PhoneBook();
    void    add(const Contact& NewContact);
    int     displayContacts();
    int     displayOneContact(int contact_id) const;
    void    exit();
    ~PhoneBook();

private:
    int        _index;
    Contact    _Contacts[8];
};

#endif