#include <bits/stdc++.h>
#include<vector>
using namespace std;


class FenwickTree{
    public:
    FenwickTree(int n): sums(n+1,0){};

    void update(int i , int del){
        while(i < sums.size()){
            sums[i] += del;
            i += lowbit(i); // this means we are going to the child node
        }
    }

    int query(int i){
        int sum = 0;
        while(i > 0){
            sum += sums[i];
            i -= lowbit(i); // this means we are going to the parent node 
        }
        return sum;
    }
    private:
        vector<int>sums;
        static inline int lowbit(int x){
            return x & (-x); // x & (-x) will get the last 1 in the binary representation of x
        }   
};

class Solution
{
public:
    int reversePairs(vector<int> &nums)
    {
        int n = nums.size();
        if(!n) return 0;
        vector<long>temp;
        for(long num : nums){
            temp.push_back(2*num);
        }
        set<long>sorted;
        sorted.insert(nums.begin() , nums.end());
        sorted.insert(temp.begin(),temp.end());


        int rank=0;
        unordered_map<long,int>ranks; 

        for (long num : sorted){
            ranks[num] = ++rank;
        }

        FenwickTree Fn(ranks.size());

        int ans = 0;
        int k = temp.size();
        for(int i = static_cast<int>(k)-1; i>=0;i--){ // loop from the end to the start  to avoid the duplicate
            ans+=Fn.query(ranks[temp[i] / 2] -1); // query the number of elements that are smaller than temp[i]/2
            Fn.update(ranks[temp[i]],1); // update the number of elements that are smaller than temp[i]
        }
        return ans;
    }
};


int main(){
    Solution s;
    vector<int>nums = {1,3,2,3,1};
    cout<<s.reversePairs(nums)<<endl;
    return 0;
}

/*
    8 ->> 1000  parent node is 0  flip the last 1 to 0 in c++ we can use x & (-x) to get the last 1
    9->> 1001  parent node is 8  flip the last 1 to 0 in c++ we can use x & (-x) to get the last 1
*/

