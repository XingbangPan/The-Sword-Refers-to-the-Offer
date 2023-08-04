using namespace std;
#include "stack"
class CQueue
{
private:
    stack<int> push;
    stack<int> pop;

public:
    CQueue()
    {
    }

    void appendTail(int value)
    {
        push.push(value);
    }

    int deleteHead()
    {
        if (push.empty() && pop.empty())
            return -1;

        if (pop.empty())
        {
            while (!push.empty())
            {
                pop.push(push.top());
                push.pop();
            }
        }

        int result=pop.top();
        pop.pop();
        return result;
    }
};