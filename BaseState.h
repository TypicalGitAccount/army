#ifndef STATE_H
#define STATE_H

#include <iostream>
#include "../exceptions.cpp"
#include "../schema.h"

class BaseState {
    protected:
        int hp;
        int maxHp;
        int dmg;
        std::string* name;
    public:
        BaseState(const std::string& name, int hp, int dmg);
        virtual ~BaseState();
        bool isDead();

        virtual void takeDamage(int damage);

        int getHp() const ;
        int getMaxHp() const ;
        int getDMG() const ;
        std::string* getName() const ;

        void setHp(int hp) ;
        void setMaxHp (int Hp) ;
        void setDMG(int damage) ;
        void setName(std::string name);
};

std::ostream& operator<<(std::ostream& out, BaseState& state);

#endif // STATE_H