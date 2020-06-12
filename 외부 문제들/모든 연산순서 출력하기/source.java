package test;
import java.util.Scanner;
import java.util.ArrayList;

public class source { 
	
	public static int res=1, n;
	static ArrayList <String> q = new ArrayList<String>();
	
	public static void main(String[] args) {
    	Scanner sn = new Scanner(System.in);
    	n=sn.nextInt();
    	q.add("(o o)");
    	for(int i=2;i<n;i++) {
    		String []t = new String[res];
    		int[] cur = new int[res];
    		for(int j=0;j<res;j++) {
    			t[j] = q.get(j);
    		}
    		q.clear();
    		
    		for(int j=0;j<i;j++) {
    			for(int k=0;k<res;k++) {
    				int idx = cur[k];
    				while(t[k].charAt(idx)!='o') idx++;
    				String tmp = t[k].substring(0, idx) + "(o o)" + t[k].substring(idx+1);
    				if(!q.contains(tmp)) q.add(tmp);
    				cur[k]=idx+1;
    			}
    		}
    		res=q.size();
    	}
    	for(String t : q) System.out.println(t);
    	System.out.println(res);
	}
}


