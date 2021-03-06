/*
 * LeetCode168.cpp
 *
 *  Created on: 2015年8月4日
 *      Author: juanecho
 */
#include<stdlib.h>
#include "leetcode.h"


class Solution {
public:
	 int compareVersion(string version1, string version2) {
		    int i = 0;
		 	while(i < version1.length() && version1[i] == '0')i++;
		    if(version1[i] == '.'){

		 	}
		 	version1 = version1.substr(i);
		 	i = 0;
		 	while(i < version2.length() && version2[i] == '0')i++;
		 	version2 = version2.substr(i);

		 	int indexA = version1.find_first_of('.',0);
		 	int indexB = version2.find_first_of('.',0);
		 	string strA,strAA,strB,strBB;
		 	if(indexA == -1){
		 		strA=version1;
		 		strAA = "";
		 	}else{
		 		 strA = version1.substr(0,indexA);
		 	     strAA =version1.substr(indexA+1);
		 	}
		 	if(indexB == -1){
		 		strB = version2;
		 		strBB = "";
		 	}else{
		 		strB = version2.substr(0,indexB);
		 		strBB = version2.substr(indexB+1);
		 	}
//		 	cout<<"strAA = "<<strAA<<endl;
//		 	cout<<"strBB = "<<strBB<<endl;
			int len_a = strA.length();
			int len_b = strB.length();
			if(len_b - len_a == 0){
				if(strA.compare(strB) > 0) return 1;
				if(strA.compare(strB) < 0) return -1;
			}else{
				return  (len_b - len_a)>0?-1:1;
			}
			if(indexA == -1 && indexB == -1) return 0;
			if(indexA == -1&& indexB != -1){
				int m = 0;
				while(m < strBB.length()){
					if(strBB[m]=='0'){
						m++;
					}else if(strBB[m] == '.'){
						m++;
					}else{
						return -1;
					}
				}
				return 0;
			}else if(indexB == -1&& indexA != -1){
				int m = 0;
				while(m < strAA.length()){
						if(strAA[m]=='0'){
								m++;
						}else if(strAA[m] == '.'){
							m++;
						}else{
							return 1;
						}
					}
				return 0;
			}else{
					return compareVersion(strAA,strBB);
			}
			return 0;
	}
};
//int main(){
//	Solution * s= new Solution();
//	string stra = "1.1";
//	string strb = "1.01.0";
//	cout<<s->compareVersion(stra,strb)<<endl;
//	stra = "01";
//	strb = "1";
//	cout<<s->compareVersion(stra,strb)<<endl;
//	stra = "0.1";
//	strb = "1";
//	cout<<s->compareVersion(stra,strb)<<endl;
//	stra = "1.2";
//	strb = "1.10";
//	cout<<s->compareVersion(stra,strb)<<endl;
//	stra = "1.0";
//	strb = "1";
//	cout<<s->compareVersion(stra,strb)<<endl;
//	stra = "19.8.3.17.5.01.0.0.4.0.0.0.0.0.0.0.0.0.0.0.0.0.00.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000";
//	strb = "19.8.3.17.5.01.0.0.4.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0000.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000";
//	cout<<s->compareVersion(stra,strb)<<endl;
//	return 0;
//}
