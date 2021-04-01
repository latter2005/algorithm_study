import java.util.*;
import java.util.Map.Entry;
class Solution {
    public int solution(String str1, String str2) {
        int res;
        str1 = str1.toLowerCase();//모두 소문자로 만들기
        str2 = str2.toLowerCase();
        String key;
        Map<String, Integer> mp1 = new HashMap<String, Integer>(),
        		mp2 = new HashMap<String, Integer>();//해쉬맵 사용 key : 원소, value : 등장횟수
    	for(int i=0;i<str1.length()-1;i++) {
    		
    		if(Character.isLowerCase(str1.charAt(i)) && Character.isLowerCase(str1.charAt(i+1))) {
    			key = str1.substring(i, i+2);
    			if(mp1.containsKey(key))
    				mp1.put(key, mp1.get(key) + 1);//이미 있으면 +1
    			else
    				mp1.put(key, 1);//없으면 새로 생성
    		}
    	}
    	for(int i=0;i<str2.length()-1;i++) {
    		if(Character.isLowerCase(str2.charAt(i)) && Character.isLowerCase(str2.charAt(i+1))) {
    			key = str2.substring(i, i+2);
    			if(mp2.containsKey(key))
    				mp2.put(key, mp2.get(key) + 1);
    			else
    				mp2.put(key, 1);
    		}
    	}
    	double inter = 0, union = 0;
    	for(Entry<String, Integer> entry : mp1.entrySet()) {
    		key = entry.getKey();
    		int val = entry.getValue();
    		if(mp2.containsKey(key)){//공통 원소가 있다면
    			int tmp = mp2.get(key);
    			if(val > tmp) {inter += tmp; union+=val;}//교집합 : 적은값, 합집합 : 큰값
    			else {inter += val; union+=tmp;}
    		}
    		else//공통 원소가 없다면 합집합만 추가
    			union+=val;
    	}
    	for(Entry<String, Integer> entry : mp2.entrySet()) {//str2의 원소들을 합집합에 추가
    		if(!mp1.containsKey(entry.getKey()))//str1 검사하면서 추가했으므로 str1에 없는 원소만을 추가
    			union+=entry.getValue();
    	}
        if(union==0)return 65536;//합집합 개수가 0
    	return (int)(inter / union * 65536);
    }
}