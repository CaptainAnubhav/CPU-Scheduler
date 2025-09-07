// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)cin>>A[i];
    vector<int>loc_max;
    loc_max.push_back(0);
    int ma=-1;
    for(int i=1;i<n;i++){
        if(A[i]>ma){
            ma=max(ma,A[i]);
        }
        else{
            loc_max.push_back(i-1);
            ma=A[i];
        }
    }
    loc_max.push_back(n-1);
    vector<int>final;
    final.push_back(0);
    for(int i=1;i<loc_max.size()-1;i++){
        if(A[loc_max[i+1]]>A[loc_max[i]])continue;
        else final.push_back(loc_max[i]);
    }
    final.push_back(n-1);
    if(final.size()==2)cout<<2<<endl;
    else {
        int ans=0;
        for(int i=2;i<final.size();i++){
            ans=max(final[i]-final[i-2],ans);
        }
        cout<<ans<<endl;
    }
    return 0;
}


