#include <bits/stdc++.h>
using namespace std;






int memo[10010];                                 // old limit: up to 10^4
int LIS(const vector<int> &A, int i) {           // O(n^2) overall
  if (i == 0) 
    return 1;
  if (memo[i] != -1) 
    return memo[i];                              // was computed before
  memo[i] = 1;                                   // LIS can start anywhere
  for (int j = 0; j < i; ++j)                    // O(n) here
    if (A[j] < A[i])                             // increasing condition
      memo[i] = max(memo[i], LIS(j)+1);                  // pick the max
  return memo[i];
}
// result: memo[A.size() - 1]





















int LIS_log(const vector<int> &A) {           //
  vector<int> L(A.size(), 100000000);
  int k = 0;
  for (int i = 0; i < n; ++i) {                  // O(n)
    int pos = lower_bound(L.begin(), L.begin()+k, A[i]) - L.begin();
    L[pos] = min(L[pos], A[i]);

    if (pos == k) {                              // can extend LIS?
      k = pos + 1;                               // k = longer LIS by +1
    }
  }

  printf("Final LIS is of length %d: ", k);
}








