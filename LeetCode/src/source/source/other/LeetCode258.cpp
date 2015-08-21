/*
 * LeetCode005.cpp
 *
 *  Created on: 2015年8月4日
 *      Author: juanecho
 */

#include "leetcode.h"
#include<stdint.h>
class Solution {
public:
	int addDigits(int num) {
			if(num % 9 ==  0 && num >= 9)
				return 9;
			else
				return num % 9;
	}
};

//int main(){
//	Solution * s= new Solution();
//	cout<<s->addDigits(38);
//	return 0;
//}
