//https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/description/

class Solution {
public:
    int dijkstra(vector<vector<int>>& grid, int sx, int sy )
    {
        int fx[] = {0,1,0,-1};
        int fy[] = {1,0,-1,0};

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> distFromStart (n, vector<int>(m,INT_MAX));
    
        distFromStart[sx][sy] = grid[sx][sy];
        priority_queue< pair<int ,pair<int,int>> , vector< pair<int,pair<int,int>> >, greater<pair<int,pair<int,int>>> > pq;
        
        pq.push({distFromStart[sx][sy],{sx,sy}});//{dist of (x,y) from (sx,sy), {x,y}}

        while(!pq.empty())
        {
            int distance = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;

            pq.pop();

            if( distance > distFromStart[x][y] )
            {
                continue;
            }

            for( int k = 0 ; k < 4 ; k++ )
            {
                int newX = x + fx[k];
                int newY = y + fy[k];

                if( newX >= 0 && newY >=0 && newX < n && newY < m )
                {
                    if( distFromStart[x][y] + grid[newX][newY] < distFromStart[newX][newY] )
                    {
                        distFromStart[newX][newY] = distFromStart[x][y] + grid[newX][newY];
                        pq.push({distFromStart[newX][newY],{newX,newY}});
                    }
                }
            }
        }
        return distFromStart[n-1][m-1];

    }

    int minimumObstacles(vector<vector<int>>& grid) {

        return dijkstra(grid, 0, 0);
    }
};