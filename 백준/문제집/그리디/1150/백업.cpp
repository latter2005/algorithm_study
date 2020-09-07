#include <cstdio>
#include <vector>
#include <queue>
typedef struct data {
	int val, left, right;
	
}data;
struct comp {
	bool operator()(data a, data b) {
		return a.val > b.val;
	}
};
inline int next_int() {
	int x = 0;
	bool neg = false;
	register int c;
	c = getchar();
	if (c == '-') {
		neg = true;
		c = getchar();
	}
	for (; (c > 47 && c < 58); c = getchar())
		x = (x << 1) + (x << 3) + c - 48;
	if (neg)
		x *= -1;
	return x;
}
int main() {
	std::priority_queue<data, std::vector<data>, comp> pty_queue;
	int n, k, res = 0, p;
	data point[100001];
	scanf("%d%d", &n, &k);
	getchar();
	p = next_int();
	for (int i = 1, tmp; i < n; i++) {
		tmp = tmp = next_int();
		point[i].val = tmp-p;
		point[i].left = i - 1;
		point[i].right = i + 1;
		
		pty_queue.push(data{ point[i].val , i, i+1});
		p = tmp;
	}
	point[n] = { 0, n - 1, n + 1 };

	for (int i = 0; i < k;) {
		data t = pty_queue.top();
		pty_queue.pop();
		int cl = t.left, cr = t.right;
		if (cl >= 1 && cr <= n && cr == point[cl].right && cl == point[cr].left) {
			res += t.val;
			if (++i >= k) break;
			int nl = point[cl].left, nr = point[cr].right;
			t.left = nl; t.right = nr;
			point[nl].val = point[nl].val + point[cr].val - t.val;
			t.val = point[nl].val;
			pty_queue.push(t);
			point[nl].right = nr;
			point[nr].left = nl;
			
		}
	}
	printf("%d", res);
	return 0;
}
