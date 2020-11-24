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
	for (; a ; prev = a, a = a->right) {
		if (a->degree <= b->degree)
			break;
	}
	if (!a) {
		prev->right = b;
	}
	else if (a->degree != b->degree) {//insert
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
				b->right = a->down;
				a->down = b;
				b = a->right;
			}
		}
	}
}
void merge_heap(node *a, node *b) {//merge heap(set of tree) a <- b
	node *prev = NULL, *tmp;
	while (b) {
		tmp = b->right;
		if (a->degree == b->degree) {//
			if (a->key > b->key) {
				b->right = a->right;
				if (prev)
					prev->right = b;

				a->right = b->down;
				b->down = a;
				prev = b;
			}
			else {
				a->degree++;
				b->right = a->down;
				a->down = b;
				prev = a;
			}
			node *check = prev;
			
		}
		b = tmp;
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

}
void print() {
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
1 1
1 2
1 3
1 4
1 5
1 6
1 7
1 8
1 9
1 10
1 11
1 12
1 13
1 14
1 15
1 16
1 17
1 18
1 19
1 20
3
*/