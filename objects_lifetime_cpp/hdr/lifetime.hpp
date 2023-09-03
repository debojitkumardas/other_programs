#pragma once

struct Lifetime {
    Lifetime() noexcept;
    Lifetime(const Lifetime&) noexcept;
    Lifetime(Lifetime&&) noexcept;
    ~Lifetime() noexcept;
    Lifetime& operator=(const Lifetime&) noexcept;
    Lifetime& operator=(Lifetime&&) noexcept;
};
