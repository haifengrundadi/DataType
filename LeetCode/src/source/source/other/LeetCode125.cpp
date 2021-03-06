/*
 * LeetCode005.cpp
 *
 *  Created on: 2015年8月4日
 *      Author: juanecho
 */
#include "leetcode.h"

class Solution {
public:
//	bool isMyAlpha(char ch){
//		if((ch>='A' && ch <='Z') ||(ch>='a' && ch <='z'))
//			return true;
//		else
//			return false;
//	}
	bool isPalindrome(string s) {
		int len = s.length();
		int j = len -1;
		int i = 0;
//		cout<<"len ="<<len<<endl;
		while((!isalpha(s[i])&&!isdigit(s[i]))&& i < len){
					i++;
		}
		if(i == len) return true;
		while(i<=j){
//			cout<<s[i]<<"***"<<isalpha(s[i])<<endl;
			while(!isalpha(s[i])&&!isdigit(s[i])){
				i++;
			}
			while(!isalpha(s[j])&&!isdigit(s[j])){
				j--;
			}
			if((s[i] == s[j] || abs(s[i]-s[j])==32)){
//				cout<<i<<"\t"<<j<<"\t"<<s[i]<<"\t"<<s[j]<<endl;
				i++;
				j--;
			}else{
				return false;
			}
		}
		return true;
	 }
};

//int main()
//{
//	Solution * s= new Solution();
//	char ch ='2';
//	cout<<isdigit(ch)<<endl;
//	cout<<isalpha(',')<<endl;
//	fstream in;
//	char buffer[256];
//	in.open("src/source/source/in.txt",ios::in);
//	 if(in.is_open()){
//		while(!in.eof()){
//			in.getline(buffer,256);
//			cout<<buffer<<endl;
//			cout<<s->isPalindrome(buffer)<<endl;
//		}
//	}
//	return 0;
//}
