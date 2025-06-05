#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

// Fuerza bruta: O(n^2)
bool twoSumBruteForce(const vector<int>& nums, int target) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target) {
                return true;
            }
        }
    }
    return false;
}

// Optimizado: O(n)
bool twoSumOptimized(const vector<int>& nums, int target) {
    unordered_set<int> seen;
    for (int num : nums) {
        int complement = target - num;
        if (seen.count(complement)) {
            return true;
        }
        seen.insert(num);
    }
    return false;
}

int main() {
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;

    cout << "Fuerza bruta: ";
    if (twoSumBruteForce(numbers, target)) {
        cout << "Existe una pareja con suma " << target << endl;
    } else {
        cout << "No existe pareja con suma " << target << endl;
    }

    cout << "Optimizado: ";
    if (twoSumOptimized(numbers, target)) {
        cout << "Existe una pareja con suma " << target << endl;
    } else {
        cout << "No existe pareja con suma " << target << endl;
    }

    return 0;
}

