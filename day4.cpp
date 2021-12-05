//
// Created by Mayeul Rousselet on 12/5/21.
//
#include "day4.h"

namespace day4_part1 {

void play(){
    using T = Set<22,13,17,11,0>;
    cout << Row<Set<22,13,17,11,0>, Set<22>>::over << endl;

    cout << boolalpha << IsPresent<1,T>::value << endl;
    cout << boolalpha << IsPresent<1,Add<1, T>::Result>::value << endl;
}

}