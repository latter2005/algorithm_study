#include <cstdio>
char a[16]="               ";
int n,m,v[8]; 
void d(int c) {
	if(c==m){printf("%s\n", a);return;}
	for(int i=0;i<n;i++)
		if(!v[i]) {
			a[c] = i + '1';
			v[i] = 1;
			d(c + 2);
			v[i] = 0;
		}
}
int main() {
	scanf("%d%d", &n, &m);
	m += m;
	a[m] = 0;
	d(0);
}
