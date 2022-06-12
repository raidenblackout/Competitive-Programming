#include <bits/stdc++.h>

struct queueT
{
    int data[100], n, ch, fr = 0, re = 0, qSize = 0, v;
    int getFrontElement()
    {
        return data[fr];
    }

    int enqueue(int v)
    {
        data[re] = v;
        re++;
        if (re == n)
            re = 0;
        qSize++;
        return re;
    }

    int dequeue()
    {
        fr = (fr + 1) % n;
        qSize--;
        return fr;
    }
    bool isEmpty()
    {
        if (qSize == 0)
            return true;
        else
            return false;
    }
};
using namespace std;
int main()
{
    int n;
    cin >> n;
    queueT a,b,c;
    a.n=n;
    b.n=n;
    c.n=n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.enqueue(x);
    }
    while (!a.isEmpty())
    {
        if (c.isEmpty())
        {
            c.enqueue(a.getFrontElement());
            a.dequeue();
        }
        else
        {
            queue<int> temp;
            while(!c.isEmpty()){
                cout<<c.getFrontElement()<<" ";
                temp.push(c.getFrontElement());
                c.dequeue();
            }
            while(!temp.empty()){
                c.enqueue(temp.front());
                temp.pop();
            }
            cout<<endl;
            if(c.getFrontElement()>=a.getFrontElement()){
                while (c.getFrontElement() >= a.getFrontElement())
                {
                    b.enqueue(c.getFrontElement());
                    c.dequeue();
                    if (c.isEmpty())
                        break;
                }
                c.enqueue(a.getFrontElement());
                a.dequeue();
                while (!b.isEmpty())
                {
                    c.enqueue(b.getFrontElement());
                    b.dequeue();
                }
            }else{
                while(c.getFrontElement()<a.getFrontElement()){
                    b.enqueue(c.getFrontElement());
                    c.dequeue();
                    if(c.isEmpty())
                        break;
                }
                b.enqueue(a.getFrontElement());
                a.dequeue();
                while(!c.isEmpty()){
                    b.enqueue(c.getFrontElement());
                    c.dequeue();
                }
                while(!b.isEmpty()){
                    c.enqueue(b.getFrontElement());
                    b.dequeue();
                }

            }
        }
    }
    cout << "Condition of queue C: ";
    while (!c.isEmpty())
    {
        cout << c.getFrontElement() << " ";
        c.dequeue();
    }
    cout << endl;
    cout << "Condition of queue B: ";
    cout << "Empty";
    cout << endl;
    cout << "Condition of queue A: ";
    cout << "Empty";
    cout << endl;
    return 0;
}
