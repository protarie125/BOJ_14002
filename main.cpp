#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;

ll n;
vl A;
vl dp, lg;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> n;
  A = vl(n);
  for (auto&& a : A) {
    cin >> a;
  }

  dp = vl(n, 1);
  lg = vl(n, -1);

  ll mx = 1;
  ll mxid = 0;
  for (auto i = 1; i < n; ++i) {
    for (auto j = 0; j < i; ++j) {
      if (A[j] < A[i]) {
        if (dp[i] <= dp[j]) {
          dp[i] = dp[j] + 1;
          if (mx < dp[i]) {
            mx = dp[i];
            mxid = i;
          }
          lg[i] = j;
        }
      }
    }
  }

  vl ans;
  while (0 <= mxid) {
    ans.push_back(A[mxid]);
    mxid = lg[mxid];
  }

  reverse(ans.begin(), ans.end());

  cout << mx << '\n';
  for (const auto& x : ans) {
    cout << x << ' ';
  }

  return 0;
}