#ifndef DECK_H
#define DECK_H
#include "card.h"
#include <list>
using namespace std;


class deck
{
	list<card> cardDeck;
	list<card>::iterator it;
public:
	deck();
	void pushCard( card curr);
	card drawCard();
	void shuffle();
	void printDeck();
	int size();
};





#endif