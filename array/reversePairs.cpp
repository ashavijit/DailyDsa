#include<header.h>

class Solution
{
private:
    int cnt = 0;
    void checK(vector<int> &nums,int start,int mid,int end){
        int l = start;
        int r = mid+1;
        while((long)l<=r && (long)r<= end){
            if (nums[l] > 2* nums[r]){
                cnt+=(mid-l+1);
                r++;
            } else {
                l++;
            }
        }
        sort(nums.begin()+start,nums.end()+end+1);
        return;
    }
    void mergeSort(vector<int> &nums , int start , int end){
        if( start == end ) return;
        int mid = (start+end) /2;
        mergeSort(nums,start,mid);
        mergeSort(nums,mid+1,end);
        checK(nums,start,mid,end);
        return;
    }
public:
    int reversePairs(vector<int> &nums)
    {
        int n = nums.size();
        if(!n) return 0;
        cnt=0;
        mergeSort(nums,0,n-1);
        return cnt;
    }
};