/*
Descriptioin
Let S be a set of n integral points on the x-axis. For each given interval [a, b], you are asked to count the points lying inside.

Input
The first line contains two integers: n (size of S) and m (the number of queries).

The second line enumerates all the n points in S.

Each of the following m lines consists of two integers a and b and defines an query interval [a, b].

Output
The number of points in S lying inside each of the m query intervals.

Example
Input

5 2
1 3 7 9 11
4 6
7 12
Output

0
3
Restrictions
0 <= n, m <= 5 * 10^5

For each query interval [a, b], it is guaranteed that a <= b.

Points in S are distinct from each other.

Coordinates of each point as well as the query interval boundaries a and b are non-negative integers not greater than 10^7.

Time: 2 sec

Memory: 256 MB
*/


#include <stdio.h>
#include <new>

static const unsigned long kMaxPoint = 10000000;
static int allpoints[kMaxPoint + 1];

int main() {
	int len, queries;
	scanf("%d %d", &len, &queries);

	int v, minpoint = kMaxPoint, maxpoint = 0;
	for (int i = 0; i < len; ++ i) {
		scanf("%d", &v);
		if (v < minpoint) minpoint = v;
		if (v > maxpoint) maxpoint = v;
		allpoints[v] = 1;
	}

	for (int i = minpoint + 1; i <= maxpoint; ++i) {
		allpoints[i] = allpoints[i] + allpoints[i - 1];
	}

	for (int i = 0; i < queries; ++i) {
		int low, high;
		scanf("%d %d", &low, &high);

		int highrange, lowrange;
		if (high > maxpoint)
			highrange = allpoints[maxpoint];
		else
			highrange = allpoints[high];

		if (low > maxpoint)
			lowrange = allpoints[maxpoint];
		else {
			lowrange = allpoints[low];
			if (allpoints[low] != allpoints[low - 1]) {
				lowrange -= 1;
			}
		}

		int counter = highrange - lowrange;
		printf("%d\n", counter);
	}

	return 0;
}
