class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //Using SLide Window
        unordered_map<char,int> mymap;
        unordered_map<char,int> ::iterator it;
        int len =0; 
        int i=-1;
        for(int j=0;j<s.length();j++){
            it = mymap.find(s.at(j));
            if(it != mymap.end())
            //Have repeteaded charactors
                i = std::max(it->second,i)
            mymap[s.at(j)]=j;
            len = std::max(len,(j-i));
        }
        return len;
    }
};