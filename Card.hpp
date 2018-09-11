#ifndef CARD_HPP
#define CARD_HPP

#include <string>
#include <iostream>

class Card
{
public:
	enum Ranks
	{
		RANK_2,
		RANK_3,
		RANK_4,
		RANK_5,
		RANK_6,
		RANK_7,
		RANK_8,
		RANK_9,
		RANK_10,
		RANK_JACK,
		RANK_QUEEN,
		RANK_KING,
		RANK_ACE,
		MAX_RANK
	};

	enum Suits
	{
		CLUBS,
		DIAMONDS,
		HEARTS,
		SPADES,
		MAX_SUIT
	};

private:
	Ranks m_rank;
	Suits m_suit;

public:
	Card(Ranks rank = Ranks::RANK_2, Suits suit = Suits::CLUBS) : m_rank{rank}, m_suit{suit} {};
	void printCard() const;
	int getCardValue() const;
};

#endif