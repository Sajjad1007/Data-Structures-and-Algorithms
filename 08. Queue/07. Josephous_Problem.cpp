#include <iostream>
#include <queue>

using namespace std;

queue <int> q;

int josephous(int n, int k)
{
    int i = 1, temp;

    while(i <= n)
    {
        q.push(i);
        i++;
    }

    cout << "\nExecuted people :";
    while(q.size() != 1)
    {
        for(i = 1; i <= k; i++)
        {
            temp = q.front();
            q.push(temp);
            q.pop();
        }
        cout << " " << q.front();
        q.pop();
    }
    return q.front();
}

int main()
{
    int n, k;
    cout << "Number of people = ";
    cin >> n;
    cout << "Positions to be skipped = ";
    cin >> k;
    int safe = josephous(n, k);
    cout << "\nSafest position : " << safe << "\n";
    return 0;
}

/*
Number of people = 5
Positions to be skipped = 1

Executed people : 2 4 1 5
Safest position : 3
*/
