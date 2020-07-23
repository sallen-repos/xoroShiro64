#pragma once
#include <stdint.h>

struct State {

	uint64_t s0;
	uint64_t s1;
	uint64_t s2;
	uint64_t s3;

};

struct StateArr {

	uint64_t s[4];


};

struct Seed {

	//unsigned long long seedVal : 64;
	uint64_t seedVal;
	//unsigned long long result : 64;
	uint64_t result;
};

class xoShiro64
{

private:
	

	Seed seed;


	void setState();
	uint64_t splitmix64();
	uint64_t rotate(uint64_t, int);
	
	//uint64_t state[4];
	State state;
	StateArr stateArr;
	double applyMask(uint64_t &value, uint64_t start, uint64_t length);
	

public:
	xoShiro64();
	~xoShiro64();

	void setSeed(uint64_t);
	
	uint64_t nextState();
	double generateFloat();

	uint64_t getRandOne();

	State getState();
};

