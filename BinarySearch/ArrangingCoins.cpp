#include <iostream>
#include <cmath>

using namespace std;

// math way
int arrangeCoins(int n) {
	return (int)(-0.5 + sqrt(2 * (long)n + 0.25));
}

// binary search method
int arrangeCoins(int n) {
	long left = 1, right = n;
	long mid, res;
    long coins;

	while (left <= right) {
		mid = (left + right) / 2; 
        coins = mid * (mid + 1) / 2;
		if (coins <= n) {
			left = mid + 1;
			res = mid;
		}
		else right = mid - 1;
	}

	return res;
}

int main() {
	int n;
	cin >> n;

	cout << arrangeCoins(n);

	return 0;
}