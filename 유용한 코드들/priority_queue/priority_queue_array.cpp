#define MAX_SIZE 300000
#define swap(a, b) int tmp=a;a=b;b=tmp
typedef struct priority_queue {
	int heap[MAX_SIZE];
	int size=0;


	int push(int value) {
		if (size + 1 > MAX_SIZE) {
			return 0;
		}

		heap[size] = value;

		int current = size;
		int parent = (size - 1) / 2;

		while (current > 0 && heap[current] > heap[parent]) {
			swap(heap[current], heap[parent]);
			current = parent;
			parent = (parent - 1) / 2;
		}

		size++;

		return 1;
	}

	int pop() {
		if (size <= 0) return -1;

		int ret = heap[0];
		size--;

		heap[0] = heap[size];
		int current = 0;
		int leftChild = current * 2 + 1;
		int rightChild = current * 2 + 2;
		int maxNode = current;

		while (leftChild < size) {
			if (heap[maxNode] < heap[leftChild]) {
				maxNode = leftChild;
			}
			if (rightChild < size && heap[maxNode] < heap[rightChild]) {
				maxNode = rightChild;
			}

			if (maxNode == current) {
				break;
			}
			else {
				swap(heap[current], heap[maxNode]);
				current = maxNode;
				leftChild = current * 2 + 1;
				rightChild = current * 2 + 2;
			}
		}

		return ret;
	}

	inline bool empty() {
		return size == 0;
	}
}priority_queue;
