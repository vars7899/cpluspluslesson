// . The follwing questions have the same approach
// . 1. Detect loop in a linked list
// . 2. Detect and remove cycle from linked list
// . 3. begging/start node of the loop in the linked list

// ? We will be using multiple approaches to solve the questions
#include <bits/stdc++.h>
using namespace std;

// structure of the linked list node
class Node{
    public: // public members
    int data; // data feild property
    Node* next; // pointer to the next Node
    // parametersied constructor
    Node(int data){
        this->data = data; 
        this->next = NULL;
    }
};
// @ isCircular --> detect loop in the linked list
// space --> O(n), where n is the number of node, as we are traversing through each node of the linked list
// time --> O(n), where n is the number of node as we are traversing and storing visited node value in the map
bool isCircular(Node* &head){
    // if the list is empty
    if(head == NULL) return false;
    // we will create a map to keep track of the Node visited in the linked list
    map<Node*, bool> visited;
    Node* current = head;

    while(current != NULL){
        // loop is present if the follwing execute
        if(visited[current] == true){
            return true;
        }
        visited[current] = true;
        current = current->next;
    }
    return false;
}
// There is an optimal solution for the same problem to detect cycle that is known as floyds-cycle-detection algorithm or tortoise-hare algorithm
// In this algorithm we take two pointer
// 1. fast pointer --> that move by 2 place 
// 2. slow pointer --> that move by 1 place
// if a cycle exist in the linked list the two pointer will meet again, if not the faster pointer will reach end of the linked list (NULL), and we can say that no cycle exist in the linked list.
bool detectCycle(Node* &head){
    // if the list is empty
    if(head == NULL) return false;

    // Both the fast and the slow pointer starts from the same node
    Node* fast = head;
    Node* slow = head;

    while(fast != NULL && slow != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }
        slow = slow->next;
        if(fast == slow){ 
            cout<<"Cycle present :"<<slow->data<<endl;
            return true;
        }
    }
    return false; //as fast reached the end and never met slow, so loop does not exist
}


int main(){
    // * There can be two ways loop can exist in the linked list
    // * 1. It is circular linked list, the tail of the linked list is pointing to the head of the linked list
    // * 2. There are two node whose next property is pointing to the same node.  
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n2;
    Node* head = n1;
    // cout<<isCircular(head)<<endl;
    cout<<detectCycle(head)<<endl;
}