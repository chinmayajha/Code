    #include <bits/stdc++.h>
    using namespace std;
     
    typedef unsigned long long ull;
    typedef long long int lli;
    typedef vector<int> vi;
    typedef vector<long long int> vlli;
     
    #define pb push_back
    #define pi 3.1415
     
    const lli MOD= 1e9+7;
     
    int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);cout.tie(NULL);
        lli t;cin>>t;
        while(t--){
            int n,k;cin>>n>>k;
            vi arr(n);
            for(int i=0;i<n;i++){
                cin>>arr[i];
            }
            if(k>0){
                sort(arr.begin(),arr.end());
                int mex,maxx=arr[n-1];
                if(n==1 && arr[0]!=0){mex=0;}
                else if(n==1 && arr[0]==0){mex=1;}
                else{
                    for(int i=0;i<n-1;i++){
                        if(arr[i+1]!=arr[i]+1){
                            mex=arr[i]+1;
                            break;
                        }
                    }
                }
                int elem=(maxx+1+mex)/2;
                auto it=find(arr.begin(),arr.end(),elem);
                if(mex<maxx && it==arr.end())
                    cout<<n+1<<"\n";
                else if(mex<maxx && it!=arr.end())
                    cout<<n<<"\n";
                
                else
                    cout<<n+k<<"\n";
            }
            else{cout<<n<<"\n";}
        
        }
        return 0;
    }