#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;

    do {
        if(!fast || !fast->next) return nullptr;
        fast = fast->next->next;
        slow = slow->next;
    } while(fast != slow);

    fast = head;
    while(fast != slow){
        slow = slow->next;
        fast = fast->next;
    }

    return fast;
}

int main(){
    //ListNode *list = new ListNode(3, new ListNode(2));

    /*
    int values[] = {3, 2, 0, -4};
    ListNode *list = new ListNode(values[0]);
    ListNode *cur = list;
    for(int i = 1; i < 4; ++i){
        cur->next = new ListNode(values[i]);
        cur = cur->next;
    }
    cur->next = list->next;
    */

    
    ListNode *list = new ListNode(3);
    ListNode *node2 = list->next = new ListNode(2);
    ListNode *node3 = node2->next = new ListNode(0);
    ListNode *node4 = node3->next = new ListNode(-4); 
    node4->next = node2;
    

    cout << detectCycle(list)->val << endl;

    return 0;
}