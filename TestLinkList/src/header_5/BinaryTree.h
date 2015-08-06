/*
 * BinaryTree.h
 *
 *  Created on: 2015年8月2日
 *      Author: juanecho
 */

#ifndef HEADER_5_BINARYTREE_H_
#define HEADER_5_BINARYTREE_H_
#include<iostream>
using namespace std;
template <typename T>
struct BinTreeNode{
	T data;
	BinTreeNode<T>*leftChild,*rightChild;
	BinTreeNode():leftChild(NULL),rightChild(NULL){};
	BinTreeNode(T x, BinTreeNode<T>* l = NULL, BinTreeNode<T>*r = NULL):data(x),leftChild(l),rightChild(r){}
};
template <typename T>
class BinaryTree{
public:
	BinaryTree():root(NULL){};
	BinaryTree(T value):RefValue(value),root(NULL){}
	BinaryTree(BinaryTree<T>& s);
	~BinaryTree(){destroy(root);}
	bool IsEmpty(){return (root==NULL)?true:false;}
		BinTreeNode<T>* Parent(BinTreeNode<T>* current)
		{
		return (root== NULL || root == current)?NULL:Parent(root,current);
		}
		BinTreeNode<T>*LeftChild(BinTreeNode<T>*current)
		{
		return (current != NULL)?current->leftChild:NULL;
		}
		BinTreeNode<T>*rightChild(BinTreeNode<T>*current)
		{
		return (current != NULL)?current->rightChild:NULL;
		}

		int Height(){return Height(root);}
		int Size(){return Size(root);}
		BinTreeNode<T>*getRoot()const{return root;}
		/*void preOrder(void (*visit)BinTreeNode<T> *p)
		{
			preOrder(root, visit);
		}
		void inOrder(void (*visit)BinTreeNode<T> *p)
		{
			inOrder(root, visit);
		}
		void postOrder(void (*visit)BinTreeNode<T> *p)
		{
			postOrder(root, visit);
		}
		void levelOrder(void (*visit)BinTreeNode<T> *p);*/
		int Insert(const T& item);
		BinTreeNode<T>*Find(T& item)const;
protected:
	BinTreeNode<T>*root;
	T RefValue;
	BinTreeNode<T>*Parent(BinTreeNode<T>*subTree, BinTreeNode<T>*current);
	bool Insert(BinTreeNode<T>* & subTree, const T& x);
	void destory(BinTreeNode<T>*&subTree);
	bool Find(BinTreeNode<T>*subTree,const T& x)const;

};




#endif /* HEADER_5_BINARYTREE_H_ */
