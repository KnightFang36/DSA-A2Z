#include <bits/stdc++.h>
using namespace std;

vector<int> unionArray(vector<int> a,vector<int> b){
    int n1=a.size();
    int n2=b.size();

    int i=0;
    int j=0;

    vector<int> unionArr;

    while(i<n1 && j<n2){
        if(a[i]<=b[j]){
            if( unionArr.empty()  || unionArr.back()!=a[i]){
                unionArr.push_back(a[i]);
            }
            i++;
            }
            else{
                if( unionArr.empty()  || unionArr.back()!=b[j]){
                unionArr.push_back(b[j]);
            }
            j++;

            }
        }

        while(j<n2){
             if( unionArr.empty()  || unionArr.back()!=b[j]){
                unionArr.push_back(b[j]);
            }
            j++;

        }
        while(i<n1){
            if( unionArr.empty()  || unionArr.back()!=a[i] ){
                unionArr.push_back(a[i]);
            }
            i++;
        }

        return unionArr;
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

    vector<int> unionArr=unionArray(a,b);

    cout << "Union: ";
    for (int val :unionArr ) cout << val << " ";

}