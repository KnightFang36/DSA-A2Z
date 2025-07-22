
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






Node* reverseLink(Node* head){
   Node* prev=nullptr;
   Node* temp=head;
   Node* front;
   while(temp!=NULL){
    front=temp->next;
    temp->next=prev;
    prev=temp;
    temp=front;
   }
   return prev;

}

bool CheckPalindrome(Node* head){
    Node* slow=head;
    Node* fast=head;

    while(fast->next!=NULL && fast->next->next!=NULL ){
        slow=slow->next;
        fast=fast->next->next;

    }
    Node* newH=reverseLink(slow->next);

    Node* first=head;
    Node* second=newH;

    while(second!=NULL){
        if(first->data != second->data){
            reverseLink(newH);
            return false;
        }
        first=first->next;
        second=second->next;
    }
    reverseLink(newH);
    return true;
}




int main(){
    vector<int> arr={1,2,3,3,2,1,0};
    //conversion to LL
    Node* head=convertToLL(arr);
    printLL(head);

    cout<<CheckPalindrome(head);

 
     

    


    

}












  
