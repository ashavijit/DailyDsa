#include<bits/stdc++.h>
using namespace std;


class FenwickTree{
    public:
        FenwickTree(int n) : sums(n + 1, 0) {}
        void update(int i , int del){
            while(i<sums.size()){
                sums[i]+= del;
                i+=lowbit(i);
            }
        }

        int query(int i){
            int sum =0 ;
            while(i > 0){
                sum += sums[i];
                i-=lowbit(i);
            }
            return sum;
        }
    private:
        vector<int>sums;
        static inline int lowbit(int x){
            return x & (-x);
        }

};
class Solution
{
public:
    vector<int> countSmaller(vector<int> &nums)
    {
        vector<int>sorted_nums(nums);
        int n = sorted_nums.size();
        sort(sorted_nums.begin(),sorted_nums.end());
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[sorted_nums[i]] = i;
        }
       FenwickTree Fn(n);
       vector<int>res;

       for(int i=nums.size() -1 ;i>=0;i--){
        res.push_back(Fn.query(mp[nums[i]]));
        Fn.update(mp[nums[i]]+1,1);  //  1 is added because we are using 1 based indexing in fenwick tree

       }
    reverse(res.begin(),res.end());
    return res;
    }
};

// int main(){
//     int n;
//     cin>>n;
//     vector<int>arr(n);
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     Solution s;
//     vector<int>res = s.countSmaller(arr);
//     for(int i=0;i<res.size();i++){
//         cout<<res[i]<<" ";
//     }
//     cout<<endl;
// }

int main(){
    Solution s;
    vector<int>nums = {1,3,2,3,1};
    vector<int>res = s.countSmaller(nums);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
}

