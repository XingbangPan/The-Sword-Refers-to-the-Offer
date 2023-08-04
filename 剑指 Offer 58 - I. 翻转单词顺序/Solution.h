using namespace std;
#include "string"
#include "vector"
#include "algorithm"
#include "iostream"
class Solution
{

public:
    string reverseWords(string s)
    {

        string result;

        int rend=s.size()-1;

        while(1)
        {
            //找rbegin
            int rbegin=rend;
            while(rbegin>=0&&s[rbegin]==' ') rbegin--;
            if(rbegin==-1) break;

            //找rend
            rend=rbegin;
            while(rend>=0&&s[rend]!=' ') rend--;
            result.append(s.substr(rend+1,rbegin-rend));
            result+=' ';

        }

        if(!result.empty()) result.pop_back();

        return result;

       
    }
};