#include "CommonHeader.h"
#include <sstream>
using namespace std;


class Solution
{
  public:
    string simplifyPath(string path)
    {
        string res, tmp;
        vector<string> stk;
        istringstream ss (path); // istringstream needs <sstream>
                                 // You can also split string using string[] splits = path.split(".")
        while(getline(ss,tmp,'/')){
            if(tmp == "" or tmp==".")
                continue;
            if(tmp==".." and !stk.empty())
                stk.pop_back();
            else if (tmp!="..")
                stk.push_back(tmp);
        }
        for(auto str:stk)
            res += "/" + str;
        return res.empty() ? "/" : res;
    }
};