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
