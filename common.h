//
// Created by mayeu on 03/12/2021.
//

#ifndef ADVENTOFCODE_COMMON_H
#define ADVENTOFCODE_COMMON_H

#include <iostream>

using namespace std;

template <typename T>
inline void display(size_t day, size_t part, T answer) {
    cout << "Day "<< day << " Part " << part << ": " << answer <<endl;
}

template <size_t Day, size_t Part, size_t Expected, size_t Actual, size_t Answer>
inline void challenge(){
    static_assert(Expected == Actual);
    display(Day, Part, Answer);
};

#endif //ADVENTOFCODE_COMMON_H
