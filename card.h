#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <string>
using namespace std;

class card{
	public:
		card();
		card(string suit, string calle, int low , int reg);
		//manipulators
		void set_suite(string type);
		void set_value(int reg);
		void set_call(string called);
		void set_low_value(int low);
		void set_next(card * nxt_card);
		//getters
		string get_suite();
		int get_value();
		string get_call();
		int get_low_value();
		card * get_next();
		//others
		void print();


	private:
		string suite;
		int value;
		string call;
		int low_value;
		card * next;
};

#endif