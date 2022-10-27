#include <iostream>
using namespace std;


  struct ListNode 
  {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution 
{
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) 
    {
       // one or both of the lists are null
       // there is no intersection
        if (headA == NULL || headB == NULL) 
        {
            return NULL;
        }

        // pointers to help us traverse through each linked list
        ListNode* a_pointer = headA;
        ListNode* b_pointer = headB;

        while (a_pointer != b_pointer)
        {

            // we have reached the end of Linked List A
            if (a_pointer == NULL) 
            {

                // begin searching Linked List B
                a_pointer = headB;
            }

            // we are not at the end of Linked List A
            // continue to traverse through Linked List A
            else 
            {
                a_pointer = a_pointer->next;
            }


            // we have reached the end of Linked List B
            if (b_pointer == NULL)
            {

                // begin searching Linked List A
                b_pointer = headA;
            }

            // we are not at the end of Linked List B
            // continue to traverse through Linked List B
            else 
            {
                b_pointer = b_pointer->next;
            }
        }

        // while loop will loop until we find intersection point
        return a_pointer;
    }
};

int main()
{
    Solution solution;

    ListNode four(4);

    ListNode two(2);
    two.next = &four;

    ListNode one(1);
    one.next = &two;

    ListNode nine(9);
    nine.next = &one;

    ListNode aHead(1);
    aHead.next = &nine;

    ListNode bHead(3);
    bHead.next = &two;

    ListNode *answer = solution.getIntersectionNode(&aHead, &bHead);
    cout << "Example One : " << answer->val << endl;
   
	return 0;
}
