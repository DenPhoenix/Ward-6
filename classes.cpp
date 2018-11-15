#include "classes.h"

//*********************************************************//
card::card(int t){
  type=t;
  switch (t) {
      //legend: arg_type=1 - act for target player; arg_type=2 - act on self; arg_type=3 - act on a group player by condition
    case 1: {arg_type=1;
             name="I am hangry...give your tablets!!!";break;}
    case 2: {arg_type=1;
             name="Blow to the skull";break;}
    case 3: {arg_type=2;
             name="Meditation or sleep?";break;}
    case 4: {arg_type=1;
             name="Talk in the s..Shower";break;}
    case 5: {arg_type=1;
             name="You owe me!!!";break;}
    case 6: {arg_type=2;
             name="See how I can!!!";break;}
    case 7: {arg_type=1;
             name="I like you";break;}
    default:{name="Error.This type don't exist..";break;} }
                                                            }
void card::show(){
  std::cout<<name<<std::endl;}

int card::get_arg_type(){return arg_type;}

//*********************************************************//

card_deck::card_deck(std::vector<int> init){
    for(unsigned i=0;i<init.size();i++){
            for(int j=0;j<init[i];j++){
                card tmp(i+1);
                deck.push_back(tmp);} } }

card card_deck::operator [](int i){return deck[i];}

void card_deck::resort(){
std::default_random_engine dre;
std::shuffle(deck.begin(),deck.end(),dre);
}

//*********************************************************//

player::player(string NN,vector<player>* PS){
name=NN;coin=0;active=true;pls=PS;}

