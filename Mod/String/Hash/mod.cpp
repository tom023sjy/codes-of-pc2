struct Hash {
    int a, b, c;
};
bool operator == (Hash x, Hash y) {
    return x.a == y.a && x.b == y.b && x.c == y.c;
}
Hash hs(string s) {
    int rs1 = 0, rs2 = 0, rs3 = 0;
    const int mod1 = 65537, mod2 = 998244353, mod3 = 1e9 + 7, base = 233;
    for (char c : s) {
        rs1 = rs1 * base + c;
        rs2 = rs2 * base + c; 
        rs3 = rs3 * base + c;
        rs1 %= mod1;
        rs2 %= mod2;
        rs3 %= mod3;
    }
    return {rs1, rs2, rs3};
}