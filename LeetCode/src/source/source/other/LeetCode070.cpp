#include "leetcode.h"
class Solution {
public:
	//递归不行，超时
//	 int climbStairs(int n) {
//		 if(n <= 2) return n;
//		 int x =  climbStairs(n -1);
//		 int y =  climbStairs(n-2);
//		 return x + y;
//	 }
//速度更慢的一种方法
//	 int climbStairs(int n) {
//	 		if(n <= 2)return n;
//	 		int count = 0;
//	 		int x = 0;
//	 		stack<int> s;
//	 		s.push(n);
//	 		while(!s.empty()){
//	 			x = s.top();
////	 			cout<<"x="<<x<<endl;
//	 			s.pop();
//	 			if(x == 1){count++;continue;}
//	 			s.push(x -1);
//	 			if(x == 2)
//	 				s.push(x - 1);
//	 			else
//	 				s.push(x -2);
//	 		}
//	 		return count;
//	}

	 int climbStairs(int n) {
			 if(n <= 2) return n;
			 int * nums = new int[n];
			 nums[0] = 1;
			 nums[1] = 2;
			 for(int i = 2;i < n; i++){
				 nums[i] = nums[i - 1]+nums[i -2];
			 }
			 return nums[n-1];
		 }
};

//int main(){
//	Solution * s= new Solution();
//	for(int i = 1; i < 44; i++)
//		cout<<s->climbStairs(i)<<endl;
//	return 0;
//}
