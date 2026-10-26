const int N = 0; // Replace '0' to your want value.
int vl[N + 5], prv[N + 5], nxt[N + 5];
int head = 0, tail = N + 3, id = 0;

void conn(int x, int y) {
	prv[y] = x, nxt[x] = y;
}
void insL(int id, int nid) {
	conn(prv[id], nid);
	conn(nid, id);
}
void insR(int id, int nid) {
	conn(nid, nxt[id]);
	conn(id, nid);
}
void del(int k) {
	conn(prv[k], nxt[k]);
}
void init() {
	conn(head, tail);
}