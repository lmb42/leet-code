#include <iostream>
#include <vector>
#include "add_two_numbers_solution.cpp"
using namespace std;

ListNode* createList(vector<int> vals) {
    ListNode dummy;
    ListNode* current = &dummy;
    for (int v : vals) {
        current->next = new ListNode(v);
        current = current->next;
    }
    return dummy.next;
}

void printList(ListNode* node) {
    while (node) {
        cout << node->val;
        if (node->next) cout << " -> ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    Solution sol;
    ListNode* l1 = createList({2,4,3});
    ListNode* l2 = createList({5,6,4});

    ListNode* result = sol.addTwoNumbers(l1, l2);

    printList(result);  // Expected: 7 -> 0 -> 8
    return 0;
}
