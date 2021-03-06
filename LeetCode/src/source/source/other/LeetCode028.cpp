/*
 * LeetCode005.cpp
 *
 *  Created on: 2015年8月4日
 *      Author: juanecho
 */

#include "leetcode.h"

class Solution {
public:
	int strStr(string haystack, string needle) {
		int j = 0;
		int len_h = haystack.length();
		int len_n = needle.length();
		if(len_n == 0) return 0;
		if(len_n > len_h) return -1;
		int index = haystack.find_first_of(needle[0]);
		if(index != -1){
			if(len_h - index >= len_n){
				for(int i = index; i < len_h; i++){
					i = index;
					while(j <len_n && i < len_h){
						if(haystack[i] != needle[j]){
							break;
						}
						i++,j++;
					}
					if(j == len_n) return index;
					index = haystack.find_first_of(needle[0],index+1);
					if(index == -1) return index;
					if(len_h - index < len_n){
						return -1;
					}
					j = 0;
				}
			}else{
				return -1;
			}
		}
		return index;
	}
};

//int main(){
//	Solution * s= new Solution();
//	string a = "abcd";
//	string b = "f";
//	cout<<s->strStr(a,b)<<endl;
//	a="mississippi";
//	b= "issip";
//	cout<<s->strStr(a,b)<<endl;
//	a ="aaabb";
//	b = "baba";
//		cout<<s->strStr(a,b)<<endl;
//	return 0;
//}
