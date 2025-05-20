#include <iostream>
using namespace std;
int N;
int arr[129][129];
int blue, white;
void f(int n, int x, int y)
{
    int k = arr[x][y];
    int check = 1;
    if(n==1)
    {
        if(k == 1) blue++;
        else white++;
        return;
    }
    for(int i=x;i<x+n;i++)
    {
        for(int j=y;j<y+n;j++)
        {
            if(arr[i][j] != k) 
            {
                check = 0;
                break;
            }
        }
    }
    if(check == 0)
    {
        f(n/2, x, y);
        f(n/2, x + n/2, y);
        f(n/2, x, y + n/2);
        f(n/2, x + n/2, y + n/2);
    }
    else
    {
        if(k == 0) white++;
        else blue++;
        return;
    }
}
int main()
{
    cin >> N;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin >> arr[i][j];
        }
    }
    f(N, 0, 0);
    cout << white << endl;
    cout << blue << endl;
}