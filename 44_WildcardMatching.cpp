#include <vector>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty()) return s.empty();

        int m=s.length();
        int n=p.length();

        vector<vector<bool> > f(m+1,vector<bool>(n+1,false));

        f[0][0] =true;
        for(int i=1;i<=n;i++)
            f[0][i]=(p[i-1]=='*')&&f[0][i-1];

        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++){
                if(p[j-1]!='*')
                    f[i][j]=f[i-1][j-1]&&(p[j-1]=='?'||s[i-1]==p[j-1]);
                else
                    f[i][j]=f[i][j-1]||f[i-1][j];

            }
        return f[m][n];
    }
};