#ifndef __CARD_H__
#define __CARD_H__

#include <cctype>
#include "Card.h" 
#include <iostream>

Card::Card()
    : _suit('c'),
      _rank(2)
{
}

Card::Card(char c, int r)
{
    _suit = tolower(c);

    if (_suit != 'c' && _suit != 'd' && _suit != 'h' && _suit != 's')
    {
        _suit = 'c';
    }

    _rank = r;

    if (_rank < 1 || _rank > 13)
    {
        _rank = 2;
    }
}

char Card::suit() const
{
    return _suit;
}

int Card::rank() const
{
    return _rank;
}
	
ostream & operator<<(ostream & out, const Card & card)
{
    string rank;

    if (card.rank() == 1)
    {
        rank = "Ace";
    }
    else if (card.rank() == 2)
    {
        rank = "2";
    }
    else if (card.rank() == 3)
    {
        rank = "3";
    }
    else if (card.rank() == 4)
    {
        rank = "4";
    }
    else if (card.rank() == 5)
    {
        rank = "5";
    }
    else if (card.rank() == 6)
    {
        rank = "6";
    }
    else if (card.rank() == 7)
    {
        rank = "7";
    }
    else if (card.rank() == 8)
    {
        rank = "8";
    }
    else if (card.rank() == 9)
    {
        rank = "9";
    }
    else if (card.rank() == 10)
    {
        rank = "10";
    }
    else if (card.rank() == 11)
    {
        rank = "Jack";
    }
    else if (card.rank() == 12)
    {
        rank = "Queen";
    }
    else if (card.rank() == 13)
    {
        rank = "King";
    }

    string suit;

    if (card.suit() == 'c')
    {
        suit = "Clubs";
    }
    else if (card.suit() == 'd')
    {
        suit = "Diamonds";
    }
    else if (card.suit() == 'h')
    {
        suit = "Hearts";
    }
    else if (card.suit() == 's')
    {
        suit = "Spades";
    }

    out << rank << " of " << suit;

    return out;
}

