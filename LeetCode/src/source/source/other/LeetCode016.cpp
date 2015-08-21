#include "leetcode.h"

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int size = nums.size();
		if (size <= 2) return 0;
		int i = 0, j = size - 1, tem = 0;
		sort(nums.begin(), nums.end());
		map<int, int> m;
		for (i = 0; i < size; i++) {
			if (m.find(nums[i]) == m.end())
				m.insert(pair<int, int>(nums[i], 1));
			else
				m.find(nums[i])->second += 1;
		}
		i = 0;
		int k = 0, s = 0,sum = target-( nums[0] + nums[j]);
		while (j) {
			k  = 0; s  = j;
			while (k < s) {
				tem = target - (nums[k] + nums[s]);
				cout<<"k="<<k<<"\ts="<<s<<"\tnums[k]="<<nums[k]<<"\tnums[s]="<<nums[s]<<"\ttem="<<tem<<"\tsum="<<sum;
				if(m.find(tem) != m.end() ){
////					if((tem == nums[s] || tem == nums[k]) && m.find(tem)->second < 2){
////						k++;
////						cout<<"\tfind but only occur once"<<endl;
////						continue;
////					}
//					tem = target - tem * (-1) ;
					sum = abs(tem)>abs(sum)?sum:tem;
					cout<<"\tfind"<<endl;
				}else{
					cout<< "\tnot find"<<endl;
				}
				k++;
				cout<<endl;
			}
			j--;
		}
		return sum;
	}
};

//int main() {
//	Solution *s = new Solution();
//	vector<int> nums;
////	int arr[] = {-4,-4,-3,-2,-2,-1,-1,0,0,0,0,1,2,2,4,5,10};
////	int arr[] = {-2,0,0,2,2};{-4,-1,-1,0,1,2};{-1,1,0};{1,2,-2,-1};
//	int arr[] = {-2,0,2,4};
//	for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
//		nums.push_back(arr[i]);
//	}
//	cout<< s->threeSumClosest(nums,1);
//}
