#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int>available(m);
    int allocation[n][m], allocation1[n][m], mx[n][m], need[n][m], need1[n][m];
    int finish[n] = { 0 };
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> allocation[i][j];
            allocation1[i][j] = allocation[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mx[i][j];
            need[i][j] = mx[i][j] - allocation[i][j];
            need1[i][j] = mx[i][j] - allocation[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        cin >> available[i];
    }
    int req[m];
    int q;
    cin >> q;
    while (q--)
    {
        int p;
        cin >> p;
        int err = 1;
        for (int i = 0; i < m; i++)
        {
            cin >> req[i];
            err &= (req[i] <= need[p][i]);
        }
        if (err == 0)
        {
            cout << "Error: Process " << p << " has exceeded max request" << endl;
            continue;
        }
        for (int i = 0; i < m; i++)
        {
            err &= (req[i] <= available[i]);
        }
        if (err == 0)
        {
            cout << "Error: Available is less than request" << endl;
            continue;
        }
        vector<int>temp(m);
        temp = available;
        for (int i = 0; i < m; i++)
        {
            available[i] -= req[i];
            need[p][i] -= req[i];
            allocation[p][i] += req[i];
        }
        int tot = 0, pass = 0;
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
                    pass = 1;
                    break;
                }
                else
                {
                    break;
                }
            }
        }

        available = temp;
        if (pass == 1)
        {
            for (int i = 0; i < m; i++)
            {
                available[i] -= req[i];
            }
            cout << "Resource allocation is possible" << endl;
        }
        else
        {
            cout << "Resource allocation is impossible" << endl;
            for (int i = 0; i < m; i++)
            {
                need[p][i] += req[i];
                allocation[p][i] -= req[i];
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