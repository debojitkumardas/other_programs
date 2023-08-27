// NOLINTBEGIN
// NOLINTEND
#include <iostream>
#include <string>
#include <vector>

enum class order_book_type{kBid, kAsk};

class OrderBookEntry {
    public:
        double price_;
        double amount_;
        std::string timestamp_;
        std::string product_;
        order_book_type order_type_;

        OrderBookEntry() {
            std::cout << "The default constructor is called." << std::endl;
        }

        OrderBookEntry( double price,
                        double amount,
                        const std::string& timestamp,
                        const std::string& product,
                        order_book_type order_type)
        : price_{price},
          amount_{amount},
          timestamp_{timestamp},
          product_{product},
          order_type_{order_type} {}

        ~OrderBookEntry() {
            std::cout << "The default destructor is called." << std::endl;
        }
};

int main() {

    std::vector<OrderBookEntry> orders;

    orders.emplace_back(10000, 0.002, "2020/03/17 17:01:24.884492", "BTC/USDT", order_book_type::kBid);
    orders.emplace_back(20000, 0.002, "2020/03/17 17:01:24.884492", "BTC/USDT", order_book_type::kBid);

    // order_book_entry orders{10000, 0.002, "2020/03/17 17:01:24.884492", "BTC/USDT", order_book_type::bid};

    for (auto& order : orders){
        std::cout << "The price is: " << order.price_ << std::endl;
    }

    std::vector<std::string> var{"one", "two"};

    for (const std::string& itr : var) {
        std::cout << itr << std::endl;
    }

    return 0;
}
