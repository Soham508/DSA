/*
You are given a list of bombs. The range of a bomb is defined as the area where its effect can be felt. This area is in the shape of a circle with the center as the location of the bomb.

The bombs are represented by a 0-indexed 2D integer array bombs where bombs[i] = [xi, yi, ri]. xi and yi denote the X-coordinate and Y-coordinate of the location of the ith bomb, whereas ri denotes the radius of its range.

You may choose to detonate a single bomb. When a bomb is detonated, it will detonate all bombs that lie in its range. These bombs will further detonate the bombs that lie in their ranges.

Given the list of bombs, return the maximum number of bombs that can be detonated if you are allowed to detonate only one bomb.
*/

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> graph(n); 

        for (int i = 0; i < n; ++i) {
            long long x1 = bombs[i][0], y1 = bombs[i][1], r1 = (long long)bombs[i][2];
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                long long x2 = bombs[j][0], y2 = bombs[j][1];
                long long dx = x1 - x2, dy = y1 - y2;
                long long distSq = dx * dx + dy * dy;
                if (distSq <= r1 * r1) {
                    graph[i].push_back(j); 
                }
            }
        }

        int maxDetonated = 0;
        for (int i = 0; i < n; ++i) {
            vector<bool> visited(n, false);
            int count = dfs(i, graph, visited);
            maxDetonated = max(maxDetonated, count);
        }

        return maxDetonated;
    }

private:
    int dfs(int node, vector<vector<int>>& graph, vector<bool>& visited) {
        visited[node] = true;
        int count = 1; 
        for (int nei : graph[node]) {
            if (!visited[nei]) {
                count += dfs(nei, graph, visited);
            }
        }
        return count;
    }
};
