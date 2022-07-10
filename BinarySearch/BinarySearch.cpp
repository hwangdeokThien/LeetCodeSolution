#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int search(vector<int> &nums, int target) {
		int left = 0, right = nums.size() - 1;
		int mid;

		while (left <= right) {
			mid = (right + left) / 2;
			if (nums[mid] == target) return mid;
			if (target < nums[mid]) {
				right = mid - 1;
			} else {
				left = mid + 1;
			}
		}
		return -1;
	}
};