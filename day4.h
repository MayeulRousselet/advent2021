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

template <size_t Value>
struct IsPresent<Value, Set<>>{
    static constexpr const bool value = false;
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

template <typename R, typename A, typename B>
struct IntersectionImpl {
};

template <size_t... R, size_t Head, size_t ...Rest,size_t ...B>
struct IntersectionImpl<Set<R...>, Set<Head, Rest...>,Set<B...>> {
    using Result = conditional_t<
            IsPresent<Head, Set<Rest...>>::value,
            typename Add<Head, Set<R...>>::Result ,
            Set<R...>
            >;
};

template <typename A, typename B>
struct Intersection {
};

template <size_t ...A,size_t ...B>
struct Intersection<Set<A...>,Set<B...>> {
    using Result = typename IntersectionImpl<Set<>, Set<A...>, Set<B...>>::Result;
};

template <typename S, typename Drawn>
struct Row {
};

template <size_t ...Values,size_t... Drawn>
struct Row<Set<Values...>, Set<Drawn...>> {
    static constexpr const bool complete = Set<Values...>::N == Set<Drawn...>::N;
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
