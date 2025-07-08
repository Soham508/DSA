/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
*/

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    
    void dfs(vector<vector<char>>& grid, int i, int j) {
        int n = grid.size();
        int m = grid[0].size();

        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == '0')
            return;

        grid[i][j] = '0'; 

        dfs(grid, i+1, j); 
        dfs(grid, i-1, j); 
        dfs(grid, i, j+1); 
        dfs(grid, i, j-1); 
    }

     int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    count++;       
                }
            }
        }
        return count;
    }
};

#include <vector>
#include <queue>
using namespace std;

// BFS version

class Solution {
public:
    void bfs(vector<vector<char>>& grid, int x, int y) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        q.push({x, y});
        grid[x][y] = '0'; // mark visited

        // directions: up, down, left, right
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            for (int d = 0; d < 4; ++d) {
                int ni = i + dx[d];
                int nj = j + dy[d];

                if (ni >= 0 && nj >= 0 && ni < n && nj < m && grid[ni][nj] == '1') {
                    q.push({ni, nj});
                    grid[ni][nj] = '0'; // mark visited
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1') {
                    bfs(grid, i, j);
                    count++;
                }
            }
        }

        return count;
    }
};
