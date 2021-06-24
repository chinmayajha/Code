import java.io.*;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.Collections;
import java.util.StringTokenizer;
public class _990B {
//	int binarySearch(int arr[], int x)
//    {
//        int l = 0, r = arr.length - 1;
//        while (l <= r) {
//            int m = l + (r - l) / 2;
//            if (arr[m] == x) return m;
//            if (arr[m] < x)l = m + 1;
//            else r = m - 1;
//        }
//        return -1;
//    }
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int ttt=1;
		for (int zxc=0; zxc<ttt; zxc++) {
			int n = fs.rint();
			int m = fs.rint();
			int a[] = fs.rA(n+1);
			a[n] = 200000000;
			n++;
			sort(a);
			int cnt = 0;int j = 0;
			for(int i=0;i<n-1;++i) {
				while(j<n && a[i] == a[j]) {
					j++;
				}
				if(a[j] - a[i] > m) {
					cnt++;
				}
			}
			System.out.println(cnt);
		}
		
	}

	static void sort(int[] a) {
		//Use Collections.sort(); for ArrayList
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
	}
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));StringTokenizer st=new StringTokenizer("");
		String rstr() {while (!st.hasMoreTokens()){try {st=new StringTokenizer(br.readLine());} catch (IOException e) {e.printStackTrace();}}return st.nextToken();}
		String rline(){try{return br.readLine(); } catch(IOException e) {} return "";}
		int rint() {return Integer.parseInt(rstr());}
		int[] rA(int n) {int[] a=new int[n];for (int i=0; i<n-1; i++){a[i]=rint();}return a;}
		long rlong() {return Long.parseLong(rstr());}
		double rdouble(){return Double.parseDouble(rstr());}
	}
}
