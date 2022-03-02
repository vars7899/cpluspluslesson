// . The follwing questions have the same approach
// . 1. Detect loop in a linked list ☑️
// . 2. Detect and remove cycle from linked list ☑️
// . 3. begging/start node of the loop in the linked list ☑️

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
// time --> O(n), where n is the number of nodes in the linked list, as we are traversing through all the nodes in the linked list
// space --> O(1), it is constant space.
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
            return true;
        }
    }
    return false; //as fast reached the end and never met slow, so loop does not exist
}

// ! find the starting of the cycle
Node* getStartNode(Node* &head){
    // if list is empty
    if(head == NULL) return head;

    // pointers for floyds cycle detection algorithm
    Node* slow = head;
    Node* fast = head;
    // the following loop will get the point of intersection
    while(fast != NULL && slow != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next; 
        }
        slow = slow -> next;
        if(fast == slow){
            break;
        }
    }
    // here we will get the value of head
    slow = head;
    while(slow != fast){
        fast = fast->next;
        slow = slow->next;
    }
    return slow; //or we can send the fast it does not matter as they both are at same node
}

// ! remove loop from linked list
void removeLoop(Node* &head){
    //for empty list
    if(head == NULL) return;

    // floyds cycle detection algorithm
    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }
        slow = slow->next;
        if(slow == fast){
            break;
        }
    }

    //get the head of loop
    slow = head;
    Node* tailOfLoop = NULL;
    while(slow != fast){
        tailOfLoop = fast;
        slow = slow->next;
        fast = fast->next;
    }
    //removing the connecting loop
    tailOfLoop->next = NULL;
}

void print(Node* head){
    Node* temp = head;
    if(head == NULL) return;
    do{
        cout<<head->data<<" ";
        head = head->next;
    }while(head != temp);
    cout<<endl;
}

int main(){
    // * There can be two ways loop can exist in the linked list
    // * 1. It is circular linked list, the tail of the linked list is pointing to the head of the linked list
    // * 2. There are two node whose next property is pointing to the same node.  
    Node* n1 = new Node(1);
    // Node* n2 = new Node(2);
    // Node* n3 = new Node(3);
    // Node* n4 = new Node(4);
    // Node* n5 = new Node(5);
    n1->next = n1;
    // n2->next = n3;
    // n3->next = n4;
    // n4->next = n5;
    // n5->next = n5;
    Node* head = n1;
    // cout<<isCircular(head)<<endl;
    // cout<<detectCycle(head)<<endl;
    cout<<"Head : "<<getStartNode(head)->data<<endl;
    removeLoop(head);
    // cout<<n5->next<<endl;
    print(head);
}