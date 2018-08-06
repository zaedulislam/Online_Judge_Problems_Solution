// HackerRank - Find Merge Point of Two Lists.cpp

// Complete the findMergeNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    
    map<SinglyLinkedListNode*, int> MAP;
    int ans;
    
    while(head1 != NULL)
    {
        MAP[head1]++;
        head1 = head1->next;
    }
    
    while(head2 != NULL)
    {
        MAP[head2]++;
        
        if(MAP[head2] == 2)
        {
            ans = head2->data;
            break;
        }
        
        head2 = head2->next;
    }
    
    return ans;
}