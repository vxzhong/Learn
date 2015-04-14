/*
Let's play the game Zuma!

There are a sequence of beads on a track at the right beginning. All the beads are colored but no three adjacent ones are allowed to be with a same color. You can then insert beads one by one into the sequence. Once three (or more) beads with a same color become adjacent due to an insertion, they will vanish immediately.

Note that it is possible for such a case to happen for more than once for a single insertion. You can't insert the next bead until all the eliminations have been done.

Given both the initial sequence and the insertion series, you are now asked by the fans to provide a playback tool for replaying their games. In other words, the sequence of beads after all possible eliminations as a result of each insertion should be calculated.

Input
The first line gives the initial bead sequence. Namely, it is a string of capital letters from 'A' to 'Z', where different letters correspond to beads with different colors.

The second line just consists of a single interger n, i.e., the number of insertions.

The following n lines tell all the insertions in turn. Each contains an integer k and a capital letter Σ, giving the rank and the color of the next bead to be inserted respectively. Specifically, k ranges from 0 to m when there are currently m beads on the track.

Output
n lines of capital letters, i.e., the evolutionary history of the bead sequence.

Specially, "-" stands for an empty sequence.

Example
Input

ACCBA
5
1 B
0 A
2 B
4 C
0 A
Output

ABCCBA
AABCCBA
AABBCCBA
-
A

*/

#include <stdio.h>
#include <string>
#include <iostream>

int main()
{
	std::string zuma;
	typedef std::string::size_type size_type;
	typedef std::string::iterator iterator;
	std::getline(std::cin, zuma);

	int total;
	std::cin >> total;

	size_type pos;
	char ch;
	size_type apos, bpos;
	iterator iter, aiter, biter;
	size_type count;
	size_type npos = std::string::npos;
	for (int i = 0; i < total; ++i) {
		std::cin >> pos >> ch;
		zuma = zuma.insert(pos, 1, ch);
		while (true) {
			apos = zuma.find_last_not_of(ch, pos);
			bpos = zuma.find_first_not_of(ch, pos);
			if (apos == npos) {
				aiter = zuma.begin();
			} else {
				aiter = zuma.begin() + apos + 1;
			}

			if (bpos == npos) {
				biter = zuma.end();
			} else {
				biter = zuma.begin() + bpos;
			}

			count = biter - aiter;

			if (count >= 3) {
				iter = zuma.erase(aiter, biter);

				if (zuma.empty()) {
					break;
				}

				pos = iter - zuma.begin();
				ch = *iter;
			} else {
				break;
			}
		}

		if (zuma.empty()){
			std::cout << '-' << std::endl;
		} else {
			std::cout << zuma << std::endl;
		}
	}

	return 0;
}

