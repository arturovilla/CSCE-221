//
//  Jeans.h
//  programming assignment 1 collecting balls
//
//  Created by Arturo Villalobos on 2/15/20.
//  Copyright © 2020 Arturo Villalobos. All rights reserved.
//

#ifndef Jeans_h
#define Jeans_h

#include <ostream>
#include <fstream>


enum class Jean_colors{torn, blueish, indigo, acidwash};
//
enum class Jean_sizes{skinny, Straightcut, wide};
//
class Jeans
{
    Jean_colors color;
    //
    Jean_sizes size;
public:
   Jeans();
    Jeans(Jean_colors c, Jean_sizes s);
    //
    Jean_colors get_color() const {return color;}
    //
    Jean_sizes get_size() const  {return size;}
    //
     bool operator == (Jeans const& JN) const;
};
//
std::ostream& operator<<(std::ostream& o, const Jeans& sb);


#endif /* Jeans_h */
