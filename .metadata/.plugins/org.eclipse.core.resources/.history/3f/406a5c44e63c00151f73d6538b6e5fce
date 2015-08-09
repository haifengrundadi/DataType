/*
 * LeetCode005.cpp
 *
 *  Created on: 2015年8月4日
 *      Author: juanecho
 */

#include "leetcode.h"
#include<stdint.h>
class Solution {
	/*
	Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).
For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.
	 */
public:
	 int hammingWeight(uint32_t n) {
		 int num = 0;
		 while(n)
		 {
			 num += n & 0x1;
			 n >>= 1;
		 }
		 return num;
	  }
};

//int main(){
//	Solution * s= new Solution();
//	cout<<s->hammingWeight(11)<<endl;
//	return 0;
//}
