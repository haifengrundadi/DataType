/*
 * LeetCode005.cpp
 *
 *  Created on: 2015年8月4日
 *      Author: juanecho
 */

#include "leetcode.h"
#include<stdint.h>
/*
 * 10 只能有2和5 相乘所得，由于2，出现在5前面，且2 的幂函数多于5，所以要求，5的个数，但要考虑可以分解成5的数。
 */
class Solution {
public:
		int trailingZeroes(int n) {
			int count = 0;
			if(n == 0) return count;
			while(n){
				count += n / 5;
				n = n / 5;
			}
			return count;
	    }
};

//int main(){
//	Solution * s= new Solution();
//	for(int i = 1; i<= 1001; i++){
//		cout<<"\t"<<i<<"---"<<s->trailingZeroes(i)<<endl;
//		cout<<"***************"<<endl;
//	}
//	return 0;
//}
