#include "contact.hpp"
#include "phonebook.hpp"
#include <cstdlib>
#include <string>
int main() {
  PhoneBook phone;
  while (true) {
    std::string cmd;
    std::cout << YELLOW << "Phonebook> " << RESET;
    std::getline(std::cin, cmd);
    if (std::cin.eof())
      break;
    if (!cmd.compare("ADD"))
      phone.add_contact();
    else if (!cmd.compare("SEARCH"))
      phone.search_for_contact();
    else if (!cmd.compare("EXIT"))
      exit(EXIT_SUCCESS);
    else
      std::cout << RED << "Please enter a valid cmd : ADD or SEARCH or EXIT"
                << RESET;
    std::cout << std::endl;
  }
  return (EXIT_SUCCESS);
}
