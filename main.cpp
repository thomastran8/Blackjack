#include <ctime>
#include <cstdlib>
#include "Deck.hpp"

int main()
{
    // std::srand(static_cast<unsigned int>(std::time(0)));
    // std::rand();    // Windows fix

    Deck deck;
    deck.shuffleDeck();

    bool winStatus = deck.playBlackJack();

    char hello {};

    std::cout << "--------------------------------\n"
                 "Press 'Enter' to end the program\n"
                 "--------------------------------\n";
    std::getchar();

    return 0;
}