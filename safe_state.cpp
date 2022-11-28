#include<bits/stdc++.h>

#define mamun()         ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl            '\n'
#define tab             '\t'
#define ll              long long
#define lli             long long int
#define pb              push_back
#define fin(file)       freopen(file".txt", "r", stdin)
#define fout(file)      freopen(file".txt", "w", stdout)
#define FOR(i, a, b)    for (int i=a; i<=b; i++)
#define loop(i, n)      for (int i=0; i<n; i++)
#define srt(v)          sort(v.begin(), v.end())
#define rsrt(v)         sort(v.rbegin(), v.rend())
#define Fill(ar, val)   memset(ar, val, sizeof(ar))
#define testcase()      ll t; cin>>t; while(t--)

using namespace std;

int main()
{
    // mamun();

    int n, m;
    cout << "Enter the number of processes: ";
    cin >> n;
    cout << "Enter the number of resources: ";
    cin >> m;

    vector<ll>available(m);
    cout << "Enter the available resources: ";
    loop(i, m)
        cin >> available[i];

    vector<vector<ll>>allocation(n, vector<ll>(m));
    cout << "Enter the allocation matrix: " << endl;
    loop(i, n)
        loop(j, m)
        cin >> allocation[i][j];

    vector<vector<ll>>request(n, vector<ll>(m));
    cout << "Enter the request matrix: ";
    loop(i, n)
        loop(j, m)
        cin >> request[i][j];

    vector<ll>finish(n, 0);

    vector<ll>safeSequence;

    bool flag = true;

    while (flag)
    {
        flag = false;
        loop(i, n)
        {
            if (finish[i] == 0)
            {
                bool possible = true;
                loop(j, m)
                {
                    if (request[i][j] > available[j])
                    {
                        possible = false;
                        break;
                    }
                }
                if (possible)
                {
                    loop(j, m)
                    {
                        available[j] += allocation[i][j];
                    }
                    finish[i] = 1;
                    safeSequence.pb(i);
                    flag = true;
                }
            }
        }
    }

    loop(i, n)
    {
        if (finish[i] == 0)
        {
            cout << "Deadlock detected" << endl;
            return 0;
        }
    }

    cout << "Safe Sequence: ";
    loop(i, n)
    {
        cout << safeSequence[i] << " ";
    }
    cout << endl;



    return 0;
}


/*
Enter the number of processes: 5
Enter the number of resources: 3
Enter the available resources: 3 3 2
Enter the allocation matrix:
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2
Enter the request matrix:
7 4 3
1 2 2
6 0 0
0 1 1
4 3 1
Safe Sequence: 1 3 4 0 2
*/


/*
Enter the number of processes: 5
Enter the number of resources: 3
Enter the available resources: 3 2 2
Enter the allocation matrix:
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2
Enter the request matrix:
7 4 3
1 2 2
6 0 0
0 1 1
4 3 1
Deadlock detected
*/