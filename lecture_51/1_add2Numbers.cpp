#include <bits/stdc++.h>
#include "../LinkedList.cpp"
using namespace std;

// This approach works only for small test cases not for test case with big linked list.
long long int createInt(Node* head){
    long long int num = 0;
    while(head != NULL){
        int digit = head->data;
        num = (num * 10) + digit;
        head = head->next;
    }
    return num;
}
void insertAtHead(Node* &head, int digit){
    Node* newNode = new Node(digit);
    if(head == NULL){
        head = newNode;
    }else{
        newNode->next = head;
        head = newNode;
    }
}
Node* getSum(Node* head1, Node* head2){
    long long int num1 = createInt(head1);
    long long int num2 = createInt(head2);
    // sum
    long long int sum = num1 + num2;
    // create new linked list;
    Node* ansHead = NULL;
    while(sum != 0){
        int digit = sum % 10;
        sum = sum / 10;
        insertAtHead(ansHead, digit);
    }
    return ansHead;
}
// other approach
// time complexity --> O(m+n), where n and m is the size of each linked list
// space complexity --> O(Max(m,n)), where n and m is the size of each linked list
Node* reverse(Node* head){
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        // traverse
        prev = current;
        current = next;
    }
    return prev;
}
void addTail(Node* &head, Node* &tail, int digit){
    Node* newNode = new Node(digit);
    if(head == NULL){
        head = newNode;
        tail = newNode;
    }else{
        tail->next = newNode;
        tail = newNode;
    }
}
Node* add(Node* &first, Node* &second){
    Node* ptr1 = first;
    Node* ptr2 = second;

    Node* ansHead = NULL;
    Node* ansTail = NULL;
    int carry = 0;

    while(ptr1 != NULL || ptr2 != NULL || carry != 0){ // O(Max(m,n))
        int val1 = 0;
        if(ptr1 != NULL){
            val1 = ptr1->data;
            ptr1 = ptr1->next;
        }
        int val2 = 0;
        if(ptr2 != NULL){
            val2 = ptr2->data;
            ptr2 = ptr2->next;
        }
        int sum = val1 + val2 + carry;
        int digit = sum % 10;
        addTail(ansHead, ansTail, digit);
        carry = sum/10;
    }
    // // add the two node using carry
    // while(ptr1 != NULL && ptr2 != NULL){
    //     int sum = ptr1->data + ptr2->data + carry;
    //     int digit = sum % 10;
    //     addTail(ansHead, ansTail, digit);
    //     carry = sum / 10;
    //     ptr1 = ptr1->next;
    //     ptr2 = ptr2->next;
    // }
    // // if linked list one still has node in it
    // while(ptr1 != NULL){
    //     int sum = ptr1->data + carry;
    //     int digit = sum % 10;
    //     addTail(ansHead, ansTail, digit);
    //     carry = sum / 10;
    //     ptr1 = ptr1->next;
    // }
    // // if linked list two has still nodes in it
    // while(ptr2 != NULL){
    //     int sum = ptr2->data + carry;
    //     int digit = sum % 10;
    //     addTail(ansHead, ansTail, digit);
    //     carry = sum / 10;
    //     ptr2 = ptr2->next;
    // }
    // // check if carry still has something in it
    // while(carry != 0){
    //     int sum = carry;
    //     int digit = sum % 10;
    //     addTail(ansHead, ansTail, carry);
    //     carry = sum / 10;
    // }
    return ansHead;
}
Node* twoSum(Node* first, Node* second){
    // step 1. reverse both linked list
    first = reverse(first); // O(n)
    second = reverse(second); // O(m)
    // step 2. add the two linked list
    Node* third = add(first, second);
    // step 3. reverse the answer list
    third = reverse(third); // O(m+n)
    return third;
}

int main(){
    Node* n1 = new Node(4);
    Node* n2 = new Node(3);
    Node* n3 = new Node(2);
    Node* n4 = new Node(5);
    Node* n5 = new Node(6);
    Node* n6 = new Node(7);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    Node* head1 = n1;
    Node* nn1 = new Node(5);
    Node* nn2 = new Node(7);
    Node* nn3 = new Node(9);
    Node* nn4 = new Node(9);
    Node* nn5 = new Node(9);
    Node* nn6 = new Node(8);
    Node* nn7 = new Node(5);
    Node* nn8 = new Node(5);
    Node* nn9 = new Node(3);
    Node* nn10 = new Node(9);
    Node* nn11 = new Node(2);
    Node* nn12 = new Node(9);
    Node* nn13 = new Node(8);
    Node* nn14 = new Node(7);
    nn1->next = nn2;
    nn2->next = nn3;
    nn3->next = nn4;
    nn4->next = nn5;
    nn5->next = nn6;
    nn6->next = nn7;
    nn7->next = nn8;
    nn8->next = nn9;
    nn9->next = nn10;
    nn10->next = nn11;
    nn11->next = nn12;
    nn12->next = nn13;
    nn13->next = nn14;
    Node* head2 = nn1;
    print(head1);
    print(head2);
    print(twoSum(head1,head2));
}