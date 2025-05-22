#include <iostream>
using namespace std;
int n;
int psi(int N)
{
    for(int i=2;i*i<=N;i++)
    {
        bool sosu = true;
        for(int j=2;j<i;j++)
        {
            if(i%j ==0)
            {
                sosu = false;
                break;
            }
        }
    }
}
int main()
{
    cin >> n;

}