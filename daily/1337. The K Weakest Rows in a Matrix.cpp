#include<bits/stdc++.h>
using namespace std;



typedef pair<int,int> pii;
#define vi vector<int>
#define fr(i,a,b) for(int i=a;i<b;i++)
#define binarySearch(arr, l, r, x) while (l <= r) { int m = l + (r - l) / 2; if (arr[m] == x) return m; if (arr[m] < x) l = m + 1; else r = m - 1; } return -1;


class Solution
{
public:
    int bs(vi m){
        int l=0,h=m.size()-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(m[mid] == 0){
                h=mid-1;
            } else {
                l=mid+1;
            }
        }
        return l;
    }
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        priority_queue<pii> pq;
        vi(ans);
        fr(i,0,mat.size()){
            pq.push({bs(mat[i]),i}); 
            if(pq.size()>k){ 
                pq.pop();
            }
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end()); 
        return ans;
    }
};