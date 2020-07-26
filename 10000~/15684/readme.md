15684 사다리 조작<br/>

주소 : <https://www.acmicpc.net/problem/15684><br/>
코드 : <https://www.acmicpc.net/source/20661984><br/>

* 풀이<br/>
dfs, 의미없는 탐색을 줄이기 위해 세로 방향 탐색 시 의미가 중복되는 사다리는 넘어감<br/>
//while(!a[i][j - 1] && !a[i][j + 1]) i++;