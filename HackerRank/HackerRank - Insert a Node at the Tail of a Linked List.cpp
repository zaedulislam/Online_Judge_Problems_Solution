// HackerRank - Insert a Node at the Tail of a Linked List.cpp

// Complete the insertNodeAtTail function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
    
    SinglyLinkedListNode *curr = head;
    SinglyLinkedListNode *newNode = new SinglyLinkedListNode(data);
    
    
    if(curr == NULL)  
        head = newNode;
    else
    {
        while(curr->next != NULL)
            curr = curr->next;
        
        curr->next = newNode;
    }
    
    curr = head;
    while(curr != NULL)
    {
        cout << curr->data << endl;
        curr = curr->next;
    }
    
    return head;
}