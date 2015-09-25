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
	int*AP;
	int s;//the original size
	int CurrentSize;//modified by insert, remove, and clear
	int* CP;

public:
	ArrayContainer2(int size=DEFAULT_SIZE){
		this->s=size;
		int array[size];
		this->AP=&array[0];
		this->CurrentSize = 0;
		this->CP=NULL;
	}
	~ArrayContainer2(){
		delete AP;
		delete CP;
	}
	void Clear(){
		for (int i=0; i<CurrentSize; i++)
			*(AP+i) = NULL;
		CurrentSize = 0;
		std:: cout << "Clear" << std:: endl;
		//Runs through the array one by one O(n)
	}

        int Size(){
        	std:: cout << "Size" << std:: endl;
        	return CurrentSize;
        	//Returns the value from running Clear(), O(n)
        }

        bool Empty(){//saves the iteration
        	std:: cout << "Empty" << std:: endl;
        	return(CurrentSize==0);
        }

        int MaxSize(){return s;}
        	//Returns value inputed, O(1)

        void Insert(const T& item){
        	*(AP+CurrentSize) = item;
        	CurrentSize++;
        	//std:: cout << "Insert doing its shit." << std:: endl;
        	//Knows the index and replaces "Null" with the "inserted" value, O(1)
        }
        bool Contains(const T&  item){
        	std:: cout << "Contains" << std:: endl;
        	for(int* q=AP; q<(AP+CurrentSize); q++){
        		std:: cout<<*q<<std::endl;
        		if (*(q)==item){
        			CP=q;
        			return true;
        		}
        	}
        	return false;
        	//Runs through one by one checking if "item" exists, O(n)
        }

        T* Find(const T& item){
        	std:: cout << "Find" << std:: endl;
        	if (Contains(item)){
        		std:: cout << "Finding and return'" << std:: endl;
        		std:: cout<<(*AP)<<std::endl;
        		return CP;
        	}
        	else return NULL;
        	//Utilizes Contains() with an if else bool, O(n)
        }
	void Remove(const T& item){
		std:: cout << "Remove" << std:: endl;
		int *p=Find(item);
		for (int x = 1; x<CurrentSize-2; x++){
			std:: cout<<(*p)<<std::endl;
			*(p+x-1) = *(p+x);
		}
		*(AP+CurrentSize-1) = NULL;
		CurrentSize--;
		std:: cout << *(p) << std:: endl;


		//Sets the value before equal to the one after shifting the array back, O(n)
	}
};

#endif
