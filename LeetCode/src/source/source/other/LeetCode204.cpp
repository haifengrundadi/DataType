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
	Count the number of prime numbers less than a non-negative number, n.
	 */
public:

	int countPrimes(int n) {
		if(n <= 1) return 0;
		bool arr[n+1];
		for (int i = 2; i <= n; i++)
				arr[i] = true;
		for (int i = 2; i*i <= n; i++) {
			if(!arr[i]) continue;
			for(int j = i * i; j <= n; j += i){
				arr[j] = false;
			}
		}
		int count = 0;
		   for (int i = 2; i <= n; i++) {
		      if (arr[i]) count++;
		      cout<<arr[i]<<"--"<<i<<endl;
		   }
		   return count;
	 }
};

//int main(){
//	Solution * s= new Solution();
//	cout<<s->countPrimes(7)<<endl;
//	return 0;
//}
