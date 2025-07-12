#include <bits/stdc++.h>
using namespace std;

void leftRotate(int arr[],int n,int d){

    d=d%n;
    reverse(arr,arr+d);
    reverse(arr+d,arr+n);
    reverse(arr,arr+n);
}




int main(){
   int n ;
   int d ;
   cin>> n; 
   cin>>d; 

   int arr[n];
   for (int i = 0; i < n; i++) cin>>arr[i];

   leftRotate(arr,n,d);
   for (int i = 0; i < n; i++) cout<<arr[i]<<" ";

}