#include "phonebook.hpp"
#include "contact.hpp"

PhoneBook::PhoneBook() : number_of_contacts(0) {}
PhoneBook::~PhoneBook() {}

void PhoneBook::add_contact() {
  int index = this->number_of_contacts % 8;
  this->contacts[index].set_contact();
  this->number_of_contacts++;
  std::cout << GREEN << "Contact Saved successfully !" << RESET << std::endl;
}

void PhoneBook::list_phonebook(void) {
  int contacts = this->number_of_contacts;
  if (contacts > 8)
    contacts = 8;
  std::cout << UNDERLINE;
  std::cout << trunc_str("index") << "|" << trunc_str("first name") << "|"
            << trunc_str("lastname") << "|" << trunc_str("nickname") << "|"
            << std::endl;
  for (int i = 0; i < contacts; i++) {
    this->contacts[i].list_all(i);
  }
  std::cout << RESET;
}

std::string iToString(int i) {
  std::string str;
  std::stringstream ss;

  ss << i;
  ss >> str;

  return (str);
}

void PhoneBook::search_for_contact() {
  if (!this->number_of_contacts) {
    std::cout << RED << "Contact List is Empty" << RESET << std::endl;
    return;
  }
  int n = (number_of_contacts > 8) ? 8 : number_of_contacts;
  this->list_phonebook();
  std::string input;
  std::cout << std::endl
            << "For more informations, Enter the index of the contact: "
            << std::endl;
  ;
  getline(std::cin, input);
  if (std::cin.eof())
    std::exit(EXIT_SUCCESS);
  for (int i = 0; i < n; i++) {
    if (input == iToString(i)) {
      contacts[i].list_contact();
      return;
    }
  }
  std::cout << RED << "Invalid index" << RESET << std::endl;
}
