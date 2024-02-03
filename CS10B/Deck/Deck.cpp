#include <algorithm>

using namespace std;

// THE FOLLOWING shuffleDeck() IMPLEMENTATION IS GIVEN TO YOU. 
// DO NOT CHANGE!!

/* Places all cards back into theDeck and shuffles them into random order.
   Uses random_shuffle function from algorithm library.
*/
void Deck::shuffleDeck() {
	for (unsigned i = 0; i < dealtCards.size(); ++i) {
		theDeck.push_back(dealtCards.at(i));
	}
	dealtCards.clear();
	random_shuffle(theDeck.begin(), theDeck.end());
}