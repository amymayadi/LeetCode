#include <iostream>
#include <assert.h>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *t1 = l1;
        ListNode *t2 = l2;
        ListNode *head = (ListNode *)malloc(sizeof(ListNode));;
        ListNode *q = head;
        int extra =0;
        while(t1->next&&t2->next) {
            t1=t1->next;
            t2=t2->next;
            ListNode *p= (ListNode *)malloc(sizeof(ListNode));
            p->next = NULL;
            q->next=p;
            q=p;

            int a = t1->val+t2->val+extra;
            if (a >= 10) {
                p->val = a - 10;
                extra = 1;
            } else{
                p->val = a;
                extra =0;
            }
            //assert(p->val!=7);
        }

        while(t1->next){
            ListNode *p= (ListNode *)malloc(sizeof(ListNode));
            p->next = NULL;
            q->next= p;
            p->val = t1->val;
        }

        while(t2->next){
            ListNode *p= (ListNode *)malloc(sizeof(ListNode));
            p->next = NULL;
            q->next= p;
            p->val = t2->val;
        }

        return head;
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