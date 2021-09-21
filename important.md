Chicken Mcnugget theorem : "https://artofproblemsolving.com/wiki/index.php/Chicken_McNugget_Theorem#Origins"
for any two relatively prime positive integers (m, n) the greatest integer that cannot be written in the form (am + bn) for nonnegative integers (a, b) is mn-m-n. 
Consequence of the theorem - here are exactly (m - 1)*(n - 1)/2 positive integers which cannot be expressed in the form am + bn. The proof is based on the fact that in each pair of the form (k, mn - m - n - k), exactly one element is expressible. 
-
Harmonic progression sum : https://codeforces.com/blog/entry/55912?#comment-396436
1 / 1 + 1 / 2 + 1 / 3 has a ceil value of log(n)

Equivalent to Python's split function
vector<string> split(string s, char c) {
    vector<string> a;
    string t = "";
    int n = s.size();
    for(int i = 0; i < n; ++i) {
        if(s[i] == c) {
            a.emplace_back(t);
            t = "";
        } else t.push_back(s[i]);
    }
    return a;
}