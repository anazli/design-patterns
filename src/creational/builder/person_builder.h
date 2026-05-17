#pragma once

#include <memory>
#include <string>

class Person;

class PersonBuilder {
 public:
  PersonBuilder();

  void reset();
  PersonBuilder& setFirstName(std::string first_name);
  PersonBuilder& setLastName(std::string last_name);
  PersonBuilder& setEmail(std::string email);
  PersonBuilder& setResidence(std::string residence);
  PersonBuilder& setAge(unsigned int age);
  std::unique_ptr<Person> build();

 private:
  std::unique_ptr<Person> m_person;
};