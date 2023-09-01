#include "../hdr/orderbookentry.hpp"
#include <iostream>

OrderBookEntry::OrderBookEntry(double _price, double _amount, std::string _timestamp, std::string _product, OrderBookType _order_type)
    : price(_price), amount(_amount), timestamp(std::move(_timestamp)), product(std::move(_product)), order_type(_order_type) { }

void OrderBookEntry::GetValue() const {
    // std::array<std::string, 2> enum_string = {"ask", "bid"};

    std::cout << "price: " << price << '\n';
    std::cout << "amount: " << amount << '\n';
    std::cout << "timestamp: " << timestamp << '\n';
    std::cout << "product: " << product << '\n';
    // std::cout << "ordertype: \n" << order_type;
}
