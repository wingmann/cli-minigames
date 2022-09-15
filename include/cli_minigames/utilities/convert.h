#ifndef WINGMANN_CLI_MINIGAMES_UTILITIES_CONVERT_H
#define WINGMANN_CLI_MINIGAMES_UTILITIES_CONVERT_H

#include <concepts>
#include <iostream>
#include <optional>
#include <string>

std::optional<int> try_stoi(const std::string& value) {
    if (value.empty()) {
        std::cerr << "[!] Your input is empty.\n";
    } else {
        try {
            auto number = std::stoi(value);
            return number;
        } catch (std::invalid_argument&) {
            std::cerr << "[!] Your input is incorrect.\n";
        } catch (std::out_of_range&) {
            std::cerr << "[!] Too long a number.\n";
        }
    }
    return std::nullopt;
}

#endif // WINGMANN_CLI_MINIGAMES_UTILITIES_CONVERT_H
