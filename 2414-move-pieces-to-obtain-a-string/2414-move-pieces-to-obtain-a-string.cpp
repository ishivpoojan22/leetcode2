class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.length();
        string startStripped, targetStripped;
        for (char c : start)
            if (c != '_')
                startStripped += c;
        for (char c : target)
            if (c != '_')
                targetStripped += c;
        if (startStripped != targetStripped)
            return false;

        int i = 0, j = 0;
        while (i < n && j < n) {
            while (i < n && start[i] == '_')
                i++;
            while (j < n && target[j] == '_')
                j++;

            if (i < n && j < n) {
                if (start[i] != target[j])
                    return false;
                if (start[i] == 'L' && i < j)
                    return false;
                if (start[i] == 'R' && i > j)
                    return false;
                i++;
                j++;
            }
        }

        return true;
    }
};