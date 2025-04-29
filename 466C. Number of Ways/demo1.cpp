#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

long long countSplitsWithEqualSum(int n, const vector<int>& arr) {
    // Step 1: Calculate the total sum of the array
    long long total_sum = 0;
    total_sum = std::accumulate(arr.begin(), arr.end(), 0LL);
    
    // Step 2: Check if the total sum is divisible by 3
    if (total_sum % 3 != 0||n<3) {
        return 0;
    }
    
    long long part_sum = total_sum / 3;
    long long current_sum = 0;
    long long count_part1 = 0;  // Count of indices where the sum equals part_sum
    long long result = 0;       // Final count of valid splits

    // Traverse the array from left to right
    for (int i = 0; i < n - 1; ++i) {
        current_sum += arr[i];

        // Check if current_sum forms the second partition's end (2 * part_sum)
        if (current_sum == 2 * part_sum) {
            result += count_part1;
        }

        // Check if current_sum forms the first partition's end (part_sum)
        if (current_sum == part_sum) {
            count_part1++;
        }
    }

    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << countSplitsWithEqualSum(n, arr) << endl;
    return 0;
}