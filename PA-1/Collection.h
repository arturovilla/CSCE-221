//
//  Collection.h
//  programming assignment 1 collecting balls
//
//  Created by Arturo Villalobos on 1/16/20.
//  Copyright © 2020 Arturo Villalobos. All rights reserved.



#ifndef Collection_h
#define Collection_h
#include <stdio.h>
#include <iostream>
using namespace std;


template <typename Obj,typename F1,typename F2 >
class Collection// of stress balls
{
    Obj *array;
    int size;
    int capacity;
public:
    
    Collection()
    {
        size=0;
        capacity=0;
        array=nullptr;
    }
    //
    Collection(int size)
    {
        size=0;
        capacity = size;
        array = new Obj [capacity];
    }
    //
    Collection(const Collection& oldcollection)
    {
        size = oldcollection.size;
        capacity = oldcollection.capacity;
        array = new Obj [capacity];
        for(int i =0; i<capacity;i++)
        {
        array[i] = oldcollection.array[i];
        }
    }
    //
    ~Collection()
    {
        size = 0;
        capacity=0;
        array=nullptr;
    }
    //
    Collection(Collection&& oldcollection)
    {
        this->capacity = oldcollection.capacity;
        this->size = oldcollection.size;
        this->array=oldcollection.array;
        oldcollection.array=nullptr;
        oldcollection.size=0;
        oldcollection.capacity=0;
    }
    //
    Collection & operator= ( Collection&& oldcollection)
    {
        if(this == &oldcollection)
        {
            return *this;
        }
        
        this->capacity = oldcollection.capacity;
        this->size = oldcollection.size;
        this->array=oldcollection.array;
        oldcollection.array=nullptr;
        oldcollection.size=0;
        oldcollection.capacity=0;
        return *this;
    }
    //
    Collection & operator= ( const Collection & oldcollection)
    {
        if(this == &oldcollection)
        {
            return *this;
        }
        
        this->capacity = oldcollection.capacity;
        this->size = oldcollection.size;
        
        Obj* newary = new Obj[this->capacity];
        for(int i =0; i<this->size;i++)
        {
            newary[i] = oldcollection.array[i];
        }
        this->array = newary;
        newary = nullptr;
        return *this;
    }
    //
    void insert_item(const Obj& sb)
    {
        if(this->array==nullptr || this->size+1 == this->capacity)
        {
            this->resize();
        }
        this->array[size] = sb;
        this->size++;
    }
    //
    bool contains(const Obj& sb) const
    {
        for(int i  = 0; i<this->capacity; i++)
        {
            if((this->array[i].get_color() == sb.get_color()) && (this->array[i].get_size() == sb.get_size()))
            {
                return true;
            }
        }
        return false;
    }
    //
    Obj remove_any_item()
    {
        if(this->size==0)
        {
            throw 0;
        }
        else
        {
             int balltoremove = int(rand()%this->size);
            Obj btr = this->array[balltoremove];
            this->size--;
            
            
            if(this->size==0)
            {
                return btr;
            }
            
            for(int i = balltoremove; i<this->size; i++)
            {
                this->array[i] = this->array[i+1];
            }
            return btr;
        }
        
    }
    //
    void remove_this_item(const Obj& sb)
    {
        int oldsize = this->size;
        
          if(this->size==0)//my exception
             {
                 throw 0;//do catch
             }
          
          for(int i =0; i<oldsize;i++)
             {
                 if((this->array[i].get_color() == sb.get_color())&&(this->array[i].get_size()==sb.get_size()))
                 {
                     for(int x = i; x<oldsize; x++)
                     {
                         this->array[x] = this->array[x+1];
                         //this->size--;
                     }
                 }
             }
        this->size--;
    }
    //
    void make_empty()
    {
        this->size = 0;
        Obj* newary = new Obj[this->capacity];
        delete [] this->array;
        this->array = newary;
    }
    //
    bool is_empty() const
    {
        if(this->size==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    //
    int total_items() const
    {
        return this->size;
    }
    //
    int total_items(F2 s) const
    {
        int cnt = 0;
        
        for(int i = 0; i<this->size;i++)
        {
            if(this->array[i].get_size()==s)
            {
                cnt++;
            }
        }
        return cnt;
    }
    //
    int total_items(F1 t) const
    {
        int cnt = 0;
           for(int i =0; i <this->size; i++)
           {
               if(this->array[i].get_color()==t)
               {
                   cnt++;
               }
           }
           return cnt;
    }
    //
    void print_items() const
    {
        for(int i = 0; i<this->size;i++)
           {
                cout << this->array[i] <<endl;
           }
    }
    //
    Obj& operator[](int i)
    {
        if(i >=this->size)
        {
            throw 1;
        }
        return this->array[i];
    }
    //
    const Obj& operator[](int i) const
    {
        if(i >=this->size)
        {
            throw 1;
        }
        return this->array[i];
    }
    //
    void resize()
    {
        Obj* newary = new Obj[this->capacity*2];
        
        for(int i = 0; i<this->capacity;i++)
        {
            newary[i] = this->array[i];
        }
        delete [] this->array;
        this->array = newary;
        newary=nullptr;
    }
    //
    void bubblesort()
    {
        for(int passes = 0;passes<this->size-1;passes++)
        {
            for(int traversal = 0; traversal<this->size-passes-1;traversal++)
            {
                if(this->array[traversal].get_size()>this->array[traversal+1].get_size())
                {
                    Obj temp=this->array[traversal];
                    this->array[traversal]=this->array[traversal+1];
                    this->array[traversal+1] = temp;
                }
            }
        }
    }
    //
    void insertionsort()
    {
        int j;
        for(int i =1; i<this->size;i++)
        {
            j=i;
            while(j>0 && this->array[j-1].get_size()>this->array[j].get_size())
            {
                Obj temp = this->array[j-1];
                this->array[j-1] = this->array[j];
                this->array[j] = temp;
                j=j-1;
            }
        }
    }
    //
    void selectionsort()
    {
        int partition=0;
        int cplace=0;
        int cminimum=0;
        for(int i =partition; i<this->size;i++)
        {
            cminimum=i;
            cplace=i;
            while(cplace<this->size)
            {
                if(this->array[cminimum].get_size()>=this->array[cplace].get_size())
                {
                    cminimum=cplace;
                }
                cplace++;
            }
            Obj temp = this->array[i];
            this->array[i] = this->array[cminimum];
            this->array[cminimum] = temp;
        }
    }
};

template <typename Obj,typename F1, typename F2>
std::istream& operator>>(std::istream& is, Collection<Obj,F1,F2>& c)
{
    
        F2 si;
       F1 co;
       int ccolor;
       int ssize;
       string color;
       string size;
       while(!is.eof())
       {
           is>>color;
           is>>size;
           if(is.fail())
           {
               break;
           }
           if(color == "red"){
               ccolor = 0;}
           else if(color == "blue"){
               ccolor = 1;}
           else if(color == "yellow"){
               ccolor = 2;}
           else if(color == "green"){
               ccolor = 3;}
           

           
           if(size == "small"){
               ssize = 0;}
           else if(size == "medium"){
               ssize = 1;}
           else if(size == "large"){
               ssize = 2;}
           
           
           
           
           switch(ssize)
           {
               case 0: si = F2::small;
                   break;
               case 1: si = F2::medium;
                   break;
               case 2: si = F2::large;
                   break;
           }
           
           switch(ccolor)
           {
               case 0: co = F1::red;
                   break;
               case 1: co = F1::blue;
                   break;
               case 2: co = F1::yellow;
                   break;
               case 3: co = F1::green;
                   break;
           }
           
           Obj x(co,si);
           c.insert_item(x);
       }
       return is;

}
//
template <typename Obj,typename F1, typename F2>
std::ostream& operator <<(std::ostream& os, const Collection<Obj,F1,F2>& c)
{
    for(int i = 0; i<c.total_items();i++)
       {
            os << c[i] <<endl;
       }
       return os;
}
//
enum class Sort_choice { bubble_sort, insertion_sort, selection_sort };
//
template <typename Obj,typename F1, typename F2>
Collection<Obj,F1,F2> make_union(const Collection<Obj,F1,F2>& c1, const Collection<Obj,F1,F2>& c2)
{
    Collection <Obj,F1,F2>newcollec;
    for(int i =0; i<c1.total_items();i++)
    {
        newcollec.insert_item(c1[i]);
    }
    for(int x = 0;x<c2.total_items();x++)
    {
        newcollec.insert_item(c2[x]);
    }
    return newcollec;
}
//
template <typename Obj,typename F1, typename F2>
void swap(Collection<Obj,F1,F2>& c1, Collection<Obj,F1,F2>& c2)
{
    Collection <Obj,F1,F2>temp1;
    temp1 = std::move(c1);
    c1 = std::move(c2);
    c2 = std::move(temp1);
}
//
template <typename Obj,typename F1, typename F2>
void sort_by_size(Collection<Obj,F1,F2>& c, Sort_choice sort)
{
    switch (sort)
       {
           case Sort_choice::bubble_sort: c.bubblesort();
                   break;
           case Sort_choice::selection_sort: c.selectionsort();
                    break;
           case Sort_choice::insertion_sort: c.insertionsort();
                   break;
       }
}




#endif /* Collection_h */
