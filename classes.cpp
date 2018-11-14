#include "classes.h"

card::card(int t){
  type(t);
  switch t {
    case 1: {arg_type=1;
             name="I am hangry...";break;}
    case 2: {arg_type=2;
             name=" ";break;}
    case 3: {arg_type=3;
             name="";break;}
    default:{name="Error.This type don't exist..";break;} }
                                                            }
void card::show(){
  std::cout<<name<<std::endl;}

int card::get_arg_type(){return arg_type;}
