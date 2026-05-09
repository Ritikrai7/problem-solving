#include<iostream>
#include<vector>
using namespace std;
void insertionSort(vector<int>&v){
    int n=v.size();
    for(int i=1;i<n;i++){
        int curr=v[i];
        int j=0;
        while (j>=0 && v[j]>curr)
        {
          v[j+1]=v[j];
          j--;
        }
        v[j+1]=curr;
    }
    return ;
}
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    insertionSort(v);
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    } cout<<endl;
}
