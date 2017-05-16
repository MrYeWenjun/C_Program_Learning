bool hasCycle(struct ListNode *head) {
    struct ListNode *fast = head;
    struct ListNode *slow = head;

    while( fast != NULL && fast->next != NULL )
    {
        fast = fast->next->next;
        slow = slow->next;
        if( fast == slow )
            break;
    }

    return !( Fast == NULL || fast->next == NULL);

}
