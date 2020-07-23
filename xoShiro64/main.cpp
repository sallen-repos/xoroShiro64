// xoShiro64.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "xoShiro64.h"
#include <chrono>
#include <bitset>

int main()
{
	xoShiro64 random;

	auto epoch = std::chrono::high_resolution_clock::now().time_since_epoch().count();
	
	random.setSeed(1);

	for (int i = 0; i < 50; i++) {

		uint64_t rand = random.nextState();
;
		//double genFloat = random.generateFloat();
		//range._16 = randNum;
		//std::cout << randFloat << "\t";
		//std::cout << genFloat << "\n";
		//std::cout << range._16 << "\n";
		std::bitset<64> bitSet(rand);
		std::bitset<64> inverse;

		std::bitset<64> flip;

		//bitSet.set(63, 0);
		//bitSet.set(62, 0);
		//bitSet.set(61, 0);

		int n = 64;

		for (int j = 0; j < 64; j++) {
			inverse[--n] = bitSet[j];

		}

		for (int j = 0; j < 64; j++) {
			flip[j] = bitSet[j];
			flip[j].flip();

		}
		for (int j = 0; j < 64; j++) {
			flip[j] = inverse[j];
			flip[j].flip();

		}

		//bitSet.set(0, 0);

		rand = bitSet.to_ullong();

		uint64_t inv = inverse.to_ullong();
		uint64_t flipped = flip.to_ullong();

		std::cout << i << "rnd: " << bitSet << "\n";
		std::cout << i << "inv: " << inverse << "\n";
		std::cout << i << "flp: " << flip << "\n";
		std::cout << i << "random: " << rand << "\n";
		std::cout << i << "flipd: " << flipped << "\n";
		std::cout << i << "inv: " << inv << "\n";

	}


	//std::cout << epoch << "\n";
	
	system("pause");

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
