// HackerRank - Merge two sorted linked lists.cpp

// Complete the mergeLists function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    
    SinglyLinkedListNode *root = NULL, *newNode, *curr, *tail;
    
    int data;
    while(head1 != NULL && head2 != NULL)
    {
        if(head1->data <= head2->data)
        {
            data = head1->data;
            head1 = head1->next;
        }
        else
        {
            data = head2->data;
            head2 = head2->next;
        }
    
        newNode = new SinglyLinkedListNode(data);
        
        if(root == NULL)
        {
            root = newNode;
            curr = root;
        }
        else
        {
            curr->next = newNode;
            curr = newNode;        
        }
    }
    
    
    if(head1 == NULL)
    {
        while(head2 != NULL)
        {
            data = head2->data;
            head2 = head2->next;
            
            newNode = new SinglyLinkedListNode(data);
            
            curr->next = newNode;
            curr = newNode;
        }
    }
    else if(head2 == NULL)
    {
        while(head1 != NULL)
        {
            data = head1->data;
            head1 = head1->next;
            
            newNode = new SinglyLinkedListNode(data);
            
            curr->next = newNode;
            curr = newNode;
        }
    }

    return root;
}