/*
 * LeetCode005.cpp
 *
 *  Created on: 2015年8月4日
 *      Author: juanecho
 */

#include"leetcode.h"
using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		int i = 0,flag = 1,sum = 2147483647;
		vector<int> v;
		int len = str.length();
		/*处理前面的空白符*/
		while(i < len && str[i] == ' ')
			i++;
		if(i >= len) return 0;
		/*处理第一个字符是-，+*/
		if(str[i] == '-') {
			flag  = -1;
			sum = -2147483648;
			i++;
		}else if(str[i]== '+'){
			flag = 1;
			i++;
		}
		if(i >= len) return 0;
		/*处理数字*/
		if(isdigit(str[i])){
			while(i < len && isdigit(str[i])){
				v.push_back(str[i] - '0');
				i++;
			}
			int j = 0;
			while(!v.empty()){
				if(flag == -1&& sum < 0){
					sum += v.back() * int(pow(10,j));
					v.pop_back();
					j++;
				}else if(flag == -1){
					return  -2147483648;
				}
				if(flag == 1&& sum > 0){
					sum -= v.back() * int(pow(10,j));
					v.pop_back();

					j++;
				}else if(flag == 1){
					return  2147483647;
				}
			}
		}else{
			return 0;
		}
		if(i > len) return 0;

		if(flag == 1){
			if(sum >= 0)
				return 2147483647 - sum;
			else
				return 2147483647 ;
		}else{
			if(sum <= 0)
				return -2147483648 - sum;
			else
				return -2147483648 ;
		}

    }
};

//int main(){
//	Solution * s= new Solution();
//	fstream in;
//		  char buffer[256];
//		  in.open("src/source/source/other/in.txt",ios::in);
//		  if(in.is_open())
//		  {
//			  while(!in.eof())
//			  {
//				  in.getline(buffer,256);
//				  cout<<s->myAtoi(buffer)<<endl;
//			  }
//		  }
//}
