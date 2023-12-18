#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"

class PhoneBook {
private:
  int number_of_contacts;
  Contact contacts[8];

public:
  PhoneBook(void);
  ~PhoneBook(void);
  void add_contact(void);
  void search_for_contact(void);
  void list_phonebook(void);
};

#endif
