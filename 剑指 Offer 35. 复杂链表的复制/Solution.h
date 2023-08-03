using namespace std;
#include"unordered_map"
#include"iostream"
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = nullptr;
    }
};

class Solution
{
    // 利用哈希表存储原节点地址和复制节点地址的对应关系
private:
    unordered_map<Node *, Node *> dic;

public:
    // 递归
    // 解问题的思想
    // 递归函数，创建节点，更新节点next指针和random指针
    void recurse(Node *origin)
    {
        // 递归终止条件
        if (origin == NULL)
            return;

        // 单层递归逻辑
        Node *copy = new Node(origin->val);
        dic.insert({origin, copy});

        recurse(origin->next);

        copy->next = dic[origin->next];
        copy->random = dic[origin->random];
    }

    Node *copyRandomList(Node *head)
    {
        recurse(head);

        return dic[head];
    }
};