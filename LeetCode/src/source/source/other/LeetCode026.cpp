/*
 * LeetCode005.cpp
 *
 *  Created on: 2015年8月4日
 *      Author: juanecho
 */

#include "leetcode.h"

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int len = nums.size();
		if(len == 0) return 0;
		for (unsigned i=0; i<nums.size(); i++)
		{
			for (unsigned j=i+1; j<nums.size(); j++){
				if(nums[i] == nums[j]){
//				    cout<<i<<"---"<<nums[j]<<"--"<<j<<"--"<<nums.size()<<endl;
					nums.erase(nums.begin() + j);
					j--;
				}else if(nums[j] > nums[i]){
					break;
				}
			}
		}
//		 for (unsigned i=0; i<nums.size(); ++i){
//		    std::cout << ' ' << nums[i];
//		 }
//		 cout<<endl;
//		 cout<<"size"<<nums.size()<<endl;
		return nums.size();
	}
};

//int main(){
//	Solution * s= new Solution();
//	 std::vector<int> myvector;
////	for (int i=1; i<=10; i++) {myvector.push_back(i);myvector.push_back(i);}
//	myvector.insert(myvector.begin(),1);
//	myvector.insert(myvector.begin(),1);
//	myvector.insert(myvector.begin(),1);
//	cout<<s->removeDuplicates(myvector)<<endl;
//	return 0;
//}
