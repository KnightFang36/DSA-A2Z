
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

// deletion of head
Node* deleteHead(Node* head){
    if(head==NULL) return head;

    Node* temp=head;
    head=head->next;
    delete temp;
    
    return head;
}
// deletion of tail
Node* deleteTail(Node* head){
    if(head==NULL || head->next==NULL){
        delete head;
        return NULL;

    } 

    Node* temp=head;
    while(temp->next->next != NULL){
        temp=temp->next;
    }
    delete temp->next;
    temp->next=nullptr;
     return head;
    
}

// deletion of kth element

Node* deletek(Node* head,int k){
    if(head==NULL) return head;
    if(k==1){
        Node*temp=head;
        head=head->next;
        delete temp;

        return head;
    }
    int cnt=0;
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL){
        cnt++;
        if(cnt==k){
            prev->next=prev->next->next;
            delete temp;
            break;

        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}



// deletion of given element 

Node* deleteValue(Node* head,int value){
    if(head==NULL) return head;
    if(head->data==value){
        Node*temp=head;
        head=head->next;
        delete temp;

        return head;
    }
   
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL){
        
        if(temp->data==value){
            prev->next=prev->next->next;
            delete temp;
            break;

        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}




int main(){
    vector<int> arr={111,20,3,4,555,60,70,8,9,1001};
    //conversion to LL
    Node* head=convertToLL(arr); 
    printLL(head);
   
    
    // deletion 

    // head=deleteHead(head);

    // head=deleteTail(head);

    // head=deletek(head,4);

    head=deleteValue(head,555);

    
    printLL(head);

  return 0;

}