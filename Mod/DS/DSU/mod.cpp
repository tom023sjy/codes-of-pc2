int f[N + 5];
int find(int id) {
    if (f[id] != id)
        f[id] = find(f[id]);
    return f[id];
}
void merge(int a, int b) {
    int fta = find(a), ftb = find(b);
    if (fta != ftb)
        f[fta] = ftb;
}
bool query(int a, int b) {
    return find(a) == find(b);
}