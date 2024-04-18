/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL){
            return head;
        }

        Node* temp = head;
        Node* rootHead = temp;
        while(temp != NULL){
            Node* newNodeAtPosition = new Node(temp->val);
            Node* existingNext = temp->next;
            temp->next = newNodeAtPosition;
            newNodeAtPosition->next = existingNext;
            temp = temp->next->next;
        }

        Node* randomHead = head;
        while(randomHead != NULL){
            if(randomHead->random != NULL){
                randomHead->next->random = randomHead->random->next;
            }
            randomHead = randomHead->next->next;
        }

        Node* dummy = new Node(0);
        Node* headDummy = dummy;
        rootHead = head;
        while(rootHead != NULL){
            Node* next = rootHead->next->next;
            Node* newNode = rootHead->next;
            headDummy->next = newNode;
            rootHead->next = next;
            headDummy = headDummy->next;
            rootHead = next;
        }
        return dummy->next;
    }
};

// 