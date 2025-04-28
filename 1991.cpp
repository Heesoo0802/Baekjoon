#include <iostream>
#include <vector>
using namespace std;
int n;
vector <char> v[30];
void b(int I)
{
    if(I > n) return;

    cout << v[I][0];
    if(v[I][1]!='.') b(v[I][1]-'A'+1);
    if(v[I][2]!='.') b(v[I][2]-'A'+1);
}
void m(int I)
{
    if(I > n) return;

    if(v[I][1]!='.') m(v[I][1]-'A'+1);
    cout << v[I][0];
    if(v[I][2]!='.') m(v[I][2]-'A'+1);
}
void a(int I)
{
    if(I > n) return;
    
    if(v[I][1]!='.') a(v[I][1]-'A'+1);
    if(v[I][2]!='.') a(v[I][2]-'A'+1);
    cout << v[I][0];
}
int main()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        char mom;
        cin >> mom;
        v[mom-'A'+1].push_back(mom);

        for(int j=1;j<=2;j++)
        {
            char x;
            cin >> x;
            v[mom-'A'+1].push_back(x);
        }
    }
    
    b(1);
    cout << endl;
    m(1);
    cout << endl;
    a(1);
    cout << endl;
}