#include "leetcode.h"

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
		int size = nums.size();
		int max =  nums[0], tem = 0;
		for(int i = 0; i < size; i++){
			tem += nums[i];
			if(tem >= max){
				max = tem;
			}
			if(tem < 0){
				tem = 0;
			}
		}
		return max;
    }
};

//int main()
//{
//	Solution * s = new Solution();
//	 vector<int> nums;
//		int arr[] = {-2,1};
//		for(int i =0; i < sizeof(arr)/ sizeof(int); i++){
//			nums.push_back(arr[i]);
//		}
//		cout<<s->maxSubArray(nums)<<endl;
//}
