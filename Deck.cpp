#include "Deck.hpp"
#include "Globals.hpp"

int Deck::getRandomNumber(int min, int max)
{
    // Setup mersenne twister for uniform randomization
    std::random_device rd {};
    std::mt19937 mersenne {rd()};

    std::uniform_int_distribution<> randCard(min, max);

    return randCard(mersenne);
}

void Deck::swapCard(Card &cardA, Card &cardB)
{
    Card tempCard = cardA;
    cardA = cardB;
    cardB = tempCard;
}

Deck::Deck()
{
    int curCard {0};
    for (int rank {0}; rank < Card::MAX_RANK; ++rank)
    {
        for (int suit {0}; suit < Card::MAX_SUIT; ++suit)
        {
            m_deck[curCard] = Card(static_cast<Card::Ranks>(rank), static_cast<Card::Suits>(suit));
            ++curCard;
        }
    }
}
void Deck::printDeck() const
{
    for (Card curCard : m_deck)
        curCard.printCard();
    std::cout << '\n';
}

void Deck::shuffleDeck()
{
    for (int index {0}; index < g_deckSize; ++index)
    {
        int randIndex = getRandomNumber(0, g_deckSize-1);

        swapCard(m_deck[index], m_deck[randIndex]);
    }

    // Reset
    m_cardIndex = 0;
}

const Card& Deck::dealCard()
{
    assert(m_cardIndex < g_deckSize);
    return m_deck[m_cardIndex++];
}

Deck::BlackJackStatus Deck::playBlackJack()
{
    m_dealerScore += dealCard().getCardValue();
    m_playerScore += dealCard().getCardValue();
    m_playerScore += dealCard().getCardValue();

    // loop until player stands or loses
    while(true)
    {
        std::cout << "===Begin m_round " << m_round << "===\n";
        std::cout << "You: " << m_playerScore << " Dealer: " << m_dealerScore << "\n";
        std::cout << "h to hit or s to stand: ";
        char decision {};
        std::cin >> decision;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (decision == 's')
        {
            std::cout << "*You stand\n";
            if ((m_dealerScore >= m_playerScore && m_dealerScore >= g_dealerLimit) || m_dealerScore > m_playerScore)
            {
                std::cout << "*Dealer stands\n";
                break;
            }
        }
        else if (decision == 'h')
        {
            int drawnCard = dealCard().getCardValue();

            // check if ace
            if (drawnCard == g_aceValue)
            {
                m_playerAces += 1;
            }
            std::cout << "*You draw a " << drawnCard << "\n";
            m_playerScore += drawnCard;
            // reduce score if ace is available
            if (m_playerScore > g_maxScore && m_playerAces > 0)
            {
                m_playerAces -= 1;
                m_playerScore -= g_aceValue - 1;
                std::cout << "*Changed ace value to 1. Score updated\n";
            }

            std::cout << "You: " << m_playerScore << " Dealer: " << m_dealerScore << "\n";

            // check for automatic win states
            if (m_playerScore > g_maxScore)
            {
                std::cout << "Player busts! You lose!\n";
                return BlackJackStatus::LOSE;
            }
            else if (m_dealerScore == g_maxScore && m_dealerScore == m_playerScore)
            {
                std::cout << "Dealer and player has " << g_maxScore << ". Tie!\n";
                return BlackJackStatus::TIE;
            }
        }

        if (m_dealerScore < g_dealerLimit || (decision == 's' && m_dealerScore < m_playerScore))
        {
            int drawnCard = dealCard().getCardValue();

            // check if ace
            if (drawnCard == g_aceValue)
            {
                m_dealerAces += 1;
            }
            std::cout << "*Dealer draws a " << drawnCard << "\n";
            m_dealerScore += drawnCard;
            // reduce score if ace is available
            if (m_dealerScore > g_maxScore && m_dealerAces > 0)
            {
                m_dealerAces -= 1;
                m_dealerScore -= g_aceValue - 1;
                std::cout << "*Changed ace value to 1. Score updated\n";
            }
        }
        else
        {
            std::cout << "*Dealer stands\n";
        }

        std::cout << "You: " << m_playerScore << " Dealer: " << m_dealerScore << "\n";


        // check for automatic win states
        if (m_dealerScore > g_maxScore)
        {
            std::cout << "Dealer busts! You win!\n";
            return BlackJackStatus::WIN;
        }
        else if (m_dealerScore == g_maxScore && m_dealerScore == m_playerScore)
        {
            std::cout << "Dealer and player has " << g_maxScore << ". Tie!\n";
            return BlackJackStatus::TIE;
        }

        std::cout << "===End m_round " << m_round++ << "===\n\n";
    }

    // check win status
    if (m_playerScore > m_dealerScore && m_playerScore <= g_maxScore)
    {
        std::cout << "You win!\n";
        return BlackJackStatus::WIN;
    }
    else if (m_playerScore == m_dealerScore)
    {
        std::cout << "Tie!\n";
        return BlackJackStatus::TIE;
    }

    std::cout << "You Lose!\n";

    return BlackJackStatus::LOSE;
}