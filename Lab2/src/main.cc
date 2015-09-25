#include <iostream>
#include <sys/time.h>
#include "Container.h"
#include "ArrayContainer2.hpp"

using namespace std;

void RunOfSize(int size);

int main(int argc,char** argv)
{
	RunOfSize(100);
//	RunOfSize(1000);
//	RunOfSize(10000);
//	RunOfSize(100000);
//	RunOfSize(1000000);
//	RunOfSize(10000000);
//	RunOfSize(100000000);
}

void RunOfSize(int size)
{
	Container<int>* dataContainer=new ArrayContainer2<int>(size);
	for (int i=0;i<size;i++) {
		dataContainer->Insert(i);
	}
	cout<<"The container now contains "<<dataContainer->Size()<<" objects."<<endl;
	if (dataContainer->Contains(size-1))
	{
		std:: cout<<("Contains = true")<<std::endl;
		int item=*(dataContainer->Find(size-1));
		dataContainer->Remove(item);
	}
	if (!dataContainer->Empty())
		dataContainer->Clear();
	delete (dataContainer);


}

