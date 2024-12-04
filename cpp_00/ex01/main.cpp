#include "Contact.hpp"

int main()
{
    Contact person;

    person.fill_contact("diogo", "pinheiro", "dawn", "suzi", 912191421, 1);
    person.print_contactInfo();
    return 0;
}