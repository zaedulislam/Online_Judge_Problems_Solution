// HackerRank - Print the Elements of a Linked List.cpp

// Complete the printLinkedList function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
void printLinkedList(SinglyLinkedListNode* head) {
    
    SinglyLinkedListNode *curr = head;
    while(curr != NULL)
    {
        cout << curr->data << endl;
        curr = curr->next;
    }
    
    
}