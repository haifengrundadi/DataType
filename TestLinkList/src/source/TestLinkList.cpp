//============================================================================
// Name        : TestLinkList.cpp
// Author      : juanecho
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "../header/LinkedList.h"
#include "../header/StaticList.h"
using namespace std;
//........
int main() {
	/*cout << "------******----顺序表------*******" << endl;
	List<int>* list = new List<int>();
	list->inputFront(-1);
	cout<<list->Length()<<endl;
	list->output();*/
	cout << "------******----静态链表-----*******" << endl;
	StaticList<int> * list = new StaticList<int>();
	list->InitList();
	for(int i = 1; i<9; i++)
	{
		list->Append(i);
	}
	list->Remove(3);
	list->Append(111);
	list->Output();
	cout<<list->GetAvil()<<endl;
	return 0;
}
