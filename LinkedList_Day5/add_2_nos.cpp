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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {

        ListNode *dummy = new ListNode(-1);
        ListNode *temp = dummy;
        int carry = 0;
        while (l1 != NULL && l2 != NULL)
        {
            int sum = l1->val + l2->val + carry;
            dummy->next = new ListNode(sum % 10);
            sum = sum / 10;
            carry = sum % 10;
            dummy = dummy->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l1 != NULL)
        {
            // cout<<"SD"<<endl ;
            while (l1 != NULL)
            {
                int sum = l1->val + carry;
                // cout<<sum<<endl;
                dummy->next = new ListNode(sum % 10);
                sum = sum / 10;
                carry = sum % 10;
                dummy = dummy->next;
                l1 = l1->next;
            }
        }
        else if (l2 != NULL)
        {
            while (l2 != NULL)
            {
                int sum = l2->val + carry;
                dummy->next = new ListNode(sum % 10);
                sum = sum / 10;
                carry = sum % 10;
                dummy = dummy->next;
                l2 = l2->next;
            }
        }

        if (carry)
            dummy->next = new ListNode(carry);
        return temp->next;
    }
};