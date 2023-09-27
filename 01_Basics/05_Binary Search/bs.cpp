#include<bits/stdc++.h>
using namespace std;

//TC : O(log n)
int binarySearch(vector<int> arr, int target) {
	/*
		Return : position of target in array, -1 if not found
		Note   : if duplicates of target in array it can return any one of the indexes 
	*/
    
    int L = 0, R = arr.size();          // search space [L, L + 1, ..., R - 1, R]
    
    while (L <= R) {
        int mid = (L + R) / 2;
        if (target > arr[mid]) {
            L = mid + 1;                // search space reduces to [mid + 1, mid + 2, ..., R]
        } else if (target < arr[mid]) {
            R = mid - 1;                // search space reduces to [L, L + 1, ..., mid - 1]
        } else {
            return mid;
        }
    }
    return -1;
}

int lower_bound(vector<int> arr, int target){
	/*
		Return : position of element in array which greater than or equal to target
		Note   : 1. if duplicates of target in array it will return the first postion where it is found
				 2. if not found returns index of first element which is just greater than target
	*/
	int L = 0, R = arr.size() - 1;              // search space is [0, 1,..., arr.size() - 1] or [L, L+1,..., R-1, R]
    
	while(R - L >= 0) {
		int mid = (L + R) / 2;
		int value = arr[mid];
		if(value < target) {
			L = mid + 1;                        // search space reduces to [L + 1, ..., R]
		}
		else{
			R = mid - 1;                        // search space reduces to [L, L+1,..., R - 1]
            // values at positions [mid, mid + 1,..., R] are
			// values >= target, so ans = R + 1
		}
	}
	return R + 1;
}

int upper_bound(vector<int> arr, int target){
	/*
		Return : position of element in array which greater than target
		Note   : if target is greater than maximum element of array, returns size of the array
	*/
	int L = 0, R = arr.size() - 1;          // search space is [0, 1,..., arr.size() - 1] or [L, L+1,..., R-1, R]

	while(R - L >= 0) {
		int mid = (L + R) / 2;
		int value = arr[mid];

		if(value <= target) {
			L = mid + 1;                    // search space reduces to [mid + 1, ..., R]
		}
		else{
			R = mid - 1;                    // search space reduces to [L, L+1,..., mid - 1],
            // values at positions [mid, mid + 1,..., R] are
			// values > target, so ans = R + 1
		}
	}
	return R + 1;
}

int main()
{
    vector<int>nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(9);
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(-1);

	sort(nums.begin(), nums.end());
    cout << binarySearch(nums, 1) << endl;
    cout << lower_bound(nums, 3) << endl;
    cout << upper_bound(nums, 4) << endl;
}
