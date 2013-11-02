import java.util.*;
import java.io.*;
import java.math.*;

class P{
	BigInteger i, x, y;
	void update(){
		BigInteger z=x.gcd(y);
		x=x.divide(z);
		y=y.divide(z);
	}
}
class Gao{
	P[] a=new P[1010];
	BigInteger x, y;
	
	
	BigInteger lcm(BigInteger a, BigInteger b){
		BigInteger c=(a.divide(a.gcd(b))).multiply(b);
		return c;
	}
	
	public void solve(){
		Scanner cin = new Scanner(System.in);
		while (cin.hasNext()){
			int n=cin.nextInt();
			for (int i=0; i<n; ++i){ 
				a[i]=new P(); 
				a[i].i=cin.nextBigInteger();
			}
			
			for (int i=1; i<n; ++i){
				x=a[0].i; y=a[i].i;
				if (x.compareTo(y)==1){
					BigInteger z=x; x=y; y=z;
				}
				a[i].x=x.multiply(y);
				a[i].y=(y.subtract(x)).multiply(new BigInteger("2"));
				a[i].update();				
			}
			
		/*	for (int i=1; i<n; ++i){
				System.out.print(a[i].x);
				System.out.print(' ');
				System.out.println(a[i].y);
			}
			*/

			for (int i=2; i<n; ++i){
				a[1].x=lcm(a[1].x, a[i].x);
				a[1].y=a[1].y.gcd(a[i].y);
			}
			
			System.out.print(a[1].x);
			System.out.print(' ');
			System.out.println(a[1].y);
		}
	}
}
public class Main {
	public static void main(String args[]){
		new Gao().solve();
	}
}
