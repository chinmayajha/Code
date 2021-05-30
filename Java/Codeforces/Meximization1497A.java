import java.io.*;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Meximization1497A {
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int ttt=fs.nextInt();
		for (int zxc=0; zxc<ttt; zxc++) {
			int n = fs.nextInt();
			int a[] = fs.readArray(n);
			int b[] = new int[101];
			int j = 0;
			sort(a);
			System.out.print(a[0]+" ");
			for(int i=1;i<n;++i) {
				if(a[i]==a[i-1]) {
					b[j] = a[i];
					j++;
				} else System.out.print (a[i]+" ");
			}
			for(int i=0;i<j;i++)System.out.print(b[i]+" ");
			System.out.println(" ");
		}
	}

	static void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		String next() {while (!st.hasMoreTokens()){try {st=new StringTokenizer(br.readLine());} catch (IOException e) {e.printStackTrace();}}return st.nextToken();}
		int nextInt() {return Integer.parseInt(next());}
		int[] readArray(int n) {int[] a=new int[n];for (int i=0; i<n; i++){a[i]=nextInt();}return a;}
		long nextLong() {return Long.parseLong(next());}
	}
}
