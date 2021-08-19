#include <bits/stdc++.h>
using namespace std;

int n, m;
int main()
{
    /*
        If there are multiple possible answers, you may print any of them.

        This is written in the problem statement, which reveals a lot about the problem
        First of all you need to notice that there is no limit on the number of operations you can perform
        So we should look for a case which matches all the testcases (i.e. a suitable pattern)
        Therefore we need to construct our answer which follows these rules : 
        -  if it has a number k>0 written on it, then exactly k of its neighboring cells have a number greater than 0 written on them
        Now a box can have at max 4 sides, therefore if any of the existing cells have a value greater than 4,
        we ouput NO (you can process this while taking input itself)
        Also, any corner cell can;t have ore than 2 sides, therefore if a corner cell
        has a value > 2, we print NO
        Similarly if any edge box has a value > 3, we print NO.

        Now let's see an example, n = 4, m = 5
        Now it doesn't matter what the initial matrix looks like, as we've already checked the validity and printed NO if invalid
        so the matrix will be something like
        X X X X X
        X X X X X
        X X X X X
        X X X X X
        Now we just simply fill the cells with the number of neighbours they have
        So the matrix would look like
        2 3 3 3 2
        3 4 4 4 3
        3 4 4 4 3
        2 3 3 3 2
        So the answer to any valid matrix is, 2 in the corners, 4 in the centers, and 3 on the edges
        This is guaranteed to give AC because there is no limit on the number of operations.

        Now the implementation part is the big deal here, (which is pretty simple actually)
    */
    int t; cin >> t;
    while(t--){
        cin >> n >> m;
        int a[n + 2][m + 2]; 
        bool ok = 0; //boolean to check if the matrix is invalid at any point of time
        for (int i = 1; i < n + 1; ++i) for (int j = 1; j < m + 1; ++j){
            cin >> a[i][j];
            if (a[i][j] > 4) ok = 1; // check if any number is greater than 4 or not
        }

        if (ok != 1) {
            if (a[1][1] > 2 || a[n][1] > 2 || a[1][m] > 2 || a[n][m] > 2) ok = 1; 
            //checking if corners are greater than 2 or not
        }
        if (ok != 1){
            for (int i = 0; i < m + 2; ++i){
                a[0][i] = 5;
                a[n + 1][i] = 5;
                if (i >= 1 && i <= m && (a[1][i] > 3 || a[n][i] > 3)) ok = 1;
                //checking if the edge numbers are greater than 3 or not
                //(for the first and last row)
            }
        }
        if (ok != 1){
            for (int i = 0; i < n + 2; ++i){
                a[i][0] = 5;
                a[i][m + 1] = 5;
                if (i >= 0 && i < n && (a[i + 1][1] > 3 || a[i + 1][m] > 3)) ok = 1;
                //checking if the edge numbers are greater than 3 or not
                //(for the first and last column)
            }
        }

        // IF any of the checks above are True, then our matrixx is invalid and we print NO to stdout
        if (ok){
            cout << "NO\n";
            continue;
        }
        //if the matrix is valid, we begin on constructing our answer
        // Remember that our answer is nothing but
        // So the answer to any valid matrix is, 2 in the corners, 4 in the centers, and 3 on the edges


        for (int i = 2; i < n; ++i) for (int j = 2; j < m; ++j) a[i][j] = 4; //assigning 4 to centers

        for (int i = 1; i < m + 1; ++i){ 
            //assigning 3 to first and last rows
            a[1][i] = 3;
            a[n][i] = 3;
        }

        for (int i = 1; i < n + 1; ++i){
            //assigning 3 to first and last columns            
            a[i][1] = 3;
            a[i][m] = 3;
        }
        a[1][1] = 2, a[n][1] = 2, a[1][m] = 2, a[n][m] = 2;
        // ^ assigning 2 to the corners

        cout << "YES\n";
        //printing YES and the matrix
        for (int i = 1; i < n + 1; ++i){
            for (int j = 1; j < m + 1; ++j) cout << a[i][j] << " ";
            cout << "\n";
        }
    }
}

