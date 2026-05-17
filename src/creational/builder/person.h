#pragma once

#include <string>

class PersonBuilder;

class Person {
 public:
  friend class PersonBuilder;
  void printInfo();

 private:
  // Mandatory fields
  std::string m_first_name;
  std::string m_last_name;

  // Optional fields
  std::string m_email;
  std::string m_residence;
  unsigned int m_age;
};