#pragma once

#include <memory>
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

// Fluent builder, provides more flexibility to the client
// to construct relatively complex entities, instead of using
// many overloaded constructors or constructors with many parameters
// in entity's implementation.

class PersonBuilder {
 public:
  PersonBuilder();

  void reset();
  PersonBuilder& setFirstName(const std::string& first_name);
  PersonBuilder& setLastName(const std::string& last_name);
  PersonBuilder& setEmail(const std::string& email);
  PersonBuilder& setResidence(const std::string& residence);
  PersonBuilder& setAge(unsigned int age);
  std::unique_ptr<Person> build();

 private:
  std::unique_ptr<Person> m_person;
};