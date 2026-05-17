#include <print>

#include "character.h"
#include "person.h"

int main() {
  auto person_builder = PersonBuilder();
  auto john = person_builder.setFirstName("John")
                  .setLastName("Doe")
                  .setAge(40)
                  .setEmail("johndoe@example.com")
                  .setResidence("City of God")
                  .build();
  john->printInfo();

  auto jane = person_builder.setFirstName("Jane")
                  .setLastName("Doe")
                  .setAge(35)
                  .setEmail("janedoe@example.com")
                  .setResidence("Jane from occupied Europe")
                  .build();
  jane->printInfo();

  CharacterCreator creator;
  auto character_builder = std::make_unique<StandardCharacterBuilder>();
  creator.setBuilder(character_builder.get());

  auto conan = creator.createWarrior("Conan");
  conan->display();
  auto gandalf = creator.createMage("Gandalf");
  gandalf->display();

  return 0;
}