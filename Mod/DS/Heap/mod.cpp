const int N = 1e6;
int heap[N + 5], hpsize;
void tup(int x) {
    while (x > 1) {
        int ft = x >> 1;
        if (heap[ft] < heap[x]) {
            swap(heap[x], heap[ft]);
            x = ft;
        } 
		else break;
    }
}
void tdown(int x) {
    while ((x << 1) <= hpsize) {
        int c = x << 1;
        if (c + 1 <= hpsize && heap[c + 1] > heap[c]) c ++;
        if (heap[c] > heap[x]) {
            swap(heap[c], heap[x]);
            x = c;
        } 
		else break;
    }
}
void add(int x) {
    heap[++ hpsize] = x;
    tup(hpsize);
}
void pop() {
    swap(heap[hpsize], heap[1]);
    hpsize --;
    tdown(1);
}
int top() {
	return heap[1];
}
int size() {
	return hpsize;
}