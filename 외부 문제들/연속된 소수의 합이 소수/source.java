package test;
import java.util.Scanner;
import java.util.Vector;
import java.util.Comparator;
public class source{
	public static int bnry_search(Vector<Integer> seq, int val) {
		int s=0, e = seq.size() - 1;
		int m;
		while(s<e) {
			m = (s+e)/2;
			if(seq.get(m)<val) 
				s=m+1;
			else if(seq.get(m)>val)
				e = m-1;
			else
				return m;
		}
		return e;
  	}
	
    public static void main(String[] args) {
    	// stdin으로부터 정수 N을 입력받음
    	Scanner input = new Scanner(System.in);
    	int T = input.nextInt();
    	Vector <Integer> list = new Vector<Integer>();
    	Vector <Integer> seq = new Vector<Integer>();
    	int N[] = new int[T], max=0;
    	
    	for(int i=0;i<T;i++) {
    		N[i]=input.nextInt();
    		if(N[i]>max) max=N[i];
    	}
    	
		int i, cnt=0;
    	boolean prime[] = new boolean[max+1]; //false = 소수
    	
    	for(i=2;i*i<=max;i++){
    		if(!prime[i]) {
    			cnt+=i;
    			list.add(i);
    			seq.add(cnt);
    			for(int j=i+i;j<=max;j+=i)
    				prime[j]=true;
    		}
    	}
    	while(i<max) {
    		if(!prime[i]) {
    			cnt+=i;
    			list.add(i);
    			seq.add(cnt);
    			if(cnt>max)
    				break;
    			
    		}
    		i++;
    	}
    	for(int j=0;j<T;j++) {
    		int val=N[j];
    		int idx = bnry_search(seq, val);
    		
    		for(int g=0;g<idx;g++) {
        		int s=0, e=idx-g;
        		int tmp = seq.get(e);
        		while(e<list.size() && tmp<val) {
        			if(!prime[tmp]) {
        				s=-1;
        				System.out.println(tmp + " " + (idx - g + 1));
            			break;
        			}
        			tmp += list.get(++e) - list.get(s++);
        		}
        		if(s==-1) break;
        	}
    	}		
    }
   	
}

