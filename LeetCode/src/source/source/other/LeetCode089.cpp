#include "leetcode.h"

class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> v;
		v.push_back(0);
		if(n == 0) return v;
		v.push_back(1);
		int tem = 0,size = 0, j= 0;
		for(int i =2; i <= n; i++){
			size = v.size();
			j = size;
			tem = pow(2, i-1);
			while(j){
				v.push_back(tem + v[j -1]);
				j--;
			}
		}
		return v;
	 }
};

//int main()
//{
//	Solution * s = new Solution();
//	vector<int> nums;
//	nums = s->grayCode(0);
//	vector<int>::iterator it;
//	for(it = nums.begin(); it != nums.end();it++){
//		cout<<*it<<"\t";
//	}
//	cout<<endl;
//	return 0;
//}
