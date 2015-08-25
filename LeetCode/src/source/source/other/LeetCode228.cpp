/**
 * Product of Array Except Self
 */
#include "leetcode.h"

/**
 * 思路：两个pass，第一个pass
 */
class Solution {
public:
	 vector<int> productExceptSelf(vector<int>& nums) {
		 int size = nums.size();
		 vector<int> v(size,1);
		 if(size == 1) {
			 v[0] = nums[0];
			 return v;
		 }
		for(int i = 1; i < size; i++){
			v[i] = nums[i-1] * v[i-1];
		}
		for(int j= size -1, tem = 1; j >= 0; tem *= nums[j--]){
			v[j] *= tem;
		}
		return v;
	 }
};
//
//int main(){
//	Solution * s= new Solution();
//	vector<int> v,ve;
//	int nums[] = {5};
//	for( int i =0; i < sizeof(nums) / sizeof(int); i++){
//		v.push_back(nums[i]);
//	}
//	ve = s->productExceptSelf(v);
//	for(int i=0; i < ve.size(); i++){
//		cout<<ve[i]<<"\t";
//	}
//	cout<<endl;
//	return 0;
//}
