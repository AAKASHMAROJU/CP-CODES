// Problem Link: https://leetcode.com/problems/find-the-duplicate-number/

// Not the most Optimized 
#include<bits/stdc++.h>
using namespace std;
class Solution {
    bool isDuplicate(int num, vector<int>& nums, int n){
        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]<=num){
                cnt++;
            }
            if(cnt>num) return true;
        }
        return false;
    }
    
    
    
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int low=1;
        int high=n-1;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(isDuplicate(mid, nums, n)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};