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

bool card::operator ==(card cd){return (type==cd.type);}

//*********************************************************//

void deck_manip::initialize(std::vector<card>& deck,std::vector<int>& init){
    for(unsigned i=0;i<init.size();i++){
            for(int j=0;j<init[i];j++){
                card tmp(i+1);
                deck.push_back(tmp);} } }

void deck_manip::resort(std::vector<card>& deck){
unsigned int seed=time(0);
static std::default_random_engine dre(seed);
std::shuffle(deck.begin(),deck.end(),dre);
}

//*********************************************************//

player::player(std::string NN,std::vector<player>* PS){
name=NN;coin=0;active=true;pls=PS;}

void player::show_status(){std::cout<<"Name="<<name<<"  Coin="<<coin<<"  Active:"<<active<<std::endl;}

void player::give_coin(int count,int& bank){
if(coin>=count){coin=coin-count;bank=bank+count;}
if(coin<count && coin>0){bank=bank+count-coin;coin=0;} }

void player::get_coin(int count,int& bank){
if (bank<count){std::cout<<"Bank is empty!!!"<<std::endl;}
else{coin=coin+count;bank=bank-count;} }

void player::get_card(std::vector<card>& deck,std::vector<card>& table){
if (deck.empty()){deck=table;deck_manip::resort(deck);table.clear();}
hand.push_back(deck.back());
deck.pop_back(); }

void player::give_card(card cd,std::vector<card>& table){
    if(!hand.empty()){
            std::vector<card>::iterator pos=std::find(hand.begin(),hand.end(),cd);
            if (pos!=hand.end()){table.push_back(cd);hand.erase(std::find(hand.begin(),hand.end(),cd));}
            else {std::cout<<"In hand no such card!!!"<<std::endl;} }
    else{std::cout<<"hand is empty!!!"<<std::endl;} }

void player::show_hand(){
for(auto elem:hand){
            elem.show();}
}

int player::play_dice(){
unsigned int seed=time(0);
static std::default_random_engine dre(seed);
static std::uniform_int_distribution<int> Nd(1,6);
return  Nd(dre)+Nd(dre);}

