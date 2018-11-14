#ifndef WARD_6_CLASSES_H_INCLUDED
#define WARD_6_CLASSES_H_INCLUDED
#include <string>

class card {
  int type;
  int arg_type;
  std::string name;
  public:
  card(int t);
  void show();
  int get_arg_type();
};

#endif // WARD_6_CLASSES_H_INCLUDED
