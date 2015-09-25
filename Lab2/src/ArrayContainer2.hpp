#ifndef __ARRAYCONTAINER_H__
#define __ARRAYCONTAINER_H__
#include <iostream>
#include <typeinfo>//NOTE MAIN HAS BEEN ADJUSTED TO WORK WITH ARRAYCONTAINER2!!!!!

#define DEFAULT_SIZE 50

// LAB PARTNERS:
// Steven Sell
// Jared Sharpe

template<class T> class ArrayContainer2:public Container<T>
{
private:
	T*array;
	int s;
	int CurrentSize;
	int CP;//For large n this save a lot of time parsing through since you don't need to have another for loop (therefore saving O(n))

public:
	ArrayContainer2(int size=DEFAULT_SIZE){
		this->s=size;
		array = new T[size];
		this->CurrentSize = 0;
		this->CP=0;
	}
	~ArrayContainer2(){
		delete[] array;
		CP=NULL;
		CurrentSize=NULL;
		s=NULL;
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

	int MaxSize(){return s;}
		//Returns value inputed, O(1)

	void Insert(const T& item){
		array[CurrentSize] = item;
		CurrentSize++;
		//Knows the index and replaces "Null" with the "inserted" value, O(1)
	}
	bool Contains(const T&  item){
		for(int q=0; q<CurrentSize; q++){
			if (array[q]==item){
				CP=q;
				return true;
			}
		}
		return false;
		//Runs through one by one checking if "item" exists, O(n)
	}

	T* Find(const T& item){
		if (Contains(item)){
			return &array[CP];
		}
		else return NULL;
		//Utilizes Contains() with an if else bool, O(n)
	}
	void Remove(const T& item){
		int *p=Find(item);
		for (int x = 0; x<CurrentSize-2-CP; x++){
			array[CP+x] = array[CP+x+1];
		}
		CurrentSize--;
		//Sets the value before equal to the one after shifting the array back, O(n)
	}
};

#endif
