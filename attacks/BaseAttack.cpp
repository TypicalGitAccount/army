#include "BaseAttack.h"

BaseAttack::BaseAttack() {};
BaseAttack::~BaseAttack() {};

void BaseAttack::attack(Unit* enemy, Unit* attacker) {
    if ( enemy == attacker ) {
        throw new CantSelfAttackException();
    }

    enemy->takeDamage( attacker->getState()->getDMG() );
    
    
    enemy->counterAttack(attacker);
}

void BaseAttack::counterAttack(Unit* enemy, Unit* attacker) {
    enemy->takeDamage( attacker->getState()->getDMG() / 2 );
}
