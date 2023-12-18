#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>

#define RESET "\033[0m"
#define RED "\033[1;31m"
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define UNDERLINE "\033[4;37m"

class Contact {
private:
  int index;
  std::string FirstName;
  std::string LastName;
  std::string Nickname;
  std::string PhoneNumber;
  std::string DarkestSecret;

public:
  Contact(void);
  ~Contact(void);
  void set_contact(void);
  void list_contact(void);
  void list_all(int i);
};

std::string get_input(std::string str);
std::string trunc_str(std::string str);

#endif
