/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
*/

ListNode* ReverseList(ListNode* A){
    ListNode *prev=NULL, *nextNode, *currNode = A;

    while(currNode){
        nextNode = currNode->next;
        currNode->next = prev;
        prev = currNode;
        currNode = nextNode;
    }
    return prev;
}

ListNode* SecondHalf(ListNode* A){
    ListNode* slowPointer, *fastPointer;
    slowPointer = A;
    fastPointer = A->next;

    while(fastPointer){
        fastPointer = fastPointer->next;
        if(fastPointer){
            slowPointer = slowPointer->next;
            fastPointer = fastPointer->next;
        }
    }
    ListNode* temp = slowPointer->next;
    slowPointer->next = NULL;

    return temp;
}

int Solution::lPalin(ListNode* A) {
    ListNode *B = SecondHalf(A);
    ListNode *reversedList = ReverseList(B);
    int flag = 1;

    while(reversedList){
        if(A->val != reversedList->val){
            flag = 0;
            break;
        }
        reversedList = reversedList->next;
        A = A->next;
    }

    return flag;
}
