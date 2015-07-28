#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
    	//通过异或操作
    	if (nums.size() == 0)
    		return 0;
    	int result = nums[0];
    	vector<int>::iterator it;
    	for(it=nums.begin()+1;it!=nums.end();it++)
    		result = *it ^ result;
    	return result;
    }
    /*
     * 1 基本操作
	(1)头文件#include<vector>.
	(2)创建vector对象，vector<int> vec;
	(3)尾部插入数字：vec.push_back(a);
	(4)使用下标访问元素，cout<<vec[0]<<endl;记住下标是从0开始的。
	(5)使用迭代器访问元素.
	vector<int>::iterator it;
	for(it=vec.begin();it!=vec.end();it++)
		cout<<*it<<endl;
	(6)插入元素：    vec.insert(vec.begin()+i,a);在第i+1个元素前面插入a;
	(7)删除元素：    vec.erase(vec.begin()+2);删除第3个元素
	vec.erase(vec.begin()+i,vec.end()+j);删除区间[i,j-1];区间从0开始
	(8)向量大小:vec.size();
	(9)清空:vec.clear();
     */
};
