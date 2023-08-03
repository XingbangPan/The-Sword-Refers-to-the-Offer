# 解题思路：
维护三个节点 pre,cur,next


遍历整个链表
```c++
//反转
cur->next=pre;
//更新三个节点
pre=cur;
cur=next;
next=next->next
```

注意使用头结点技巧，减少边界判断逻辑

# 返回值
终止条件：`while(head!=null)`
返回值：`return pre`;

--- 

# 递归解题思路

专注于两个节点`pre,cur`

当然是后序遍历，因为在进入下一层递归时，需要用到`cur->next`信息，如果前序遍历，递归之前就反转了，进入下一层递归时就获取不到`cur->next`信息了！

编写代码见leetcode提交记录

