
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

//length of DLL
int lengthDLL(Node* head){
    int count=0;
    Node* temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;

}

// delete  head
Node* DeleteHead(Node* head){
    if(head==NULL || head->next==NULL) return NULL;

    Node* prev=head;
    head=head->next;
    head->back=nullptr;
    prev->next=nullptr;
    delete prev;
    return head;
}

Node* DeleteTail(Node* head){
    if(head==NULL || head->next==NULL) return NULL;

    Node* tail=head;
    while(tail->next!=NULL){
        tail=tail->next;

    }
    Node* prev=tail->back;
    tail->back=nullptr;
    prev->next=nullptr;

    delete tail;
    return head;


}

Node* deleteK(Node* head,int k){
    Node* temp=head;
    int  cnt=0;
    while(temp!=NULL){
        cnt++;
        if(cnt==k) break;
        temp=temp->next;
    }
        Node* prev=temp->back;
        Node* front=temp->next;

        if(prev==NULL && front==NULL){
            delete temp;
            return NULL;
        }
        else if (prev==NULL){
            DeleteHead(head);
        }
        else if (front==NULL){
            DeleteTail(head);
        }
        else{
            prev->next=front;
            front->back=prev;
            temp->next=nullptr;
            temp->back=nullptr;

            delete temp;
            return head;
        }


    }







int main(){
    vector<int> arr={7,1,4,6,90,80};
    //conversion to LL
    Node* head=convertToDLL(arr);
    printDLL(head);

    //Length of DLL

    // int length=lengthDLL(head);
    // cout<<"\nLength:"<<length;

    // deletion

    // head=DeleteHead(head);
    // head=DeleteTail(head);

    

    head=deleteK(head,5);
    printDLL(head);




}