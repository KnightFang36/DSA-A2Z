 
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

 void createLoop(Node* head, int pos) {
    if (pos == -1) return; 

    Node* loopNode = head;
    for (int i = 0; i < pos; i++) {
        if (loopNode->next)
            loopNode = loopNode->next;
        else
            return; 
    }

    Node* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }

    tail->next = loopNode; 
}


bool  DetectLoop(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;

            if(slow==fast)  return true;
    }
    return false;

    
}

Node* StartPointOfLoop(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;

            if(slow==fast){
                slow=head;
                while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow; //starting point
            }
    }
    return NULL;

}
int loopLength(Node* slow,Node* fast){
    int cnt=1;
    fast=fast->next;
    while(slow!=fast){
        cnt++;
        fast=fast->next;
    }
    return cnt;
    
}


int findloopLength(Node* head){
    Node* slow=head;
    Node* fast=head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast) return loopLength(slow,fast);
    }
    return 0;
}




int main(){
    vector<int> arr={7,3,1,8,67,89,0,12,};
    //conversion to LL
    Node* head=convertToLL(arr);
    printLL(head);

    createLoop(head,4);

    cout<< findloopLength(head);


}


 
