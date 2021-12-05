//
// Created by Mayeul Rousselet on 12/5/21.
//
#include "day4.h"

namespace day4_part1 {

void play(){
    using T = Set<22,13,17,11,0>;
    cout << boolalpha << Row<Set<22,13,17,11,0>, Set<22,13,17,12,11>>::complete << endl;

    Intersection<Set<1,2>, Set<3,4>>::Result a;

    cout << boolalpha << IsPresent<1,T>::value << endl;
    cout << boolalpha << IsPresent<1,Add<1, T>::Result>::value << endl;
}

}