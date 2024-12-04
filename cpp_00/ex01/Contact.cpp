#include "Contact.hpp"


void Contact::print_contactInfo()
{
	std::cout << "First Name " << first_name << std::endl;
	std::cout << "Last Name " << last_name << std::endl;
	std::cout << "Nick Name " << nickname << std::endl;
	std::cout << "Darkest Secret " << darkest_secret << std::endl;
	std::cout << "Phone Number " << number << std::endl;
}

void Contact::fill_contact(std::string fname, std::string lname, std::string nname, std::string secret, int nbr, int i)
{
	first_name = fname;
	last_name = lname;
	nickname = nname;
	darkest_secret = secret;
	number = nbr;
	index = i;
}