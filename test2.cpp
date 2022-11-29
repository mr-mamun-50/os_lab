#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int>available(m);
    int allocation[n][m], mx[n][m], need[n][m];
    int finish[n] = { 0 };
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> allocation[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mx[i][j];
            need[i][j] = mx[i][j] - allocation[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        cin >> available[i];
    }
    vector<int>v;
    int tot = 0;
    while (1)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (finish[i] == 1)continue;

            int ok = 1;
            for (int j = 0; j < m; j++)
            {
                ok &= (need[i][j] <= available[j]);
            }

            if (ok)
            {
                cnt++;
                tot++;
                v.push_back(i);
                finish[i] = 1;
                for (int j = 0; j < m; j++)
                {
                    available[j] += allocation[i][j];
                }
            }
        }
        if (cnt == 0)
        {
            if (tot == n)
            {
                cout << "SAFE" << endl;
                for (int i = 0; i < v.size(); i++)
                {
                    cout << "P" << v[i] << " ";
                }
                cout << endl;
                break;
            }
            else
            {
                cout << "DEAD LOCK" << endl;
                break;
            }
        }
    }
}
/*
010 753 332
200 322
302 902
211 222
002 433
*/
int main()
{
    int t = 1;
    //cin>>t;
    while (t--)
    {
        solve();
    }
}