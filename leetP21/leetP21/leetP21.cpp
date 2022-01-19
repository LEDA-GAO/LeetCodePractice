// leetP21.cpp : 
//

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        bool firstnode = true;
        ListNode* head = NULL;
        ListNode* cur = NULL;
        int val;

        while (list1 || list2) {
            if (!list2 || (list1 && list1->val < list2->val)) {
                val = list1->val;
                list1 = list1->next;
            }
            else {
                val = list2->val;
                list2 = list2->next;
            }

            if (firstnode) {
                head = new ListNode(val);
                cur = head;
                firstnode = false;
            }
            else {
                cur->next = new ListNode(val);
                cur = cur->next;
            }
        }

        return head;

      

    }
};

int main()
{   
    ListNode* head1 = new ListNode(1);
    ListNode* head2 = new ListNode(2);
    ListNode* cur1 = new ListNode();
    ListNode* cur2 = new ListNode();
    cur1 = head1;
    cur2 = head2;
    for (size_t i = 2; i < 4; i++)
    {        
        cur1->next = new ListNode(i);
        cur1 = cur1->next;
    }

    for (size_t i = 3; i < 5; i++)
    {
        cur2->next = new ListNode(i);
        cur2 = cur2->next;
    }

    cur1 = head1;
    while (cur1) {
        cout << "list1    " << cur1->val << endl;
        cur1 = cur1->next;
    }

    cur2 = head2;
    while (cur2) {
        cout << "list2    " << cur2->val << endl;
        cur2 = cur2->next;
    }


    Solution solution;
    ListNode* head3 = new ListNode();
    head3 = solution.mergeTwoLists(head1, head2);

    cur2 = head3;
    while (cur2) {
        cout << "Merged List " << cur2->val << endl;
        cur2 = cur2->next;
    }
}


