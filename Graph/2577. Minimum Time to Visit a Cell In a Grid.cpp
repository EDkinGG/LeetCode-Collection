//https://leetcode.com/problems/minimum-time-to-visit-a-cell-in-a-grid/description/
class Solution {
public:

    int dijkstra(vector<vector<int>>& grid, int sx, int sy)
    {
        
        int fx[] = {0,1,0,-1};
        int fy[] = {1,0,-1,0};

        int n = grid.size();
        int m = grid[0].size();

        if( n > 1 && grid[0][1] > 1 )
        {
            if( m > 1 && grid[1][0] > 1 )
            {
                return -1;
            }
            if( m == 1 )
            {
                return -1;
            }
        }

        vector<vector<int>> time (n, vector<int>(m,INT_MAX));
        time[sx][sy] = 0;
        priority_queue< pair<int ,pair<int,int>> , vector< pair<int,pair<int,int>> >, greater<pair<int,pair<int,int>>> > pq;
        
        pq.push({time[sx][sy],{sx,sy}});//{time of (x,y) from (sx,sy), {x,y}}

        while(!pq.empty())
        {
            int distance = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;

            pq.pop();

            if( distance > time[x][y] )
            {
                continue;
            }

            for( int k = 0 ; k < 4 ; k++ )
            {
                int newX = x + fx[k];
                int newY = y + fy[k];

                if( newX >= 0 && newY >=0 && newX < n && newY < m )
                {
                    if( (time[x][y] + 1 >= grid[newX][newY]) && (time[x][y] + 1 < time[newX][newY]) )
                    {
                        time[newX][newY] = time[x][y] + 1;
                        pq.push({time[newX][newY],{newX,newY}});
                    }
                    else if( time[x][y] + 1 < grid[newX][newY] )
                    {
                        int dif = grid[newX][newY] - (time[x][y] + 1);
                        if( dif%2 )
                        {
                            dif++;
                        }
                        if( (time[x][y] + 1 + dif >= grid[newX][newY]) && (time[x][y] + 1 + dif < time[newX][newY]) )
                        {
                            time[newX][newY] = time[x][y] + 1 + dif;
                            pq.push({time[newX][newY],{newX,newY}});
                        }
                    }
                }
            }
        }
        return time[n-1][m-1];
    }

    int minimumTime(vector<vector<int>>& grid) {

        return dijkstra(grid, 0, 0);
    }
};