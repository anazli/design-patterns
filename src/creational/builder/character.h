#pragma once

#include <memory>
#include <string>

struct Attributes {
  int strength = 0;
  int intelligence = 0;
  int agility = 0;
};

struct Equipment {
  std::string weapon;
  std::string armor;
};

class StandardCharacterBuilder;

class Character {
 public:
  friend class StandardCharacterBuilder;
  void display() const;

 private:
  std::string m_name;
  Attributes m_attributes;
  Equipment m_equipment;
};

class CharacterBuilder {
 public:
  virtual ~CharacterBuilder() = default;
  virtual void reset() = 0;
  virtual void buildName(const std::string& name) = 0;
  virtual void buildAttributes(int strength, int intelligence, int agility) = 0;
  virtual void buildEquipment(const std::string& weapon,
                              const std::string& armor) = 0;

  virtual std::unique_ptr<Character> getProduct() = 0;
};

class StandardCharacterBuilder : public CharacterBuilder {
 public:
  StandardCharacterBuilder();
  ~StandardCharacterBuilder() override = default;
  void reset() override;
  void buildName(const std::string& name) override;
  void buildAttributes(int strength, int intelligence, int agility) override;
  void buildEquipment(const std::string& weapon,
                      const std::string& armor) override;

  std::unique_ptr<Character> getProduct() override;

 private:
  std::unique_ptr<Character> m_character;
};

class CharacterCreator {
 public:
  void setBuilder(CharacterBuilder* builder);
  std::unique_ptr<Character> createWarrior(const std::string& name);
  std::unique_ptr<Character> createMage(const std::string& name);

 private:
  CharacterBuilder* m_builder = nullptr;
};