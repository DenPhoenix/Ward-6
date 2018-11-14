#include "classes.h"

card::card(int t){
  type(t);
  switch t {
    case 1: {arg_type=1;break;}
    case 2: {arg_type=2;break;}
    case 3: {arg_type=3;break;}
    default:{std::cout<<"Error.This type don't exist.."<<std::endl;break;} }
