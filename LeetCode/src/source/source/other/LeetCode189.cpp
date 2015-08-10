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
	void rotate(vector<int>& nums, int k) {
		int len = nums.size();
		if(len <= 0 ||k == 0) return;
		k = k % len;
		vector<int> newArr;
		int i = k;
		while(i){
			nums.insert(nums.begin(),nums.back());
			nums.pop_back();
			i--;
		}
//		for(int i = 0; i < len;i++){
//			cout<<nums[i]<<"\t";
//		}
	}
};

//int main(){
//	Solution * s= new Solution();
//	vector<int> nums;
//	for(int i = 0; i< 3; i++)
//	{
//		nums.push_back(i);
//	}
//	s->rotate(nums,2);
//	return 0;
//}
