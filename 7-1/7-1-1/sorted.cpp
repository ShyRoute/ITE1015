#include <iostream>
#include <vector>
#include <algorithm>
#include "sorted.h"

bool des(int a, int b) {
    return a > b;
}


SortedArray::SortedArray() {
    
}

SortedArray::~SortedArray() {

}

void SortedArray::AddNumber(int num) {
    numbers_.push_back(num);
}

std::vector<int> SortedArray::GetSortedAscending() {
    std::vector<int> arr = numbers_;
    std::sort(arr.begin(), arr.end());
    return arr;
}

std::vector<int> SortedArray::GetSortedDescending() {
    std::vector<int> arr = numbers_;
    std::sort(arr.begin(), arr.end(), des);
    return arr;
}

int SortedArray::GetMax() {
    return *std::max_element(numbers_.begin(), numbers_.end());
}

int SortedArray::GetMin() {
    return *std::min_element(numbers_.begin(), numbers_.end());
}