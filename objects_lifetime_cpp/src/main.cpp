#include "../hdr/lifetime.hpp"
#include <iostream>
#include <string>

Lifetime f1() {
    return Lifetime{};
}

Lifetime f2() {
    return f1();
}

Lifetime f3(std::string msg) {
    std::cout << msg << '\n';
    return f2();
}

// study the lambda

int main() {

    // std::cout << "l() defined\n";
    // Lifetime l = f3("object l");

    // std::cout << "l2() defined\n";
    /*
    auto l2 = []() {
        return f3("object l2");
    };

    // std::cout << "l2() called\n";
    l2();
    */

    // std::cout << "l3() defined\n";
    /*
    auto l3 = [lt = Lifetime{}]() {
        return f3("object l3");
    };

    // std::cout << "l3() called\n";
    l3();
    */

    // std::cout << "l4() defined\n";
    /*
    auto l4 = []() {
        Lifetime{};
        return f3("object l4");
    };

    // std::cout << "l4() called\n";
    l4();
    */

    auto l5 = Lifetime{};
    auto l5_1 = [l5](){ };
    l5_1();
    auto l5_2 = [l5 = std::move(l5)](){ };
    l5_2();

    return 0;
}
