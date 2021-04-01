import java.util.*;
class node implements Comparable<node>{
	double key;//시각
	int val;//트래픽 시작지점 : 1, 끝지점 -1
	node(double key, int val){
		this.key = key;
		this.val = val;
	}
	@Override
	public int compareTo(node t) {//정렬 함수
		if(this.key < t.key)
			return -1;
		else if(this.key != t.key)
			return 1;
		return 0;
	}
}
class Solution {
    public int solution(String[] lines) {
       node[] ary = new node[lines.length << 1];
        int idx = 0;
        for(String t : lines) {
        	String[] log = t.split(" ");
        	String[] time_log = log[1].split(":");
        	double end = Double.parseDouble(time_log[0])*3600 + //작업 끝시간 : line
        			Double.parseDouble(time_log[1])*60 + 
        			Double.parseDouble(time_log[2]);
        	double start = end - Double.parseDouble(log[2].replace("s", "")) + 0.001;//작업 시작 시간 
        	end = (double)((int)(end * 1000))/1000;
        	start = (double)((int)(start * 1000))/1000;//소수점 3자리 까지
        	ary[idx++] = new node(start, 1); 
        	ary[idx++] = new node(end, -1);
        }
        Arrays.sort(ary);//정렬
        int sum = 0, mx = -1;//sum : 현재 지점에서의 트래픽 : prefix sum
        
        for(int i=0;i<idx;i++) {
        	int val = sum + (ary[i].val== 1 ? 1 : 0); //현재 끝 지점인 경우도 포함하기 위해 0
        	
        	for(int j=i+1;j<idx;j++) {	
        		if(ary[j].key>=ary[i].key + 1) break;//1초 이상의 지점이 나오면 break;
        		if(ary[j].val==1)//새로운 트래픽 : 1
        			val++;
        	}
        	mx = val > mx ? val : mx;
        	sum += ary[i].val;//prefix sum
        }
        
        return mx;
    }
}