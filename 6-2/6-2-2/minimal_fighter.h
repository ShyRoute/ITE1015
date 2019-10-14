// minimal_fighter.h
// Implement your minimal_fighter.cpp

#ifndef __minimal_fighter__
#define __minimal_fighter__

#include <iostream>
using namespace std;

enum EFighterStatus {
    Invalid = 0,

    Alive,
    Dead,
};
typedef enum EFighterStatus FighterStatus;

class MinimalFighter {
    private:
    int mHp;
    int mPower;
    FighterStatus mStatus;

    public:
    MinimalFighter();
    MinimalFighter(int _hp, int _power);
    int hp();
    int power();
    FighterStatus status();
    void setHp(int _hp);
    void hit(MinimalFighter *_enemy);
    void attack(MinimalFighter *_enemy);
    void fight(MinimalFighter *_enemy);
};
#endif