#include <iostream>
#include <string>
#include <fstream>
#include "card.h"
using namespace std;

		card::card(){
			suite = "NULL";
			call = "NULL";
			low_value =0;
			value =0;
			next = NULL;
		};
		card::card(string suit, string calle, int low , int reg){
			suite = suit;
			call = calle;
			low_value = low;
			value = reg;
			next = NULL;
		};
		//manipulators
		void card::set_suite(string type){
			suite = type;
		};
		void card::set_value(int reg){
			value = reg;
		};
		void card::set_call(string called){
			call = called;
		};
		void card::set_low_value(int low){
			low_value = low;
		};
		void card::set_next(card * nxt_card){
			next = nxt_card;
		};
		//getters
		string card::get_suite(){
			return suite;
		};
		int card::get_value(){
			return value;
		};
		string card::get_call(){
			return call;
		};
		int card::get_low_value(){
			return low_value;
		};
		card * card::get_next(){
			return next;
		};
		//others
		void card::print(){
			cout<< call <<" of "<< suite << endl;
		};