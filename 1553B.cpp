#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int T;
string s,t;
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>T;
	while (T--)
	{
		cin>>s>>t;
		int sl=s.length(),tl=t.length();
		for (int i=0;i<sl;i++)
		{
			bool bo=0;
			for (int r=1;r<=tl;r++)
			{
				bool ok=1;
				for (int j=0;j<r;j++)
					if (t[j]!=s[i+j]) {ok=0;break;}
				if (!ok) break;
				int now=i+r-2;
				for (int j=r;j<tl;j++)
				{
					if (now<0) {ok=0;break;}
					if (t[j]!=s[now]) {ok=0;break;}
					now--;
				}
				if (ok) {bo=1;break;}
			}
			if (bo) {cout<<"YES"<<endl;break;}
			if (i==sl-1) {cout<<"NO"<<endl;break;}
		}
	}
	return 0;
}
