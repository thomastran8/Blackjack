#include <ctime>
#include <cstdlib>
#include "Deck.hpp"

int main()
{
    std::srand(static_cast<unsigned int>(std::time(0)));

    Deck deck;
    deck.shuffleDeck();

    bool winStatus = deck.playBlackJack();

    return 0;
}