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
		map<int,int> m;
		for(int i = 0; i < nums.size(); i++){
			for(int j = i+1; j < nums.size(); j++){
				if(nums[i] == nums[j]){
//					m.insert(pair<int,int>(i,j));
					if(k - (j - i) >=0)
						return true;
				}
			}
		}
//		map<int,int>::iterator it;
//		for(it = m.begin(); it!= m.end(); it++){
//			if(k - ( it->second - it->first ) >= 0){
//				return true;
//			}
//		}
		return flag;
	 }
};

//int main(){
//	Solution * s= new Solution();
//	int nums[] = {1};
//    vector<int> ass;
//    int i = 0;
//    while(i < 1){
//    	ass.push_back(nums[i]);
//    	i++;
//    }
//	cout<<s->containsNearbyDuplicate(ass,1);
//	return 0;
//}
