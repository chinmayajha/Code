import java.io.*;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int ttt=fs.rint();
		for (int zxc=0; zxc<ttt; zxc++) {
//			int n = fs.rint();
			
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
