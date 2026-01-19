// UID: 24BCS12643
// Leet Code: 142. Linked List Cycle II
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (!head)
            return NULL;

        ListNode *slow = head, *fast = head;

        // Stage 1: detect cycle
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                // Stage 2: find cycle start
                slow = head;
                while (slow != fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};