#include <iostream>

using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> mat[n];

    while (e--)
    {
        int a, b;
        cin >> a >> b;

        // connection
        mat[a].push_back(b);
        mat[b].push_back(a);
    }

    for (int x : mat[4])
    {
        cout << x << " ";
    }

    return 0;
}