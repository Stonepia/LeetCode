
//Similar Questions: 44. Wildcard Matching

class Solution {
public:
// regular Solution
/*
    bool isMatch(string s, string p) {
        if (p.empty())    return s.empty();
    if(p[1]=='*')
        return (isMatch(s,p.substr(2))|| 
        !s.empty() &&(s[0]==p[0]||p[0]=='.')
        &&isMatch(s.substr(1),p));
    else
        return !s.e mpty()&&(s[0]==p[0]||p[0]=='.')
        &&isMatch(s.substr(1),p.substr(1));
    }
*/
//DP solution 

    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();
        int m=s.length();
        int n=p.length();
// f[i][j] matches the s[0:i-1] and p[0:j-1]
        vector<vector<bool>> f(m+1,vector<bool>(n+1,false));

        f[0][0]=true;

        for(int i=1;i<=m;i++)
            f[i][0]=false;
        for(int j=1;j<=n;j++)
            f[0][j]= (j>1)&&(p[j-1]=='*')&&f[0][j-2];
        
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++){
                if(p[j-1]!='*')
                    f[i][j]=f[i-1][j-1]&&((s[i-1]==p[j-1])||p[j-1]=='.');
                else
                    f[i][j]=f[i][j-2]||(s[i-1]==p[j-2]||p[j-2]=='.')&&f[i-1][j];

            }
    return f[m][n];
    }
};