#include <iostream>
#include <string>
#include <fstream>
#include "card.h"
#include "deck.h"
using namespace std;

//hi
int main(){

	cout<<"Hello, World"<<endl;

	deck opponentDeck = deck();
	deck yourDeck = deck();
	yourDeck.shuffle();
	yourDeck.shuffle();
	list<card>::iterator i;
	//cout << "Unshuffled deck:\n\n";
	//opponentDeck.printDeck();
	opponentDeck.shuffle();
	//cout << "Shuffled deck:\n\n";
	//opponentDeck.printDeck();
	bool over = false;
	cout<< "Availble moves include: draw and quit"<<endl;
	string move;
	card them, us, them1, them2, them3, them4, us1, us2, us3, us4;

	while(over == false){
		cin>> move;
		if(move == "quit"){
			over == true;
		}else if(opponentDeck.size() == 0){
			cout<< "You have won the war!"<<endl;
			over = true;
		}else if(yourDeck.size() == 0){
			cout<< "You have succumb to defeat!"<<endl;
			over = true;
		}else if(move == "draw"){
			them = opponentDeck.drawCard();
			us = yourDeck.drawCard();
			cout<< "You show a ";
			us.print();
			cout<< endl;
			cout<< "they show a ";
			them.print();
			cout<< endl;
			if( them.get_value() > us.get_value()){
				opponentDeck.pushCard(us);
				opponentDeck.pushCard(them);
			}else if( us.get_value() > them.get_value()){
				yourDeck.pushCard(them);
				yourDeck.pushCard(us);
			}else{
				if(opponentDeck.size() < 4){
					cout<<"Your army has overtaken their forces! You win!"<<endl;
					over = true;
				}else if(yourDeck.size() < 4){
					cout<<"Your army has been overtaken! You've lost the War!"<<endl;
					over = true;
				}else{
					them1 = opponentDeck.drawCard();
					them2 = opponentDeck.drawCard();
					them3 = opponentDeck.drawCard();
					them4 = opponentDeck.drawCard();
					us1 = yourDeck.drawCard();
					us2 = yourDeck.drawCard();
					us3 = yourDeck.drawCard();
					us4 = yourDeck.drawCard();
					cout<< "You show a ";
					us4.print();
					cout<< endl;
					cout<< "they show a ";
					them4.print();
					if(us4.get_value() > them4.get_value()){
						cout<< endl<< "You've gained: "<<endl;
						them1.print();
						them2.print();
						them3.print();
						yourDeck.pushCard(them1);
						yourDeck.pushCard(them2);
						yourDeck.pushCard(them3);
						yourDeck.pushCard(them4);
						yourDeck.pushCard(them);
						yourDeck.pushCard(us1);
						yourDeck.pushCard(us2);
						yourDeck.pushCard(us3);
						yourDeck.pushCard(us4);
						yourDeck.pushCard(us);
					}else{
						if(them4.get_value() > us4.get_value()){
							opponentDeck.pushCard(them1);
							opponentDeck.pushCard(them2);
							opponentDeck.pushCard(them3);
							opponentDeck.pushCard(them4);
							opponentDeck.pushCard(them);
							opponentDeck.pushCard(us1);
							opponentDeck.pushCard(us2);
							opponentDeck.pushCard(us3);
							opponentDeck.pushCard(us4);
							opponentDeck.pushCard(us);
						}else{
							cout<< "mass casualties on both sides... no one survived"<<endl;
						}
						cout<< endl<< "You've lost: "<<endl;
						us.print();
						us1.print();
						us2.print();
						us3.print();
						us4.print();
					}
				}
			}

		}else{
			cout<<"that didn't look like draw or quit to me..."<<endl;
		}
	}
	int stop =0;
	cin>> stop;


return 0;
}