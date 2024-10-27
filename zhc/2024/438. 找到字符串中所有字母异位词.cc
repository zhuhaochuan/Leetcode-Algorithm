class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();
        if (n < m) return {};
        vector<int> res;
        vector<int> table(26, 0);
        for (int i=0; i<m; i++) {
            table[p[i] - 'a']++;
        }
        int l = 0, r = 0;
        vector<int> cur(26, 0);
        for (int i=0; i<m; i++) {
            cur[s[i]-'a']++;
        }
        r = m-1;
        while(r < n) {
            // cout << l << r << endl;
            // if (r - l + 1 == m) {
                bool eq = true;
                for (int i=0; i<26; i++) {
                    if (table[i] != cur[i]) {
                        eq = false;
                        break;
                    }
                }
                if (eq) {
                    res.push_back(l);
                }
                cur[s[l]-'a']--;
                l++;
                r++;
                if (r < n) cur[s[r]-'a']++;
            // }
        }
        return res;
    }
};