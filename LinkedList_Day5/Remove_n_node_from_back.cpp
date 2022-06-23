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
    // int counter(ListNode* head)
    // {
    //     int cnt = 0 ;
    //     while(head != NULL)
    //         cnt++, head=head->next ;
    //     return cnt ;
    // }
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // O(2*n)
        // int cnt = counter(head) ;
        // ListNode* temp = head ;
        // ListNode* prev = NULL ;
        // int x = cnt-n ;
        // if(x == 0) return head->next ;
        // while(x--)
        // {
        //     prev = temp ;
        //     temp = temp->next ;
        // }
        // prev->next = temp->next ;
        // return head;

        // O(n) approach
        ListNode *temp = new ListNode(-1);
        ListNode *start = temp;
        ListNode *end = temp;

        temp->next = head;

        while (n--)
            end = end->next;

        while (end->next != NULL)
        {
            start = start->next;
            end = end->next;
        }
        start->next = start->next->next;
        return temp->next;
    }
};