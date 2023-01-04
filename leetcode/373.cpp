#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2,
                                     int k) {
    if (nums1.empty() || nums2.empty())
      return {};
    int lo = nums1[0] + nums2[0];
    int hi = nums1.back() + nums2.back();
    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;
      // number of pair sums equal to or below mid
      long long cnt = 0;
      int r = nums2.size() - 1;
      for (int l = 0; l < nums1.size(); l++) {
        while (r >= 0 && nums1[l] + nums2[r] > mid)
          r--;
        cnt += r + 1;
      }
      if (cnt >= k)
        hi = mid;
      else
        lo = mid + 1;
    }
    int val = lo;
    vector<vector<int>> ans;

    // strictly less than val
    int r = nums2.size() - 1;
    for (int l = 0; l < nums1.size(); l++) {
      while (r >= 0 && nums1[l] + nums2[r] >= val)
        r--;
      for (int i = 0; i <= r; i++) {
        ans.push_back({nums1[l], nums2[i]});
      } 
    }

    // equal to val
    r = nums2.size() - 1;
    // there might be extra pairs with sum equal to val
    int remaining = k - ans.size();
    for (int l = 0; l < nums1.size(); l++) {
      while (r >= 0 && nums1[l] + nums2[r] > val)
        r--;
      int temp = r;
      while (temp >= 0 && nums1[l] + nums2[temp] == val) {
        ans.push_back({nums1[l], nums2[temp]});
        remaining--;
        if (remaining == 0) return ans;
        temp--;
      }
    }

    return ans;
  }
};
