/*
 * LeetCode004.cpp
 *
 *  Created on: 2015年8月4日
 *      Author: juanecho
 */

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	        int len_nums1 = nums1.size();
	        int len_nums2 = nums2.size();
	        if(len_nums1 == 0 && len_nums2 == 0)
	        	return 0;
	        if(len_nums1 == 0){
	        	if(len_nums2 % 2 == 0)
	        		return ( nums2[len_nums2/2 -1] + nums2[len_nums2/2]) * 1.0/2;
	        	else
	        		return  nums2[len_nums2/2];
	        }
	        if(len_nums2 == 0){
	        	if(len_nums1 % 2 == 0)
	        	      return ( nums1[len_nums1/2 -1] + nums1[len_nums1/2]) * 1.0/2;
	        	else
	        	      return nums1[len_nums1/2];
	        }
	        int i = 0, j =0;
	        vector<int> nums3;
	        while(i < len_nums1 && j < len_nums2)
	        {
	        	if(nums1[i] <= nums2[j])
	        	{
	        		nums3.push_back(nums1[i]);
	        		i++;
	        	}else{
	        		nums3.push_back(nums2[j]);
	        	    j++;
	        	}
	        }
	        while(i == len_nums1 && j < len_nums2)
	        {
	        	nums3.push_back(nums2[j]);
	        	j++;
	        }
	        while(j == len_nums2 && i < len_nums1)
	       {
	        	nums3.push_back(nums1[i]);
	        	i++;
	        }
	        int len3 = nums3.size();
	        	if(len3 % 2 == 0)
	        	     return ( nums3[len3/2 -1] + nums3[len3/2]) * 1.0/2;
	        	 else
	        	      return nums3[len3/2];
	 }

	 vector<int> creat(int nums[],int n)
	{
		 int i  = 0;
		 vector<int> arr;
		 while(i < n)
		 {
			 arr.push_back(nums[i]);
			 i++;
		 }
		 return arr;
	}
};

/*int main()
{
	Solution * s= new Solution();
	int array1[] = {1,2,3};
	int array2[] = {1,2};
	  vector<int> nums3 = s->creat(array1,3);
	  vector<int> nums4 = s->creat(array2,2);
	cout<<s->findMedianSortedArrays(nums3,nums4)<<endl;
	return 0;
}*/
