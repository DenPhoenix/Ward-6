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

#endif // CLASSES_H_INCLUDED
//*********************************************************//
