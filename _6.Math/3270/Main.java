import java.io.*;
import java.util.*;

public class Main{
	static final int N = 10000, M = 100000;
	static int[] a = new int[N+10], b = new int [M+10];
	static int[] v = new int[N+10];

	public static void main(String args[]){
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		Arrays.fill(b, 0);
		Arrays.fill(v, 0);

		int mm=-1;
		for (int i=1; i<=n; ++i){
			a[i] = in.nextInt();
			if (mm==-1 || mm>a[i]) mm=a[i];
			b[a[i]] = i;
		}
		int k=0;
		for (int i=1; i<=M; ++i){
			if (b[i]!=0) v[b[i]]= ++k;
		}
/*
		for (int i=1; i<=n; ++i) System.out.print(v[i]+" ");
		System.out.println();
*/
		int min=-1, ret=0, tot=0;
		for (int i=1; i<=n; ++i) if (v[i]!=0){
			k=i;
			min=-1; tot=0;
			while (v[k]!=0){
				int l=k;
				k=v[k];
				v[l]=0;
				ret+=a[l];
				tot++;
				if (min==-1 || min>a[l]) min=a[l];
		//		System.out.print(a[l]+" ");
			}
/*			System.out.println();
			System.out.println(min);
			System.out.println(ret);
			*/
			ret+=Math.min(mm*(tot+1)+min   ,(tot-2)*min);
		}
		System.out.println(ret);
	}
}
