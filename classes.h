#ifndef CLASSES_H_INCLUDED
#define CLASSES_H_INCLUDED

#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <iostream>
#include <cmath>

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
class deck_manip{
public:
   static void initialize(std::vector<card> deck,std::vector<int> init);
   static void resort(std::vector<card> deck);
};

//*********************************************************//
class player {
  std::string name;
  int coin;
  bool active;
  std::vector <card> hand;
  std::vector<player>* pls;
public:
  player(std::string NN,std::vector<player>* PS);
  void give_coin(int count,int& bank);
  void get_coin(int count,int& bank);
  void get_card(std::vector<card>& deck,std::vector<card>& table);
  void give_card(card cd,std::vector<card>& table);//table - discard
  void show_status();//{cout<<name<<coin<<active<<endl;}
  int play_dice();
  void play_card();//{card logic();void act(card cd,player target);void act(card cd) - on-self;void act(card cd)- on-players,modify pls}
};

#endif // CLASSES_H_INCLUDED
