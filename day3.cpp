//
// Created by Mayeul Rousselet on 12/3/21.
//
#include "day3.h"

namespace day3_part1 {

void play(){
    using Example = PowerConsumption<4, 0b00100,
            0b11110,
            0b10110,
            0b10111,
            0b10101,
            0b01111,
            0b00111,
            0b11100,
            0b10000,
            0b11001,
            0b00010,
            0b01010>;
    challenge<3, 1, 198, Example::value, 0>();
}

}