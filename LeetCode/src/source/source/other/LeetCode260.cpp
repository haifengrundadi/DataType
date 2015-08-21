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
	/*
	 * 思路： 第一次pass完，得到出现一次的两个数的异或结果，因为出现的两个数不一样，又因为 0 ^ 1 = 1所以肯定最后的结果有
	 * 一位是一，取出这一位，然后pass第二遍，把数组分成两个组。每个组都包含一个出现一次的数组
	 */
	vector<int> singleNumber(vector<int>& nums) {
		vector<int> result;
		int x = 0, y = 0, i = 0;
		int size = nums.size();
		for(i = 0; i < size; i++){
				x = x ^ nums[i];
		}
		int mask = x & (~(x -1));
		x = 0;
		for(i = 0; i < size; i++){
			if((mask & nums[i]) ==0)
					y ^= nums[i];
			else
					x ^= nums[i];
		}
		result.push_back(x);
		result.push_back(y);
		return result;
	}
};

//int main(){
//	Solution * s= new Solution();
//	vector<int> nums,result;
//	int arr[] = {1,2,1,3,5,2};
//	for(int i = 0; i < sizeof(arr)/sizeof(int); i++){
//		nums.push_back(arr[i]);
//	}
//	result = s->singleNumber(nums);
//	for(int i = 0; i < result.size(); i++){
//		cout<<result[i]<<"\t";
//	}
//	cout<<endl;
//	return 0;
//}
