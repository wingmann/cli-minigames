#ifndef WINGMANN_CLI_MINIGAMES_UTILITIES_INPUT_H
#define WINGMANN_CLI_MINIGAMES_UTILITIES_INPUT_H

#include <string>
#include <iostream>

std::string read_line(const std::string& message = "") {
    std::cout << message << ": " << std::flush;
    std::string input;
    std::getline(std::cin, input);
    return std::move(input);
}

#endif // WINGMANN_CLI_MINIGAMES_UTILITIES_INPUT_H
