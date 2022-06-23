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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        /* ListNode* dummy = new ListNode(-1) ;
         ListNode* temp = dummy ;
         while(list1 != NULL && list2!= NULL)
         {
             if(list1->val <= list2->val)
             {
                 temp->next = list1 , list1 = list1->next ;
                 temp = temp->next ;
             }
             else
             {
                 temp->next = list2 ;
                 list2= list2->next ;
                 temp = temp->next ;
             }
         }
         if(list1)
             temp->next = list1;
         if(list2)
             temp->next = list2 ;
         return dummy->next ;
         */
        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;

        if (list1->val > list2->val)
            swap(list1, list2);

        ListNode *ans = list1;

        while (list1 != NULL && list2 != NULL)
        {
            ListNode *temp;
            while (list1 != NULL && list1->val <= list2->val)
            {
                temp = list1;
                list1 = list1->next;
            }
            temp->next = list2;
            swap(list1, list2);
        }
        return ans;
    }
};