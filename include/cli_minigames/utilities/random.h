#ifndef WINGMANN_CLI_MINIGAMES_UTILITIES_RANDOM_H
#define WINGMANN_CLI_MINIGAMES_UTILITIES_RANDOM_H

#include <chrono>
#include <concepts>
#include <random>

template<typename T>
requires std::integral<T>
T generate_number(T min, T max) {
    auto engine = std::mt19937(std::chrono::steady_clock::now()
        .time_since_epoch()
        .count());
    return std::uniform_int_distribution<T>{min, max}(engine);
}

template<typename T>
requires std::floating_point<T>
T generate_number(T min, T max) {
    auto engine = std::mt19937(std::chrono::steady_clock::now()
        .time_since_epoch()
        .count());
    return std::uniform_real_distribution<T>{min, max}(engine);
}

#endif // WINGMANN_CLI_MINIGAMES_UTILITIES_RANDOM_H
