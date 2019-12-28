#include "clocks.h"
#include <iostream>

Clock::Clock() {
    
}


Clock::Clock(int hour, int minute, int second, double driftPerSecond) {
    _clockTime = ClockTime(hour, minute, second, 1);
    _driftPerSecond = driftPerSecond;
}

Clock::~Clock() {
    
}

void Clock::reset() {
    _clockTime.reset();
}

void Clock::tick() {
    _clockTime.increment();
    _totalDrift += _driftPerSecond;
}

NaturalClock::NaturalClock(int hour, int minute, int second, double driftPerSecond) : Clock(hour, minute, second, driftPerSecond) {

}

MechanicalClock::MechanicalClock(int hour, int minute, int second, double driftPerSecond) : Clock(hour, minute, second, driftPerSecond) {

}

DigitalClock::DigitalClock(int hour, int minute, int second, double driftPerSecond) : Clock(hour, minute, second, driftPerSecond) {

}

QuantumClock::QuantumClock(int hour, int minute, int second, double driftPerSecond) : Clock(hour, minute, second, driftPerSecond) {

}

SundialClock::SundialClock(int hour, int minute, int second)  : NaturalClock(hour, minute, second, 0) {
}

void SundialClock::displayTime() {
    std::cout << "SundialClock ";
    _clockTime.display();
    std::cout << ", total drift: " << _totalDrift << std::endl;
}

CuckooClock::CuckooClock(int hour, int minute, int second) : MechanicalClock(hour, minute, second, 0.000694444) {
}

void CuckooClock::displayTime() {
    std::cout << "CuckooClock ";
    _clockTime.display();
    std::cout << ", total drift: " << _totalDrift << std::endl;
}

GrandFatherClock::GrandFatherClock(int hour, int minute, int second) : MechanicalClock(hour, minute, second, 0.000347222) {
}

void GrandFatherClock::displayTime() {
    std::cout << "GrandFatherClock ";
    _clockTime.display();
    std::cout << ", total drift: " << _totalDrift << std::endl;
}

WristClock::WristClock(int hour, int minute, int second) : DigitalClock(hour, minute, second, 0.000034722) {
}

void WristClock::displayTime() {
    std::cout << "WristClock ";
    _clockTime.display();
    std::cout << ", total drift: " << _totalDrift << std::endl;
}

AtomicClock::AtomicClock(int hour, int minute, int second) : QuantumClock(hour, minute, second, 0) {
}

void AtomicClock::displayTime() {
    std::cout << "AtomicClock ";
    _clockTime.display();
    std::cout << ", total drift: " << _totalDrift << std::endl;
}