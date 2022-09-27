#include "cli_minigames/utilities.h"

int main()
{
    std::cout << "Guess the number!\n";

    auto secret_number = generate_number(1, 100);
    unsigned counter{};

    while (true) {
        auto guess = read_line("Please input your guess");
        auto number = try_stoi(guess);

        if (!number.has_value()) continue;

        if (number < 1 || number > 100) {
            std::cerr << "[!] Secret number ranges from 1 to 100\n";
            continue;
        }
        counter++;

        if (number < secret_number) {
            std::cout << "- too small!\n";
        }
        else if (number > secret_number) {
            std::cout << "- to big!\n";
        }
        else {
            std::cout << "You win!\nCount of attempts: " << counter << '\n';
            break;
        }
    }
    return 0;
}
