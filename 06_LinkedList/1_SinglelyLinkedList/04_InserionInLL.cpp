
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
//printig LL
void printLL(Node* head){
    
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"\n";
}

// insert at head
Node* insertHead(Node* head,int val){
    Node* temp=new Node(val,head);
    return temp;
}

//insert at tail

Node* insertTail(Node* head,int val){
    if(head==NULL) return new Node(val);

    Node* temp=head;
    while (temp->next!=NULL){

        temp=temp->next;
    }
    Node* newNode= new Node(val);
    temp->next=newNode;
    
   return head;
}

Node* insertAtK(Node* head,int val,int k){

    if(head==NULL){
        if(k==1) {
            Node*x= new Node(val);
            return x;
        }
        else {
        return head;              
        }
    }
    if(k==1){
        Node* temp=new Node(val,head);
        return temp;
    }

    int cnt=0;
    Node* temp=head;
    while(temp!=NULL){
        cnt++;
        if(cnt==k-1){
            Node* x=new Node(val);
            x->next=temp->next;
            temp->next=x;
            break;
        }
        temp=temp->next;
    }
    return head;
}

Node* insertBeforeVal(Node* head,int el,int val){

    if(head==NULL) return NULL;
       
   
    if(head->data==val){
        Node* temp=new Node(el,head);
        return temp;
    }

    
    Node* temp=head;
    while(temp->next!=NULL){
      
        if(temp->next->data==val){
            Node* x=new Node(el,temp->next);
            temp->next=x;
            break;
        }
        temp=temp->next;
    }
    return head;
}



int main(){
    vector<int> arr={1,2,3,4,5,6};
    //conversion to LL
    Node* head=convertToLL(arr); 
    printLL(head);
   
    //insertion

    // head=insertHead(head,100);

    // head=insertTail(head,30);

    // head=insertAtK(head,66,2);

    // head=insertBeforeVal(head,390,5);

    printLL(head);

  return 0;

}