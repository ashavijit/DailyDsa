#include<bits/stdc++.h>
using namespace std;


class FenwickTree {
    public:
        FenwickTree(int n) : sums(n+1,0) {}
        void update(int idx ,int val){
            while(idx<sums.size()){
                sums[idx]+=val;
                idx+=lowbit(idx); // this is child node index we can get parent node index by subtracting lowbit
            }
        }

        int query(int idx){
            int sum = 0;
            while(idx > 0){
                sum+=sums[idx];
                idx-=lowbit(idx); // this is parent node index 
            }
        }
    private:
    vector<int>sums;
    static inline int lowbit(int x){
        return x & (-x); // 2^k
    }
};

class Solution
{
public:
    vector<int> countSmaller(vector<int> &nums)
    {
        vector<int> sorted(nums);
        int n = sorted.size();
        sort(sorted.begin(),sorted.end());
        unordered_map<int,int> ranks;
        for(int i = 0;i<n;i++){
            ranks[sorted[i]] = i+1;  // assigning ranks to the sorted array
        }
        FenwickTree tree(n);
        vector<int> ans;
        for(int i = n-1;i>=0;i--){ // traversing from back
            int rank = ranks[nums[i]]; // getting rank of the number
            ans.push_back(tree.query(rank-1)); // query will give the sum of all the elements less than rank
            tree.update(rank,1); // updating the rank
        }
        reverse(ans.begin(),ans.end()); 
        return ans;
    }
};

/* Logic of this question
1. We will create a fenwick tree of size n
2. We will traverse the array from back and get the rank of the number from the sorted array
3. We will query the fenwick tree to get the sum of all the elements less than the rank
4. We will update the fenwick tree with the rank
5. We will reverse the answer and return it

*/