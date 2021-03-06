#include "leetcode.h"

class Solution {
public:
	 vector<vector<int> > threeSum(vector<int>& nums) {
			vector<vector<int> > v;
			int size = nums.size();
			map<int, int> m;
			int i = 0, j = size - 1, tem = 0, begin = 0, end = 0;
			vector<int> v_in;
			if (size <= 2)
				return v;
			sort(nums.begin(), nums.end());
			for (i = 0; i < size; i++) {
				if (m.find(nums[i]) == m.end())
					m.insert(pair<int, int>(nums[i], 1));
				else
					m.find(nums[i])->second += 1;
			}
			if (m.find(0) != m.end()) {
				if (m.find(0)->second >= 3) {
					v_in.push_back(0);
					v_in.push_back(0);
					v_in.push_back(0);
					v.push_back(v_in);
					v_in.clear();
				}
				m.find(0)->second = 1;
			}
			i = 0;
			int k = 0, s = 0;
			while (j) {
				k = 0;
				if(nums[j] <= 0) break;
				while(nums[k] + nums[j] < nums[j] * (-1)){
					k++;
				}
				s = j;
				while (k < s) {
					if (nums[k] >= 0 || nums[s] <= 0) break;
					tem = (nums[k] + nums[s]) * (-1);
					if( tem < nums[k] ) {break;}
					if (tem > nums[s])  {break;}
					if (m.find(tem) != m.end()) {
						if (m.find(tem)->second < 2&& (nums[s] == tem || nums[k] == tem)) {
							k++;
							continue;
						}
						v_in.push_back(nums[k]);
						v_in.push_back(tem);
						v_in.push_back(nums[s]);
						v.push_back(v_in);
						v_in.clear();
						//会减两次
						if (m.find(nums[s])->second >= 2 && nums[s -1] == nums[s]) {
							s = s - m.find(nums[s])->second + 1;
	//						cout << s << "___" << endl;
							j = s;
						}
						if (m.find(nums[k])->second >= 2) {
							k = k + m.find(nums[k])->second - 1;
	//						cout << "___" << k << endl;
						}
					}
					k++;
				}
				j--;
			}
			return v;
		}
};

//int main() {
////	Solution *s = new Solution();
////	vector<vector<int> > v;
////	vector<int> nums;
//////	int arr[] = {-4,-4,-3,-2,-2,-1,-1,0,0,0,0,1,2,2,4,5,10};
//////	int arr[] = {-2,0,0,2,2};{-4,-1,-1,0,1,2};{-1,1,0};{1,2,-2,-1};
////	int arr[] = {-4,-4,-3,-2,-2,-1,-1,0,0,0,0,1,2,2,4,5,10};
////	for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
////		nums.push_back(arr[i]);
////	}
////	v = s->threeSum(nums);
//////	cout<<endl;
////	int size = v.size();
////	vector<int>::iterator it;
////	for (int i = 0; i < size; i++) {
////		for (int j = 0; j < v[i].size(); j++) {
////			cout << v[i][j] << "\t";
////		}
////		cout << endl;
////	}
//}

