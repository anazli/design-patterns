#include "person_builder.h"

#include "person.h"

PersonBuilder::PersonBuilder() { reset(); }

void PersonBuilder::reset() { m_person = std::make_unique<Person>(); }

PersonBuilder& PersonBuilder::setFirstName(std::string first_name) {
  m_person->m_first_name = std::move(first_name);
  return *this;
}

PersonBuilder& PersonBuilder::setLastName(std::string last_name) {
  m_person->m_last_name = std::move(last_name);
  return *this;
}

PersonBuilder& PersonBuilder::setEmail(std::string email) {
  m_person->m_email = std::move(email);
  return *this;
}

PersonBuilder& PersonBuilder::setResidence(std::string residence) {
  m_person->m_residence = std::move(residence);
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
