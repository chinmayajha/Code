import java.io.*;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.Collections;
import java.util.StringTokenizer;


public class Main {
	public static void main(String[] args) {
		int ttt = 1;
		for (int zxc=0; zxc<ttt; zxc++) {
			int z = rint();
			int[] a = rA(z);
			Map<Integer,Integer> x = new HashMap<Integer, Integer>();
			for (int i : a) {
				if(x.containsKey(i)) x.replace(i, x.get(i) + 1);
				else x.put(i, 1);
			}
			ArrayList<Integer> m = new ArrayList<>();
			ArrayList<Integer> n = new ArrayList<>();
			boolean k = true;
			for (Map.Entry<Integer, Integer> i : x.entrySet()) {
				if(i.getValue() > 2) {
					k = false;
					System.out.println("NO");
					break;
				}
				m.add(i.getKey());
				if(i.getValue() == 2) n.add(i.getKey());
	        }
			if(k == true) {
				System.out.println("YES");
				Collections.sort(m);
				Collections.sort(n,Collections.reverseOrder());
				
					System.out.println(m.size());
					for(int i : m) System.out.print(i + " ");
					System.out.println();
				
				
					System.out.println(n.size());
					for(int i : n) System.out.print(i + " ");
					System.out.println();
				
			}
		}
	}

	static void sort(int[] a) {
		//Use Collections.sort(); for ArrayList
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);Collections.sort(l);
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
