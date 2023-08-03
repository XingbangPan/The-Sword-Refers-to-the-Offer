#include "Solution.h"
#include "iostream"
#include "vector"

Node* createListHelper(vector<pair<int, int>> &in,int index,unordered_map<int,Node*>&dic)
{
    //递归终止条件
    if(index==in.size()) return nullptr;

    //单层递归逻辑
    
    Node* cur=new Node(in[index].first);
    dic.insert({index,cur});

    Node* next= createListHelper(in,index+1,dic);

    cur->next=next;
    cur->random=dic[in[index].second];

    return cur;
}


Node *createList(vector<pair<int, int>> &in)
{
    unordered_map<int,Node*>dic;
    dic.insert({-1,nullptr});
    return createListHelper(in,0,dic);
    
}


void printListHelper(Node* head,int index,unordered_map<Node*,int>&dic)
{
    //递归终止条件
    if(head==nullptr) return;

    //单层递归逻辑
    dic.insert({head,index});
    printListHelper(head->next,index+1,dic);
    cout<<"第"<<index<<"个节点:value="<<head->val<<" random="<<dic[head->random]<<endl;

}

void printList(Node* head)
{
    unordered_map<Node*,int>dic;
    dic.insert({nullptr,-1});   //加入键值对：空节点地址对应的index为-1
    printListHelper(head,0,dic);
}

int main()
{
    vector<pair<int, int>> in = {{7, -1}, {13, 0}, {11, 4}, {10, 2}, {1, 0}};
    Node *head = createList(in);
    printList(head);

    cout<<endl;

    Solution s;
    Node* copyHead=s.copyRandomList(head);
    printList(copyHead);
}