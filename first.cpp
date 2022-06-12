#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    queue<int> a, b, c;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push(x);
    }
    while (!a.empty())
    {
        if (c.empty())
        {
            c.push(a.front());
            a.pop();
        }
        else
        {
            if (c.front() >= a.front())
            {

                while (c.front() >= a.front())
                {
                    b.push(c.front());
                    c.pop();
                    if (c.empty())
                    {
                        break;
                    }
                }
                c.push(a.front());
                a.pop();
                while (!b.empty())
                {
                    c.push(b.front());
                    b.pop();
                }
            }else if(c.front()<a.front()){
                while (c.front() < a.front())
                {
                    b.push(c.front());
                    c.pop();
                    if (c.empty())
                    {
                        break;
                    }
                }
                
                while (!b.empty())
                {
                    c.push(b.front());
                    b.pop();
                }
            }
        }
    }
    cout << "Condition of queue C: ";
    while (!c.empty())
    {
        cout << c.front() << " ";
        c.pop();
    }
    cout << endl;
    cout << "Condition of queue B: ";
    cout << "Empty";
    cout << endl;
    cout << "Condition of queue A: ";
    cout << "Empty";
    cout << endl;
}