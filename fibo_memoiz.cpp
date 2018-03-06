// v3. use tabulation

#include <iostream>
using namespace std;

#define LL long long

#define _trace(x) cout << #x << ": " << x << endl

LL fibo(LL seed1, LL seed2, LL n)
{
	if (n < 0) exit(1);
	if (n == 0) return seed1;
	if (n == 1) return seed2;

	LL fibo_prev = seed2;
	LL fibo_prev_prev = seed1;
	LL fibo_next;

	for (LL i = 2; i <= n; i++)
	{
		fibo_next = fibo_prev + fibo_prev_prev;
		// _trace(fibo_next);

		// make the shift
		fibo_prev_prev = fibo_prev;
		fibo_prev = fibo_next;
	}

	return fibo_next;
}

int main()
{
	int t;
	cin >> t;

	while (t > 0)
	{
		int a, b, n;
		cin >> a >> b >> n;
		cout << (fibo(a, b, n) % 1000000007) << endl;

		t--;
	}

	return 0;
}
