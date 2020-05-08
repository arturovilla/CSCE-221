//
//  Stress_ball.cpp
//  programming assignment 1 collecting balls
//
//  Created by Arturo Villalobos on 1/14/20.
//  Copyright © 2020 Arturo Villalobos. All rights reserved.
//

#include <string>
#include <iostream>
#include "Stress_ball.h"
#include <ctime>

using namespace std;



Stress_ball::Stress_ball()//defult constructor
{
    color = Stress_ball_colors(rand()%4);
    size = Stress_ball_sizes(rand()%3);
}
//
Stress_ball::Stress_ball(Stress_ball_colors c, Stress_ball_sizes s)// parameteriozed constructor 
{
    this->color= c;
    this->size = s;
}
//
bool Stress_ball::operator == (const Stress_ball& sb) const
{
    if((this->get_color() == sb.get_color()) && (this->get_size() == sb.get_size()))
    {
        return true;
    }
    return false;
}
//
std::ostream& operator << (ostream& o,const Stress_ball& sb)
{
    switch (sb.get_color())
      {
          case Stress_ball_colors::red: o<<"(red,";
                  break;
          case Stress_ball_colors::blue: o<<"(blue,";
                   break;
          case Stress_ball_colors::yellow: o<<"(yellow,";
                  break;
          case Stress_ball_colors::green: o<<"(green,";
              break;
      }
    switch (sb.get_size())
    {
        case Stress_ball_sizes::small: o<<"small)";
                break;
        case Stress_ball_sizes::medium: o<<"medium)";
                 break;
        case Stress_ball_sizes::large: o<<"large)";
                break;
    }
    return o;
}


//functions



