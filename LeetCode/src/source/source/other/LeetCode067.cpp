#include "leetcode.h"

class Solution {
public:
	 string addBinary(string a, string b) {
		 int len_a = a.length();
		 int len_b = b.length();
		 int flag = 0;
		 string str="";
		 string str1="";
		 int min = len_a <= len_b?len_a:len_b;
		 int d = abs(len_a - len_b);
		 if(min == len_a){
			 while(min>0){
				 if((a[min-1] == '1' && b[min-1+ d]=='1') || (a[min-1] == '1' && flag ==1) || (b[min-1+d] == '1' && flag ==1)){
					 str +=( a[min-1] - '0' + b[min-1+d]  +flag )== '2'?'0':'1';
					 flag = 1;
				 }else{
					 str += a[min-1] - '0' + b[min-1+d]  +flag;
					 flag = 0;
				 }
				 min--;
			 }
			 while(d>0){
			 			if(b[d-1] == '1' && flag == 1){
			 				str+='0';
			 				flag = 1;
			 			}else{
			 				str+=b[d-1]+flag;
			 				flag = 0;
			 			}
			 			d--;
			 		}
		 }else{
			 while(min>0){
							 if((a[min-1+d] == '1' && b[min-1]=='1') || (a[min-1+d] == '1' && flag ==1) || (b[min-1] == '1' && flag ==1)){
								 str += ( a[min-1+d] - '0' + b[min-1]  +flag )== '2'?'0':'1';
								 flag = 1;
							 }else{
								 str += a[min-1+d] - '0' + b[min-1]  +flag;
								 flag = 0;
							 }
							 min--;
						 }
						 while(d>0){
						 			if(a[d-1] == '1' && flag == 1){
						 				str+='0';
						 				flag = 1;
						 			}else{
						 				str+=a[d-1]+flag;
						 				flag = 0;
						 			}
						 			d--;
						 		}

		 }
		 if(flag == 1) str +='1';
		 int len = str.length();
		 while(len > 0){
			 str1+= str[len -1];
			 len--;
		 }
		 return str1;
	  }
};
