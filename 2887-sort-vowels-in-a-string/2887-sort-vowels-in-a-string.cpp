class Solution {
public:
    string sortVowels(string s) {
        string vowels = "aeiouAEIOU";
        unordered_set<char> vowelSet(vowels.begin(), vowels.end());
 
        vector<char> vowelChars;
        for (char c : s) {
            if (vowelSet.count(c)) {
                vowelChars.push_back(c);
            }
        }

 
        sort(vowelChars.begin(), vowelChars.end());

 
        string result = s;
        int idx = 0;
        for (int i = 0; i < s.size(); i++) {
            if (vowelSet.count(s[i])) {
                result[i] = vowelChars[idx++];
            }
        }

        return result;
    }
};