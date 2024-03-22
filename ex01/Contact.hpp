#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class   Contact
{
public:

    bool    isContactInited() const;
    int     addDataToContact();
    void    displayFullContactData() const;
    void    quickDisplay(int index) const;

private:

    std::string     _first_name;
    std::string     _last_name;
    std::string     _nickname;
    std::string     _darkest_secret;
    std::string     _phone_num;
};


#endif