#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int n;
unordered_map <int, int> in_index;
vector <int> inorder;
vector <int> postorder;
vector <int> preorder;
void f(int in_l, int in_r, int post_l, int post_r)
{
    if(in_l > in_r) return;
    int root = postorder[post_r];
    int in_root = in_index[root];
    int left_size = in_root - in_l;

    preorder.push_back(root);
    f(in_l, in_root - 1, post_l, post_l + left_size - 1);
    f(in_root + 1, in_r, post_l + left_size, post_r - 1);
}
int main()
{
    cin >> n;
    inorder.resize(n);
    postorder.resize(n);
    for(int i=0;i<n;i++) cin >> inorder[i];
    for(int i=0;i<n;i++) cin >> postorder[i];

    for(int i=0;i<n;i++)
    {
        in_index[inorder[i]] = i;
    }
    f(0, n-1, 0, n-1);
    for(int i=0;i<n;i++)
    {
        cout << preorder[i] << " ";
    }
    return 0;
}