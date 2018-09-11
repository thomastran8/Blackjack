#ifndef DECK_HPP
#define DECK_HPP

#include <iostream>
#include <array>
#include <random>
#include <cassert>
#include "Card.hpp"
#include "Globals.hpp"

class Deck
{
public:
	enum BlackJackStatus
	{
		WIN,
		LOSE,
		TIE
	};
	
private:
	std::array<Card, g_deckSize> m_deck;
	int m_cardIndex {0};
	int m_playerScore {0};
	int m_dealerScore {0};
	int m_round {1};
	int m_playerAces {0};
	int m_dealerAces {0};

	void swapCard(Card &cardA, Card &cardB);

public:
	Deck();
	void printDeck() const;
	void shuffleDeck();
	const Card& dealCard();
	BlackJackStatus playBlackJack();
};

#endif