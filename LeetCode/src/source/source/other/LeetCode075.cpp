#include "leetcode.h"

class Solution {
public:
	void sortColors(vector<int>& nums) {
		int tem = 0;
		int size = nums.size();
		if (size <= 1)return;
		int front = nums[0], j = 1, end = nums[size - 1];
		bool flag = false;
		for (int i = 0; i < size; i++) {
			front = nums[i];
			if (!flag) {
				if (size - j <= i) {
					j = 1;
					end = nums[size - 1];
					flag = true;
					i--;
					continue;
				}
				if (front != 0) {
					while (end && j < size) {
						j++;
						end = nums[size - j];
					}
					if (size - j <= i) {
						j = 1;
						end = nums[size - 1];
						flag = true;
						i--;
						continue;
					}
					tem = end;
					nums[size - j] = nums[i];
					nums[i] = tem;
					j++;
					end = nums[size - j];
				}
			} else {
				if (front == 2) {
					if (size - j <= i) {
						return;
					}
					while (end != 1&& j < size) {
						j++;
						if (size - j <= i) {
							return;
						}
						end = nums[size - j];
					}
					tem = end;
					nums[size - j] = nums[i];
					nums[i] = tem;
					j++;
					end = nums[size - j];
				}
			}
		}
	}
};
//
//int main() {
//	Solution * s = new Solution();
//	vector<int> nums;
//	int arr[] = {1,0,0};
//	for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
//		nums.push_back(arr[i]);
//	}
//	s->sortColors(nums);
//	return 0;
//}
