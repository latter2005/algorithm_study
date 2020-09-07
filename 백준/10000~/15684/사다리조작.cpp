#include <cstdio>
int N, M, H, m = 4;
bool a[31][11];
bool ch(){
	for(int i = 1; i <= N; i++) {
		int t = i;
		for(int j = 1; j <= H; j++) {
			if(a[j][t]) t++;
			else if(a[j][t - 1]) t--;
		}
		if(t != i) return false;
	}
	return true;
}
void dfs(int cn, int mc){
	if(m!=4)return;
	if(mc==cn){
		if(ch())
			m=m>cn?cn:m;
		return;
	}
	for(int j=1; j < N; j++){
		for(int i = 1; i <= H; i++) {
			if(a[i][j] || a[i][j + 1] || a[i][j - 1])continue;
			a[i][j] = 1;
			dfs(cn+1,mc);
			a[i][j] = 0;
			while(!a[i][j - 1] && !a[i][j + 1]) i++;
		}
	}
}
int main() {
	scanf("%d%d%d", &N, &M, &H);
	for(int i = 0, x, y; i < M; i++) {
		scanf("%d%d", &x, &y);
		a[x][y] = 1;
	}
	for(int i = 0; i < 4; i++) {
		dfs(0,i);
		if(m != 4) {
			printf("%d",m);
			break;
		}
	}
	if(m==4)printf("-1");
	
}