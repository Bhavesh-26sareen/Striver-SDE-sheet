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
class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        //         ListNode* head1 = head ;
        //         int cnt = 0 ;
        //         while(head1 != NULL)
        //         {
        //             cnt++ ;
        //             head1=head1->next ;
        //         }
        //         int mid = cnt/2 ;
        //         while(mid--)
        //             head = head->next ;

        //         return head ;

        // 2nd approach
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};