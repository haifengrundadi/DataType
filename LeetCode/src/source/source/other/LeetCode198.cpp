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
	int getMax(int x,int y,int z){
		return (x + z) > y? (x + z):y;
	}
	int rob(vector<int>& nums) {
		int len = nums.size();
		int sum = 0,total = 0,tem = 0;
		int i = 0;
		if(len == 0){
			return 0;
		}else if(len == 1){
			return nums[0];
		}else if(len == 2){
			return  nums[0]>=nums[1]?nums[0]:nums[1];
		}else if(len == 3){
			return  (nums[0]+nums[2])>nums[1]?(nums[0] + nums[2]):nums[1];
		}else{
			sum = nums[0]>=nums[1]?nums[0]:nums[1];
			total =( nums[0]+nums[2])>nums[1]?(nums[0] + nums[2]):nums[1];
			i = 3;
			while(i < len){
				tem = getMax(sum, total, nums[i]);
				if(tem > total){
					sum = total;
					total = tem;
				}else{
					sum = tem;
				}
				i++;
			}
		}
		return total;
	 }
};

//int main(){
//	Solution * s= new Solution();
//	vector<int> arr;
//	int nums[] = {2,7,9,3,1};
//	for(int i = 0; i < 5; i++){
//		arr.push_back(nums[i]);
//	}
//	cout<<s->rob(arr)<<endl;
//	return 0;
//}
