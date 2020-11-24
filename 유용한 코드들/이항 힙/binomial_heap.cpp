#include <cstdio>
#include <queue>
using namespace std;
typedef struct node {
	int key;
	int degree;
	node *down,  *right;
	node(int key) : key(key), degree(0), down(NULL), right(NULL) {};
}node;

node *binomial_heap;
void merge_tree(node *a, node* b) {//merge tree a <- b
	node *prev = NULL;
	for (; a && a->degree < b->degree; prev = a, a = a->right);
	if (!a) {
		prev->right = b;
		b->right = NULL;
	}
	else if (a->degree != b->degree) {//insert middle or end
		if (prev)
			prev->right = b;
		b->right = a;
	}
	else {//merge
		b->right = a->right;
		while (b && a->degree == b->degree) {
			if (a->key > b->key) {
				if (prev)
					prev->right = b;
				else//front node
					binomial_heap = b;
				b->degree++;
				a->right = b->down;
				b->down = a;
				a = b;
				b = b->right;
			}
			else {
				a->degree++;
				a->right = b->right;
				b->right = a->down;
				a->down = b;
				b = a->right;
			}
		}
	}
}

void insert(int key){
	node *tmp_node = new node(key);
	if (!binomial_heap || binomial_heap->degree) {//empty root or doesn't have 0 degree
		tmp_node->right = binomial_heap;
		binomial_heap = tmp_node;
	}
	else {//merge in order starting with a binomial tree with zero degree
		
		merge_tree(binomial_heap, tmp_node);
	}
}
void pop() {
	node *cur = binomial_heap, *min = binomial_heap, *prev = NULL, *min_prev = NULL;
	while (cur) {//find min root
		if (min->key > cur->key) {
			min = cur;
			min_prev = prev;
		}
		prev = cur;
		cur = cur->right;
	}
	if (min_prev)
		min_prev->right = min->right;
	else //front node
		binomial_heap = min->right;
	
	cur = min->down;
	delete min;//delete root
	while (cur) {//merge heap and children
		prev = cur;
		cur = cur->right;
		merge_tree(binomial_heap, prev);//
	}
}
void print() {//level order
	node* cur = binomial_heap;
	queue<node*> que;
	while (cur) {
		printf("degree %d :\n%d\n", cur->degree, cur->key);
		que.push(cur->down);
		while (!que.empty()) {
			node* tmp = que.front();
			que.pop();
			while (tmp) {
				printf("%d ", tmp->key);
				que.push(tmp->down);
				tmp = tmp->right;
			}
		}
		printf("\n");
		cur = cur->right;
	}
}
int main() {
	int t;
	while (1) {
		printf("1: insert\n2: pop(min)\n3: print level order\n4: exit\noperation : ");
		scanf("%d", &t);
		switch (t) {
		case 1:
			printf("key : ");
			scanf("%d", &t);
			insert(t); 
			break;
		case 2:
			pop();
			break;
		case 3:
			print();
			break;
		case 4:
			return 1;
		}
		putc('\n', stdout);
	}
	
}

/*
1 5
1 4
1 3
1 2
1 1
1 6
1 7
1 8
1 9
1 10
1 15
1 14
1 13
1 12
1 11
1 16
1 17
1 18
1 19
1 20
1 25
1 24
1 23
1 22
1 21
1 26
1 27
1 28
1 29
1 30
1 31
1 32
1 33
2 3
*/