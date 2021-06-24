import java.io.*;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.Collections;
import java.util.StringTokenizer;

public class _787A {
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int ttt=1;
		for (int zxc=0; zxc<ttt; zxc++) {
			int d1 = fs.rint();
			int a1 = fs.rint();
			int d2 = fs.rint();
			int a2 = fs.rint();
			int n = 10000;
			ArrayList<Integer> a = new ArrayList<>();
			ArrayList<Integer> b = new ArrayList<>();
			for(int i=0;i<n;++i) {
				a.add(a1 + (d1*i));
				b.add(a2 + (d2*i));
			}
			int ans = -1;
//			for(int i=0;i<20;++i) {
//				System.out.print(a.get(i) + " ");
//				System.out.println(b.get(i));
//			}
			for(int i=0;i<n;++i) {
				int cur = a.get(i);
				for(int j=0;j<n;++j) {
					if(cur== b.get(j)) {
						System.out.println(cur);
						System.exit(0);
					}
				}
			}
			System.out.println(-1);
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
		int[] rA(int n) {int[] a=new int[n];for (int i=0; i<n; i++){a[i]=rint();}return a;}
		long rlong() {return Long.parseLong(rstr());}
		double rdouble(){return Double.parseDouble(rstr());}
	}
}
