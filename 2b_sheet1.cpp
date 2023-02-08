// OM SAI RAM //

#include<iostream>
#include <cstdio>
#include <time.h>
using namespace std;
int main()
{
    int elements[100000],key,i,j,n,num_comp;
    int ans=0;
    int imp;
    
    freopen("descending_100000.txt", "r", stdin);
    clock_t start = clock();
    cin>>n;
    for(i=0;i<n;i++)
        cin>>elements[i];
    cin>>imp;
    num_comp=0;
    for(j=1;j<n;j++)
    {
        key = elements[j];
        i = j-1;
        while((i>=0)&&(elements[i]>key))
        {
		num_comp++;
            elements[i+1] = elements[i];
            i = i-1;
        }
        elements[i+1] = key;
    }
	for(j=0;j<n;j++){
	    if(imp==elements[j]){
	        ans=j+1;
	        break;
	    }
	}
	cout<<ans;
    clock_t end = clock();
    double elapsed = double(end - start)/CLOCKS_PER_SEC;
    cout<<elapsed;
}

