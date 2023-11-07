#include <iostream>
#include <vector>

using namespace std;

int n, cnt;
vector <int> v;

void print()
{
    for(auto x : v)
    {
        cout << x << " ";
    }
    cout << "\n";
    return;
}

//Time complexity is O(2^n).
//Space complexity is O(n).
void print_subsequence(int i, int *arr)
{
    cnt++;
    if(i == n)
    {
        print();
    }
    else
    {
        print_subsequence(i+1, arr);         //Not taking ith element in the subsequence
        v.push_back(arr[i]);
        print_subsequence(i+1, arr);         //Taking ith element in the subsequence
        v.pop_back();
    }
    return;
}

int main()
{
    cout << "Number of elements : ";
    cin >> n;
    int i, arr[n];

    cout << "Enter the elements : ";
    for(i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "\nAll possible subsequences are\n";
    print_subsequence(0, arr);
    cout << "\nTotal function calls = " << cnt << "\n";
    return 0;
}

/*
Number of elements : 3
Enter the elements : 3 1 2

All possible subsequences are

2
1
1 2
3
3 2
3 1
3 1 2

Total function calls = 15
*/
