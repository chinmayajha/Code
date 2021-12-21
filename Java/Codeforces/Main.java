import java.io.*;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.Collections;
import java.util.StringTokenizer;


public class Main {
	public static void main(String[] args) {
		int ttt = 1;
		ttt = rint();
		for (int zxc = 0; zxc < ttt; zxc++) {
			int n = rint();
			
		}
	}

	static void sort(int[] a) {
		//Use Collections.sort(); for ArrayList
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i); Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
	}

	static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));static StringTokenizer st=new StringTokenizer("");
	static String rstr() {while (!st.hasMoreTokens()){try {st=new StringTokenizer(br.readLine());} catch (IOException e) {e.printStackTrace();}}return st.nextToken();}
	static String rline(){try{return br.readLine(); } catch(IOException e) {} return "";}
	static int rint() {return Integer.parseInt(rstr());}
	static int[] rA(int n) {int[] a=new int[n];for (int i=0; i<n; i++){a[i]=rint();}return a;}
	static long rlong() {return Long.parseLong(rstr());}
	static double rdouble(){return Double.parseDouble(rstr());}
}
