class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    
            ListNode* result =new ListNode();
            ListNode* resultPointer = result;
            int carry = 0; 
            while (l1||l2){
                int sum =carry;
                if(L1)
            {
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2)
            {
                sum+=l2->val;
                l2=l2->next;
            }
            carry=sum/10;
            resultPoiner->next=new ListNode(sum%10);
            resultPoiner=resultPoiner->next;
            if(carry)
            {
                resultPointer->next=new ListNode(carry);
                resultPointer=resultPointer->next;
            }

    };
/*---------------------------------------------------------
 placeholder node called dummyHead with a value of 0. This node will hold the resulting linked list.
 Initialize a pointer called tail and set it to dummyHead This pointer will keep track of the last node in the result list.
 Initialize a variable called carry to 0. This variable will store the carry value during addition.
 Start a loop that continues until there are no more digits in both input lists (l1 and l2) and there is no remaining carry value.
---------------------------------------------------------*/