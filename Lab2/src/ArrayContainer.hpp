#ifndef __ARRAYCONTAINER_H__
#define __ARRAYCONTAINER_H__
#include "Container.h"
#include <iostream>

#define DEFAULT_SIZE 50

// LAB PARTNERS:
// Steven Sell
// Jared Sharpe

template<class T> class ArrayContainer:public Container<T>
{
private:
	T*array;
	int max;
	int CurrentSize;
	int storedIndex;//For large n this save a lot of time parsing through since you don't need to have another for loop (therefore saving O(n))

public:
	ArrayContainer(int size=DEFAULT_SIZE){
		max=size;
		array = new T[size];
		CurrentSize = 0;
		storedIndex=0;
	}
	~ArrayContainer(){
		delete[] array;
		storedIndex=NULL;
		CurrentSize=NULL;
		max=NULL;
	}
	void Clear(){
		for (int i=0; i<CurrentSize; i++)
			array[i] = NULL;
		CurrentSize = 0;
		//Runs through the array one by one O(n)
	}

	int Size(){
		return CurrentSize;
		//Returns the value of CurrentSize, O(1)
	}

	bool Empty(){//saves the iteration
		return(CurrentSize==0);
		//Boolean evaluation, O(1)
	}

	int MaxSize(){return max;}
		//Returns value inputed, O(1)

	void Insert(const T& item){
		array[CurrentSize] = item;
		CurrentSize++;
		//Knows the index and replaces "Null" with the "inserted" value, O(1)
	}
	bool Contains(const T&  item){
		for(int q=0; q<CurrentSize; q++){
			if (array[q]==item){
				storedIndex=q;
				return true;
			}
		}
		return false;
		//Runs through one by one checking if "item" exists, O(n)
	}

	T* Find(const T& item){
		if (Contains(item)){
			return &array[storedIndex];
		}
		else return NULL;
		//Utilizes Contains() with an if else bool, O(n)
	}
	void Remove(const T& item){
		int *p=Find(item);
		for (int x = 0; x<CurrentSize-2-storedIndex; x++){
			array[storedIndex+x] = array[storedIndex+x+1];
		}
		CurrentSize--;
		//Sets the value before equal to the one after shifting the array back, O(n)
	}
};

#endif
