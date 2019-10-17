#include "intset.h"
#include <iostream>
#include <vector>
#include <algorithm>

IntegerSet::IntegerSet() {

}

IntegerSet::~IntegerSet() {

}

void IntegerSet::AddNumber(int num) {
    for(int i = 0; i < numbers_.size(); i++) {
        if(numbers_[i] == num) return;
    }
    numbers_.push_back(num);
    std::sort(numbers_.begin(), numbers_.end());
}

void IntegerSet::DeleteNumber(int num) {
    for(int i = 0; i < numbers_.size(); i++) {
        if(numbers_[i] == num) numbers_.erase(numbers_.begin() + i);
    }
    std::sort(numbers_.begin(), numbers_.end());
}

int IntegerSet::GetItem(int pos) {
    if(pos > numbers_.size()) return -1;
    else return numbers_[pos];
}

std::vector<int> IntegerSet::GetAll() {
    return numbers_;
}