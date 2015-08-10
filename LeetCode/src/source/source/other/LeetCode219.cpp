/*
 * LeetCode005.cpp
 *
 *  Created on: 2015年8月4日
 *      Author: juanecho
 */

#include "leetcode.h"
#include<stdint.h>

/**<<超时了>*/
class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		bool flag = false;
		if(k <= 0 || nums.size() <= 1) return false;
		map<int, int> m;
		int len = nums.size();
		for(int i = 0; i < len; i++){
			if(m.find(nums[i]) !=  m.end() && i - m[nums[i]] <=k){
				return true;
			}else{
				m[nums[i]] = i;
			}
		}
		return flag;
	 }
};
//
//int main(){
//	Solution * s= new Solution();
//    vector<int> ass;
//    int i = 0;
//    while(i < 29999){
//    	ass.push_back(i);
//    	i++;
//    }
//    ass.push_back(0);
//	cout<<s->containsNearbyDuplicate(ass,29999);
//	return 0;
//}
