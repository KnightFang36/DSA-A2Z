
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1,Node* next1,Node* back1){
        data=data1;
        next=next1;
        back=back1;
    }

    public:
    Node(int data1){
        data=data1;
        next=nullptr;
        back=nullptr;
    }

};

Node* convertToDLL(vector<int> &arr){
    Node* head=new Node(arr[0]);
    Node* prev=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i],nullptr,prev);
        prev->next=temp;
       prev=temp;
    }
    return head;

}
//print statement 
 void printDLL(Node* head){
    Node* temp=head;
    while(temp){
        cout<< temp->data<<" ";
        temp=temp->next;

    }
    cout<<"\n";
 }



// insertion of node 

//head
Node* insertBeforeHead(Node* head,int val){
    Node* newHead=new Node(val,head,nullptr);
    head->back=newHead;
    return newHead;
}

Node* insertBeforeTail(Node* head,int val){
    if(head->next==NULL){
        return insertBeforeHead(head,val);
    }
    Node* tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    Node* prev=tail->back;

    Node* newNode=new Node(val,tail,prev);
    prev->next=newNode;
    tail->back=newNode;

    return head;

}

Node* insertK(Node* head,int k,int val){
    if(k==1){
        return insertBeforeHead(head,val);

    }
    Node* temp=head;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        if(cnt==k) break;
        temp=temp->next;
    }
    Node* prev=temp->back;
    Node* newNode=new Node(val,temp,prev);
    prev->next=newNode;
    temp->back=newNode;
    return head;
}








int main(){
    vector<int> arr={7,1,4,6,90,80};
    //conversion to LL
    Node* head=convertToDLL(arr);
    printDLL(head);

   
   head=insertK(head,6,600);
   printDLL(head); 


}