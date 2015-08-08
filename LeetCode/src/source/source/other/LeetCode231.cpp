/*
 * LeetCode005.cpp
 *
 *  Created on: 2015年8月4日
 *      Author: juanecho
 */

#include "leetcode.h"
#include <sstream>

class Solution {
	/*
	Given an integer, write a function to determine if it is a power of two.
	 */
public:
	 bool isPowerOfTwo(int n) {
	     bool flag = false;
	     int f = 1;
	     if(n < 0) return false;
	     for(int i = 0 ; i < 31; i++)
	    	 if(n - pow(2,i) * f == 0)
	    		 flag = true;
	     return flag;
	    }
};
//
//int main(){
//	Solution * s= new Solution();
//	cout<<s->isPowerOfTwo(-2147483648)<<endl;
//	for(int i = 0 ; i < 32; i++)
//		cout<<(int)pow(2,i)<<endl;
//	return 0;
//}
