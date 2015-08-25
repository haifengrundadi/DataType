#include "leetcode.h"

class Solution {
public:
    int lengthOfLastWord(string s) {
    	int len = s.length();
    	int lenLast = 0;
    	while(s[len-1] == ' '){
        			len--;
        }
    	while(len){
    		if(isalpha(s[len-1])){
    			lenLast++;
    		}else if(s[len-1] == ' '){
    			break;
    		}else {
    			return 0;
    		}
    		len--;
    	}
    	return lenLast;
    }
};
