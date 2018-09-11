#include "Card.hpp"
#include "Globals.hpp"

void Card::printCard() const
{
    std::string cardCode { };

    switch(m_rank)
    {
        case Ranks::RANK_2:         cardCode += '2'; break;
        case Ranks::RANK_3:         cardCode += '3'; break;
        case Ranks::RANK_4:         cardCode += '4'; break;
        case Ranks::RANK_5:         cardCode += '5'; break;
        case Ranks::RANK_6:         cardCode += '6'; break;
        case Ranks::RANK_7:         cardCode += '7'; break;
        case Ranks::RANK_8:         cardCode += '8'; break;
        case Ranks::RANK_9:         cardCode += '9'; break;
        case Ranks::RANK_10:        cardCode += 'T'; break;
        case Ranks::RANK_JACK:      cardCode += 'J'; break;
        case Ranks::RANK_QUEEN:     cardCode += 'Q'; break;
        case Ranks::RANK_KING:      cardCode += 'K'; break;
        case Ranks::RANK_ACE:       cardCode += 'A'; break;
        default:                    cardCode += '?';
    }

    switch(m_suit)
    {
        case Suits::CLUBS:          cardCode += 'C'; break;
        case Suits::DIAMONDS:       cardCode += 'D'; break;
        case Suits::HEARTS:         cardCode += 'H'; break;
        case Suits::SPADES:         cardCode += 'S'; break;
        default:                    cardCode += '?';
    }

    std::cout << cardCode << ' ';
}

int Card::getCardValue() const
{
    int value {0};
    switch(m_rank)
    {
        case Ranks::RANK_2:     return 2;
        case Ranks::RANK_3:     return 3;
        case Ranks::RANK_4:     return 4;
        case Ranks::RANK_5:     return 5;
        case Ranks::RANK_6:     return 6;
        case Ranks::RANK_7:     return 7;
        case Ranks::RANK_8:     return 8;
        case Ranks::RANK_9:     return 9;
        case Ranks::RANK_10:
        case Ranks::RANK_JACK:
        case Ranks::RANK_QUEEN:
        case Ranks::RANK_KING:  return 10;
        case Ranks::RANK_ACE:   return g_aceValue;
        default:                return -1;
    }
}