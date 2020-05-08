//
//  Collection.cpp
//  programming assignment 1 collecting balls
//
//  Created by Arturo Villalobos on 1/16/20.
//  Copyright © 2020 Arturo Villalobos. All rights reserved.
//

#include <stdio.h>
#include "Collection.h"
#include "Stress_ball.h"
#include <iostream>
using namespace std;


// Collection::Collection() // defualt constructor
//{
//    size=0;
//    capacity=0;
//    array=nullptr;
//}
//
//Collection::Collection(int siz) //parameterized constructor
//{
//    size=0;
//    capacity = siz;
//    array = new Stress_ball [capacity];
//
//}
//
//Collection:: Collection(const Collection& oldcollection)//copy cunstructor
//{
//    size = oldcollection.size;
//    capacity = oldcollection.capacity;
//    array = new Stress_ball[capacity];
//
//    for(int i =0; i<capacity;i++)
//    {
//        array[i] = oldcollection.array[i];
//    }
//}
//
//Collection::~Collection()// destrucrtor
//{
//    size = 0;
//    capacity=0;
//    array=nullptr;
//}
//
//Collection::Collection(Collection&& oldcollection) // move constructor
//{
//    this->capacity = oldcollection.capacity;
//    this->size = oldcollection.size;
//    this->array=oldcollection.array;
//    oldcollection.array=nullptr;
//    oldcollection.size=0;
//    oldcollection.capacity=0;
//}
//
//Collection & Collection::operator= ( Collection&& oldcollection) // move assignment
//{
//    if(this == &oldcollection)
//    {
//        return *this;
//    }
//    
//    this->capacity = oldcollection.capacity;
//    this->size = oldcollection.size;
//    this->array=oldcollection.array;
//    oldcollection.array=nullptr;
//    oldcollection.size=0;
//    oldcollection.capacity=0;
//    return *this;
//}
//
//Collection& Collection::operator= ( const Collection & oldcollection) // copy assignment
//{
//    if(this == &oldcollection)
//    {
//        return *this;
//    }
//    
//    this->capacity = oldcollection.capacity;
//    this->size = oldcollection.size;
//    
//    Stress_ball* newary = new Stress_ball[this->capacity];
//    for(int i =0; i<this->size;i++)
//    {
//        newary[i] = oldcollection.array[i];
//    }
//    this->array = newary;
//    newary = nullptr;
//    return *this;
//}
//
//void Collection::resize()
//{
//    Stress_ball* newary = new Stress_ball[this->capacity*2];
//    
//    for(int i = 0; i<this->capacity;i++)
//    {
//        newary[i] = this->array[i];
//    }
//    delete [] this->array;
//    this->array = newary;
//    newary=nullptr;
//}
//
//void Collection::insert_item(const Stress_ball& sb)
//{
//    if(this->array==nullptr || this->size+1 == this->capacity)
//    {
//        this->resize();
//    }
//    this->array[size] = sb;
//    this->size++;
//}
//
//bool Collection::contains(const Stress_ball& sb) const
//{
//    for(int i  = 0; i<this->capacity; i++)
//    {
//        if((this->array[i].get_color() == sb.get_color()) && (this->array[i].get_size() == sb.get_size()))
//        {
//            return true;
//        }
//    }
//    return false;
//}
//
//Stress_ball Collection::remove_any_item()
//{
//    if(this->size==0)
//    {
//        throw 0;
//    }
//    else
//    {
//         int balltoremove = int(rand()%this->size);
//        Stress_ball btr = this->array[balltoremove];
//        this->size--;
//        
//        
//        if(this->size==0)
//        {
//            return btr;
//        }
//        
//        for(int i = balltoremove; i<this->size; i++)
//        {
//            this->array[i] = this->array[i+1];
//        }
//        return btr;
//    }
//}
//
//void Collection::remove_this_item(const Stress_ball& sb)
//{
//    int oldsize = this->size;
//  
//    if(this->size==0)//my exception
//       {
//           throw 0;//do catch
//       }
//    
//    for(int i =0; i<oldsize;i++)
//       {
//           if((this->array[i].get_color() == sb.get_color())&&(this->array[i].get_size()==sb.get_size()))
//           {
//               for(int x = i; x<oldsize; x++)
//               {
//                   this->array[x] = this->array[x+1];
//                   this->size--;
//               }
//           }
//       }
//}
//
//void Collection::make_empty()
//{
//    this->size = 0;
//    Stress_ball* newary = new Stress_ball[this->capacity];
//    delete [] this->array;
//    this->array = newary;
//}
//
//  bool Collection::is_empty() const
//{
//    if(this->size==0)
//    {
//        return true;
//    }
//    else
//    {
//        return false;
//    }
//}
//
//  int Collection::total_items() const
//{
//    return this->size;
//}
//
//  int Collection::total_items(Stress_ball_sizes s) const
//{
//    int cnt = 0;
//
//    for(int i = 0; i<this->size;i++)
//    {
//        if(this->array[i].get_size()==s)
//        {
//            cnt++;
//        }
//    }
//    return cnt;
//}
//
//  int Collection::total_items(Stress_ball_colors t) const
//{
//    int cnt = 0;
//    for(int i =0; i <this->size; i++)
//    {
//        if(this->array[i].get_color()==t)
//        {
//            cnt++;
//        }
//    }
//    return cnt;
//}
//
//  void Collection::print_items() const
//{
//    for(int i = 0; i<this->size;i++)
//    {
//         std::cout << this->array[i] <<endl;
//    }
//    
//}
//
//Stress_ball& Collection::operator[](int i)
//{
//    if(i >=this->size)
//    {
//        throw 1;
//    }
//    return this->array[i];
//}
//
//const Stress_ball& Collection::operator[](int i) const
//{
//    if(i >=this->size)
//    {
//        throw 1;
//    }
//    return this->array[i];
//}
//
//std::istream& operator>>(std::istream& is, Collection& c)
//{
//    Stress_ball_sizes si;
//    Stress_ball_colors co;
//    int ccolor;
//    int ssize;
//    string color;
//    string size;
//    while(!is.eof())
//    {
//        is>>color;
//        is>>size;
//        if(is.fail())
//        {
//            break;
//        }
//        if(color == "red"){
//            ccolor = 0;}
//        else if(color == "blue"){
//            ccolor = 1;}
//        else if(color == "yellow"){
//            ccolor = 2;}
//        else if(color == "green"){
//            ccolor = 3;}
//     
//        
//        if(size == "small"){
//            ssize = 0;}
//        else if(size == "medium"){
//            ssize = 1;}
//        else if(size == "large"){
//            ssize = 2;}
//        
//        switch(ssize)
//        {
//            case 0: si = Stress_ball_sizes::small;
//                break;
//            case 1: si = Stress_ball_sizes::medium;
//                break;
//            case 2: si = Stress_ball_sizes::large;
//                break;
//        }
//        
//        switch(ccolor)
//        {
//            case 0: co = Stress_ball_colors::red;
//                break;
//            case 1: co = Stress_ball_colors::blue;
//                break;
//            case 2: co = Stress_ball_colors::yellow;
//                break;
//            case 3: co = Stress_ball_colors::green;
//                break;
//        }
//        
//        Stress_ball x(co,si);
//        c.insert_item(x);
//    }
//    return is;
//
//}
//
//std::ostream& operator <<(std::ostream& os, const Collection& c)
//{
//    for(int i = 0; i<c.total_items();i++)
//    {
//         os << c[i] <<endl;
//    }
//
//
//    return os;
//
//}
//
//Collection make_union(const Collection& c1, const Collection& c2)
//{
//    Collection newcollec;
//    for(int i =0; i<c1.total_items();i++)
//    {
//        newcollec.insert_item(c1[i]);
//    }
//    for(int x = 0;x<c2.total_items();x++)
//    {
//        newcollec.insert_item(c2[x]);
//    }
//    return newcollec;
//}
//
//void swap(Collection& c1, Collection& c2)
//{
//    Collection temp1;
//    temp1 = std::move(c1);
//    c1 = std::move(c2);
//    c2 = std::move(temp1);
//}
//
//void sort_by_size(Collection& cts, Sort_choice sort)
//{
//    switch (sort)
//    {
//        case Sort_choice::bubble_sort: cts.bubblesort();
//                break;
//        case Sort_choice::selection_sort: cts.selectionsort();
//                 break;
//        case Sort_choice::insertion_sort: cts.insertionsort();
//                break;
//    }
//}
//
//void Collection::bubblesort()
//{
//
//    for(int passes = 0;passes<this->size-1;passes++)
//    {
//        for(int traversal = 0; traversal<this->size-passes-1;traversal++)
//        {
//            if(this->array[traversal].get_size()>this->array[traversal+1].get_size())
//            {
//                Stress_ball temp=this->array[traversal];
//                this->array[traversal]=this->array[traversal+1];
//                this->array[traversal+1] = temp;
//            }
//        }
//    }
//}
//
//void Collection::insertionsort()
//{
//    int j;
//    for(int i =1; i<this->size;i++)
//    {
//        j=i;
//        while(j>0 && this->array[j-1].get_size()>this->array[j].get_size())
//        {
//            Stress_ball temp = this->array[j-1];
//            this->array[j-1] = this->array[j];
//            this->array[j] = temp;
//            j=j-1;
//        }
//    }
//}
//
//void Collection::selectionsort()
//{
//    int partition=0;
//    int cplace=0;
//    int cminimum=0;
//    for(int i =partition; i<this->size;i++)
//    {
//        cminimum=i;
//        cplace=i;
//        while(cplace<this->size)
//        {
//            if(this->array[cminimum].get_size()>=this->array[cplace].get_size())
//            {
//                cminimum=cplace;
//            }
//            cplace++;
//        }
//        Stress_ball temp = this->array[i];
//        this->array[i] = this->array[cminimum];
//        this->array[cminimum] = temp;
//    }
//}

