const int N = 2e4;
vector<int> g[N + 5];
int dfn[N + 5], low[N + 5], tmstmp;
bool res[N + 5];
void tarjan(int id, bool ir = 0) {
	dfn[id] = low[id] = ++ tmstmp;
	int chcnt = 0;
	for (int nxt : g[id]) {
		if (!dfn[nxt]) {
			tarjan(nxt);
			low[id] = min(low[id], low[nxt]);
			if (low[nxt] >= dfn[id] && !ir)
				res[id] = 1;
			if (ir) chcnt ++;
		}
		else 
			low[id] = min(low[id], dfn[nxt]);
	}
	if (chcnt >= 2 && ir)
		res[id] = 1;
}