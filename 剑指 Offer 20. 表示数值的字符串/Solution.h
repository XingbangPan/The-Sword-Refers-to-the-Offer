using namespace std;
#include"string"
#include"unordered_map"
#include"vector"

//状态转移的动作用哈希表unordered<char,int>来存储，key值代表符号类型，value值代表转换后的状态
//每一个状态都有一个状态转移动作的哈希表，那么10个状态就用一个vector<unordered_map<char,int>>来存储
//

class Solution
{
private:
vector<unordered_map<char,int>>state;
unordered_map<char,int>temp;

public:
void stateInitialization()
{
    //状态1
    
}

};