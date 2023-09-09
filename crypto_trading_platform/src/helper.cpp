#include "helper.hpp"
#include <iostream>
#include <vector>

Helper::Helper() : orders() { }

void Helper::Init() {
    int input;

    LoadOrderBook();
    while (true) {
        PrintMenu();
        input = GetUserOption();
        ProcessUserOption(input);
    }
}

void Helper::LoadOrderBook() {
    orders.emplace_back(10000, 0.002, "2020/03/17 17:01:24.884492", "BTC/USDT", OrderBookType::bid);
    orders.emplace_back(20000, 0.002, "2020/03/17 17:01:24.884492", "BTC/USDT", OrderBookType::bid);
}

void Helper::PrintMenu() {
    std::cout << "1. Print help \n";
    std::cout << "2. Print exchange stats \n";
    std::cout << "3. Make an offer \n";
    std::cout << "4. Make a bid \n";
    std::cout << "5. Print Wallet \n";
    std::cout << "6. Continue \n";
    std::cout << "===========================\n";
}
void Helper::PrintHelp() {
    std::cout << "Help - your aim is to make money. Analyse the market and make money.\n";
}
void Helper::PrintMarketStats() {
    std::cout << "Oderbook contains: " << orders.size() << " entries.\n";
}
void Helper::EnterOffer() {
    std::cout << "Make an offer - enter the amount \n";
}
void Helper::EnterBid() {
    std::cout << "Make a bid - enter the amount \n";
}
void Helper::PrintWallet() {
    std::cout << "Your wallet is empty.\n";
}
void Helper::GotoNextTimeframe() {
    std::cout << "Go to next time frame.\n";
}
int Helper::GetUserOption() {
    int user_option;

    std::cout << "Type in 1-6: ";
    std::cin >> user_option;
    std::cout << "You chose: " << user_option << '\n';
    return user_option;
}
void Helper::ProcessUserOption(int user_option) {
    switch (user_option) {
        case 1: // bad input
            PrintHelp();
            break;
        case 2: // bad input
            PrintMarketStats();
            break;
        case 3: // bad input
            EnterOffer();
            break;
        case 4: // bad input
            EnterBid();
            break;
        case 5: // bad input
            PrintWallet();
            break;
        case 6: // bad input
            GotoNextTimeframe();
            break;
        default: // bad input
            std::cout << "Invalid choice. Choose from 1-6.\n";
            break;
    }
}
