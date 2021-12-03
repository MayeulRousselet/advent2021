#ifndef ADVENTOFCODE_DAY2_H
#define ADVENTOFCODE_DAY2_H

#include "common.h"

struct forwar {
};

struct up {
};

struct down {
};

namespace day2_part1 {

	template <typename Dir, size_t N>
	struct Move {
		static constexpr const size_t horizontal = 0;
		static constexpr const size_t depth = 0;
	};

	template <size_t N>
	struct Move<forwar, N> {
		static constexpr const size_t horizontal = N;
		static constexpr const size_t depth = 0;
	};

	template <size_t N>
	struct Move<up, N> {
		static constexpr const size_t horizontal = 0;
		static constexpr const size_t depth = -N;
	};

	template <size_t N>
	struct Move<down, N> {
		static constexpr const size_t horizontal = 0;
		static constexpr const size_t depth = N;
	};

	template <typename ...Rest>
	struct Pilot {
		static constexpr const size_t horizontal = 0;
		static constexpr const size_t depth = 0;
	};

	template <typename Head, typename ...Rest>
	struct Pilot<Head, Rest...> {
		static constexpr const size_t horizontal = Head::horizontal + Pilot<Rest...>::horizontal;
		static constexpr const size_t depth = Head::depth + Pilot<Rest...>::depth;
	};

	void play();

}


namespace day2_part2 {

	template <size_t N>
	struct Wrapper {
		static constexpr const size_t value = N;
	};

	template <typename ...Rest>
	struct Pilot {
		static constexpr const size_t horizontal = 0;
		static constexpr const size_t depth = 0;
	};

	template <typename Aim, typename N, typename ...Rest>
	struct Pilot<Aim, down, N, Rest...> {
		static constexpr const size_t horizontal = Pilot<Wrapper<Aim::value + N::value>, Rest...>::horizontal;
		static constexpr const size_t depth = Pilot<Wrapper<Aim::value + N::value>, Rest...>::depth;
	};

	template <typename Aim, typename N, typename ...Rest>
	struct Pilot<Aim, up, N, Rest...> {
		static constexpr const size_t horizontal = Pilot<Wrapper<Aim::value - N::value>, Rest...>::horizontal;
		static constexpr const size_t depth = Pilot<Wrapper<Aim::value - N::value>, Rest...>::depth;
	};

	template <typename Aim, typename N, typename ...Rest>
	struct Pilot<Aim, forwar, N, Rest...> {
		static constexpr const size_t horizontal = N::value + Pilot<Aim, Rest...>::horizontal;
		static constexpr const size_t depth = N::value * Aim::value + Pilot<Aim, Rest...>::depth;
	};

	void play();

}

#endif //ADVENTOFCODE_DAY2_H