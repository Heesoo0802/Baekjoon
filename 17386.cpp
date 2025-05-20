#include <iostream>
#define int long long
using namespace std;
struct point
{
    int x; int y;
};
int ccw(point A, point B, point C)
{
    int dx1 = A.x - C.x;
    int dy1 = A.y - C.y;
    int dx2 = C.x - B.x;
    int dy2 = C.y - B.y;
    int op = dx1 * dy2 - dy1 * dx2;
    if(op < 0) return -1;
    if(op > 0) return 1;
    else return 0;
}
bool cross(point A, point B, point C, point D)
{
    if(ccw(A, B, C) * ccw(A, B, D) < 0 && ccw(C, D, A) * ccw(C, D, B) < 0) return true;
    else return false;
}
point p[4];
signed main()
{
    for(int i=0;i<4;i++)
    {
        cin >> p[i].x >> p[i].y;
    }
    if(cross(p[0], p[1], p[2], p[3])) cout << "1";
    else cout << "0";
    return 0;
}