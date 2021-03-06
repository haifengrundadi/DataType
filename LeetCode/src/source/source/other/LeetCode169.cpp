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
	int majorityElement(vector<int>& nums) {
	      map<int, int> m;
	      int len = nums.size();
	      if(len == 1) return nums[0];
	      while(len){
	    	  map<int, int>::iterator it;
	    	 	      for(it = m.begin(); it != m.end(); it++){
	    	 	    	  cout<<it->first<<"\t\t"<<it->second<<endl;
	    	 	      }
	    	  if(m.find(nums[len -1]) == m.end()){
	    		  m.insert(pair<int,int>(nums[len -1], 1));
	    	  }else{
	    		  if(m.find(nums[len - 1])->second+1 > nums.size()/2)
	    			  return m.find(nums[len -1])->first;
	    		   m.find(nums[len - 1])->second += 1;
	    	  }
	    	  len--;
	      }

	      return 0;
	}
};

//int main(){
//	Solution * s= new Solution();
//		vector<int> nums;
////		for(int i = 0; i< 3; i++)
////		{
////			nums.push_back(i);
////		}
//		nums.push_back(2);
//		nums.push_back(2);
//		nums.push_back(1);
//		nums.push_back(1);
//		nums.push_back(1);
//		nums.push_back(2);
//		nums.push_back(2);
//		cout<<s->majorityElement(nums)<<endl;
//	return 0;
//}
