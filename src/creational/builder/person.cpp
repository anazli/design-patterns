#include "person.h"

#include <print>

void Person::printInfo() {
  std::println("==============================");
  std::println("First name: {}", m_first_name);
  std::println("Last name: {}", m_last_name);
  std::println("Email: {}", m_email);
  std::println("Residence: {}", m_residence);
  std::println("Age: {}", std::to_string(m_age));
  std::println("==============================");
}

PersonBuilder::PersonBuilder() { reset(); }

void PersonBuilder::reset() { m_person = std::make_unique<Person>(); }

PersonBuilder& PersonBuilder::setFirstName(const std::string& first_name) {
  m_person->m_first_name = first_name;
  return *this;
}

PersonBuilder& PersonBuilder::setLastName(const std::string& last_name) {
  m_person->m_last_name = last_name;
  return *this;
}

PersonBuilder& PersonBuilder::setEmail(const std::string& email) {
  m_person->m_email = email;
  return *this;
}

PersonBuilder& PersonBuilder::setResidence(const std::string& residence) {
  m_person->m_residence = residence;
  return *this;
}

PersonBuilder& PersonBuilder::setAge(unsigned int age) {
  m_person->m_age = age;
  return *this;
}

std::unique_ptr<Person> PersonBuilder::build() {
  auto product = std::move(m_person);
  reset();
  return std::move(product);
}