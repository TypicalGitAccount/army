#include "Unit.h"

Unit::Unit(State* state, BaseAttack* attack) {
    this->uState = state;
    this->uAttack = attack;
    this->isObserved = false;
    this->observer = NULL;
};

Unit::~Unit() {
    delete this->uState;
    delete this->uAttack;
    delete this->observer;
};

Unit::Unit(Unit* u) {
    this->uState = u->getState();
    this->uAttack = u->getAttack();
    this->isObserved = u->getIsObserved();
    this->observer = u->getObserver();
    this->isUndead = u->getIsUndead();
}

void Unit::changeState(State* changeOn) {
    this->uState->setMaxHp(changeOn->getMaxHp());
    this->uState->setDMG(changeOn->getDMG());
    this->uState->setName(*(changeOn->getName()));

    delete changeOn;
}

void Unit::changeAttack(BaseAttack* changeOn) {
    delete this->uAttack;

    this->uAttack = changeOn;
}

void Unit::becomeObservedBy(Unit* observer) {
    this->isObserved = true;
    this->observer = observer;
}

void Unit::giveHp() {
    if ( isObserved == true ) {
        if ( (observer->getState()->getHp() + this->getState()->getMaxHp() / 5 ) > observer->getState()->getMaxHp() ) {
            observer->getState()->setHp(observer->getState()->getMaxHp());
        } else {
            observer->getState()->setHp(observer->getState()->getHp() + ( this->getState()->getMaxHp() / 5 ) );
        }
    }
}

void Unit::attack(Unit* enemy) {
    this->uAttack->attack(enemy, this);
};

void Unit::counterAttack(Unit* enemy) {
    this->uAttack->counterAttack(enemy, this);
};

void Unit::takeDamage(int damage) {
    if ( damage >= this->getState()->getHp() ) {
        this->giveHp();
    }

    this->uState->takeDamage(damage);
};

BaseAttack* Unit::getAttack() const {
    return this->uAttack;
}

State* Unit::getState() const { 
    return this->uState; 
}

Unit* Unit::getObserver() const {
    return this->observer;
}

bool Unit::getIsObserved() const {
    return this->isObserved;
}

bool Unit::getIsUndead() const {
    return this->isUndead;
}

std::ostream& operator<<(std::ostream& out, Unit* unit) {
    out << "Unit " << *(unit->getState()) << std::endl;

    return out;
};

