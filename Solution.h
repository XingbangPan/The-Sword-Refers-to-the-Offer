using namespace std;
#include "string"
#include "unordered_map"
#include "vector"

// 状态转移的动作用哈希表unordered<char,int>来存储，key值代表符号类型，value值代表转换后的状态
// 每一个状态都有一个状态转移动作的哈希表，那么10个状态就用一个vector<unordered_map<char,int>>来存储
//

class Solution
{
private:
    vector<unordered_map<char, int>> state;
    unordered_map<char, int> temp;

public:
    bool isNumber(string s)
    {
        // 初始化state表
        // 0:起始的空格
        temp.insert({' ', 0});
        temp.insert({'d', 2});
        temp.insert({'s', 1});
        temp.insert({'.', 4});
        state.push_back(temp);
        temp.clear();
        // 1:符号位
        temp.insert({'d', 2});
        temp.insert({'.', 4});
        state.push_back(temp);
        temp.clear();
        // 2:整数部分
        temp.insert({'d', 2});
        temp.insert({'e', 6});
        temp.insert({'.', 3});
        temp.insert({' ',9});
        state.push_back(temp);
        temp.clear();
        // 3:左侧有整数的小数点
        temp.insert({'e', 6});
        temp.insert({'d', 5});
        temp.insert({' ',9});
        state.push_back(temp);
        temp.clear();
        // 4:左侧无整数的小数点
        temp.insert({'d', 5});
        state.push_back(temp);
        temp.clear();
        // 5:小数部分
        temp.insert({'d', 5});
        temp.insert({'e', 6});
        temp.insert({' ',9});
        state.push_back(temp);
        temp.clear();
        // 6:字符eE
        temp.insert({'d', 8});
        temp.insert({'s', 7});
        state.push_back(temp);
        temp.clear();
        // 7:指数部分的符号位
        temp.insert({'d', 8});
        state.push_back(temp);
        temp.clear();
        // 8:整数部分
        temp.insert({'d', 8});
        temp.insert({' ', 9});
        state.push_back(temp);
        temp.clear();
        // 9:末尾的空格
        temp.insert({' ', 9});
        state.push_back(temp);
        temp.clear();

        //初始化当前状态
        int curState = 0;

        for (auto c : s)
        {
            char charType;
            if (c == ' ')
                charType = c;
            else if (c == '+' || c == '-')
                charType = 's';
            else if (c >= '0' && c <= '9')
                charType = 'd';
            else if (c == '.')
                charType = c;
            else if (c == 'e' || c == 'E')
                charType = 'e';
            else
                return false;

            // 状态转移失败！
            if (state[curState].find(charType) == state[curState].end())
                return false;
            // 状态转移成功
            else
                curState = state[curState][charType];
        }

        // 判断最终状态是否属于接受状态！
        if (curState == 2 || curState == 3 || curState == 5 || curState == 8 || curState == 9)
            return true;
        else
            return false;
    }
};