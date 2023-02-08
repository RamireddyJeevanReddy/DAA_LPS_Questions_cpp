// OM SAI RAM //


#include <iostream>
using namespace std;
#include <vector>
#include <limits>

int main(){
    int n,ele;
    cin>>n;
    vector<int> a(n+1,0);
    a[0]=0;
    a[1]=0;
    a[2]=1;
    a[3]=2;
    for(int i=4;i<=n;i++){
        a[i]=a[i-1]+a[i-2]+a[i-3];
    }
    cout<<a[n];
}