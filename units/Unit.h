#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include <set>
#include <iterator>
#include "../states/BaseState.h"
#include "../attacks/BaseAttack.h"

class BaseAttack;
class BaseState;

class Unit {
    protected:
        BaseState* uState;
        BaseAttack* uAttack;
        bool isObserved;
        bool isUndead;
        Unit* observer;
    public:
        Unit(BaseState* state, BaseAttack* attack);
        Unit(Unit* u);
        virtual ~Unit();
        
        BaseAttack* getAttack() const;
        BaseState* getState() const;
        Unit* getObserver() const;
        bool getIsObserved() const;
        bool getIsUndead() const;
                
        void changeState(BaseState* changeOn);
        void changeAttack(BaseAttack* changeOn);
        virtual void attack(Unit* enemy);
        virtual void counterAttack(Unit* enemy);

        void takeDamage(int damage);
};

std::ostream& operator<<(std::ostream& out, Unit& unit);

#endif //UNIT_H
