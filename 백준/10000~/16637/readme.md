16637 괄호 추가하기<br/>

주소 : <https://www.acmicpc.net/problem/15683><br/>
코드 : <https://www.acmicpc.net/source/20342820><br/>

* 풀이<br/>
dfs풀이, 연산자 우선순위가 없기 때문에 현재 식을 계산하면 스텍 top의 값만 변경, 계산하지 않으면 스택에 push, 괄호 중첩을 빼기 위해 전 단계에서 bool 변수 추가