/*
 * LeetCode005.cpp
 *
 *  Created on: 2015年8月4日
 *      Author: juanecho
 */

#include<iostream>
#include<string>
#include<cmath>
#include<fstream>
#include <stdlib.h>
using namespace std;

class Solution {
public:
	int reverse(int x)
	{
        int num = 0,flag = 1,len = 0,isBigger=0;
        int max = 4294967295,m = 0;
        if(x == 0) return x;
        if(x < 0) flag = -1;
        len = (int)log10(abs(x)) + 1;
        if(len > 10)return 0;
        x = abs(x);

        while(len)
        {
            num += x % 10 * pow(10, len-1);
            x = x / 10;
            m = max - num;
            if(m < 0)
                return 0;
            else
                len--;
        }
        //4294967295
        return num * flag;
    }
};
