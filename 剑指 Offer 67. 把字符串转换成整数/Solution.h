using namespace std;
#include "unordered_map"
#include "vector"
#include "string"
#include"iostream"

class Solution
{
private:
    vector<unordered_map<char, int>> state;
    unordered_map<char, int> temp;
#define BOUNDARY 214748364
public:
    int strToInt(string str)
    {
        // 初始化state
        // 0:起始的空格
        temp.insert({' ', 0});
        temp.insert({'s', 1});
        temp.insert({'d', 2});
        state.push_back(temp);
        temp.clear();
        // 1:符号位
        temp.insert({'d', 2});
        state.push_back(temp);
        temp.clear();
        // 2:整数部分
        temp.insert({'d', 2});
        state.push_back(temp);
        temp.clear();

        for(auto temp:state)
        {
            for(auto p:temp)
            {
                cout<<"{"<<p.first<<","<<p.second<<"}"<<endl;
            }
            cout<<endl;
        }

        // 初始化当前状态、符号位、结果
        int curState = 0;
        int sign = 1;
        int result = 0;

        // 状态转移
        for (char c : str)
        {
            char charType;
            if (c == ' ')
                charType = c;
            else if (c == '+' || c == '-')
                charType = 's';
            else if (c >= '0' && c <= '9')
                charType = 'd';
            else
                break; // 违法输入，停止状态转移
            cout<<"c="<<c<<" charType="<<charType<<endl;

            if (state[curState].find(charType) == state[curState].end()) // 状态转移失败
                break;
            else
                curState = state[curState][charType];
            if (curState == 1)
                sign = (c == '+' ? 1 : -1);
            if (curState == 2) // 更新结果
            {
                // 判断是否越界
                if (result > BOUNDARY || (result == BOUNDARY && c > '7'))
                    return sign == 1 ? INT_MAX : INT_MIN;
                else
                    result = result * 10 + (c - '0');
            }
        }
        return sign*result;
    }
};