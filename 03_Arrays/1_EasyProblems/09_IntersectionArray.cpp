#include <bits/stdc++.h>
using namespace std;

vector<int> intersectionArray(vector<int> a,vector<int> b){
    int n1=a.size();
    int n2=b.size();

    int i=0;
    int j=0;

    vector<int> inter;

    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            i++;
        }
        else if(b[j]<a[i]){
            j++;
        }
        else{
            inter.push_back(a[i]);
            i++;
            j++;
        }
    }
    return inter;

   
    



}


int main(){
    int n1;
    cin>>n1;
    vector<int> a(n1);
    for (int i = 0; i < n1; i++) {
        cin >> a[i];
    }

    int n2;
    cin>>n2;
    vector<int> b(n2);
     for (int i = 0; i < n2; i++) {
        cin >> b[i];
    }

    vector<int> inter=intersectionArray(a,b);

    cout << "inter: ";
    for (int val :inter ) cout << val << " ";

}