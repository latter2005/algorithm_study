import java.util.*;

class Solution {
	
	public int solution(int n, int[] stations, int w) {
        int answer = 0;

        int sn = stations.length;
                
        if(stations[0] - w - 1>0)
        	answer += (stations[0] - w - 2)/(2*w + 1) + 1;
        
        for(int i=0;i<sn-1;i++){
            int interval = (stations[i + 1] - w) - (stations[i] + w) - 1;
            if(interval > 0)
                answer += (interval - 1)/(2*w + 1) + 1;
        }
        if(n - (stations[sn-1] + w) > 0)
        	answer += (n - (stations[sn-1] + w) - 1)/(2*w + 1) + 1;

        return answer;
    }
    public static void main(String arg[]) {
    	int ary[] = {8, 18};
    	Solution t = new Solution();
    	t.solution(18, ary, 2);
    }
}