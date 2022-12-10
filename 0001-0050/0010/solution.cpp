#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        s = ' ' + s, p = ' ' + p;
        vector<vector<bool>> f(n + 1, vector<bool>(m + 1));
        f[0][0] = true;
        for (int i = 0; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (j + 1 <= m && p[j + 1] == '*') continue;
                if (p[j] != '*') {
                    f[i][j] = i && j && f[i - 1][j - 1] && (s[i] == p[j] || p[j] == '.');
                } else {
                    f[i][j] = (j >= 2 && f[i][j - 2]) || (i && j && f[i - 1][j] && (s[i] == p[j - 1] || p[j - 1] == '.'));
                }
            }
        }
        return f[n][m];
    }
};

struct Example {
    string s, p;
    bool ans;
};

int main() {
    vector<Example> examples = {
        {"aa", "a", false},
        {"aa", "a*", true},
        {"ab", ".*", true},
    };
    
    Solution *solve = new Solution();
    for (int i = 0; i < examples.size(); i++) {
        bool ans = solve->isMatch(examples[i].s, examples[i].p);
        if (ans == examples[i].ans) {
            cout << "PASS: CASE " << i << endl;
        } else {
            cout << "FAIL: CASE " << i << endl;
        }
    }
    
    return 0;
}