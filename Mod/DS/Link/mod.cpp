int vl[N + 5], prv[N + 5], nxt[N + 5];
int head = 0, tail = N + 3, id = 0;
inline void conn(int x, int y) {
	prv[y] = x, nxt[x] = y;
}
inline void insL(int id, int nid) {
	conn(prv[id], nid);
	conn(nid, id);
}
inline void insR(int id, int nid) {
	conn(nid, nxt[id]);
	conn(id, nid);
}
inline void del(int k) {
	conn(prv[k], nxt[k]);
}
inline void init() {
	conn(head, tail);
}