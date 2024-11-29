#include "TQueue.h"
#include <iostream>
#include <random>
void main() {
	TQueue<int> q1(50);
	int Q = 50, P = 40, N = 10;
	int pushs = 0, pops = 0;
	for (int i = 0; i < N; i++) {
		int q = rand() % 100;
		int p = rand() % 100;
		//std::cout << q << " " << p << std::endl;
		if (p - P > 0) {
			try {
				q1.push(i);
			}
			catch (...) {
				pushs++;
			}
		}
		if (q - Q > 0) {
			try {
				q1.pop();
			}
			catch (...) {
				pops++;
			}
		}
	}
	std::cout << "Errors with push: " << pushs << std::endl;
	std::cout << "Errors with pops: " << pops;
}
