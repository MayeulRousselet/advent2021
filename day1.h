#ifndef ADVENTOFCODE_DAY1_H
#define ADVENTOFCODE_DAY1_H

#include "common.h"

namespace day1_part1 {

template<size_t First, size_t Second, size_t...Rest>
struct DepthMeasurement {
    static constexpr const size_t numberOfTimes =
            (Second > First ? 1 : 0) + DepthMeasurement<Second, Rest...>::numberOfTimes;
};

template<size_t First, size_t Second>
struct DepthMeasurement<First, Second> {
    static constexpr const size_t numberOfTimes = (Second > First ? 1 : 0);
};

void play();

}

namespace day1_part2 {

template<size_t First, size_t Second, size_t Third, size_t Fourth, size_t...Rest>
struct DepthMeasurementWithWindow {
    static constexpr const size_t firstWindow = First + Second + Third;
    static constexpr const size_t secondWindow = Second + Third + Fourth;
    static constexpr const size_t numberOfTimes = (secondWindow > firstWindow ? 1 : 0) +
                                                  DepthMeasurementWithWindow<Second, Third, Fourth, Rest...>::numberOfTimes;
};

template<size_t First, size_t Second, size_t Third, size_t Fourth>
struct DepthMeasurementWithWindow<First, Second, Third, Fourth> {
    static constexpr const size_t firstWindow = First + Second + Third;
    static constexpr const size_t secondWindow = Second + Third + Fourth;
    static constexpr const size_t numberOfTimes = (secondWindow > firstWindow ? 1 : 0);
};

void play();

}

#endif //ADVENTOFCODE_DAY1_H