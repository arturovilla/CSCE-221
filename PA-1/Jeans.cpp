//
//  Jeans.cpp
//  programming assignment 1 collecting balls
//
//  Created by Arturo Villalobos on 2/15/20.
//  Copyright © 2020 Arturo Villalobos. All rights reserved.
//

#include <string>
#include <iostream>
#include "Jeans.h"
#include <ctime>

using namespace std;



Jeans::Jeans()//defult constructor
{
    color = Jean_colors(rand()%4);
    size = Jean_sizes(rand()%3);
}
//
Jeans::Jeans(Jean_colors c, Jean_sizes s)// parameteriozed constructor
{
    this->color= c;
    this->size = s;
}
//
bool Jeans::operator == (const Jeans& sb) const
{
    if((this->get_color() == sb.get_color()) && (this->get_size() == sb.get_size()))
    {
        return true;
    }
    return false;
}
//
std::ostream& operator << (ostream& o,const Jeans& sb)
{
    switch (sb.get_color())
      {
          case Jean_colors::torn: o<<"(torn,";
                  break;
          case Jean_colors::blueish: o<<"(blueish,";
                   break;
          case Jean_colors::acidwash: o<<"(acidwash,";
                  break;
          case Jean_colors::indigo: o<<"(indigo,";
              break;
      }
    switch (sb.get_size())
    {
        case Jean_sizes::skinny: o<<"skinny)";
                break;
        case Jean_sizes::Straightcut: o<<"straight cut)";
                 break;
        case Jean_sizes::wide: o<<"wide)";
                break;
    }
    return o;
}
