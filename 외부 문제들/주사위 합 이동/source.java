package test;
import java.util.Scanner;
import java.util.Arrays;
import java.lang.Math;
public class source { 
	
    public static void main(String[] args) throws Exception {
    	Scanner sn = new Scanner(System.in);
		int K = sn.nextInt(), N= sn.nextInt(), I= sn.nextInt();
		double[][] ary = new double[I][K+1];
		for(int i=1;i<=N;i++) ary[0][(i)%K+1]=1.0/N;
		for(int i=0;i<I-1;i++) {
			for(int j=1;j<=K;j++) {
				if(ary[i][j]!=0)
				for(int t=1;t<=N;t++) {
					ary[i+1][(j+t-1)%K+1]+=ary[i][j]/N;
				}
			}
		}
		for(int i=1;i<=K ;i++) {
			System.out.printf("%.5f\n", ary[I-1][i]);
		}
			
		
    }
}


 

