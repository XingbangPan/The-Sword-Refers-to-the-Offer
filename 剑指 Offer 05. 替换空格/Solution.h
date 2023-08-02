using namespace std;

#include"string"


class Solution {
public:
    string replaceSpace(string s) {
       
       string result;
       
       for(auto c:s)
       {
        if(c==' ') result.append("%20");

        else result.push_back(c);
       }

       return result;


    }
};