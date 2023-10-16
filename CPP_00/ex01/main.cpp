#include "phonebook.hpp"

int main(void)
{
    Phonebook phonebook;
    
    std::string command;
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;
    int index;

    while (true)
    {
        std::cout << "Please enter a command: ";
        std::cin >> command;

        if (command == "EXIT")
            break ;
        
        else if (command == "ADD")
        {
            std::cout << "Please enter a first name: ";
            std::cin >> first_name;
            std::cout << "Please enter a last name: ";
            std::cin >> last_name;
            std::cout << "Please enter a nickname: ";
            std::cin >> nickname;
            std::cout << "Please enter a phone number: ";
            std::cin >> phone_number;
            std::cout << "Please enter a darkest secret: ";
            std::cin >> darkest_secret;

            Contact contact(first_name, last_name, nickname, phone_number, darkest_secret);
            phonebook.add_contact(contact);
            
        }

        else if (command == "SEARCH")
        {
            std::cout << "Enter a index: ";
            std::cin >> index;

            Contact contact = phonebook.get_contact(index);
            std::cout << "First name: " << contact.get_first_name() << std::endl;
            std::cout << "Last name: " << contact.get_last_name() << std::endl;
            std::cout << "Nickname: " << contact.get_nickname() << std::endl;
            std::cout << "Phone number: " << contact.get_phone_number() << std::endl;
            std::cout << "Darkest secret: " << contact.get_darkest_secret() << std::endl;
        }
        else
            std::cout << "Invalid command\n";
    }
    return (0);
}