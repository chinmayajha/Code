
#include "bits/stdc++.h"
#pragma GCC optimize "trapv"
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
//
i64 merge(i64 arr[], i64 temp[], i64 left, i64 mid, i64 right)
{
    i64 inv_count = 0;
 
    i64 i = left; /* i is index for left subarray*/
    i64 j = mid;  /* j is index for right subarray*/
    i64 k = left; /* k is index for resultant merged subarray*/
    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
        {
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid - i);
        }
    }
    while (i <= mid - 1)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];
    for (i=left; i <= right; i++)
        arr[i] = temp[i];
 
    return inv_count;
}
 
i64 _mergeSort(i64 arr[], i64 temp[], i64 left, i64 right)
{
    i64 mid, inv_count = 0;
    if (right > left)
    {
        mid = (right + left)/2;
        inv_count  = _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid+1, right);
        inv_count += merge(arr, temp, left, mid+1, right);
    }
 
    return inv_count;
}
i64 countSwaps(i64 arr[], i64 n)
{
    i64 temp[n];
    return _mergeSort(arr, temp, 0, n - 1);
}
string solve(){
    i64 n;
    cin >> n;
    i64 a[n]; inarr(a, n);
    i64 k = countSwaps(a, n);
    if(n*(n - 1) > 2*k) return "YES";
    else return "NO";
}

int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int testt = 1;
    cin >> testt;
    for (int i = 1; i <= testt; ++i){
        // cout << "Case #" << i << ": ";
        cout << solve() << "\n";
    }
}


