class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        const string& first = strs[0];
        const size_t n = strs.size();

        for (size_t i = 0; i < first.size(); i++) {
            char c = first[i];
            for (size_t j = 1; j < n; j++) {
                if (i == strs[j].size() || strs[j][i] != c) {
                    return first.substr(0, i);
                }
            }
        }
        return first;
    }
};