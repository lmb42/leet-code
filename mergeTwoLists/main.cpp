#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

// מבנה הצומת
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// פתרון השאלה
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;

        // מיזוג לפי סדר עולה
        while (list1 && list2) {
            if (list1->val < list2->val) {
                current->next = new ListNode(list1->val);
                list1 = list1->next;
            } else {
                current->next = new ListNode(list2->val);
                list2 = list2->next;
            }
            current = current->next;
        }

        // חיבור שארית אחת הרשימות (אם נותרה)
        while (list1) {
            current->next = new ListNode(list1->val);
            list1 = list1->next;
            current = current->next;
        }

        while (list2) {
            current->next = new ListNode(list2->val);
            list2 = list2->next;
            current = current->next;
        }

        return dummy->next;
    }
};

// פונקציית עזר ליצירת רשימה מקושרת מוקטור
ListNode* createList(const vector<int>& values) {
    ListNode dummy(0);
    ListNode* current = &dummy;
    for (int val : values) {
        current->next = new ListNode(val);
        current = current->next;
    }
    return dummy.next;
}

// הדפסת רשימה
void printList(ListNode* node) {
    while (node) {
        cout << node->val;
        if (node->next) cout << " -> ";
        node = node->next;
    }
    cout << endl;
}

// השוואת שתי רשימות
bool isEqual(ListNode* a, ListNode* b) {
    while (a && b) {
        if (a->val != b->val) return false;
        a = a->next;
        b = b->next;
    }
    return a == nullptr && b == nullptr;
}

int main() {
    Solution sol;

    // קלט: שתי רשימות
    vector<int> list1_vals = {1, 2, 4};
    vector<int> list2_vals = {1, 3, 4};

    ListNode* list1 = createList(list1_vals);
    ListNode* list2 = createList(list2_vals);

    // מיזוג והדפסה
    ListNode* merged = sol.mergeTwoLists(list1, list2);

    cout << "Merged list: ";
    printList(merged);

    // בדיקה מול תוצאה מצופה
    ListNode* expected = createList({1, 1, 2, 3, 4, 4});
    assert(isEqual(merged, expected));

    cout << "✅ Test passed!" << endl;
    return 0;
}
