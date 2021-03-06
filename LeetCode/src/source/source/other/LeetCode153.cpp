#include "leetcode.h"

class Solution {
public:
	int findMin(vector<int>& nums) {
		int size = nums.size();
		if(size == 0) return 0;
		int min = nums[0];
		for(int i = 0; i < size; i++){
			if(nums[i] < min){
				min = nums[i];
				break;
			}
		}
		return min;
	}
};

//int main() {
//	Solution *s = new Solution();
//	vector<int> nums;
//	int arr[] = { 1};
//	for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
//		nums.push_back(arr[i]);
//	}
//	cout << s->findMin(nums);
//	return 0;
//}
