#ifndef WINGMANN_CLI_MINIGAMES_UTILITIES_CONVERT_H
#define WINGMANN_CLI_MINIGAMES_UTILITIES_CONVERT_H

#include <concepts>
#include <iostream>
#include <optional>
#include <string>

/// @brief Safe converts string to primitive integral.
///
/// @tparam T    The type convert to.
/// @param f     Pointer to converter function.
/// @param radix The base of a system of numeration.
/// @return      Converted integral value.
///
template<typename T>
requires std::integral<T>
std::optional<T> safe_convert(
    const std::string& value,
    T (*f)(const std::string&, std::size_t*, int))
{
    if (value.empty()) {
        std::cerr << "[!] Your input is empty.\n";
        return std::nullopt;
    }
    try {
        return f(value, nullptr, 10);
    } catch (std::out_of_range&) {
        std::cerr << "[!] Too long a number.\n";
    } catch (std::invalid_argument&) {
        std::cerr << "[!] Your input is incorrect.\n";
    }
    return std::nullopt;
}

/// @brief Safe converts string to primitive floating point.
///
/// @tparam T The type convert to.
/// @param f  Pointer to converter function.
/// @return   Converted integral value.
///
template<typename T>
requires std::floating_point<T>
std::optional<T> safe_convert(const std::string& value, T (*f)(const std::string&, std::size_t*)) {
    if (value.empty()) {
        std::cerr << "[!] Your input is empty.\n";
        return std::nullopt;
    }
    try {
        return f(value, nullptr);
    } catch (std::out_of_range&) {
        std::cerr << "[!] Your input is incorrect.\n";
    } catch (std::invalid_argument&) {
        std::cerr << "[!] Too long a number.\n";
    }
    return std::nullopt;
}

/// @brief Converts string to primitive integral value.
///
/// @tparam T Type of integral value to which to convert.
/// @return   If converted, then integral value otherwise std::nullopt
///
template<std::integral T>
std::optional<T> to_integer(const std::string& value, int radix = 10);

/// @brief Converts string to primitive floating point value.
///
/// @tparam T Type of floating point value to which to convert.
/// @return   If converted, then floating point value otherwise std::nullopt
///
template<std::floating_point T>
std::optional<T> to_floating(const std::string& value);

/// @brief Converts string to primitive integral value.
///
/// @tparam T Type of integral value to which to convert.
/// @return   If converted, then integral value otherwise std::nullopt
///
template<>
[[nodiscard]]
std::optional<int> to_integer<int>(const std::string& value, int radix) {
    return safe_convert(value, std::stoi);
}

/// @brief Converts string to primitive integral value.
///
/// @tparam T Type of integral value to which to convert.
/// @return   If converted, then integral value otherwise std::nullopt
///
template<>
[[nodiscard]]
std::optional<std::int64_t> to_integer<std::int64_t>(const std::string& value, int radix) {
    return safe_convert(value, std::stoll);
}

/// @brief Converts string to primitive integral value.
///
/// @tparam T Type of integral value to which to convert.
/// @return   If converted, then integral value otherwise std::nullopt
///
template<>
[[nodiscard]]
std::optional<std::uint64_t> to_integer<std::uint64_t>(const std::string& value, int radix) {
    return safe_convert(value, std::stoull);
}

/// @brief Converts string to primitive floating point value.
///
/// @tparam T Type of floating point value to which to convert.
/// @return   If converted, then floating point value otherwise std::nullopt
///
template<>
[[nodiscard]]
std::optional<float> to_floating<float>(const std::string& value) {
    return safe_convert(value, std::stof);
}

/// @brief Converts string to primitive floating point value.
///
/// @tparam T Type of floating point value to which to convert.
/// @return   If converted, then floating point value otherwise std::nullopt
///
template<>
[[nodiscard]]
std::optional<double> to_floating<double>(const std::string& value) {
    return safe_convert(value, std::stod);
}

/// @brief Converts string to primitive floating point value.
///
/// @tparam T Type of floating point value to which to convert.
/// @return   If converted, then floating point value otherwise std::nullopt
///
template<>
[[nodiscard]]
std::optional<long double> to_floating<long double>(const std::string& value) {
    return safe_convert(value, std::stold);
}

#endif // WINGMANN_CLI_MINIGAMES_UTILITIES_CONVERT_H
