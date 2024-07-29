#include <iostream>
#include <vector>

using namespace std;

int n, cnt, scnt;
vector<int> v;

void print()
{
    for(auto x : v)
    {
        cout << x << " ";
    }
    cout << "\n";
    return;
}

void print_subset(int i, int *arr, int sum)
{
    cnt++;

    if(sum == 0)
    {
        print();
        scnt++;
    }
    else if(i == n || sum < 0);
    else
    {
        print_subset(i+1, arr, sum);
        v.push_back(arr[i]);
        print_subset(i+1, arr, sum-arr[i]);
        v.pop_back();
    }
    return;
}

int main()
{
    cout << "Number of elements : ";
    cin >> n;
    int i, sum, arr[n];

    cout << "Enter the elements : ";
    for(i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the sum : ";
    cin >> sum;

    cout << "\nAll possible subsets are\n\n";
    print_subset(0, arr, sum);
    cout << "\nNumber of subsets = " << scnt;
    cout << "\nTotal function calls = " << cnt << "\n";
    return 0;
}

/*
Number of elements : 5
Enter the elements : 5 15 3 17 12
Enter the sum : 20

All possible subsets are

3 17
5 3 12
5 15

Number of subsets = 3
Total function calls = 39
*/
