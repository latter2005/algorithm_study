#include <cstdio>
#include <cstring>
/*
		  38 37 36
		  41 40 39
		  44 43 42
		  ---------
45 46 47 : 0  1  2 : 24 25 26
48 49 50 : 3  4  5 : 21 22 23
51 52 53 : 6  7  8 : 18 19 20
          ---------
           9 10 11
		  12 13 14
		  15 16 17
		  ---------
		  29 28 27
		  32 31 30
		  35 34 33

*/
char ary[55];
char p_seq[][8] = {
	{0,3,6,7,8,5,2,1},		//U
	{29,32,35,34,33,30,27,28},		//D
	{24,21,18,19,20,23,26,25},		//R
	{45,48,51,52,53,50,47,46},		//L
	{9,12,15,16,17,14,11,10},		//F
	{38,41,44,43,42,39,36,37}		//B
};
char seq[][12] = {
	{9,10,11,18,21,24,42,43,44,47,50,53},		//U
	{51,48,45,38,37,36,26,23,20,17,16,15},		//D
	{2,5,8,11,14,17,27,30,33,36,39,42},		//R
	{44,41,38,35,32,29,15,12,9,6,3,0},		//L
	{53,52,51,29,28,27,20,19,18,8,7,6},		//F
	{0,1,2,24,25,26,33,34,35,45,46,47}		//B
};

void rotate(char seq_n, char d) {
	char *ts = seq[seq_n], *pts = p_seq[seq_n], tmp[3];
	if (d == '+') {
		tmp[0] = ary[ts[0]]; tmp[1] = ary[ts[1]]; tmp[2] = ary[ts[2]];
		for (int i = 0; i < 9; i++) 
			ary[ts[i]] = ary[ts[i + 3]];
		ary[ts[9]] = tmp[0]; ary[ts[10]] = tmp[1]; ary[ts[11]] = tmp[2];

		tmp[0] = ary[pts[0]]; tmp[1] = ary[pts[1]];
		for (int i = 0; i < 6; i++) 
			ary[pts[i]] = ary[pts[i + 2]];
		ary[pts[6]] = tmp[0]; ary[pts[7]] = tmp[1];
	}
	else {
		tmp[0] = ary[ts[9]]; tmp[1] = ary[ts[10]]; tmp[2] = ary[ts[11]];
		for (int i = 11; i > 2; i--)
			ary[ts[i]] = ary[ts[i - 3]];
		ary[ts[0]] = tmp[0]; ary[ts[1]] = tmp[1]; ary[ts[2]] = tmp[2];

		tmp[0] = ary[pts[6]]; tmp[1] = ary[pts[7]];
		for (int i = 7; i > 1; i--)
			ary[pts[i]] = ary[pts[i - 2]];
		ary[pts[0]] = tmp[0]; ary[pts[1]] = tmp[1];
	}
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0, m; i < n; i++) {
		scanf("%d", &m);
		memcpy(ary, "wwwwwwwwwrrrrrrrrrbbbbbbbbbyyyyyyyyyoooooooooggggggggg", sizeof(ary));
		for (int j = 0; j < m; j++) {
			char op[3], seq_n;
			scanf("%s", op);
			if (op[0] == 'U') seq_n = 0;
			else if (op[0] == 'U') seq_n = 0;
			else if (op[0] == 'D') seq_n = 1;
			else if (op[0] == 'R') seq_n = 2;
			else if (op[0] == 'L') seq_n = 3;
			else if (op[0] == 'F') seq_n = 4;
			else if (op[0] == 'B') seq_n = 5;
			rotate(seq_n, op[1]);
		}
		printf("%c%c%c\n%c%c%c\n%c%c%c\n", ary[0], ary[1], ary[2], ary[3], ary[4], ary[5], ary[6], ary[7], ary[8]);
	}

}