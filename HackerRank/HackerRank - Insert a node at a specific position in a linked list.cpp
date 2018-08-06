// HackerRank - Insert a node at a specific position in a linked list.cpp

// Complete the insertNodeAtPosition function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
    
    SinglyLinkedListNode *newNode = new SinglyLinkedListNode(data);
    SinglyLinkedListNode *curr = head;
    
    if(curr == NULL)
        head = newNode;
    else
    {
        int currPos = 0;
    
        if(position == 0)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            curr = head;
            
            while(curr != NULL && currPos + 1 != position)
            {
                currPos++;
                curr = curr->next;
            }
            
            newNode->next = curr->next;
            curr->next = newNode;
            
        }
    }
    
    return head;

}