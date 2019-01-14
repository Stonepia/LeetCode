
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        gen("", 0, 0, n, res);
        return res;

    }
    void gen(string pre, int open, int close,int n , vector<string> & res){
        if(open < n)
            gen(pre + "(", open + 1, close, n, res);
        if(close<open)
            gen(pre + ")", open, close + 1, n, res);
        if(close==n&&close==open)
            res.push_back(pre);
    }
};