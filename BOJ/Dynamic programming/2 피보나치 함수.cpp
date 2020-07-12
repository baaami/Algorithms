#include <stdio.h>
using namespace std;
int cnt0(0);
int cnt1(0);
int fibo[41];
int fibonacci(int n) {
    if (n <= 0) 
    {
        fibo[0] = 0;
        cnt0++;
        return 0;
    }
    else if (n == 1) {
        fibo[1] = 1;
        cnt1++;
        return 1;
    }
    if (fibo[n] != 0)
    {
        return fibo[n];
    }
    else {
        return fibo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int x; scanf("%d", &x);
        if (x == 0) { printf("%d %d\n", 1, 0); }
        else if (x == 1) { printf("%d %d\n", 0, 1); }
        else { fibonacci(x); printf("%d %d\n", fibo[x - 1], fibo[x]); }
    }
	return 0;
}