class Solution {
    //--------- Time complexity: O(NLogN) Space complexity: O(N) --------- //     
    
    bool binarySearch(int arr[], int size, int target) {
        int left = 0, right = size - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) {
                return true;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }

    vector<int>::iterator lowerBound(vector<int>& vec, int target) {
        return lower_bound(vec.begin(), vec.end(), target);
    }

  public:
  
    int minInsAndDel(int arr1[], int arr2[], int n, int m) {
        vector<int> longestCommonSubsequence;

        for (int i = 0; i < n; i++) {
            if (binarySearch(arr2, m, arr1[i])) {
                auto it = lowerBound(longestCommonSubsequence, arr1[i]);
                if (it == longestCommonSubsequence.end()) 
                    longestCommonSubsequence.push_back(arr1[i]);
                else 
                    *it = arr1[i];
                
            }
        }

        return n + m - 2 * longestCommonSubsequence.size();
    }
};
