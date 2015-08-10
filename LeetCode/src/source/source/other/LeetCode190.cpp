/*
 * LeetCode005.cpp
 *
 *  Created on: 2015年8月4日
 *      Author: juanecho
 */

#include "leetcode.h"
#include<stdint.h>
/*
 * Reverse bits of a given 32 bits unsigned integer.
For example, given input 43261596 (represented in binary as 00000010100101000001111010011100),
return 964176192 (represented in binary as 00111001011110000010100101000000).
 */
class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		unsigned char arr[32] = {0};
		   int i = 0;
		   uint32_t x = 0;
		   while(i <= 31){
			   arr[i] = n & 0x1;
//			   cout<<char(arr[i]+'0');
			   n>>= 1;
			   i++;
		   }
//		   cout<<endl;
		   int m = 1;
		   i = 31;
		  while(i >= 0){
			  x += m * arr[i];
//			   cout<<char(arr[i]+'0');
			  m = m<<1;
			  i--;
		  }
//		  cout<<endl;
		   return x;
	}
};

//int main(){
//	Solution * s= new Solution();
//	cout<<endl;
//	cout<<s->reverseBits(43261596)<<endl;
//	cout<<s->reverseBits(2147483648)<<endl;
//	cout<<s->reverseBits(1)<<endl;
//	cout<<s->reverseBits(0)<<endl;
//	return 0;
//}
