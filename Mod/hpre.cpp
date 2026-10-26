#define int long long
struct big {
	int a[100005];
	int &operator [] (int x) {
		if (x > 100000) throw "ValueError!";
		return a[x];
	}
	int size() {
		return a[0];
	}
	void clear() {
		memset(a, 0, sizeof a);
		a[0] = 1;
	}
	void push(string s) {
		int l = s.size();
		for (int i = 1; i <= l; i ++)
			a[i] = s[l - i] - '0';
		a[0] = l;
	}
	void reset() {clear();}
	string getstr() {
		string res = "";
		for (int i = 1; i <= a[0]; i ++)
			res += char(a[i] + '0');
		return res;
	} 
	big(string _str) {
		reset();
		push(_str);
	} 
	big(int _num) {
		reset();
		push(to_string(_num));
	}
	big() {
		reset();
	}
	void put() {
		for (int i = a[0]; i >= 1; i --)
			cout << a[i];
	}
	void get() { 
		string s;
		cin >> s;
		push(s);
	}
	void operator = (int n) { 
		reset();
		push(to_string(n));
	}
	void operator = (string s) {
		reset();
		push(s);
	}
	void operator = (const char* s) { 
		string tmp = s;
		reset();
		push(tmp);
	}
	void operator = (big c) { 
		a[0] = c[0];
		for (int i = 1; i <= a[0]; i ++)
			a[i] = c[i];
	}
	void operator += (big b) { 
		big c;
		c[0] = max(a[0], b[0]);
		for (int i = 1; i <= c[0]; i ++)
			c[i] = a[i] + b[i];
		for (int i = 1; i <= c[0]; i ++) {
			c[i + 1] += c[i] / 10;
			c[i] %= 10;
			if (c[c[0] + 1])
				c[0] ++;
		}
		a[0] = c[0];
		for (int i = 1; i <= a[0]; i ++)
			a[i] = c[i];
	}
	void operator += (int _b) { 
		big b, c;
		b.reset();
		b.push(to_string(_b));
		c[0] = max(a[0], b[0]);
		for (int i = 1; i <= c[0]; i ++)
			c[i] = a[i] + b[i];
		for (int i = 1; i <= c[0]; i ++) {
			c[i + 1] += c[i] / 10;
			c[i] %= 10;
			if (c[c[0] + 1])
				c[0] ++;
		}
		a[0] = c[0];
		for (int i = 1; i <= a[0]; i ++)
			a[i] = c[i];
	}
	void operator -= (big b) {
		big c;
		c[0] = max(a[0], b[0]);
		for (int i = 1; i <= c[0]; i ++)
			c[i] = a[i] - b[i];
		for (int i = 1; i <= c[0]; i ++)
			if (c[i] < 0)
				c[i] += 10, c[i + 1] --;
		while (c[c[0]] == 0 && c[0] > 1) c[0] --;
		a[0] = c[0];
		for (int i = 1; i <= a[0]; i ++)
			a[i] = c[i];
	}
	void operator -= (int _b) {
		big b, c;
		b.reset();
		b.push(to_string(_b));
		c[0] = max(a[0], b[0]);
		for (int i = 1; i <= c[0]; i ++)
			c[i] = a[i] - b[i];
		for (int i = 1; i <= c[0]; i ++)
			if (c[i] < 0)
				c[i] += 10, c[i + 1] --;
		while (c[c[0]] == 0 && c[0] > 1) c[0] --;
		a[0] = c[0];
		for (int i = 1; i <= a[0]; i ++)
			a[i] = c[i];
	}
	void operator *= (int b) { 
		big c;
		c[0] = a[0];
		for (int i = 1; i <= c[0]; i ++)
			c[i] = a[i] * b;
		for (int i = 1; i <= c[0]; i ++) {
			c[i + 1] += c[i] / 10;
			c[i] %= 10;
			if (c[c[0] + 1])
				c[0] ++;
		}
		a[0] = c[0];
		for (int i = 1; i <= a[0]; i ++)
			a[i] = c[i];
	}
	void operator *= (big b) {
		big c;
		c[0] = a[0] + b[0];
		for (int i = 1; i <= a[0]; i ++)
			for (int j = 1; j <= b[0]; j ++)
				c[i + j - 1] = a[i] * b[j];
		for (int i = 1; i <= c[0]; i ++) {
			c[i + 1] += c[i] / 10;
			c[i] %= 10;
			if (c[c[0] + 1])
				c[0] ++;
		}
		a[0] = c[0];
		for (int i = 1; i <= a[0]; i ++)
			a[i] = c[i];
	}
	void operator /= (int b) {
		big c;
		c[0] = a[0];
		int r = 0;
		for (int i = c[0]; i >= 1; i --) {
			int t = r * 10 + a[i];
			c[i] = t / b;
			r = t % b;
		}
		while (c[c[0]] == 0 && c[0] > 1)
			c[0] --;
		a[0] = c[0];
		for (int i = 1; i <= a[0]; i ++)
			a[i] = c[i];
	}
	void operator %= (int b) {
		big c;
		c[0] = a[0];
		int r = 0;
		for (int i = c[0]; i >= 1; i --) {
			int t = r * 10 + a[i];
			c[i] = t / b;
			r = t % b;
		}
		push(to_string(r));
	}
};
big operator + (big a, big b) { 
	big c;
	c[0] = max(a[0], b[0]);
	for (int i = 1; i <= c[0]; i ++)
		c[i] = a[i] + b[i];
	for (int i = 1; i <= c[0]; i ++) {
		c[i + 1] += c[i] / 10;
		c[i] %= 10;
		if (c[c[0] + 1])
			c[0] ++;
	}
	return c;
}
big operator - (big a, big b) { 
	big c;
	c[0] = max(a[0], b[0]);
	for (int i = 1; i <= c[0]; i ++)
		c[i] = a[i] - b[i];
	for (int i = 1; i <= c[0]; i ++)
		if (c[i] < 0)
			c[i] += 10, c[i + 1] --;
	while (c[c[0]] == 0 && c[0] > 1) c[0] --;
	return c;
}
big operator * (big a, int b) { 
	big c;
	c[0] = a[0];
	for (int i = 1; i <= c[0]; i ++)
		c[i] = a[i] * b;
	for (int i = 1; i <= c[0]; i ++) {
		c[i + 1] += c[i] / 10;
		c[i] %= 10;
		if (c[c[0] + 1])
			c[0] ++;
	}
	return c;
}
big operator * (int a, big b) { 
	return b * a;
}
big operator * (big a, big b) { 
	big c;
	c[0] = a[0] + b[0];
	for (int i = 1; i <= a[0]; i ++)
		for (int j = 1; j <= b[0]; j ++)
			c[i + j - 1] = a[i] * b[j];
	for (int i = 1; i <= c[0]; i ++) {
		c[i + 1] += c[i] / 10;
		c[i] %= 10;
		if (c[c[0] + 1])
			c[0] ++;
	}
	return c;
}
big operator / (big a, int b) { 
	big c;
	c[0] = a[0];
	int r = 0;
	for (int i = c[0]; i >= 1; i --) {
		int t = r * 10 + a[i];
		c[i] = t / b;
		r = t % b;
	}
	while (c[c[0]] == 0 && c[0] > 1)
		c[0] --;
	return c;
}
int operator % (big a, int b) { 
	big c;
	c[0] = a[0];
	int r = 0;
	for (int i = c[0]; i >= 1; i --) {
		int t = r * 10 + a[i];
		c[i] = t / b;
		r = t % b;
	}
	return r;
}
bool operator < (big a, big b) {
	if (a[0] != b[0]) return a[0] < b[0];
	for (int i = a[0]; i >= 1; i --)
		if (a[i] != b[i])
			return a[i] < b[i];
	return 0;
}
bool operator == (big a, big b) {
	if (a[0] != b[0]) return 0;
	for (int i = a[0]; i >= 1; i --)
		if (a[i] != b[i])
			return 0;
	return 1;
}
bool operator > (big a, big b) {
	if (a[0] != b[0]) return a[0] > b[0];
	for (int i = a[0]; i >= 1; i --)
		if (a[i] != b[i])
			return a[i] > b[i];
	return 0;
}