class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int ans = 0;
        int i = 0;
        int maxfreq = 0;
        unordered_map<char, int> mp;

        for (int j = 0; j < n; j++) {
            mp[s[j]]++;
            maxfreq = max(maxfreq, mp[s[j]]);

            while ((j - i + 1) - maxfreq > k) {
                mp[s[i]]--;
                i++;
            }

            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};
