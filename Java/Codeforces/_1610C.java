import java.io.*;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.Collections;
import java.util.StringTokenizer;


public class _1610C {
	
	static boolean check(int mid, int first[], int second[]) {
		int n = first.length;
		int x = 0, y = mid - 1;
		for(int i = 0; i < n; ++i) {
			if(x <= second[i] && y <= first[i]) {
				x++; y--;
			}
		}
		
		if(y < 0) return true;
		return false;
	}
	
	public static void main(String[] args) {
		int ttt = 1;
		ttt = rint();
		for (int zxc = 0; zxc < ttt; zxc++) {
			int n = rint();
			int first[] = new int[n];
			int second[] = new int[n];
			for(int i = 0; i < n; ++i) {
				first[i] = rint();
				second[i] = rint();
			}
			//
			int l = 0, r = n, cnt = 0;
			while(l <= r) {
				int mid = (l + r)/2;
				if(check(mid, first, second) == true) {
					l = mid + 1;
					cnt = mid;
				}
				else r = mid - 1;
			}
			System.out.println(cnt);
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
