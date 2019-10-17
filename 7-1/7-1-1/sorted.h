#pragma once

#include <iostream>
#include <vector>

class SortedArray {
    public:
    SortedArray();
    ~SortedArray();

    void AddNumber(int num);
    std::vector<int> GetSortedAscending();
    std::vector<int> GetSortedDescending();
    int GetMax();
    int GetMin();

    private:
    std::vector<int> numbers_;
};