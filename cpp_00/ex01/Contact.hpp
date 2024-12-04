#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>
#include <cctype>


class Contact{

	private:
		int index;
        int number;
		std::string first_name; 
		std::string last_name;
		std::string nickname;
        std::string darkest_secret;

    public:
    // funcoes entram aqui
        void    print_contactInfo();
        void    fill_contact(std::string fname, std::string lname, std::string nname, std::string secret, int nbr, int i);
};

#endif