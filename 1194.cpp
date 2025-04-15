#include <iostream>
#include <queue>
using namespace std;
struct point
{
    int x; int y; int k; //k = 0~63 : 이진수로 바꾸었을 때 xxxxxx 각 자리 숫자는 a~f의 유무 의미함
};
int main()
{
    int N, M;
    cin >> N >> M;
    char arr[60][60] = {};
    int visited[51][51][65] = {}; // 65 : a, b, c, d, e, f 열쇠 유무
    queue <point> q;
    point end;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin >> arr[i][j];
            if(arr[i][j]=='0') 
            {
                q.push({i, j, 0});
                visited[i][j][0] = 1; //전체적으로 1씩 커진 상태
            }
            else if(arr[i][j] == '1')
            {
                end.x = i;
                end.y = j;
            }
        }
    }
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    while(!q.empty())
    {
        point now = q.front();
        q.pop();
        for(int s=0;s<4;s++)
        {
            int nx = now.x + dx[s];
            int ny = now.y + dy[s];

            if(nx>=0 && nx<N && ny>=0 && ny<M && arr[nx][ny]!='#')
            {
                if(arr[nx][ny]=='1')
                {
                    cout << visited[now.x][now.y][now.k];
                    return 0;
                }
                else if(arr[nx][ny]>='a' && arr[nx][ny]<='f')
                {
                    int nk = (now.k | (1 << (arr[nx][ny]-'a')));
                    if(visited[nx][ny][nk]!=0) continue;
                    
                    visited[nx][ny][nk] = visited[now.x][now.y][now.k] + 1;
                    q.push({nx, ny, nk});
                }
                else if(arr[nx][ny]>='A' && arr[nx][ny]<='F')
                {
                    if((now.k & (1 << (arr[nx][ny]-'A'))) == 0) continue;
                    if(visited[nx][ny][now.k]!=0) continue;

                    visited[nx][ny][now.k] = visited[now.x][now.y][now.k] + 1;
                    q.push({nx, ny, now.k});
                }
                else
                {
                    if(visited[nx][ny][now.k]!=0) continue;

                    visited[nx][ny][now.k] = visited[now.x][now.y][now.k] + 1;
                    q.push({nx, ny, now.k});
                }
            }
        }
    }
    cout << "-1";
}