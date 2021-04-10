#include<cstdio>
int main(){
	char a[101][101]={0},dy[]={1,0,-1,0},dx[]={0,-1,0,1};
	int n,c=0;
	scanf("%d",&n);
	for(int i=0,x,y,d,g;i<n;i++){
		scanf("%d%d%d%d",&y,&x,&d,&g);
		a[x][y]=1;
		x+=dx[d];y+=dy[d];
		a[x][y]=1;
		char s[1024]={d};
		for(int t=0,c=1;t<g;t++,c<<=1){
			for(int j=0;j<c;j++){
				d=s[c+j]=(s[c-j-1]+1)%4;
				x+=dx[d];y+=dy[d];
				a[x][y]=1;
			}
		}
	}
	for(int i=0;i<100;i++){
		for(int j=0;j<100;j++){
			if(a[i][j]&&a[i][j+1]&&a[i+1][j]&&a[i+1][j+1])
				c++;
		}
	}
	printf("%d",c);
}