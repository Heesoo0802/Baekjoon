#include <iostream>
#include <queue>
using namespace std;
struct point
{
    int x; int y;
};
int main()
{
    int h, w;
    cin >> h >> w;
    int arr[1010][1010];
    int visited[1010][1010]={};
    queue <point> q;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            char x;
            cin >> x;
            if(x=='.') arr[i][j] = 10;
            else arr[i][j] = x-'0';
        }
    }
    int dx[8] = {1, 1, 1, -1, -1, -1, 0, 0};
    int dy[8] = {1, -1, 0, 1, -1, 0, 1, -1};
    for(int i=1;i<h-1;i++)
    {
        for(int j=1;j<w-1;j++)
        {
            if(arr[i][j]==10) continue;
            
            int check = 0;
            for(int s=0;s<8;s++)
            {
                int nx = i + dx[s];
                int ny = j + dy[s];
                if(arr[nx][ny] == 10) check++;
            }
            arr[i][j] -= check;
            if(arr[i][j]<=0) 
            {
                q.push({i, j});
                visited[i][j] = 1;
            }
        }
    }
    while(!q.empty())
    {
        point top = q.front();
        q.pop();
        
        for(int s=0;s<8;s++)
        {
            int nx = top.x + dx[s];
            int ny = top.y + dy[s];
            
            if(nx>=0 && nx<h && ny>=0 && ny<w && arr[nx][ny]!=10) arr[nx][ny]--;
            if(nx>=0 && nx<h && ny>=0 && ny<w && visited[nx][ny]==0 && arr[nx][ny]<=0)
            {
                q.push({nx, ny});
                visited[nx][ny] = visited[top.x][top.y] + 1;
            }
        }
    }
    int ans = 0;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            ans = max(ans, visited[i][j]);
        }
    }
    cout << ans;
}