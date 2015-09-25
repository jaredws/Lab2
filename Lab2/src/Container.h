#ifndef __CONTAINER_H__
#define __CONTAINER_H__

template<class T> class Container
{
public:
	virtual void Clear()=0;
	virtual int Size()=0;
	virtual bool Empty()=0;
	virtual int MaxSize()=0;
	virtual void Insert(const T& )=0;
	virtual bool Contains(const T& )=0;
	virtual T* Find(const T&)=0;
	virtual void Remove(const T& )=0;
	virtual ~Container(){}
};

#endif
