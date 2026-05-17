#include "character.h"

#include <print>

void Character::display() const {
  std::println("=====Character=====");
  std::println("Name: {}", m_name);
  std::println("Attributes: strength:{}, intelligence: {}, agility: {}",
               m_attributes.strength, m_attributes.intelligence,
               m_attributes.agility);
  std::println("Equipment: weapon:{}, armor:{}", m_equipment.weapon,
               m_equipment.armor);
}

StandardCharacterBuilder::StandardCharacterBuilder() { reset(); }

void StandardCharacterBuilder::reset() {
  m_character = std::make_unique<Character>();
}

void StandardCharacterBuilder::buildName(const std::string& name) {
  m_character->m_name = name;
}

void StandardCharacterBuilder::buildAttributes(int strength, int intelligence,
                                               int agility) {
  m_character->m_attributes = Attributes{
      .strength = strength, .intelligence = intelligence, .agility = agility};
}

void StandardCharacterBuilder::buildEquipment(const std::string& weapon,
                                              const std::string& armor) {
  m_character->m_equipment = Equipment{.weapon = weapon, .armor = armor};
}

std::unique_ptr<Character> StandardCharacterBuilder::getProduct() {
  auto product = std::move(m_character);
  reset();
  return std::move(product);
}

void CharacterCreator::setBuilder(CharacterBuilder* builder) {
  m_builder = builder;
}

std::unique_ptr<Character> CharacterCreator::createWarrior(
    const std::string& name) {
  m_builder->buildName(name);
  m_builder->buildAttributes(85, 42, 96);
  m_builder->buildEquipment("Sword", "Chainmail");
  return std::move(m_builder->getProduct());
}

std::unique_ptr<Character> CharacterCreator::createMage(
    const std::string& name) {
  m_builder->buildName(name);
  m_builder->buildAttributes(25, 82, 38);
  m_builder->buildEquipment("Wooden Staff", "Silk Robe");
  return std::move(m_builder->getProduct());
}
