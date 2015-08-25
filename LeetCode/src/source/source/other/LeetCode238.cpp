/*
 * LeetCode005.cpp
 *
 *  Created on: 2015年8月4日
 *      Author: juanecho
 */

#include "leetcode.h"
#include <sstream>

class Solution {
	/*
	   Given a sorted integer array without duplicates, return the summary of its ranges.
		For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
	 */
public:
	vector<string> summaryRanges(vector<int>& nums) {
		vector<string> strArray;
		if(nums.size() <= 0)
			return strArray;
		int begin = nums[0], end =  nums[0];
		vector<int>::iterator it;
		for(it = nums.begin();it!= nums.end();it++){
			if(*it != end && (end -begin) >= 2){
				strArray.push_back(to_string(begin)+"->"+to_string(end-1));
				begin = end = *it;
			}else if(*it != end ){
				strArray.push_back(to_string(begin));
				begin = end = *it;
			}
			end++;
		}
		if(nums.back() == begin){
			strArray.push_back(to_string(begin));
		}else if(nums.back() != begin){
			strArray.push_back(to_string(begin)+"->"+to_string(end-1));
		}
		return strArray;
	}

	string to_string(int i) {
	  string s;
	  stringstream ss(s);
	  ss << i;
	  return ss.str();
	}

	vector<int> create(int num[], int n){
		vector<int> s;
		for(int i = 0 ; i < n; i++)
			s.push_back(num[i]);
		return s;
	}
};

//int main(){
//	Solution * s= new Solution();
//	cout<<s->to_string(1)<<endl;
//	int num[] = {0,1,2,4,5,7,9,10,11,13,15};
//	vector<int> nums = s->create(num, sizeof(num)/sizeof(int));
//	cout<<s->summaryRanges(nums).size()<<endl;
//	return 0;
//}
