#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
	int romanToInt(string s) {
		unordered_map<char, int> key;

		// assign pair into map
		key['I'] = 1;
		key['V'] = 5;
		key['X'] = 10;
		key['L'] = 50;
		key['C'] = 100;
		key['D'] = 500;
		key['M'] = 1000;

		char temp = ' ';
		int result = 0;

		// read string backward and calculate
		for (int i = s.length() - 1; i >= 0; i--) {
			if (key[temp] > key[s[i]]) {
				result -= key[s[i]];
			} else {
				result += key[s[i]];
			}
			temp = s[i];
		}

		return result;
	}
};

int main() {


	return 0;
}