#include <cstdio>
#include <cstring>
int main() {
	char ary[51];
	
	scanf("%s", ary);

	int n = strlen(ary);
	int stk[50] = { 0 }, rec[50], top = 0;
	for (int i = 0; i < n; i++) {
		if (ary[i] == '(') {
			--stk[top];
			rec[++top] = ary[i - 1] - '0';//문자로 입력받은 수를 K로 변경
		}
		else if (ary[i] == ')') {
			stk[top - 1] += rec[top] * stk[top];
			stk[top--] = 0;//스택 반영
		}
		else {
			++stk[top];//길이 증가
		}
	}
	printf("%d", stk[0]);
}
