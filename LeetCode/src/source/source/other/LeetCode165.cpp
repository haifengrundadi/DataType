///*
// * LeetCode168.cpp
// *
// *  Created on: 2015年8月4日
// *      Author: juanecho
// */
//#include<stdlib.h>
//#include "leetcode.h"
//
//
//class Solution {
//public:
//	 int compareVersion(string version1, string version2) {
//		 	int indexA = version1.find_first_of('.',0);
//		 	int indexB= version2.find_first_of('.',0);
////		 	cout<<indexA<<"***"<<indexB<<endl;
//		 	string strA,strAA,strB,strBB;
//		 	if(indexA == -1){
//		 		strA=version1;
//		 		strAA = " ";
//		 	}else{
//		 		 strA( version1.substr(0,indexA));
//		 	     strAA( version1.substr(indexA+1));
//		 	}
//		 	if(indexB == -1){
//		 		strA( version2);
//		 		strAA(" ");
//		 	}else{
//		 		strB(version2.substr(0,indexB));
//		 		strBB(version2.substr(indexB+1));
//		 	}
//			int len_a = strA.length();
//			int len_b = strB.length();
////			cout<<strA<<"--"<<strAA<<endl;
////			cout<<"---"<<strB<<"----*"<<strBB<<endl;
//			int strA_i = atoi(strA.c_str());
//			int strB_i = atoi(strB.c_str());
//			cout<<strA_i<<"&&&&"<<strB_i<<endl;
//			if(len_b - len_a == 0){
//				if(strA_i > strB_i) return 1;
//				if(strA_i < strB_i) return -1;
//			}else{
//				return  len_b - len_a;
//			}
//			if(indexA == -1 && indexB == -1) return 0;
//			if(indexA == -1)
//			{
//					int i = 0;
//					while(i < strBB.length()){
//						if(strBB[i] != '0' && strBB[i] != '.')
//							return 1;
//						i++;
//					}
//					return 0;
//			}
//			if(indexB == -1)
//				{
//				int i = 0;
//				while(i < strAA.length()){
//					cout<<"***"<<strAA[i]<<endl;
//					if(strAA[i] != '0' && strAA[i] != '.')
//						return 1;
//					i++;
//				}
//				return 0;
//				}
//			if(strA_i == strB_i ){
//				cout<<"****"<<endl;
//				return compareVersion(strAA,strBB);
////				int i = 0;
////				int len_a =strAA.length();
////				int len_b = strBB.length();
////				if(len_a == len_b){
////					while(i < len_a && i < len_b){
//////						cout<<strAA[i]<<"-----"<<strBB[i]<<endl;
////						if(strAA[i] > strBB[i]) return 1;
////						if(strAA[i] < strBB[i]) return -1;
////						i++;
////					}
////				}
////				if(len_b< len_a){
////					return 1;
////				}
////				if(len_a < len_b)
////					return -1;
//			}
//			return 0;
//	}
//};
////int main(){
////	Solution * s= new Solution();
////	string stra = "1.1";
////	string strb = "1.01";
////	cout<<s->compareVersion(stra,strb);
////	return 0;
////}
