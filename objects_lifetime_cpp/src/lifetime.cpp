#include "../hdr/lifetime.hpp"
#include <cstdio>

Lifetime::Lifetime() noexcept {
    puts("Lifetime() [default constructor]");
}

Lifetime::Lifetime(const Lifetime&) noexcept {
    puts("Lifetime(const Lifetime&) [copy constructor]");
}
Lifetime::Lifetime(Lifetime&&) noexcept {
    puts("Lifetime(Lifetime&&) [move constructor]");
}
Lifetime::~Lifetime() noexcept {
    puts("~Lifetime() [destructor]");
}
Lifetime& Lifetime::operator=(const Lifetime&) noexcept {
    puts("Lifetime &operator=(const Lifetime&) [copy assignment]");
    return *this;
}
Lifetime& Lifetime::operator=(Lifetime&&) noexcept {
    puts("Lifetime &operator=(Lifetime&&) [move assignment]");
    return *this;
}
