#include <stdio.h>
#include <stdint.h>
#include <assert.h>

#if 0
uint64_t Fib(unsigned long n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;

	return Fib(n - 1) + Fib(n - 2);
}
#endif

#if 0
#define FIB_MAX 1000
uint64_t Fib(unsigned long n)
{
	static uint64_t s_fibCache[FIB_MAX] = {0};
	if (n == 0) return 0;
	if (n == 1) return 1;

	assert(n < FIB_MAX);

	if (n > 1 && s_fibCache[n] > 0) {
		return s_fibCache[n];
	}

	s_fibCache[n] = Fib(n - 1) + Fib(n - 2);
	return s_fibCache[n];
}
#endif

#if 1
uint64_t Fib(unsigned long n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;

	uint64_t f = 0, g = 1;
	while(--n) {
		g = g + f;
		f = g - f;
	}

	return g;
}
#endif


int main(int argc, char *argv[])
{
	int n;
	scanf("%d", &n);

	uint64_t result = Fib(n);
	printf("Fib(%d) = %llu\n", n, result);

	return 0;
}

