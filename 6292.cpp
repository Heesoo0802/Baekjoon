#include <iostream>
#include <stack>
using namespace std;
int H, W, num, cnt = 1;
char arr[4001][4001];
int visited[4001][4001];
struct point 
{
    int x; int y;
};
int main()
{
    cin >> H >> W;
    for(int i=0;i<H;i++)
    {
        string t;
        cin >> t;
        for(int j=0;j<W;j++)
        {
            arr[i][j] = t[j];
            if(arr[i][j] != '.') num++;
        }
    }
    stack <point> st;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    while(num > 0)
    {
        for(int i=0;i<H;i++)
        {
            for(int j=0;j<W;j++)
            {
                if(arr[i][j] != '.' && visited[i][j] == 0)
                {
                    st.push({i, j});
                    while(!st.empty())
                    {
                        point now = st.top();
                        st.pop();
                        num--;
                        visited[now.x][now.y] = cnt;
                        for(int s=0;s<4;s++)
                        {
                            int nx = now.x + dx[s];
                            int ny = now.y + dy[s];
                            if(nx>=0 && nx<H && ny>=0 && ny<W && visited[nx][ny] == 0 && arr[nx][ny]==arr[now.x][now.y])
                            {
                                st.push({nx, ny});
                            }
                        }
                    }
                    cnt++;
                }
            }
        }
    }
    cout << cnt - 1;
}