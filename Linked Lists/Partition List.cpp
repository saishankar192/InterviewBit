/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) {
    if(A==NULL || A->next==NULL)
        return A;
    
    ListNode *prevNode, *nextNode, *currNode, *sep;
    currNode = A;
    prevNode = NULL;
    sep = NULL;

    while(currNode){
        if(currNode->val < B){
            if(sep && prevNode){
                prevNode->next = currNode->next;
                currNode->next = sep->next;
                sep->next = currNode;
                currNode = prevNode->next;
                sep = sep->next;
            }
            else if(prevNode){
                prevNode->next = currNode->next;
                currNode->next = A;
                A = currNode;
                sep = currNode;
                currNode = prevNode->next;
            }
            else{
                sep = currNode;
                currNode = currNode -> next;
            }
        }
        else{
            prevNode = currNode;
            currNode = currNode -> next;
        }
    }
    return A;
}
