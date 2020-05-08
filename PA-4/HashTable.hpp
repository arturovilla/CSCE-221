/*
Arturo Villalobos
UIN: 827008236
Sec:503 username: rturovilla
email: rturovilla@tamu.edu
*/
#pragma once
#include <utility>
#include <regex>
#include <list>
#include <vector>
#include <iostream>
#include <ostream>
using namespace std;
/*
 *ont - uin - key
 t - score as a string
  pairs = UIN - score pairs
 */
template<typename T>
class HashTable
{
public:
	int size;
    
	//IMPLEMENT
    vector<list<pair<T,int>>> mtable;
	
    int hash(const int _key)
    {
        return _key % size;
    }
//public:
    HashTable(const int _size)
    {
		//IMPLEMENT
        this->size = _size;
        this->mtable = vector<list<pair<T, int>>>(_size);
        
    }
	
	~HashTable()
    {
		//IMPLEMENT
        mtable.clear();
        this->size=0;
	}
    
    void insert(const int _key, T _value)
    {
		//IMPLEMENT
        int index = hash(_key);//index in the vector
        
        pair<T, int> pti (_value,_key);
        
        this->mtable.at(index).push_back(pti);
    }
	
	int minChainLen()
    {
		//IMPLEMENT
        int min = (this->mtable[0]).size();
        int temp  = 0;
        
        for(int i =0; i<this->mtable.size();i++)
        {
            temp = this->mtable[i].size();
            if(temp<=min)
            {
                min =temp;
            }
        }
		return min;
	}
	
	int maxChainLen()
    {
		//IMPLEMENT
        int max = (this->mtable[0]).size();
        int temp = 0;
        for(int i = 0;i<this->mtable.size();i++)
        {
            temp = this->mtable[i].size();
            if(temp>=max)
            {
                max = temp;
            }
        }
		return max;
	}
	
	double averageChainLen()
    {
		//IMPLEMENT
        double avg = 0.0;
        double cnt=0;
        for(int i = 0 ;i<this->size;i++)
        {
            avg+=this->mtable[i].size();
            cnt++;
        }
        avg=avg/cnt;
		return avg;
	}
    
    T* search(int _key)//returns score
    {
        int index = hash(_key);
         for (auto ptr=this->mtable[index].begin(); ptr != this->mtable[index].end(); ptr++)
         {
             if(_key == ptr->second)
             {
                 return &ptr->first;
             }
         }
        return nullptr;
    }
    
};


