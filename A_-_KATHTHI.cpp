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
int kills[1000][1000];

char graph[1000][1000];
int a[] = {0, -1, 0, 1}, b[] = {-1, 0, 1, 0};
void run()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int r, c;
        scanf("%d %d ", &r, &c);
        fora(i, r)
        {
            fora(j, c)
            {
                kills[i][j] = 1e9;
            }
        }
        fora(i, r)
        {
            fora(j, c)
            {
                scanf("%c", &graph[i][j]);
                // cout<<graph[i][j]<<" ";
            }
            char ch;
            scanf("%c", &ch);
        }
        kills[0][0] = 0;
        deque<pair<int, int>> q;
        pair<int, int> u;
        q.push_front(make_pair(0, 0));
        while (!q.empty())
        {
            u = q.front();
            q.pop_front();
            int y = u.first, x = u.second;
            for (int i = 0; i < 4; i++)
            {
                int ny = y + a[i];
                int nx = x + b[i];
                if (ny < r && ny >= 0 && nx < c && nx >= 0)
                {
                    if (graph[y][x] == graph[ny][nx] && kills[ny][nx] > kills[y][x])
                    {
                        q.push_front(make_pair(ny, nx));
                        kills[ny][nx] = kills[y][x];
                    }
                    else if (graph[y][x] != graph[ny][nx])
                    {
                        if (kills[ny][nx] > kills[y][x] + 1)
                        {
                            q.push_back(make_pair(ny, nx));
                            kills[ny][nx] = kills[y][x] + 1;
                        }
                    }
                }
            }
        }
        printf("%d\n", kills[r - 1][c - 1]);
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
