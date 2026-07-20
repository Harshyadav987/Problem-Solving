/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
void reversese(ListNode* start, ListNode* end) {
    vector<int> victim;

    ListNode* temp = start;
    while (temp != end) {
        victim.push_back(temp->val);
        temp = temp->next;
    }
    victim.push_back(end->val);

    reverse(victim.begin(), victim.end());

    temp = start;
    for (int x : victim) {
        temp->val = x;
        temp = temp->next;
    }
}
ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (!head || left == right)
        return head;

    ListNode* start = head;
    ListNode* end = head;

    for (int i = 1; i < left; i++)
        start = start->next;

    for (int i = 1; i < right; i++)
        end = end->next;

    reversese(start, end);

    return head;
}
};