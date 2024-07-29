#include <iostream>

using namespace std;

int cnt, steps;

// Time complexity is O(2^n).
void tower_of_hanoi(int n, char a, char b, char c)
{
    ++cnt;

    if(n > 0)
    {
        tower_of_hanoi(n-1, a, c, b);
        printf("\nMove from %c to %c", a, c);
        ++steps;
        tower_of_hanoi(n-1, b, a, c);
    }
    return;
}

int main()
{
    int n;
    cout << "Enter number of discs : ";
    cin >> n;
    tower_of_hanoi(n, 'A', 'B', 'C');
    cout << "\n\nTotal function calls = " << cnt;
    cout << "\nTotal steps = " << steps << "\n";
    return 0;
}

/*
Enter number of discs : 3

Move from A to C
Move from A to B
Move from C to B
Move from A to C
Move from B to A
Move from B to C
Move from A to C

Total function calls = 15
Total steps = 7
*/
