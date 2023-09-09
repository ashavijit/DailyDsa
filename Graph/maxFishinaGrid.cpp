#include<Trees/header.h>

class Solution
{
public:
    bool check(int row, int col, int n, int m)
    {
        if (row >= 0 && row < n && col >= 0 && col < m)
        {
            return true;
        }
        return false;
    }
    int dfs(vector<vector<int>> &grid, int row, int col)
    {
        int n = grid.size();
        int m = grid[0].size();
        int curr_fish = grid[row][col];
        grid[row][col]=0;
        if (!check(row, col, n, m) || grid[row][col] == 0)
        {
            return 0;
        }
        int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for(int i=0;i<4;i++){
            int newR = row+dir[0][i];
            int newC = col+dir[i][1];
            curr_fish+=dfs(grid,newR,newC);
        }
        return curr_fish;
    }
    int findMaxFish(vector<vector<int>> &grid)
    {
        int max_fish = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] > 0){
                   int curr_fish_now = dfs(grid,i,j);
                    max_fish=max(curr_fish_now,max_fish);
                }
            }
        }
        return max_fish;
    }
};