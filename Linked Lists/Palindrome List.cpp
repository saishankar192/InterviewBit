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

ListNode* CopyOfA(ListNode* A){
    ListNode* B = new ListNode(A->val);
    ListNode* ans = B;

    A = A->next;
    
    while(A){
        ListNode* temp = new ListNode(A->val);
        B->next = temp;

        B = B->next;
        A = A->next;
    }
    return ans;
}

int Solution::lPalin(ListNode* A) {
    ListNode *B = CopyOfA(A);
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
