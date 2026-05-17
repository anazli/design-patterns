#include <print>

#include "person.h"
#include "person_builder.h"

int main() {
  auto builder = PersonBuilder();
  auto john = builder.setFirstName("John")
                  .setLastName("Doe")
                  .setAge(40)
                  .setEmail("johndoe@example.com")
                  .setResidence("City of God")
                  .build();
  john->printInfo();

  auto jane = builder.setFirstName("Jane")
                  .setLastName("Doe")
                  .setAge(35)
                  .setEmail("janedoe@example.com")
                  .setResidence("Jane from occupied Europe")
                  .build();
  jane->printInfo();
  return 0;
}