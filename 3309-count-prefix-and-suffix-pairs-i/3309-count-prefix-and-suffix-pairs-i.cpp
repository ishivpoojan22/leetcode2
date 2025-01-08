class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                string& str1 = words[i];
                string& str2 = words[j];

                int len1 = str1.length();
                int len2 = str2.length();

                if (len1 <= len2) {
                    bool isPrefix = true, isSuffix = true;

                    for (int k = 0; k < len1; k++) {
                        if (str1[k] != str2[k]) {
                            isPrefix = false;
                            break;
                        }
                    }

                    for (int k = 0; k < len1; k++) {
                        if (str1[k] != str2[len2 - len1 + k]) {
                            isSuffix = false;
                            break;
                        }
                    }

                    if (isPrefix && isSuffix) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};