/*
 * LinkNode.h
 *
 *  Created on: 2015年7月26日
 *      Author: juanecho
 */

#ifndef HEADER_LINKEDLIST_H_
#define HEADER_LINKEDLIST_H_
#include <iostream>
#include "LinearList.h"
using namespace std;

template <typename T>
struct LinkNode {
	T data;
	LinkNode<T>* link;    //链指针域
	LinkNode(LinkNode<T>* ptr = NULL)  //仅初始化指针成员的构造函数
	{
		link = ptr;
	}
	LinkNode(const T& item, LinkNode<T>* ptr = NULL)
	{
		data = item;
		link = ptr;
	}
};

template <typename T>
class List:public LinearList<T>
{
public:
	List()
	{
		first = new LinkNode<T>;
	}
	List(const T& x)
	{
		first = new LinkNode<T>(x);
	}
	List(List<T>& L);
	~List()
	{
		makeEmpty();
	}
	void makeEmpty();
	int Length()const;
	LinkNode<T> * getHead()const
	{
		return first;
	}
	LinkNode<T>* Search(T x)const;
	LinkNode<T>* Locate(int i)const;
	bool getData(int i, T& x)const;
	void setData(int i, T& x);
	bool Insert(int i, T& x);
	bool Remove(int i, T& x);
	bool IsEmpty()const
	{
		return first->link == NULL ? true:false;
	}
	bool IsFull()const
	{
		return false;
	}
	//void Sort();
	void inputAfter(T endTag);
	void inputFront(T endTag);
	void output();
	List<T> & operator = (List<T>& L);
protected:
	LinkNode<T> * first;  //链表的头指针
};

template<typename T>
List<T>::List(List<T>& L)
{
	first = new LinkNode<T>;
	//复制构造函数
	T value;
	LinkNode<T>* srcptr = L.getHead();
	LinkNode<T>* destptr = new LinkNode<T>;
	while(srcptr->link != NULL)
	{
		value = srcptr->link->data;
		destptr->link = new LinkNode<T>(value);
		destptr= destptr->link;
		srcptr = srcptr->link;
	}
	destptr->link = NULL;
}

template <typename T>
void List<T>::makeEmpty()
{
	LinkNode<T> *q;
	while(first->link != NULL)
	{
		q = first->link;
		first->link = q->link;
		delete q;
	}
}

template<typename T>
int List<T>::Length() const{
	LinkNode<T> *p = first->link;
	int count = 0;
	while(p != NULL)
	{
		p = p->link;
		count++;
	}
	return count;
};

template<typename T>
LinkNode<T> * List<T>::Search(T x)const
{
	LinkNode<T>* current = first->link;
	while(current != NULL)
	{
		if(current->data == x)
			break;
		else
			current = current->link;
	}
	return current;
}

template < typename T>
LinkNode<T>* List<T>::Locate(int i)const
{
	if( i < 0)
		return NULL;
	LinkNode<T>* current = first;
	int k = 0;
	while(current != NULL && k < i)
	{
		current = current->link;
		k++;
	}
	return current;
}

template<typename T>
bool List<T>::getData(int i, T& x)const
{
	if(i <= 0)
		return NULL;
	LinkNode<T> * current =  Locate(i);
	if(current == NULL)
		return false;
	else{
		x = current->data;
		return true;
	}
};

template<typename T>
void List<T>::setData(int i,T& x)
{
	if(i <= 0)
		return;
	LinkNode<T>* current = Locate(i);
	if(current == NULL)
		return;
	else
		current->data = x;
};

template<typename T>
bool List<T>::Insert(int i, T& x)
{
	LinkNode<T>* current = Locate(i);
	if(current == NULL)
		return false;
	LinkNode<T>* newNode = new LinkNode<T>(x);
	if(newNode == NULL)
	{
		cerr<<"存储分配失败！"<<endl;
		exit(1);
	}
	newNode->link = current->link;
	current->link = newNode;
	return true;
};

template<typename T>
bool List<T>::Remove(int i,T& x)
{
	LinkNode<T> * current = Locate(i -1);
	if(current == NULL || current->link == NULL)
		return false;
	LinkNode<T>* del = current->link;
	current->link = del->link;
	x = del->data;
	delete del;
	return true;
}

template <typename T>
void List<T>::output()
{
	cout<<"-------链表里的数据为--------"<<endl;
	LinkNode<T>* current = first->link;
	while(current != NULL)
	{
		cout<<current->data<<"\t";
		current = current->link;
	}
	cout<<"\n-------end-----"<<endl;
}

template <typename T>
List<T>& List<T>::operator=(List<T>& L)
{
	T value;
	LinkNode<T>* srcptr = L.getHead();
	LinkNode<T>* destptr = first = new LinkNode<T>;
	while(srcptr->link != NULL)
	{
		value = srcptr->link->data;
		destptr->link = new LinkNode<T>(value);
		destptr = destptr->link;
		srcptr = srcptr->link;
	}
	destptr->link = NULL;
	return * this;
}

template <typename T>
void List<T>::inputFront(T endTag)
{
	//endtag是约定的输入序列结束的标志，如果输入序列是正整数，endTag可以是0或者负数
	//如果输入序列是字符，endTag可以是字符集中不会出现的字符，如"\0"
	cout<<"-------前插法创建链表------"<<endl;
	LinkNode<T>* newNode;
	T val;
	makeEmpty();
	cin>>val;
	while(val != endTag)
	{
		newNode = new LinkNode<T>(val);
		if(newNode == NULL)
		{
			cerr<<"存储分配失败!"<<endl;
			exit(1);
		}
		newNode->link = first->link;
		first->link = newNode;
		cin>>val;
	}
	cout<<"-------end-----"<<endl;
}

template <typename T>
void List<T>::inputAfter(T endTag)
{
	    cout<<"-------后插法创建链表------"<<endl;
	    LinkNode<T>* newNode, *last;
		T val;
		makeEmpty();
		cin>>val;
		last = first;
		while(val != endTag)
		{
			newNode = new LinkNode<T>(val);
			if(newNode == NULL)
			{
				cerr<<"存储分配失败!"<<endl;
				exit(1);
			}
			last->link = newNode;
			last= newNode;
			cin>>val;
		}
		last->link = NULL;
		cout<<"-------end-----"<<endl;
}

#endif /* HEADER_LINKEDLIST_H_ */
