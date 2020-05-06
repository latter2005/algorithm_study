package test;
import java.util.Scanner;
import java.util.Vector;

public class source {
	public static void print_seq(Vector <Integer> vec,int i) {
		System.out.print(i);
		String tmp="=";
		int c=0;
		while(i!=1) {
			int div = vec.get(c++);
			while(i%div==0) {
				tmp+=div + "*";
				i/=div;
			}
		}
		tmp = tmp.substring(0, tmp.length()-1);
		System.out.println(tmp);
		
	}
	public static void main(String[] args) {	
		Scanner sn = new Scanner(System.in);
		int n, m, count=0, i;
		boolean prime[] = new boolean[1000001]; // false : 소수
		Vector <Integer> vec = new Vector<Integer>();
		n=sn.nextInt();
		m=sn.nextInt();
		for(i=2;i*i<=n;i++) {
			if(!prime[i]) {
				vec.add(i);
				for(int j=i+i;j<=n;j+=i)
					prime[j]=true;
			}
			else {
				count++;
				if(count==m) {
					print_seq(vec, i);
					return;
				}
			}
		}
		
		while(count<m) {
			if(prime[i])
				count++;
			else vec.add(i);
			i++;
		}
		i--;
		print_seq(vec, i);
		
	}

	
	
}


