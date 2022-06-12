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
    while (t--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int k = a, l = b, m = c, n = d;
        int abcount = 0, bacount = 0;
        string s;
        cin >> s;
        string pp = s;
        fora(i, s.size() - 1)
        {
            if (s[i] == 'A' && s[i + 1] == 'B' && c--)
            {
                abcount++;
                s[i] = s[i + 1] = 'C';
                i++;
            }
        }

        string temp = s;
        fora(i, s.size() - 1)
        {
            if (s[i] == 'B' && s[i + 1] == 'A' && d--)
            {
                bacount++;
                s[i] = s[i + 1] = 'C';
                i++;
            }
        }
        int acount = 0, bcount = 0;
        fora(i, s.size())
        {
            if (s[i] == 'A')
                acount++;
            if (s[i] == 'B')
                bcount++;
        }
        cout << acount << " " << bcount << endl;
        if (acount <= a && bcount <= b)
        {
            cout << "YES" << endl;
        }
        else
        {
            s = temp;
            d = n;
            for (int i = s.size() - 2; i >= 0; i--)
            {
                if (s[i] == 'B' && s[i + 1] == 'A' && d--)
                {
                    bacount++;
                    s[i] = s[i + 1] = 'C';
                    i--;
                }
            }
            acount = 0, bcount = 0;
            fora(i, s.size())
            {
                if (s[i] == 'A')
                    acount++;
                if (s[i] == 'B')
                    bcount++;
            }
            cout << acount << " " << bcount << endl;
            if (acount <= a && bcount <= b)
            {
                cout << "YES" << endl;
            }
            else
            {
                s = pp;
                c = m, d = n;
                for (int i = s.size() - 2; i >= 0; i--)
                {
                    if (s[i] == 'A' && s[i + 1] == 'B' && c--)
                    {
                        abcount++;
                        s[i] = s[i + 1] = 'C';
                        i--;
                    }
                }

                temp = s;
                fora(i, s.size() - 1)
                {
                    if (s[i] == 'B' && s[i + 1] == 'A' && d--)
                    {
                        bacount++;
                        s[i] = s[i + 1] = 'C';
                        i++;
                    }
                }
                acount = 0, bcount = 0;
                fora(i, s.size())
                {
                    if (s[i] == 'A')
                        acount++;
                    if (s[i] == 'B')
                        bcount++;
                }
                cout << acount << " " << bcount << endl;
                if (acount <= a && bcount <= b)
                {
                    cout << "YES" << endl;
                }
                else
                {
                    s = temp;
                    d = n;
                    for (int i = s.size() - 2; i >= 0; i--)
                    {
                        if (s[i] == 'B' && s[i + 1] == 'A' && d--)
                        {
                            bacount++;
                            s[i] = s[i + 1] = 'C';
                            i--;
                        }
                    }
                    acount = 0, bcount = 0;
                    fora(i, s.size())
                    {
                        if (s[i] == 'A')
                            acount++;
                        if (s[i] == 'B')
                            bcount++;
                    }
                    cout << acount << " " << bcount << endl;
                    if (acount <= a && bcount <= b)
                    {
                        cout << "YES" << endl;
                    }
                    else
                    {
                        cout << "NO\n";
                    }
                }
            }
        }
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
