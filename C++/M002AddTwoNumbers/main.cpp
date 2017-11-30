#include <iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode preHead(0), *p = &preHead;
        int extra = 0;
        while (l1 || l2 || extra) {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
            extra = sum / 10;
            p->next = new ListNode(sum % 10);
            p = p->next;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        return preHead.next;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    ListNode *l1 = (ListNode*)malloc(sizeof(ListNode));
    ListNode *p = l1;
    ListNode a = ListNode(2);
    p->next = &a;
    p=p->next;
    ListNode b = ListNode(4);
    p->next = &b;
    p=p->next;
    ListNode c = ListNode(3);
    p->next = &c;

    p=l1;
    while (p->next){
        p=p->next;
        cout<<p->val<<endl;
    }


    ListNode *l2 = (ListNode*)malloc(sizeof(ListNode));
    ListNode *q = l2;
    ListNode a2 = ListNode(5);
    q->next = &a2;
    q=q->next;
    ListNode b2 = ListNode(6);
    q->next = &b2;
    q=q->next;
    ListNode c2 = ListNode(4);
    q->next = &c2;

    Solution s;
    ListNode *t = s.addTwoNumbers(l1, l2);

    while (t->next){
        t=t->next;
        cout<<t->val<<endl;
    }
    return 0;
}