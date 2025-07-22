
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

 Node* segragateOddEven(Node* head){

    if( head==NULL)return NULL; 
    if( head->next==NULL) return head;
    Node* odd=head;
    Node* even=head->next;
    Node* evenHead=head->next;

    while(even!=NULL && even->next!=NULL){
        odd->next=odd->next->next;
        even->next=even->next->next;

        odd=odd->next;
        even=even->next;
    }
    odd->next=evenHead;
    return head;
 }








int main(){
    vector<int> arr={1,2,3,4,5};
    //conversion to LL
    Node* head=convertToLL(arr);
    printLL(head);

    head=segragateOddEven(head);
    printLL(head);



   

 
     

    


    

}












  
