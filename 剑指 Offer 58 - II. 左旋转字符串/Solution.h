#include"string"
using namespace std;


class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string result;

        result.append(s.substr(n,s.size()-n));
        result.append(s.substr(0,n));

        return result;

    }
};