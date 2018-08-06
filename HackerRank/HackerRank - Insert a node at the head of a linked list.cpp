// HackerRank - Insert a node at the head of a linked list.cpp

// Complete the insertNodeAtHead function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* llist, int data) {
    
    SinglyLinkedListNode *curr = llist;
    SinglyLinkedListNode *newNode = new SinglyLinkedListNode(data);
    
    if(curr == NULL)
        curr = newNode;
    else
        newNode->next = llist;
    
    return newNode;

}