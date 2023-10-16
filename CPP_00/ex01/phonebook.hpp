#include <iostream>
#include <string>

class Contact
{
    private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;

    public:
    Contact() = default;
    Contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret)
    {
        this->first_name = first_name;
        this->last_name = last_name;
        this->nickname = nickname;
        this->phone_number = phone_number;
        this->darkest_secret = darkest_secret;
    }
    std::string get_first_name() {return (this->first_name);}
    std::string get_last_name() {return (this->last_name);}
    std::string get_nickname() {return (this->nickname);}
    std::string get_phone_number() {return (this->phone_number);}
    std::string get_darkest_secret() {return (this->darkest_secret);}
};


class Phonebook
{
    private:
    Contact contacts[8];
    int current_index = 0;

    public:
    Phonebook() = default;
    void add_contact(Contact contact)
    {
        contacts[current_index] = contact;
        current_index = (current_index + 1) % 8;
    }

    Contact get_contact(int index)
    {
        return (contacts[index]);
    }

};


