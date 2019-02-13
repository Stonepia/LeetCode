#include "CommonHeader.h"

class Solution
{
    void justifyLine(vector<string> &words, string &temp, int maxWidth, int begIndx, int endIndx, int wordSize)
    {
        int spaceLeftWidth = 0;
        int spaceRightWidth = 0;
        if (endIndx == begIndx)
        {
            spaceRightWidth = maxWidth - wordSize;
            temp += words.at(begIndx);
            for (int i = 0; i < spaceRightWidth; ++i)
                temp += " ";
            return;
        }
        spaceRightWidth = (maxWidth - wordSize) / (endIndx - begIndx);
        spaceLeftWidth = spaceLeftWidth + 1;
        string spaceRight = "", spaceLeft = "";
        for (int i = 0; i < spaceRightWidth; ++i)
            spaceRight += " ";
        spaceLeft = spaceRight + " ";
        int numLeft = (maxWidth - wordSize) % (endIndx - begIndx);
        int numRight = (endIndx - begIndx) - numLeft;
        for (int i = 0; i < numLeft; ++i)
        {
            temp += words.at(begIndx) + spaceLeft;
            begIndx++;
        }
        for (int i = 0; i < numRight; ++i)
        {
            temp += words.at(begIndx) + spaceRight;
            begIndx++;
        }
        temp += words.at(endIndx);
    }
    void justifyLastLine(vector<string> &words, string &temp, int maxWidth, int begIndx, int endIndx, int wordSize)
    {
        int spaceWidth = maxWidth - wordSize - (endIndx - begIndx);
        string space = "";
        for (int i = 0; i < spaceWidth; ++i)
            space += " ";
        for (int i = begIndx; i < endIndx; ++i)
            temp += (words.at(i) + " ");
        temp += words.at(endIndx) + space;
    }
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        string temp;
        vector<string> res;
        if (words.empty())
            return res;

        int begIndx = 0, endIndx = 0;
        int wordSize = words.at(0).size();

        for (int i = 1; i < words.size(); ++i)
        {

            if (words.at(i).size() +
                    (wordSize + (endIndx - begIndx)) + 1 <=
                maxWidth)
            {
                wordSize += words.at(i).size();
                endIndx = i;
            }

            else
            {
                justifyLine(words, temp, maxWidth, begIndx, endIndx, wordSize);
                res.push_back(temp);
                temp = "";

                wordSize = words.at(i).size();
                begIndx = endIndx = i;
            }
        }
        if (endIndx != words.size())
        {
            justifyLastLine(words, temp, maxWidth, begIndx, endIndx, wordSize);
            res.push_back(temp);
        }
        return res;
    }
};