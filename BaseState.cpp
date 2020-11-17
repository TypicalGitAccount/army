#include <iostream>
#include "BaseState.h"

bool BaseState::isDead() {
    return this->hp <= 0;
};

BaseState::BaseState(const std::string& name, int hp, int dmg) {
    this->hp = hp;
    this->maxHp = hp;
    this->dmg = dmg;
    this->name = new std::string(name);
};

BaseState::~BaseState() {
    delete(this->name);
};

void BaseState::takeDamage(int damage) { 
    if ( damage >= this->hp ) {
        this->hp = 0;
        throw new UnitIsDeadException();
    } 
    
    this->hp -= damage;
};

int BaseState::getHp() const {
    return this->hp;
};
int BaseState::getMaxHp() const {
    return this->maxHp;
};
int BaseState::getDMG() const {
    return this->dmg;
};
std::string* BaseState::getName() const {
    return this->name;
};

void BaseState::setHp(int hp) {
    this->hp = hp;
};

void BaseState::setMaxHp (int Hp) {
    this->maxHp = Hp;
};

void BaseState::setDMG(int damage) {
    this->dmg = damage;
};

void BaseState::setName(std::string name) {
    std::string* newName = new std::string(name);
    this->name = newName;
};

std::ostream& operator<<(std::ostream& out, BaseState& state) {
    out << *state.getName() << "\n";
    out << "hp - " << state.getHp() << ":" << state.getMaxHp() << "\n";
    out << "damage - " << state.getDMG();
    return out;
};

