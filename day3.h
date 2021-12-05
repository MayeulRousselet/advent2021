//
// Created by Mayeul Rousselet on 12/3/21.
//

#ifndef ADVENTOFCODE_DAY3_H
#define ADVENTOFCODE_DAY3_H

#include "common.h"

namespace day3_part1 {


template <size_t Value, size_t Exp>
struct Pow {
    static constexpr const size_t value = Value * Pow<Value, Exp - 1>::value;
};

template <size_t Value>
struct Pow<Value, 0> {
    static constexpr const size_t value = 1;
};

template <size_t I, size_t N>
struct BitAt {
    static constexpr const bool value = (Pow<2, I>::value & N) == Pow<2, I>::value;
};

template <size_t I, size_t ...N>
struct CountBitAtImpl {
};

template <size_t I, size_t Bit>
struct CountBitAtImpl<I, Bit> {
    static constexpr const size_t zeros = (BitAt<I, Bit>::value ? 0 : 1);
    static constexpr const size_t ones = (BitAt<I, Bit>::value ? 1 : 0);
};

template <size_t I, size_t Bit, size_t ...Rest>
struct CountBitAtImpl<I, Bit, Rest...> {
    static constexpr const size_t zeros = (BitAt<I, Bit>::value ? 0 : 1) + CountBitAtImpl<I, Rest...>::zeros;
    static constexpr const size_t ones = (BitAt<I, Bit>::value ? 1 : 0) + CountBitAtImpl<I, Rest...>::ones;
};

template <size_t I, size_t ...N>
struct CountBitAt {
    using Impl = CountBitAtImpl<I, N...>;
    static constexpr const bool value = Impl::ones > Impl::zeros ? true : false;
};

template <size_t I, size_t N, size_t ...Numbers>
struct GammaRate {
    static constexpr const size_t value = CountBitAt<I, Numbers...>::value * Pow<2, I>::value
                                          + GammaRate<I+1, N, Numbers...>::value;
};

template <size_t N, size_t ...Numbers>
struct GammaRate<N, N, Numbers...> {
    static constexpr const size_t value = CountBitAt<N, Numbers...>::value * Pow<2, N>::value;
};

template <size_t I, size_t N, size_t ...Numbers>
struct EpsilonRate {
    static constexpr const size_t value = !CountBitAt<I, Numbers...>::value * Pow<2, I>::value
                                          + EpsilonRate<I+1, N, Numbers...>::value;
};

template <size_t N, size_t ...Numbers>
struct EpsilonRate<N, N, Numbers...> {
    static constexpr const size_t value = !CountBitAt<N, Numbers...>::value * Pow<2, N>::value;
};

template <size_t N, size_t ...Numbers>
struct PowerConsumption {
    static constexpr const size_t value = GammaRate<0, N, Numbers...>::value * EpsilonRate<0, N, Numbers...>::value;
};

void play();

}

#endif //ADVENTOFCODE_DAY3_H
