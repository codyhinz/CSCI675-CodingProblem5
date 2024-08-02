class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();
        // Initialize heights matrix with -1 (unassigned)
        vector<vector<int>> heights(m, vector<int>(n, -1));
        
        queue<pair<int,int>> q;
        // Initialize water cells with height 0 and add to queue
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j]) {
                    heights[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        // Directions array for adjacent cells (right, down, left, up)
        vector<int> dirs = {0, 1, 0, -1, 0};
        
        // BFS to assign heights to land cells
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            // Check all four adjacent cells
            for (int i = 0; i < 4; i++) {
                int nr = r + dirs[i], nc = c + dirs[i+1];
                // Skip if out of bounds or already assigned
                if (nr < 0 || nr == m || nc < 0 || nc == n || heights[nr][nc] != -1) continue;
                // Assign height: 1 more than current cell
                heights[nr][nc] = heights[r][c] + 1;
                // Add to queue for further processing
                q.push({nr, nc});
            }
        }
        
        return heights;
    }
};