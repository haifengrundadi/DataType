/*
 * GenList.h
 *
 *  Created on: 2015年8月2日
 *      Author: juanecho
 */

#ifndef HEADER_4_GENLIST_H_
#define HEADER_4_GENLIST_H_
#include<iostream>
#include<assert.h>
#include<stdlib.h>
using namespace std;
template <typename T>
struct Items{
	int utype;
	union{
		int ref; //utype = 0, 附加头结点，存放引用计数
		T value;//utype = 1,存放数值
		GenListNode<T> *hlink;//utype = 2,存放指向子表的指针
	}info;
	Items():utype(0),info.ref(0){}
	Items(Items<T>& RL){utype = RL.utype; info = RL.info;}
};

template <typename T>
struct GenListNode{
public:
	GenListNode():utype(0),tlink(NULL),info.ref(0){}
	GenListNode(GenListNode<T>& RL)
	{
		utype = RL.utype;
		tlink = RL.tlink;
		info = RL.info;
	}
private:
	int utype;
	GenListNode<T>*tlink;
	union{
		int ref;
		T value;
		GenListNode<T>* hlink;
	}info;
};

template <typename T>
class GenList{
public:
	GenList();
	~GenList();
	bool Head(Items<T>& x);
	bool Tail(GenList<T>& it);
	GenListNode<T>*First();
	GenListNode<T>*Next(GenListNode<T>*elem);
	void Copy(const GenList<T>& R);
	int Length();
	int depth();
	friend istream& operator>>(istream& in, GenList<T>& L);
private:
	GenListNode<T>* first;
	GenListNode<T>*Copy(GenListNode<T>*ls);
	//复制一个ls指示的无共享非递归表
	int Length(GenListNode<T>* ls);
	int depth(GenListNode<T>* ls);
	bool equal(GenListNode<T>*s,GenListNode<T>*t);
	void Remove(GenListNode<T>* ls);
	void Createlist(istream& in, GenListNode<T>*& ls);
};

template<typename T>
GenList<T>::GenList()
{
	first = new GenListNode;
	assert(first!= NULL);
}

template<typename T>
bool GenList<T>::Head(Items<T>& x)
{
	if(first->link == NULL)
		return false;
	else{
		x.utype = first->tlink->utype;
		x.info = first->tlink->info;
		return true;
	}
}

template<typename T>
bool GenList<T>::Tail(GenList<T>& it)
{
	if(first->tlink == NULL)
		return false;
	else{
		it.first->utype = 0;
		it.first->info.ref = 0;
		it.first->tlink = Copy(first->tlink->tlink);
		return true;
	}
}

template<typename T>
GenListNode<T> *GenList<T>::First(){
	if(first->tlink == NULL)
		return NULL;
	else
		return first->tlink;
}

template<typename T>
GenListNode<T>* GenList<T>::Next(GenListNode<T>*elem)
{
	if(elem->tlink == NULL)
	{
		return NULL;
	}else{
		return elem->tlink;
	}
}

template<typename T>
void GenList<T>::Copy(const GenList<T>& R)
{
	first = Copy(R.first);
}

template<typename T>
GenListNode<T> *GenList<T>::Copy(GenListNode<T>* ls)
{
	GenListNode<T> *q = NULL;
	if(ls != NULL)
	{
		q = new GenListNode<T>;
		q->utype = ls->utype;
		switch(ls->utype)
		{
		case 0:q->info.ref = ls->info.ref;break;
		case 1:q->info.value = ls->info.value; break;
		case 2:q->info.hlink = Copy(ls->info.hlink);break;
		}
		q->tlink = Copy(ls->tlink);
	}
	return q;
}

template<typename T>
int GenList<T>::Length()
{
	return Length(first);
}
template<typename T>
int GenList<T>::Length(GenListNode<T> *ls)
{
	if(ls != NULL)
		return 1 + Length(ls->tlink);
}

#endif /* HEADER_4_GENLIST_H_ */
