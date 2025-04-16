#include <bits/stdc++.h>

using namespace std;

void lcs(string s1, string s2) {

int n = s1.size();
int m = s2.size();

vector<vector<int>> dp(n + 1, vector < int > (m + 1, 0));
for (int i = 0; i <= n; i++) {
    dp[i][0] = 0;
}
for (int i = 0; i <= m; i++) {
    dp[0][i] = 0;
}

for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
        if (s1[i - 1] == s2[j - 1])
            dp[i][j] = 1 + dp[i - 1][j - 1];
        else
            dp[i][j] = 0 + max(dp[i - 1][j], dp[i][j - 1]);
    }
}

  int len = dp[n][m];
  int i = n;
  int j = m;

  int index = len - 1;
  string str = "";
  for (int k = 1; k <= len; k++) {
    str += "$"; // dummy string
  }

  while (i > 0 && j > 0) {
    if (s1[i - 1] == s2[j - 1]) {
      str[index] = s1[i - 1];
      index--;
      i--;
      j--;
    } else if (s1[i - 1] > s2[j - 1]) {
      i--;
    } else j--;
  }
  cout << str;
}

int main() {

  string s1 = "abcdek";
  string s2 = "acdfk";

  cout << "The Longest Common Subsequence is ";
  lcs(s1, s2);
}