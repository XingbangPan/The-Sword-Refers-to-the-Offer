#include "Solution.h"
#include "iostream"

int main()
{
    Solution s;
    vector<int> input = {1,11,14};
    vector<int> result = s.exchange(input);
    for(auto num:result)
    {
        cout<<num<<" ";
    }
}