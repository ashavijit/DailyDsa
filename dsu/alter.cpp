#include<bits/stdc++.h>
using namespace std;
/* Intution Behind This algorithm :

we are creating a graph of prime factors of each number and then we are checking if all the numbers are connected or not.
DSU is used to check if all the numbers are connected or not.

is to determine if for every pair of indices i and j in nums, where i < j, there exists a sequence of traversals that can take us from i to j.

ex : 2 3 4 5 6 7 8 9 10
graph :
2 -> 2
3 -> 3
4 -> 2 2
5 -> 5
6 -> 2 3
7 -> 7
8 -> 2 2 2
9 -> 3 3
10 -> 2 5

we can see that 2,3,5,7 are not connected to any other number so we can't traverse all the pairs.

hence we will use DSU to check if all the numbers are connected or not.

Leetcode Example :
Input: nums = [2,3,6]

graph :
2 -> 2
3 -> 3
6 -> 2 3

we can see that 2 and 3 are connected so we can traverse all the pairs.

we will return true in this case.



*/

class Solution {
    int N;
    vector<int> pf;
    vector<int> parent;
    vector<int> rank;
    
    void build() {
        for(long i = 2; i <= N; i++) {
            if(pf[i]) continue;
            pf[i] = i;
            for(long j = i*i; j <= N; j += i) {
                if(pf[j] == 0)
                    pf[j] = i;
            }
        }
    }
    
    int find(int a) {
        if(parent[a] == a) {
            return a;
        }
        return parent[a] = find(parent[a]);
    }
    
    void unite(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        if(rootA == rootB) {
            return;
        }
        if(rank[rootA] < rank[rootB]) {
            parent[rootA] = rootB;
        } else {
            if(rank[rootA] == rank[rootB]) {
                rank[rootA]++;
            }
            parent[rootB] = rootA;
        }
    }
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        if(nums.size() == 1) {
            return true;
        }
        N = *max_element(nums.begin(), nums.end());
        pf.resize(N + 1);
        build();
        for(int i = 0; i <= N; i++) {
            rank.push_back(1);
            parent.push_back(i);
        }
        for(int num : nums) {
            if(num == 1) {
                return false;
            }
            int temp = num;
            while(num > 1) {
                int p = pf[num];
                while(num % p == 0) {
                    num /= p;
                }
                unite(temp, p);
            }
        }
        unordered_set<int> s;
        for(int num : nums) {
            s.insert(find(num));
            if(s.size() > 1) return false;
        }
        return true;
    }
};


// Time complxity : o(sqrt(n) * log(n))