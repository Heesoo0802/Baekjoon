#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int N;
vector <string> v;
struct comp
{
    bool operator() (const string &a, const string &b) 
    const{
    if(a.size() != b.size()) return a.size() < b.size();
    else return a < b;
    }
};
set <string, comp> s;
int main()
{
    cin >> N;
    v.resize(N);
    for(int i=0;i<N;i++) 
    {
        cin >> v[i];
        s.insert(v[i]);
    }
    for(auto str : s)
    {
        cout << str << endl;
    }
    return 0;
}