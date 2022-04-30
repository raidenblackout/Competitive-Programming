#include <bits/stdc++.h>
#if 0
#define HOME
#endif
#ifndef ONLINE_JUDGE
#define dbgA2(A, n, m)                  \
    {                                   \
        cout << "-->" << #A << "=\n";   \
        for (int i = 0; i < n; i++)     \
        {                               \
            for (int j = 0; j < m; j++) \
            {                           \
                cout << A[i][j] << " "; \
            }                           \
            cout << "\n";               \
        }                               \
        cout << "\n";                   \
    }
#define dbgA(A, n)                   \
    {                                \
        cout << "-->" << #A << "=("; \
        for (int i = 0; i < n; i++)  \
            cout << A[i] << " ";     \
        cout << ")\n";               \
    }
#define dbg(args...)                                  \
    {                                                 \
        string sss(#args);                            \
        sss += ',';                                   \
        cout << "-->";                                \
        debugger::call(sss.begin(), sss.end(), args); \
        cout << "\n";                                 \
    }
#else
#define dbgA2(A, n, m)
#define dbgA(A, n)
#define dbg(args...)
#endif
#define fora(I, n) for (int I = 0; I < n; I++)
#define forb(I, n) for (int I = 1; I <= n; I++)
#define mXI (int)1e8
#define umXI UINT_MAX
#define llmXI LLONG_MAX
#define pb push_back
#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>
#define mkp(a, b) make_pair(a, b)
using namespace std;
/*struct debugger {
    typedef string::iterator si;
    static void call(si it, si ed) {}
    template<typename T, typename ... aT>
    static void call(si it, si ed, T a, aT... rest) {
        string b;
        for(; *it!=','; ++it)
            if(*it!=' ')
                b+=*it;
        cout << b << "=" << a << " ";
        call(++it, ed, rest...);
    }
};
ll siev_arr[mXI];
void siev(ll n)
{
    siev_arr[0] = siev_arr[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!siev_arr[i])
        {
            cout<<i<<endl;
            for (int j = i + i; j <= n; j += i)
            {
                siev_arr[j] = 1;
            }
        }
    }
}

int dfs(int v, int *arr, int *visited){
    if(visited[arr[v]]){
        return arr[v]=arr[arr[v]];
    }
    visited[v]=1;
    return arr[v]=dfs(arr[v],arr,visited);
}*/

void run()
{
    int t;
    cin >> t;
    forb(tt, t)
    {
        cout << "Scenario #" << tt << endl;
        int n;
        cin >> n;
        map<string, int> index;
        fora(i, n)
        {
            string s;
            cin >> s;
            index[s] = i;
        }
        int m;
        cin >> m;
        vector<vector<pll>> adj(n);
        fora(i, m)
        {
            string s1, s2;
            ll cost;
            cin >> s1 >> s2 >> cost;
            adj[index[s1]].pb(mkp(index[s2], cost));
        }
        vector<ll> dist(n, 1e10);
        vector<int> stopovers(n, 0);
        dist[index["Calgary"]] = 0;
        vector<ll> costs;
        for (int s = 1; s < n; s++)
        {
            for (int i = n - 2; i >= 0; i--)
            {
                int u = i;
                int size = adj[u].size();
                fora(j, size)
                {
                    int v = adj[u][j].first;
                    ll cost = adj[u][j].second;
                    if (dist[u] + cost < dist[v])
                    {
                        dist[v] = dist[u] + cost;
                    }
                }
            }
            costs.pb(dist[index["Fredericton"]]);
        }
        int q;
        cin >> q;
        while (q--)
        {
            int st;
            cin >> st;
            if(st>n-2){
                st=n-2;
            }
            if (costs[st] == 1e10)
            {
                cout << "No satisfactory flights\n";
            }
            else
            {
                cout << "Total cost of flight(s) is $" << costs[st] << endl;
            }
        }
        cout << (tt==t ? "":"\n");
    }
}

int main()
{
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    run();
}
