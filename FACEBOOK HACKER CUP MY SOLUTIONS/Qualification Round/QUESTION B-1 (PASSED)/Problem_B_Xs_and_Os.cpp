#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define DEEP_DAS                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

void solve()
{
    int n;
    cin >> n;
    string b[n];
    //initiased ??
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    // for loop here 
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int r = 0, re = 0;
        for (int j = 0; j < n; j++)
        {
            if (b[i][j] == 'O')
            {
                r = 0;
                re = 0;
                break;
            }
            else
            {
                if (b[i][j] == '.')
                {
                    r++;
                }
                re++;
            }
        }
        if (r == 0)
        {
            continue;
        }

        mp[r]++;
    }
    //for loop here to do
    for (int i = 0; i < n; i++)
    {
        int r = 0, re = 0;
        for (int j = 0; j < n; j++)
        {
            if (b[j][i] == 'O')
            {
                r = 0;
                re = 0;
                break;
            }
            else
            {
                if (b[j][i] == '.')
                {
                    r++;
                }
                re++;
            }
        }
        if (r == 0)
        {
            continue;
        }
        mp[r]++;
    }
    // for loop to do
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (b[i][j] == '.')
            {
                int r1 = 0, r2 = 0;
                for (int k = 0; k < n; k++)
                {
                    if (b[i][k] == 'O' || b[k][j] == 'O')
                    {
                        r1 = 0;
                        r2 = 0;
                        break;
                    }
                    if (b[i][k] == '.')
                    {
                        r1++;
                    }
                    if (b[k][j] == '.')
                    {
                        r2++;
                    }
                }
                if (r1 == 1 && r2 == 1)
                {
                    mp[r1]--;
                }
            }
        }
    }
    if (mp.size() == 0)
    {
        cout << "Impossible" << endl;
        return;
    }
    int c = 0;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        c++;
        cout << it->first << " " << it->second << endl;
        if (c == 1)
        {
            break;
        }
    }
}
int main()
{
    DEEP_DAS
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
    return 0;
}