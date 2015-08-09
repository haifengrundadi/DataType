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
				strArray.push_back(int2str(begin)+"->"+int2str(end-1));
//				cout<<int2str(begin)+"->"+int2str(end-1)<<endl;
				begin = end = *it;
			}else if(*it != end ){
				strArray.push_back(int2str(begin));
//				cout<<int2str(begin)<<endl;
				begin = end = *it;
			}
			end++;
		}
		if(nums.back() == begin){
			strArray.push_back(int2str(begin));
//			cout<<int2str(begin)<<endl;
		}else if(nums.back() != begin){
			strArray.push_back(int2str(begin)+"->"+int2str(end-1));
//			cout<<int2str(begin)+"->"+int2str(end-1)<<endl;
		}
		return strArray;
	}

	string int2str(int i) {
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
//	cout<<s->int2str(1)<<endl;
//	int num[] = {0,1,2,4,5,7,9,10,11,13,15};
//	vector<int> nums = s->create(num, 11);
//	cout<<s->summaryRanges(nums).size()<<endl;
//	return 0;
//}
