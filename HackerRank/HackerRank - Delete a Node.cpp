// HackerRank - Delete a Node.cpp

// Complete the deleteNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int position) {
    
    if(head == NULL)
        return head;
    if(position == 0)
        head = head->next;
    else
    {
        SinglyLinkedListNode *curr = head, *previous = head;
        
        int currPos = 0;
        while(curr->next != NULL && currPos != position)
        {
            currPos++;
            previous = curr;
            curr = curr->next;
        }
        
        previous->next = curr->next;

        delete(curr);
        
    }
    
    return head;
}