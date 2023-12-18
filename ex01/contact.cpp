#include "contact.hpp"
#include <sstream>
#include <string>

Contact::Contact() {}
Contact::~Contact() {}

std::string get_input(std::string str) {
  std::string input;
  std::cout << "\t" << str << " : ";
  std::getline(std::cin, input);
  if (std::cin.eof())
    exit(EXIT_FAILURE);
  if (input.empty()) {
    std::cout << RED << "Contact " << str << " Can't be empty" << RESET
              << std::endl;
    return get_input(str);
  }
  if (!str.compare("PhoneNumber")) {
    if (input.length() > 10) {
      std::cout << RED << "PhoneNumber Must contains 10 Digits" << RESET
                << std::endl;
      return get_input(str);
    }
    for (unsigned long i = 0; i < input.length(); i++) {
      if (!std::isdigit(input[i])) {
        std::cout << RED << "PhoneNumber Must contains only Numbers" << RESET
                  << std::endl;
        return get_input(str);
      }
    }
  }
  return (input);
}

std::string trunc_str(std::string str) {
  if (str.length() > 10)
    str = str.substr(0, 9) + ".";
  std::cout << std::setw(10);
  return str;
}

void Contact::set_contact() {
  std::cout << UNDERLINE << "Add New Contact" << RESET << std::endl;
  this->FirstName = get_input("FirstName");
  this->LastName = get_input("LastName");
  this->Nickname = get_input("NickName");
  this->PhoneNumber = get_input("PhoneNumber");
  this->DarkestSecret = get_input("DarkestSecret");
  this->index++;
}

void Contact::list_contact() {
  std::cout << "First name : " << this->FirstName << std::endl;
  std::cout << "Last name : " << this->LastName << std::endl;
  std::cout << "Nickname : " << this->Nickname << std::endl;
  std::cout << "Phone number : " << this->PhoneNumber << std::endl;
  std::cout << "Darkest secret : " << this->DarkestSecret << std::endl;
}

void Contact::list_all(int index) {
  std::stringstream ss;
  ss << index;
  std::string str = ss.str();
  std::cout << trunc_str(str) << '|' << trunc_str(this->FirstName) << '|'
            << trunc_str(this->LastName) << '|' << trunc_str(this->Nickname)
            << '|' << std::endl;
}
