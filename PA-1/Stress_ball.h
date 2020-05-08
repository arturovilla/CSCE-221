//
//  Stress_ball.h
//  programming assignment 1 collecting balls
//
//  Created by Arturo Villalobos on 1/14/20.
//  Copyright © 2020 Arturo Villalobos. All rights reserved.
//

#ifndef Stress_ball_h
#define Stress_ball_h
#include <ostream>
#include <fstream>


enum class Stress_ball_colors{red, blue, yellow, green};
//
enum class Stress_ball_sizes{small, medium, large};
//
class Stress_ball
{
    Stress_ball_colors color;
    //
    Stress_ball_sizes size;
public:
   Stress_ball();
    Stress_ball(Stress_ball_colors c, Stress_ball_sizes s);
    //
    Stress_ball_colors get_color() const {return color;}
    //
    Stress_ball_sizes get_size() const  {return size;}
    //
     bool operator == (Stress_ball const& sb) const;
};
//
std::ostream& operator<<(std::ostream& o, const Stress_ball& sb);


#endif
/* Stress_ball_h */


