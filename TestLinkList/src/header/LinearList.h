#ifndef LINEARLIST_H
#define LINEARLIST_H
#include <iostream>
#include<stdlib.h>
using namespace std;

template <class T>
class LinearList
{
    public:
        //LinearList();     //构造函数
        //~LinearList();   //析构函数
        //virtual int Size() const = 0;
        virtual int Length() const = 0;                      // 求表的长度
        //virtual int Search(T& x) const = 0;               //在表中搜索给定值
        //virtual int Locate(int i) const = 0;                //在表中定位第i个元素的位置
        virtual bool getData(int i, T& x) const = 0;  //取第i个表象的值
        virtual void setData(int i, T& x)  = 0;            //修改第i个表项的值为x
        virtual bool Insert(int i, T& x)  = 0;              // 在第i个表项后插入x
        virtual bool Remove(int i, T& x)  = 0;          //删除第i个表项通过x返回
        virtual bool IsEmpty() const = 0;                //判断空
        virtual bool IsFull() const = 0;                    //判断满
        //virtual void Sort() = 0;                                 //  排序
        //virtual void input() = 0;                               //输入
        virtual void output() = 0;                              //输出
        //virtual LinearList<T> operator = (LinearList<T>& L)  = 0; //复制
};
#endif // LINEARLIST_H
