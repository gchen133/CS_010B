#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

#include "Deck.h"
#include "Card.h"

// Returns true if vector of Cards contains at least 2 Cards with the same rank.
bool hasPair(const vector<Card> &hand);

// Sends to output stream a Card's value as: Rank of Suit
// i.e., Ace of Spades
ostream & operator<<(ostream &, const vector<Card> &);

int main() {
	srand(2222);

	return 0;
}