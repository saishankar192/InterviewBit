ListNode* MergeLists(ListNode* a, ListNode* b){

    ListNode *result = NULL;

    if(a==NULL)
        return b;
    else if(b==NULL)
        return a;


    if(a->val <= b->val){
        result = a;
        result->next = MergeLists(a->next, b);
    }
    else{
        result = b;
        result->next = MergeLists(a, b->next);
    }

    return result;
}

void DivideLists(ListNode *A, ListNode **left, ListNode **right){
    ListNode *fastPointer, *slowPointer;
    slowPointer = A;
    fastPointer = A->next;

    while(fastPointer != NULL){
        fastPointer = fastPointer->next;
        if(fastPointer!=NULL){
            slowPointer = slowPointer->next;
            fastPointer = fastPointer->next;
        }
    }

    *left = A;
    *right = slowPointer->next;
    slowPointer->next = NULL;

    return;
}

ListNode* MergeSort(ListNode* A){
    if(A==NULL || A->next == NULL)
        return A;

    ListNode *left, *right;
    DivideLists(A, &left, &right);

    left = MergeSort(left);
    right = MergeSort(right);

    A = MergeLists(left, right);

    return A;
}


ListNode* Solution::sortList(ListNode* A) {
    return MergeSort(A);
}
