class Solution {
public:
    int maxDepth(string s) {
        int depth = 0;
        int ans = 0;

        for (char ch : s) {
            if (ch == '(') {
                depth++;
                if (depth > ans)
                    ans = depth;
            }
            else if (ch == ')') {
                depth--;
            }
        }

        return ans;
    }
};