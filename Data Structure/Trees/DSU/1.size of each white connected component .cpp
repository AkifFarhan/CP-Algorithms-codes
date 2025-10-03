#include <bits/stdc++.h>
using namespace std;

#define N 1000005
#define ll long long

vector<vector<pair<ll,ll>>>parent;
vector<vector<ll>>sz;

void make(ll i, ll j)
{
    parent[i][j] = {i, j};
    sz[i][j] = 1;
}

pair<ll,ll> find(pair<ll,ll> v)
{
    if (parent[v.first][v.second] == v)
        return v;
    return parent[v.first][v.second] = find(parent[v.first][v.second]);
}

void Union(pair<ll,ll> a, pair<ll,ll> b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        if (sz[a.first][a.second] < sz[b.first][b.second])
            swap(a, b);
        parent[b.first][b.second] = a;
        sz[a.first][a.second] += sz[b.first][b.second];
    }
}

int main()
{
    ll n, m;
    cin >> n >> m;
    string s[n];

    for(ll i=0;i<n ; i++)
        cin>>s[i];

    parent.assign(n, vector<pair<ll,ll>>(m));
   sz.assign(n, vector<ll>(m, 0));

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            make(i, j);
        }
    }

    for(ll i=0;i<n;i++)
    {
        for(ll j =0 ;j<m;j++)
        {
            if(s[i][j]=='W')
            {
                if(s[i+1][j]=='W' && i+1<n)
                    Union({i, j}, {i+1, j});
                if(s[i][j+1]=='W' && j+1<m)
                    Union({i, j}, {i, j+1});

            }
        }
    }

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if(s[i][j]=='W' && parent[i][j] == make_pair(i, j))
                cout<<sz[i][j]<<endl;
        }
    }
}

