//
//  collection_test.cpp
//  programming assignment 1 collecting balls
//
//  Created by Arturo Villalobos on 1/15/20.
//  Copyright © 2020 Arturo Villalobos. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include "Stress_ball.h"
#include "Collection.h"
#include "Jeans.h"
using namespace std;


int main()
{
  srand(time(NULL));
    using CollectionSB = Collection<Stress_ball, Stress_ball_colors, Stress_ball_sizes>;
    using CollectionJN = Collection<Jeans, Jean_colors, Jean_sizes>;
    
    
    CollectionSB colec1;
    CollectionJN colec2;
    CollectionSB colec3;
    CollectionJN colec4;
    //
    Sort_choice selection = Sort_choice::selection_sort;
    Sort_choice bubble = Sort_choice::bubble_sort;
    Sort_choice insertion = Sort_choice::insertion_sort;
    //
    Stress_ball_colors r = Stress_ball_colors::red;
    Stress_ball_colors b = Stress_ball_colors::blue;
    Stress_ball_colors y = Stress_ball_colors::yellow;
    Stress_ball_colors g = Stress_ball_colors::green;
    //
    Jean_colors one = Jean_colors::indigo;
    Jean_colors two = Jean_colors::blueish;
    Jean_colors three = Jean_colors::acidwash;
    Jean_colors four = Jean_colors::torn;
    
    
    int choice1;
    int choice2;
    int choice3;
    int choice4;
    ifstream inFile;
    inFile.open("stress_balll.txt");

    
    Stress_ball *ballz = new Stress_ball[10];
    Jeans *Jean = new Jeans[10];
    Stress_ball *ballz2 = new Stress_ball[10];
    Jeans *Jean2 = new Jeans[10];
     for(int i = 0; i<10; i++)
        {
            colec1.insert_item(ballz[i]);
            colec2.insert_item(Jean[i]);
            colec3.insert_item(ballz2[i]);
            colec4.insert_item(Jean2[i]);
        }
    //
    cout<<"Collection 1 will have the balls from stress_balll.txt"<<endl;
    cout<<"reading in the stress balls...."<<endl;
    //inFile>>colec2;
    inFile>>colec1;
   //
    cout<<"here is collection 1 unsorted "<<endl;
    colec1.print_items();
    cout<<"here is collection 2 unsorted "<<endl;
    colec2.print_items();
    cout<<"here is collection 3 unsorted "<<endl;
    colec3.print_items();
    cout<<"here is collection 4 unsorted "<<endl;
    colec4.print_items();
    //
    cout<<"what kind of sort do you wanna use for colecction 1 ? (type 1 for selection, 2 for bubble, 3 for insertion)"<<endl;
    cin>>choice1;
    switch(choice1)
       {
           case 1: sort_by_size(colec1, selection);
               break;
           case 2: sort_by_size(colec1, bubble);
               break;
           case 3: sort_by_size(colec1, insertion);
               break;
       }
    
    cout<<"what kind of sort do you wanna use for colecction 2 ? (type 1 for selection, 2 for bubble, 3 for insertion)"<<endl;
    cin>>choice2;
    switch(choice2)
    {
        case 1: sort_by_size(colec2, selection);
            break;
        case 2: sort_by_size(colec2, bubble);
            break;
        case 3: sort_by_size(colec2, insertion);
            break;
    }
    cout<<"what kind of sort do you wanna use for colecction 3 ? (type 1 for selection, 2 for bubble, 3 for insertion)"<<endl;
    cin>>choice3;
    switch(choice3)
       {
           case 1: sort_by_size(colec3, selection);
               break;
           case 2: sort_by_size(colec3, bubble);
               break;
           case 3: sort_by_size(colec3, insertion);
               break;
       }
    
    cout<<"what kind of sort do you wanna use for colecction 4 ? (type 1 for selection, 2 for bubble, 3 for insertion)"<<endl;
    cin>>choice4;
    switch(choice4)
    {
        case 1: sort_by_size(colec4, selection);
            break;
        case 2: sort_by_size(colec4, bubble);
            break;
        case 3: sort_by_size(colec4, insertion);
            break;
    }
    //
    cout<<"here is is the 1st collection of balls sorted and total items , as well as there the number of balls according to color"<<endl;
    colec1.print_items();
    cout<<"Total items : "<<colec1.total_items()<<endl;
    cout<<"Total red items : "<<colec1.total_items(r)<<endl;
    cout<<"Total blue items : "<<colec1.total_items(b)<<endl;
    cout<<"Total yellow items : "<<colec1.total_items(y)<<endl;
    cout<<"Total green items : "<<colec1.total_items(g)<<endl;
    
    cout<<"here is the 1st collection of Jeans sorted and total items , as well as there the number of Jeans according to color"<<endl;
    colec2.print_items();
    cout<<"Total items : "<<colec2.total_items()<<endl;
    cout<<"Total red items : "<<colec2.total_items(one)<<endl;
    cout<<"Total blue items : "<<colec2.total_items(two)<<endl;
    cout<<"Total yellow items : "<<colec2.total_items(three)<<endl;
    cout<<"Total green items : "<<colec2.total_items(four)<<endl;
    
    cout<<"here is the second collection of balls sorted and total items , as well as there the number of balls according to color"<<endl;
    colec3.print_items();
    cout<<"Total items : "<<colec3.total_items()<<endl;
    cout<<"Total red items : "<<colec3.total_items(r)<<endl;
    cout<<"Total blue items : "<<colec3.total_items(b)<<endl;
    cout<<"Total yellow items : "<<colec3.total_items(y)<<endl;
    cout<<"Total green items : "<<colec3.total_items(g)<<endl;
    
    cout<<"here is the 2nd collection of Jeans sorted and total items , as well as there the number of Jeans according to color"<<endl;
    colec4.print_items();
    cout<<"Total items : "<<colec4.total_items()<<endl;
    cout<<"Total red items : "<<colec4.total_items(one)<<endl;
    cout<<"Total blue items : "<<colec4.total_items(two)<<endl;
    cout<<"Total yellow items : "<<colec4.total_items(three)<<endl;
    cout<<"Total green items : "<<colec4.total_items(four)<<endl;
    //
    
    Collection <Stress_ball,Stress_ball_colors,Stress_ball_sizes>combo = make_union(colec1, colec3);
    Collection <Jeans,Jean_colors,Jean_sizes>combo2 = make_union(colec2, colec4);
    
    cout<<"here is the unioned collection of balls sorted and total items , as well as there the number of balls according to color"<<endl;
    combo.bubblesort();
    combo.print_items();
    //
    cout<<"Total items : "<<combo.total_items()<<endl;
    cout<<"Total red items : "<<combo.total_items(r)<<endl;
    cout<<"Total blue items : "<<combo.total_items(b)<<endl;
    cout<<"Total yellow items : "<<combo.total_items(y)<<endl;
    cout<<"Total green items : "<<combo.total_items(g)<<endl;
    swap(colec1,colec3);
    
    cout<<"here is collection 1 of balls after using the swap function"<<endl;
    colec1.print_items();
    cout<<"Total items : "<<colec1.total_items()<<endl;
    cout<<"Total red items : "<<colec1.total_items(r)<<endl;
    cout<<"Total blue items : "<<colec1.total_items(b)<<endl;
    cout<<"Total yellow items : "<<colec1.total_items(y)<<endl;
    cout<<"Total green items : "<<colec1.total_items(g)<<endl;
    
    cout<<"here is collection 2 of balls after using the swap function"<<endl;
    cout<<colec3;
    cout<<"Total items : "<<colec3.total_items()<<endl;
    cout<<"Total red items : "<<colec3.total_items(r)<<endl;
    cout<<"Total blue items : "<<colec3.total_items(b)<<endl;
    cout<<"Total yellow items : "<<colec3.total_items(y)<<endl;
    cout<<"Total green items : "<<colec3.total_items(g)<<endl;
    //
    //
    //
    //
    cout<<"here is the unioned collection of Jeans sorted and total items , as well as there the number of Jeans according to color"<<endl;
    combo2.bubblesort();
    combo2.print_items();
    //
    cout<<"Total items : "<<combo2.total_items()<<endl;
    cout<<"Total indigo items : "<<combo2.total_items(one)<<endl;
    cout<<"Total blue items : "<<combo2.total_items(two)<<endl;
    cout<<"Total acidwash items : "<<combo2.total_items(three)<<endl;
    cout<<"Total torn items : "<<combo2.total_items(four)<<endl;
    swap(colec2,colec4);
    
    cout<<"here is collection 1 of jeans after using the swap function"<<endl;
    colec2.print_items();
    cout<<"Total items : "<<colec2.total_items()<<endl;
    cout<<"Total indigo items : "<<colec2.total_items(one)<<endl;
    cout<<"Total blue items : "<<colec2.total_items(two)<<endl;
    cout<<"Total acidwash items : "<<colec2.total_items(three)<<endl;
    cout<<"Total torn items : "<<colec2.total_items(four)<<endl;
    
    cout<<"here is collection 2 of jeans after using the swap function"<<endl;
    cout<<colec4;
    cout<<"Total items : "<<colec4.total_items()<<endl;
    cout<<"Total indigo items : "<<colec4.total_items(one)<<endl;
    cout<<"Total blue items : "<<colec4.total_items(two)<<endl;
    cout<<"Total acidwash items : "<<colec4.total_items(three)<<endl;
    cout<<"Total torn items : "<<colec4.total_items(four)<<endl;
    
    
    
    
    
    
    
    
    


    
     
    
}
