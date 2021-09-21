# include <bits/stdc++.h>
using namespace std;

#define fo(i, n) for(i=0;i<n;i++)

struct a{
    int speed , ram , hdd , cost ;
};

void solution(){
    int n , i ;
    cin >> n ;
    a b[n] ;
    fo(i,n){
        int speed , ram , hdd , cost ;
        cin >> speed >> ram >> hdd >> cost ;
        b[i].speed = speed ;
        b[i].ram = ram ;
        b[i].hdd = hdd ;
        b[i].cost = cost ;
    }
    // fo(i,n){
    //     cout << b[i].speed << " " << b[i].ram << " " << b[i].hdd << " " << b[i].cost << endl ;
    // }
    fo(i,n){
        for (int j = 0 ; j < n ; j++)
        {
            if((j!=i) && (b[i].speed>b[j].speed) && (b[i].ram>b[j].ram) 
            && (b[i].hdd>b[j].hdd)){
                b[j].speed = 0 ;
                b[j].ram = 0 ;
                b[j].hdd = 0 ;
                b[j].cost = 0 ;
            }
        }  
    }
    int A = 1001 , B , C = 0 ;
    fo(i,n){
        if(b[i].cost>0){
        B = A ;
        A = min(A,b[i].cost); 
        if(B!=A){
            C = i ;
            // cout << A << " " << endl ;
            // cout << C << " " << endl ;
        }
        }
    }
    cout << C + 1 ;
    //  fo(i,n){
    //     cout << b[i].speed << " " << b[i].ram << " " << b[i].hdd << " " << b[i].cost << endl ;
    // }
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
       solution();
    return 0;
}