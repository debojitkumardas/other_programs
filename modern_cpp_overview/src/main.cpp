#include <iostream>

/** lambda code */
void Lambda() {
    auto l = [](auto value, int& value2) noexcept -> long {
        return ++value + value2++;
    };

    long (*fp)(int, int&) noexcept = l;
}

/** apporximately equivalent C++ generated by the compiler */
class Lambda_n {
    template<typename T>
    using pointer_type = long (*)(int, int&) noexcept;

    template<typename T>
    constexpr static auto Func(T value, int& value2) noexcept -> long {
        return ++value + value2++;
    }

    constexpr static auto FuncInt(int value, int& value2) noexcept -> long {
        return ++value + value2++;
    }
public:
    template<typename T>
    constexpr auto operator()(T value, int& value2) const noexcept -> long {
        return ++value + value2++;
    }

    template<typename T>
    constexpr operator pointer_type<T>() const {
        return Func;
    }

    constexpr operator pointer_type<int>() const {
        return FuncInt;
    }
};

void Equivalent() {
    auto l = Lambda_n{};
    long (*fp)(int, int&) = l;
}

void VariadicLambda() {
    auto l = [](auto ... value) noexcept -> long {
        return (value + ...);
    };

    auto result = l(1, 2, 3, 4, 5);
}

class VariadicLambda_n {
public:
    template<typename ... T>
    constexpr auto operator()(T ... value) const noexcept -> long {
        return (value + ...);
    };
};

void EquivalentVL() {
    auto l = VariadicLambda_n{};
    auto result = l(1, 2, 3, 4, 5);
}