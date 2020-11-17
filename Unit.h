#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include <set>
#include <iterator>

class BaseAttack;

class Unit {
    protected:
        State* uState;
        BaseAttack* uAttack;
        bool isObserved;
        bool isUndead;
        Unit* observer;
    public:
        Unit(State* state, BaseAttack* attack);
        Unit(Unit* u);
        virtual ~Unit();
        
        BaseAttack* getAttack() const;
        State* getState() const;
        Unit* getObserver() const;
        bool getIsObserved() const;
        bool getIsUndead() const;
                
        void changeState(State* changeOn);
        void changeAttack(BaseAttack* changeOn);
        virtual void attack(Unit* enemy);
        virtual void counterAttack(Unit* enemy);

        void takeDamage(int damage);

        virtual void giveHp();
        void becomeObservedBy(Unit* observer);
};

std::ostream& operator<<(std::ostream& out, Unit& unit);

#endif //UNIT_H
