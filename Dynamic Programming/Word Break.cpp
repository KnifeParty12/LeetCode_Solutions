class Solution
{
public:
    bool find(vector<string> &dict, string str)
    {
        for (int i = 0; i < dict.size(); i++)
        {
            if (dict[i] == str)
                return true;
        }
        return false;
    }

    bool solve(string s, vector<string> &wordDict, vector<int> &memo)
    {
        if (s.empty())
            return true;
        int n = s.length();

        if (memo[n] != -1)
            return memo[n];

        memo[n] = 0;

        for (int i = 1; i <= n; i++)
        {
            string prefix = s.substr(0, i);
            if (find(wordDict, prefix) && solve(s.substr(i), wordDict, memo))
                memo[n] = 1;
        }

        return memo[n];
    }

    bool wordBreak(string s, vector<string> &wordDict)
    {

        int n = s.length();
        vector<int> memo(n + 1, -1);
        return solve(s, wordDict, memo);
    }
};
