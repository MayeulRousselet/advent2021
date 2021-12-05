//
// Created by Mayeul Rousselet on 12/5/21.
//

#ifndef ADVENTOFCODE_DAY4_H
#define ADVENTOFCODE_DAY4_H

#include "common.h"

namespace day4_part1 {

template <size_t ...Numbers>
struct Set{
    static constexpr const size_t N = sizeof...(Numbers);
};

template <size_t Value, typename S>
struct IsPresent{
};

template <size_t Value, size_t...Values>
struct IsPresent<Value, Set<Values...>>{
};

template <size_t Value, size_t Head, size_t...Rest>
struct IsPresent<Value, Set<Head, Rest...>>{
    static constexpr const bool value = (Value == Head ? true : IsPresent<Value, Set<Rest...>>::value);
};

template <size_t Value, size_t Head>
struct IsPresent<Value, Set<Head>>{
    static constexpr const bool value = (Value == Head ? true : false);
};

template <size_t Value, typename S>
struct Add{
};

template <size_t Value, size_t...Values>
struct Add<Value, Set<Values...>>{
    using Result = conditional_t<
             IsPresent<Value, Set<Values...>>::value,
             Set<Values...>,
             Set<Values..., Value>
            >;
};

template <typename S, typename Drawn>
struct Row {
};

template <size_t ...Values,size_t... Drawn>
struct Row<Set<Values...>, Set<Drawn...>> {
};

template <size_t Value, typename R>
struct Draw {
};

template <size_t Value, size_t ...Values,size_t... Drawn>
struct Draw<Value, Row<Set<Values...>,Set<Drawn...>>>{
    using Result = conditional_t<
            IsPresent<Value, Set<Values...>>::value,
            Row<Set<Values...>, typename Add<Value, Set<Drawn...>>::Result>,
            Row<Set<Values...>, Set<Drawn...>>
           >;
};

template <typename ...S>
struct Sets {

};

template <typename Rows, typename Cols>
struct Grid {
};

void play();

}

#endif //ADVENTOFCODE_DAY4_H
