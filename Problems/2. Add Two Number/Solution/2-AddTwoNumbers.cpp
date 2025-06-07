#include <iostream>
#include <list>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {} 
};

class Solution {
    public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* current = dummyHead;
        int carry = 0;
        while (l1 != NULL || l2 != NULL || carry != 0) {
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;
            int sum = carry + x + y;
            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
        }
        return dummyHead->next;
    }
};

int main() {
    // Example usage
    ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3))); // Represents 342
    ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4))); // Represents 465

    Solution solution;
    ListNode* result = solution.addTwoNumbers(l1, l2);

    // Print the result
    while (result != NULL) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}