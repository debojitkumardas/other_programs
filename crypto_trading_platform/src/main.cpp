// NOLINTBEGIN
// NOLINTEND
#include "helper.hpp"
#include <iostream>
#include <vector>

std::vector<std::string> Tokenise(std::string, char, char esc = ' ');

int main() {

    char ch = 'n';
    Helper app{};

    if (ch == 'y')
        app.Init();

    std::vector<std::string> result = Tokenise("thing1,,thing2,thing3", ',', '"');
    for (auto& var : result) {
        std::cout << var << '\n';
    }
    /*
    for (auto& order : orders) {
        order.GetValue();
    }
    */

    return 0;
}
