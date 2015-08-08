/*
 * LeetCode005.cpp
 *
 *  Created on: 2015年8月4日
 *      Author: juanecho
 */

#include "leetcode.h"

class Solution {
	/*
	  题意是n=1时输出字符串1；n=2时，数上次字符串中的数值个数，因为上次字符串有1个1，所以输出11；n=3时，
	  由于上次字符是11，有2个1，所以输出21；n=4时，由于上次字符串是21，有1个2和1个1，所以输出1211。
	  依次类推，写个countAndSay(n)函数返回字符串。
	 */
public:
	string count(string str)
	{
		string s = "";
		int i = 0;
		int len = str.length();
		for(i = 0; i < len; i++){
			if(str[i] == s[s.length() -1])
						s[s.length() - 2] += 1;
			else{
						s+= 1+'0';
						s+= str[i];
			}
		}

		return s;
	}
	string countAndSay(int n){
		if(n == 1) return "1";
		return count(countAndSay(n-1));
	 }
};

//int main(){
//	Solution * s= new Solution();
//	for(int i = 1; i < 10; i++)
//		cout<<s->countAndSay(i)<<endl;
//	return 0;
//}
