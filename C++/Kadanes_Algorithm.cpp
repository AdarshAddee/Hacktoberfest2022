#include <iostream>
#include <vector>
#include <algorithm>  // For using std::max
using namespace std;

class Solution {
public:
    // Function to find the sum of the contiguous subarray with the maximum sum
    long long maxSubarraySum(vector<int>& arr, int n) {
        long long max_current = arr[0];
        long long max_global = arr[0];

        for (int i = 1; i < n; ++i) {
            max_current = max((long long)arr[i], max_current + arr[i]);
            max_global = max(max_global, max_current);
        }

        return max_global;
    }
};

int main() {
    int t, n;
    
    cin >> t;  // input test cases
    while (t--) {
        cin >> n;  // input size of array
        
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];  // inputting elements of array
        }
        
        Solution ob;
        cout << ob.maxSubarraySum(arr, n) << endl;
    }
}
