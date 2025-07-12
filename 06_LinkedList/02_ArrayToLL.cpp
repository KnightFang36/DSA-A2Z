
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
// length of LL

int lengthOfLL(Node* head){
    int l=0;
    Node* temp=head;
    while(temp){
        l++;
        temp=temp->next;

    }
    return l;
}


//search in element
int checkIfPresent(Node* head,int val){
    
    Node* temp=head;
    while(temp){
       if (temp->data==val) return 1;
        temp=temp->next;

    }
    return 0;
}



int main(){
    vector<int> arr={7,3,1,8,67,89,0,12,};
    //conversion to LL
    Node* head=convertToLL(arr);

    
    // traversal in LL
    Node* temp=head;
    while(temp){
        cout<< temp->data<<" ";
        temp=temp->next;

    }

    //length
    int len=lengthOfLL(head);
    cout<<"\nLength:"<<len;

    //Search An element
    cout<<"\n"<<checkIfPresent(head,67);

    

}