#include <bits/stdc++.h>
#include "LinkedList.cpp"
using namespace std;

// 1. using hash map
// Use a hash map to keep track of the values
// Time complexity --> O(n), where ne is the number of nodes in the linked list
// space complexity --> O(n), where n is the number of nodes as we are saving the data of each node in a map.
bool isPalindrome(Node* head){
    if(head == NULL) return false;
    map<int,int> track;
    Node* current = head;
    int position = 1;
    while(current != NULL){
        track[position] = current->data;
        current = current->next;
        position++;
    }
    int length = position;
    position = 1;
    while(position <= length){
        if(track[position] != track[length-position]) return false;
        position++;
    }
    return true;
}
// 2. Using vector/string
// time complexity --> O(n), where n is the number of nodes in the linkes list, as we are traversing through the linkes list
// space complexity --> O(n), where n is the number of nodes in the linked list, as we are storing each node data in vector
bool isPalindrome2(Node* head){
    if(head == NULL) return false;
    vector<int> str;
    Node* current = head;
    int i = 0;
    while(current != NULL){
        str.push_back(current->data);
        current = current->next;
    }

    int start = 0;
    int end = str.size() - 1;

    while(start <= end){
        if(str[start] != str[end]){
            return false;
        };
        start++;
        end--;
    }
    return true;
}
// 3. 
Node* getMid(Node* head){
    // floyds cycle detection algorithm
    Node* slow = head;
    Node* fast = head->next;
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
Node* reverse(Node* &head){
    Node* prev = NULL;
    Node* current = head->next;
    Node* next = NULL;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
// 3. reversing approach
// time complexity --> O(n), where n is the number of node in the linked list
// space complexity --> O(1), constant space.
bool isPalindrome3(Node* head){
    // edge case
    // if the list is empty
    if(head == NULL) return false;
    // if the list has only one element
    if(head->next == NULL) return true;

    // 1. find middle
    Node* mid = getMid(head);
    // 2. reverse list after middle
    mid->next = reverse(mid->next);
    // 3. compare both halves
    Node* h1 = head;
    Node* h2 = mid->next;
    while(h2 != NULL){
        if(h1->data != h2->data) return false;
        h1 = h1->next;
        h2 = h2->next;
    }
    // 4. un-reverse the linked list (optional)
    mid->next = reverse(mid->next);

    return true;
}
int main(){
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(2);
    Node* n5 = new Node(1);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    Node* head = n1;
    print(head);
    cout<<isPalindrome3(head)<<endl;
}