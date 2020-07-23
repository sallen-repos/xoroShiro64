#include "pch.h"
#include "xoShiro64.h"
#include <limits.h>
#include <iostream>
#include <bitset>


static uint64_t seedValue;


uint64_t xoShiro64::rotate(uint64_t x, int k)
{
	return (x << k) | (x >> (64 - k));
}



uint64_t xoShiro64::splitmix64()
{


	seed.result = (seed.seedVal += 0x9e3779b97f4a7c15);
	seed.result = (seed.result ^ (seed.result >> 30)) * 0xbf58476d1ce4e5b9;
	seed.result = (seed.result ^ (seed.result >> 27)) * 0x94d049bb133111eb;
	seed.result ^ (seed.result >> 31);
	seed.seedVal += seed.result;

	return seed.result;

}



double xoShiro64::applyMask(uint64_t &value, uint64_t start, uint64_t length)
{
	//value = ((1 << length) & 1) << start;
	//value ^= (-1 ^ value) & (1UL << n);

	//value & maskValue;
	return value;
	
	// << length - sizeof(uint64_t);
}

double xoShiro64::generateFloat()
{
	//uint64_t random = applyMask(generate(), 0, 53);
	
	uint64_t random = nextState();
	//std::cout << random << "\t";
	//double randomDouble = applyMask(random, 0, 12);

	std::bitset<64> bits(random);
	
	//for (int i = 0; i < 62; i++)
	//	bits.set(i, 1);

	bits.set(63, 0);
	bits.set(1, 0);
		
	double dub = (double)bits.to_ullong();

	return dub;
}

uint64_t xoShiro64::getRandOne()
{
	nextState();
	return state.s0;
}

State xoShiro64::getState()
{
	nextState();
	return state;
}


xoShiro64::xoShiro64()
{
}

xoShiro64::~xoShiro64()
{
}

void xoShiro64::setSeed(uint64_t input)		//seeds with splitmix64 generator
{
	seedValue = input;

	setState();
	
}

void xoShiro64::setState()
{
	uint64_t temp = splitmix64();
	state.s0 = temp;
	state.s1 = splitmix64();
	state.s2 = splitmix64();
	state.s3 = splitmix64();
	
	//std::cout << state.s0 << '\n';
	//std::cout << state.s1 << '\n';
	//std::cout << state.s2 << '\n';
	//std::cout << state.s3 << '\n';
}

uint64_t xoShiro64::nextState()
{
	const uint64_t result = state.s0 + state.s3;

	const uint64_t t = state.s1 << 17;

	state.s2 ^= state.s0;
	state.s3 ^= state.s1;
	state.s1 ^= state.s2;
	state.s0 ^= state.s3;

	state.s2 ^= t;

	state.s3 = rotate(state.s3, 45);

	return result;
}


