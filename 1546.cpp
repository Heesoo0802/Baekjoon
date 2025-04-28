#include <iostream>
using namespace std;
int main()
{
    int N;
    float sum = 0;
    int M = 0;
    cin >> N;
    for(int i=0;i<N;i++) 
    {
        int x;
        cin >> x;
        M = max(M, x);
        sum += x;
    }
    sum = (float)(sum / M) * 100;
    sum /= N;
    cout << sum;
}