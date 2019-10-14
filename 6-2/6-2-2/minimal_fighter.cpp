#include "minimal_fighter.h"

MinimalFighter::MinimalFighter() {
    mHp = 0;
    mPower = 0;
    mStatus = Invalid;
}

MinimalFighter::MinimalFighter(int _hp, int _power) {
    mHp = _hp;
    mPower = _power;
    if(mHp <= 0) mStatus = Dead;
    else mStatus = Alive;
}

int MinimalFighter::hp() {
    return mHp;
}

int MinimalFighter::power() {
    return mPower;
}

FighterStatus MinimalFighter::status() {
    return mStatus;
}

void MinimalFighter::setHp(int _hp) {
    mHp = _hp;
}

void MinimalFighter::hit(MinimalFighter *_enemy) {
    mHp -= _enemy->mPower;
    _enemy->mHp -= mPower;
    if(mHp <= 0) mStatus = Dead;
    else mStatus = Alive;
    if(_enemy->mHp <= 0) _enemy->mStatus = Dead;
    else _enemy->mStatus = Alive;
}

void MinimalFighter::attack(MinimalFighter *_enemy) {
    _enemy->mHp -= mPower;
    mPower = 0;
    if(mHp <= 0) mStatus = Dead;
    else mStatus = Alive;
    if(_enemy->mHp <= 0) _enemy->mStatus = Dead;
    else _enemy->mStatus = Alive;
}

void MinimalFighter::fight(MinimalFighter *_enemy) {
    while(_enemy->mHp != 0 && mHp != 0) {
        mHp -= _enemy->mPower;
        _enemy->mHp -= mPower;
        if(mHp <= 0) mStatus = Dead;
        else mStatus = Alive;
        if(_enemy->mHp <= 0) _enemy->mStatus = Dead;
        else _enemy->mStatus = Alive;
    }
}