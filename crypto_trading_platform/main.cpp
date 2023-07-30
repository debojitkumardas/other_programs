#include <cmath>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

enum class order_book_type{bid, ask};

class order_book_entry {
    private:
        double price_;
        double amount_;
        std::string timestamp_;
        std::string product_;
        order_book_type order_type_;

    public:
        order_book_entry() {
            std::cout << "The default constructor is called." << std::endl;
        }

        order_book_entry(double price,
                         double amount,
                         const std::string& timestamp,
                         const std::string& product,
                         order_book_type order_type)
        : price_{price},
          amount_{amount},
          timestamp_{timestamp},
          product_{product},
          order_type_{order_type} {

            std::cout << "The price is: " << price << std::endl;
            std::cout << "The amount is: " << amount << std::endl;
            std::cout << "The timestamp is: " << timestamp << std::endl;
            std::cout << "The product is: " << product << std::endl;
            // std::cout << "The order type is: " << orders.order_type << std::endl;
        }

        ~order_book_entry() {
            std::cout << "The default destructor is called." << std::endl;
        }
};

int main() {

    std::vector<order_book_entry> orders;

    orders.emplace_back(10000, 0.002, "2020/03/17 17:01:24.884492", "BTC/USDT", order_book_type::bid);

    // order_book_entry orders{10000, 0.002, "2020/03/17 17:01:24.884492", "BTC/USDT", order_book_type::bid};

    return 0;
}
