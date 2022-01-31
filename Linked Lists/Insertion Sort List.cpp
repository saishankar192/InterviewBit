/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::insertionSortList(ListNode* A) {
    ListNode *currNode, *prevNode, *tempNode, *prev;
    currNode = A;
    int cnt = 0;

    while(currNode){
        cnt++;
        currNode = currNode->next;
    }

    currNode = A;
    prevNode = NULL;
    for(int i=0;i<cnt;i++){
        tempNode = A;
        prev = NULL;
        bool flag = false;
        while(tempNode != currNode){
            if(tempNode->val > currNode->val){
                prevNode->next = currNode->next;
                if(prev){
                    prev->next = currNode;
                    currNode->next = tempNode;
                }
                else{
                    currNode->next = A;
                    A = currNode;
                }
                currNode = prevNode->next;
                flag = true;
                break;
            }
            prev = tempNode;
            tempNode = tempNode->next;
        }
        if(!flag){
            prevNode = currNode;
            currNode = currNode->next;
        }
    }
    return A;
}