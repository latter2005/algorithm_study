#include<cstdio>
char a[16]="               ";
int n,m,v[8];
void dfs(int cur,int val){
	if(cur==m){
		printf("%s\n",a);
		return;
	}
	for(int i=val;i<n;i++){
		if(!v[i]){
			a[cur*2]=i+'1';
			v[i]=1;
			dfs(cur+1,i+1);
			v[i]=0;
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	a[m*2]=0;
	dfs(0,0);
}