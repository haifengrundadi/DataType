#include "leetcode.h"

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
    	int len = digits.size();
    	int flag = 1;
    	while(len >0){
    		if(digits[len -1] + flag == 10){
    			flag = 1;
    			digits[len -1] = 0;
    		}else{
    			digits[len - 1] = digits[len - 1] +  flag;
    			flag = 0;
    		}
    		len--;
    	}
    	if(flag){
    		digits.insert(digits.begin(),1);
    	}
    	return digits;
    }
};

//int main(){
//	Solution *s = new Solution();
//	vector<int> v,v1;
//	for(int i =9; i >= 1; i--){
//		v.push_back(i);
//		cout<<char(i+'0');
//	}
//	cout<<endl;
//	v1 = s->plusOne(v);
//	for(int i =0; i < 9; i++){
//			cout<<char(v1[i] + '0');
//		}
//	return 0;
//}
