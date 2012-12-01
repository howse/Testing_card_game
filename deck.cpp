#include "deck.h"
#include <string>
#include <time.h>
using namespace std;

deck::deck()
{
	it = cardDeck.begin();
	//Add Hearts
	string cardNames[11] = {"","","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten"};
	card card1 = card("Hearts","Jack",0,10);
	cardDeck.insert(it,card1);
	card card2 = card("Hearts","Queen",0,10);
	cardDeck.insert(it,card2);
	card card3 = card("Hearts","King",0,10);
	cardDeck.insert(it,card3);
	card card4 = card("Hearts","Ace",1,11);
	cardDeck.insert(it,card4);
	for(int i(2); i<=10; i++)
	{
		card card5 = card("Hearts",cardNames[i],0,i);
		cardDeck.insert(it,card5);
	}

	//Add Diamonds
	card1 = card("Diamonds","Jack",0,10);
	cardDeck.insert(it,card1);
	card2 = card("Diamonds","Queen",0,10);
	cardDeck.insert(it,card2);
	card3 = card("Diamonds","King",0,10);
	cardDeck.insert(it,card3);
	card4 = card("Diamonds","Ace",1,11);
	cardDeck.insert(it,card4);
	for(int i(2); i<=10; i++)
	{
		card card5 = card("Diamonds",cardNames[i],0,i);
		cardDeck.insert(it,card5);
	}

	//Add Clubs
	card1 = card("Clubs","Jack",0,10);
	cardDeck.insert(it,card1);
	card2 = card("Clubs","Queen",0,10);
	cardDeck.insert(it,card2);
	card3 = card("Clubs","King",0,10);
	cardDeck.insert(it,card3);
	card4 = card("Clubs","Ace",1,11);
	cardDeck.insert(it,card4);
	for(int i(2); i<=10; i++)
	{
		card card5 = card("Clubs",cardNames[i],0,i);
		cardDeck.insert(it,card5);
	}

	//Add Spades
	card1 = card("Spades","Jack",0,10);
	cardDeck.insert(it,card1);
	card2 = card("Spades","Queen",0,10);
	cardDeck.insert(it,card2);
	card3 = card("Spades","King",0,10);
	cardDeck.insert(it,card3);
	card4 = card("Spades","Ace",1,11);
	cardDeck.insert(it,card4);
	for(int i(2); i<=10; i++)
	{
		card card5 = card("Spades",cardNames[i],0,i);
		cardDeck.insert(it,card5);
	}
}

card deck::drawCard()
{
	if(cardDeck.empty())
	{
		cout << "Deck is empty. Cannot draw a card\n";
	}
	else
	{
		cardDeck.pop_front();
		return cardDeck.front();
	}
}

void deck::shuffle()
{
	srand (time(NULL));
	list<card> newDeck;
	list<card>::iterator newIt;
	int deckSize = cardDeck.size();

	while(deckSize != 0)
	{
		newIt = newDeck.begin();
		it = cardDeck.begin();
		int randNum = rand() % deckSize-1;
		for(int i(0); i<randNum; i++)
		{
			it++;
		}
		newDeck.splice(newIt,cardDeck,it);
		deckSize = cardDeck.size();
	}

	cardDeck.swap(newDeck);
}

void deck::printDeck()
{
	for(it = cardDeck.begin(); it != cardDeck.end(); it++)
	{
		it->print();
	}
}


//below is for debugging only. Feel free to erase.
int main()
{
	deck thisDeck = deck();
	list<card>::iterator i;
	cout << "Unshuffled deck:\n\n";
	thisDeck.printDeck();
	thisDeck.shuffle();
	cout << "Shuffled deck:\n\n";
	thisDeck.printDeck();
}