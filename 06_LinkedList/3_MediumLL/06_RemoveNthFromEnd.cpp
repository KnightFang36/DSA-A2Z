
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }

    public:
    Node(int data1){
        data=data1;
        next=nullptr;
    }

};

Node* convertToLL(vector<int> &arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=mover->next; //mover=temp;
    }
    return head;

}
//print statement 
 void printLL(Node* head){
    Node* temp=head;
    while(temp){
        cout<< temp->data<<" ";
        temp=temp->next;

    }
    cout<<"\n";
 }

 Node* deleteFromEnd(Node* head,int n){
    Node* fast=head;
    for (int i = 0; i < n; i++)
    {
        fast=fast->next;
    }
    if(fast==NULL) {
        Node* newHead=head->next;
        delete head;
        return newHead;
    }
    Node* slow=head;
    while(fast->next!=NULL){
        slow=slow->next;
        fast=fast->next;
    }
    Node* deleNode=slow->next;
    slow->next=slow->next->next;
    delete deleNode;
    return head;
    
 }








int main(){
    vector<int> arr={1,2,3,4,5};
    //conversion to LL
    Node* head=convertToLL(arr);
    printLL(head);

    head=deleteFromEnd(head,3);
    printLL(head);



   
}