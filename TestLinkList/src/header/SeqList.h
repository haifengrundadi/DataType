#ifndef SEQLIST_H
#define SEQLIST_H
#include<iostream>
#include<stdlib.h>

#include "LinearList.h"
const int defaultSize = 100;
template <class T>
class SeqList: public LinearList<T>
{
    protected:
        T * data; //存放数组
        int maxSize; //最大可容纳表项的项数
        int last; //当前已存表项的最后位置（从o开始）
        void reSize(int newSize); //改变data数组空间的大小

    public:
        SeqList(int sz = defaultSize);          //构造函数
        SeqList(SeqList<T>& L);                  //复制构造函数
        ~SeqList(){delete[] data;}               //析构函数
        int Size()const{return maxSize;}   //计算表最大可容纳表项个数
        int Length()const{return last+1;} //计算表的长度
        int Search(T& x) const ;                 //在表中搜索给定值
        int Locate(int i) const;                   //在表中定位第i个元素的位置
        bool getData(int i, T& x) const      //取第i个表象的值
        {
            if(i > 0 && i < last+1)
            {
                x = data[i-1];
                return true;
            }else
            {
                return false;
            }
        };
        void setData(int i, T& x)            //修改第i个表项的值为x
        {
           if(i > 0 && i < last+1)
            {
                data[i-1] = x;
            }
         };
        bool Insert(int i, T& x) ;              // 在第i个表项后插入x
        bool Remove(int i, T& x);            //删除第i个表项通过x返回
        bool IsEmpty()const                           //判断空
        {
            return (last == -1) ? true:false;
        };
        bool IsFull()const
        {
            return (last == maxSize -1) ? true:false;
        };
        void input();                                 //输入
        void output();                              //输出
        //SeqList<T> operator = (SeqList<T>& L) ; //复制
};
template <class T>
SeqList<T>::SeqList(int sz){
    //构造函数，通过指定参数sz定义数组的长度
    if(sz > 0)
    {
        maxSize = sz;
        last = -1;
        data = new T[maxSize];   //创建顺序表存储空间
        if(data == NULL)  //动态分配失败
        {
            cerr<<"存储分配错误！"<<endl;
            exit(1);
        }
    }
};
template <class T>
SeqList<T>::SeqList(SeqList<T>& L)
{
    //复制构造函数，用参数表中给出的已有顺序表初始化新建的顺序表
    maxSize = L.Size();
    last = L.Length() -1;
    T value;
    data = new T[maxSize]; //创建顺序表存储数组
    if(data == NULL)//动态分配失败
    {
        cerr<<"存储分配失败！"<<endl;
        exit(1);
    }
    for (int i = 1; i < last+1; i++)
    {
        L.getData(i, value);
        data[i - 1] = value;
    }
};
template <class T>
void SeqList<T>::reSize(int newSize) //改变data数组空间的大小
{
    //私有函数，扩充顺序表的存储数组空间大小，新数组的元素个数为newSize
    if(newSize <= 0)
    {
        cerr<<"无效的数组大小"<<endl;
        return;
    }
    if(newSize != maxSize)
    {
        T* newArray = new T[newSize];
        if(newArray == NULL)
        {
            cerr<<"存储分配失败！"<<endl;
            exit(1);
        }
        int n  = last + 1;
        T* srcptr = data; //源数组首地址
        T* destptr = newArray; //目的数组首地址
        while(n--)
        {
            *destptr++ = *srcptr++; //复制
        }
        delete []data; //删除老数组
        data = newArray;
        maxSize = newSize;//复制新数组
    }
}

template <class T>
int SeqList<T>::Locate(int i) const{
    if( i >= 1 && i <= last +1)
        return i;
    else
        return 0;
}

template <class T>
bool SeqList<T>::Insert(int i, T& x)
{
    if(last == maxSize -1)
        return false;
    if(i < 0 && i > last+1)
        return false;
    for(int j = last; j>=i;j--)
    {
        data[j+1] = data[j];
    }
    data[i] = x;
    last++;
    return true;
}

template <class T>
bool SeqList<T>::Remove(int i,T& x)
{
    if(last == -1)
        return false;
    if( i < 1 || i > last+1)
        return false;
    x = data[i -1];
    for(int j = i; j <= last; j++)
        data[j-1] = data[j];
    last--;
    return true;
}

template <class T>
void SeqList<T>::input()
{
    cout<<"开始建立顺序表，请输入表中的元素个数:";
    while(1){
        cin>>last;
        if(last <= maxSize -1)
            break;
        cout<<"表元素个数输入有误，范围不能超过"<<maxSize -1<<":";
    }
    for(int i = 0; i <= last; i++)
    {
        cin>>data[i];
        cout<<i+1<<endl;
    }
}

template <class T>
void SeqList<T>::output()
{
    cout<<"顺序表当前元素最后位置为"<<last<<endl;
    for(int i = 0; i <= last; i++)
        cout<<"#"<<i+1<<":"<<data[i]<<endl;
}

#endif // SEQLIST_H
