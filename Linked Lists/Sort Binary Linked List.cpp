/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A) {
    if(A==NULL || A->next == NULL)
        return A;
    
    ListNode *head, *lastNode, *prev, *temp, *checkNode;
    head = A;

    while(head->next){
        head = head->next;
    }
    lastNode = head;
    checkNode = head;
    head = A;
    prev = NULL;

    while(head!=checkNode){
        if(head->val == 1){
            if(prev){
                prev->next = head->next;
            }
            else{
                A = head->next;
            }

            temp = head->next;
            head->next = NULL;
            lastNode->next = head;
            lastNode = lastNode->next;
            head = temp;
        }
        else{
            prev = head;
            head = head->next;
        }
    }
    return A;
}
