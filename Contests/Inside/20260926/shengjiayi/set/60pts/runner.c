#include <windows.h>
#include <stdio.h>

int main() {
	for (int i = 1; i <= 50; i += 2) {
		freopen("p1/set.in", "w", stderr);
		fprintf(stderr, "%d", i);
		fclose(stderr);
		freopen("p2/set.in", "w", stderr);
		fprintf(stderr, "%d", i + 1);
		fclose(stderr);
		system("pause");
		int f2 = i + 1;
		const char n1[] = {'c', 'o', 'p', 'y', ' ', 
							'p', '1', '\\', 's', 'e', 't', '.', 'o', 'u', 't', ' ', 
							's', 'e', 't', i / 10 + '0', i % 10 + '0', '.', 'a', 'n', 's', '\0'};
		system(n1);
		const char n2[] = {'c', 'o', 'p', 'y', ' ', 
							'p', '2', '\\', 's', 'e', 't', '.', 'o', 'u', 't', ' ', 
							's', 'e', 't', f2 / 10 + '0', f2 % 10 + '0', '.', 'a', 'n', 's', '\0'};
		system(n2);
	}
}
