/*
 * @Author: 武家豪&&2572348815@qq.com
 * @Date: 2022-09-25 19:00:17
 * @LastEditors: wujiahao 2572348815@qq.com
 * @LastEditTime: 2022-09-26 22:16:32
 * @FilePath: \MyAlgorithmDaily\leetcode\lk4hard.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by wujiahao 2572348815@qq.com, All Rights Reserved. 
 */
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()==0){
            double res;
            res = (nums2[(nums2.size()+1)/2-1] + nums2[(nums2.size()+2)/2-1])/2.0;
            return res;
        }
		if(nums1.size() > nums2.size()){
            return findMedianSortedArrays(nums2,nums1);
        }
        
        int size1 = nums1.size();
        int size2 = nums2.size();
        int index1 = (size1 + size2 + 1)/2;
        int L = 0;
        int R = size1 - 1;
        int res1,res2;
        double res = 0.0;
        while(L <= R){
            int mid1 = (R + L)/2;
            int mid2 = index1 - mid1 - 2;
			if(mid1==-1){
				if((size1+size2)%2==0){
					res1 = nums2[mid2];
					res2 = nums1[0];
					res = ((res1 + res2)*1.0)/2;
				}else{
					res = nums2[mid2];
				}
				return res;
			}else if(mid2==-1){
				if((size1+size2)%2==0){
					res1 = nums1[mid1];
					res2 = nums2[0];
					res = ((res1 + res2)*1.0)/2;
				}else{
					res = nums1[mid1];
				}
				return res;
			}else if((mid1+1 > size1-1)&&(nums1[mid1] < nums2[mid2+1])){
				if((size1+size2)%2==0){
					res1 = max(nums1[mid1],nums2[mid2]);
					res2 = nums2[mid2+1];
					res = ((res1 + res2)*1.0)/2;
				
				}else{
					res1 = max(nums1[mid1],nums2[mid2]);
                    res = res1;
				}
				return res;
			}else if((mid2+1 > size2-1)&&(nums2[mid2] < nums1[mid1+1])){
				if((size1+size2)%2==0){
					res1 = max(nums1[mid1],nums2[mid2]);
					res2 = nums1[mid1+1];
					res = ((res1 + res2)*1.0)/2;
				}else{
					res1 = max(nums1[mid1],nums2[mid2]);
                    res = res1;
				}
				return res;
			}else if((nums1[mid1] <= nums2[mid2+1]) && (nums2[mid2] <= nums1[mid1+1])){
                if((size1+size2)%2==0){
                    res1 = max(nums1[mid1],nums2[mid2]);
                    res2 = min(nums1[mid1+1],nums2[mid2+1]);
                    res = ((res1 + res2)*1.0)/2;
                }else{
                    res1 = max(nums1[mid1],nums2[mid2]);
                    res = res1;
                }
                return res;
            }else if(nums1[mid1] > nums2[mid2+1]){
                R = mid1 - 1;
                if(R == -1){
					if((size1+size2)%2==0){
                        if(mid2+2<size2){
                            res1 = min(nums1[mid1],nums2[mid2+2]);
                        }else{
                            res1 = nums1[mid1];
                        }
		
						res2 = nums2[mid2+1];
						res = ((res1 + res2)*1.0)/2;
					}else{
						res = nums2[mid2+1];
					}
				}
            }else{
                L = mid1 + 1;
            }
        }
	return res;
	}
	
};
