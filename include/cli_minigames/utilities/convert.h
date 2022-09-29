#ifndef WINGMANN_CLI_MINIGAMES_UTILITIES_CONVERT_H
#define WINGMANN_CLI_MINIGAMES_UTILITIES_CONVERT_H

#include <concepts>
#include <iostream>
#include <optional>
#include <string>

template<typename T>
requires std::integral<T>
std::optional<T> safe_convert(
    const std::string& value,
    T (* func)(const std::string&, std::size_t*, int))
{
    if (value.empty()) {
        std::cerr << "[!] Your input is empty.\n";
        return std::nullopt;
    }
    try {
        return func(value, nullptr, 10);
    } catch (std::invalid_argument&) {
        std::cerr << "[!] Too long a number.\n";
    } catch (std::out_of_range&) {
        std::cerr << "[!] Your input is incorrect.\n";
    }
    return std::nullopt;
}

template<typename T>
requires std::floating_point<T>
std::optional<T> safe_convert(
    const std::string& value,
    T (* func)(const std::string&, std::size_t*))
{
    if (value.empty()) {
        std::cerr << "[!] Your input is empty.\n";
        return std::nullopt;
    }
    try {
        return func(value, nullptr);
    } catch (std::invalid_argument&) {
        std::cerr << "[!] Your input is incorrect.\n";
    } catch (std::out_of_range&) {
        std::cerr << "[!] Too long a number.\n";
    }
    return std::nullopt;
}

template<std::integral T>
std::optional<T> to_integer(const std::string& value, int radix = 10);

template<std::floating_point T>
std::optional<T> to_floating(const std::string& value);

template<>
[[nodiscard]]
std::optional<int> to_integer<int>(const std::string& value, int radix)
{
    return safe_convert(value, std::stoi);
}

template<>
[[nodiscard]]
std::optional<std::int64_t> to_integer<std::int64_t>(const std::string& value, int radix)
{
    return safe_convert(value, std::stoll);
}

template<>
[[nodiscard]]
std::optional<std::uint64_t> to_integer<std::uint64_t>(const std::string& value, int radix)
{
    return safe_convert(value, std::stoull);
}

template<>
[[nodiscard]]
std::optional<float> to_floating<float>(const std::string& value)
{
    return safe_convert(value, std::stof);
}

template<>
[[nodiscard]]
std::optional<double> to_floating<double>(const std::string& value)
{
    return safe_convert(value, std::stod);
}

template<>
[[nodiscard]]
std::optional<long double> to_floating<long double>(const std::string& value)
{
    return safe_convert(value, std::stold);
}

#endif // WINGMANN_CLI_MINIGAMES_UTILITIES_CONVERT_H
