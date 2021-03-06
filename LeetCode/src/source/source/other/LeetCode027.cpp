/*
 * LeetCode005.cpp
 *
 *  Created on: 2015年8月4日
 *      Author: juanecho
 */

#include "leetcode.h"

class Solution {
public:
	int removeElement(vector<int>& nums,int val) {
		int len = nums.size();
		int count = 0;
		int k = 0;
		if(len == 0) return 0;
		while(len > k){
			if(val != nums[len - 1]){
				count++;
				k++;
				nums.insert(nums.begin(),nums[len-1]);
				len++;
			}
			nums.pop_back();
			len--;
		}
//		for(int i=0; i < nums.size();i++){
//			cout<<nums[i]<<"\t";
//		}
//		cout<<endl;
		return count;
	}
};

//int main(){
//	Solution * s= new Solution();
//	 std::vector<int> myvector;
//	myvector.insert(myvector.begin(),1);
//	myvector.insert(myvector.begin(),2);
//	myvector.insert(myvector.begin(),3);
////	myvector.insert(myvector.begin(),1);
//	cout<<s->removeElement(myvector,1)<<endl;
//	return 0;
//}
