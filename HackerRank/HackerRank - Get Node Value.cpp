// HackerRank - Get Node Value.cpp

// Complete the getNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
int getNode(SinglyLinkedListNode* head, int positionFromTail) {
    
    SinglyLinkedListNode *curr = head;
    
    int countNode = 0, totalNode = 0;
    while(curr != NULL)
    {
        totalNode++;
        curr = curr->next;
    }
    
    curr = head;     
    while(curr != NULL)
    {
        countNode++;
        if(countNode == (totalNode - positionFromTail))
            break;
        
        curr = curr->next;
        
    }
    
    return curr->data;
    
}