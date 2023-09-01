#pragma once

#include "orderbookentry.hpp"
#include <vector>

class Helper {
private:
    std::vector<OrderBookEntry> orders;

public:
    Helper();
    /** Call this to start the simulation */
    void Init();

private:
    void LoadOrderBook();
    void PrintMenu();
    void PrintHelp();
    void PrintMarketStats();
    void EnterOffer();
    void EnterBid();
    void PrintWallet();
    void GotoNextTimeframe();
    int GetUserOption();
    void ProcessUserOption(int user_option);
};
