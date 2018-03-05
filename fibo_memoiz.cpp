// v2: do memoization
#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>
using namespace std;

#define _trace(x) cout << #x << ": " << x << endl

#define NIL		-1
#define MAXLEN	1000000

int fibo(vector<int> &lookup, int seed1, int seed2, int n)
{
	if (n < 0) exit(1);

	if (lookup[n] == NIL)
	{
		if (n == 0) return seed1;
		if (n == 1) return seed2;

		return fibo(lookup, seed1, seed2, n - 1) + fibo(lookup, seed1, seed2, n - 2);
	}
	else
		return lookup[n];
}

int main()
{
	vector<int> lookup(MAXLEN);
	std::fill(lookup.begin(), lookup.end(), NIL);

	int t;
	cin >> t;

	while (t > 0)
	{
		int a, b, n;
		cin >> a >> b >> n;
		cout << (fibo(lookup, a, b, n) % 1000000007) << endl;

		t--;
	}

    return 0;
}
