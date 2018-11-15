#ifndef CLASSES_H_INCLUDED
#define CLASSES_H_INCLUDED

#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <iostream>

//*********************************************************//
class card {
  int type;
  int arg_type;
  std::string name;
public:
  card(int t);
  void show();
  int get_arg_type();
};
//*********************************************************//
class card_deck{
    std::vector<card> deck;
public:
   card_deck(std::vector<int> init);
   void resort();
card operator [](int i);
};
//*********************************************************//

class player {
  string name;
  int coin;
  bool active;
  vector <card> hand;
  vector<player>* pls;
public:
  player(string NN,vector<player>* PS);
  void give_coin(int count,int& bank);
  void get_coin(int count,int& bank)
  void get_card(card_deck& deck);
  void give_card(card cd,card_deck& table);//table - discard
  void show_status();//{cout<<name<<coin<<active<<endl;}
  int play_dice();
  void play_card();//{card logic();void act(card cd,player target);void act(card cd) - on-self;void act(card cd)- on-players,modify pls}
};

#endif // CLASSES_H_INCLUDED

