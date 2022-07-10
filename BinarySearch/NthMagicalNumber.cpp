#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	// LTE
	int nthMagicalNumber(int n, int a, int b) {
		int subA = a, subB = b;
		int res;

		while (n > 0) {
			if (subA > subB) {
				res = subB;
				subB += b;
			} else if (subB > subA) {
				res = subA;
				subA += a;
			} else {
				res = subA;
				subA += a;
				subB += b;
			}
			subA %= (1e9 + 7);
			subB %= (1e9 + 7);
			n--;
		}

		return res;
	}

	// good solution
	int gcd(int a, int b) {
		if (!a && b) return b;
		if (!b && a) return a;

		return gcd(b, a % b);
	}

	int nthMagicalNumber(int n, int a, int b) {
		long lcm =  a * b / gcd(a, b);
		long left = 2, right = 1e14;
		while (left < right) {
			long m = (left + right) / 2;
			if (m / a + m / b - m / lcm < n) left = m + 1;
			else right = m;
		}

		return left % 1e9 + 7;
	}
};