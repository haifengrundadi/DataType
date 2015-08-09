/*
 * LeetCode0013.cpp
 *
 *  Created on: 2015年8月4日
 *      Author: juanecho
 */

#include "leetcode.h"
 /*
 * 基本字符
I  V    X  L    C    D  M
相应的阿拉伯数字表示为
1 5 10  50 100 500 1000
相同的数字连写、所表示的数等于这些数字相加得到的数、如：Ⅲ=3；
小的数字在大的数字的右边、所表示的数等于这些数字相加得到的数、 如：Ⅷ=8、Ⅻ=12；
小的数字、（限于 Ⅰ、X 和 C）在大的数字的左边、所表示的数等于大数减小数得到的数、如：Ⅳ=4、Ⅸ=9；
正常使用时、连写的数字重复不得超过三次。（表盘上的四点钟“IIII”例外）；
 *
 */
class Solution {
public:
	int charToInt(char ch){
		int sum = 0;
		switch(ch){
			case 'I':sum = 1; break;
			case 'V':sum = 5;break;
			case 'X':sum = 10;break;
			case 'L':sum = 50;break;
			case 'C':sum = 100;break;
			case 'D':sum = 500;break;
			case 'M':sum = 1000;break;
		}
		return sum;
	}

	int romanToInt(string s) {
		int len = s.length();
		int total = 0,lastv= 0,curv = 0,sum = 0;
		if(len == 0) return 0;
		lastv= curv = charToInt(s[0]);
		sum = curv;
//		cout<<0<<"---"<<s[0]<<"---"<<"curv--"<<curv<<endl;
		int i = 1;
		while(i < len){
			curv =  charToInt(s[i]);
//			cout<<i<<"---"<<s[i]<<"---"<<"curv--"<<curv<<"--sum--"<<sum<<endl;
			if(curv == lastv){
				sum += curv;
			}else if(curv > lastv){
				total +=  curv - sum;//一个数的终止
				lastv = curv;
				sum = 0;
			}else{
				total += sum;//一个连续数的终止 III
				sum = curv;
				lastv = curv;
			}
			i++;
//			total += sum;
//			cout<<total<<endl;
		}
		total += sum;
		return total;
	}
};

//int main()
//{
//	Solution * s = new Solution();
//	string str = "XXXIX";
//	cout<<s->romanToInt(str);
//	return 0;
//}
