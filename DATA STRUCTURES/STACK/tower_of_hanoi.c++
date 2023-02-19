//This programs implements Tower of Hanoi

#include<iostream>
using namespace std;

void ToH(int, char, char, char);

int main()
{
    int n;
    cout << "Enter numbr of Discs: ";
    cin >> n;
    ToH(n, 'A', 'B', 'C');
    return 0;
}

void ToH(int n, char S, char T, char D)
{
    //If n = 1, then move the disc directly from Source to Destination Tower
    if (n == 1)
    {
        printf("Move %d from %c to %c\n", n, S, D);
        return;
    }
    ToH(n-1, S, D, T);  //Move n-1 discs from Source to Temporary tower
    printf("Move %d from %c to %c\n", n, S, D); //then move nth the disc directly from Source to Destination Tower
    ToH(n-1, T, S, D);  //Move n-1 discs from Temporary to Destination tower
}