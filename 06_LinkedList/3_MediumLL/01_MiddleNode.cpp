
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




 Node* MiddleNode(Node* head){

    Node* slow=head;
    Node* fast=head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
 }



int main(){
    vector<int> arr={7,3,1,8,67,89,0,12,};
    //conversion to LL
    Node* head=convertToLL(arr);
    printLL(head);
     
    
    
    

    cout<< MiddleNode(head)->data;


    

}












  



