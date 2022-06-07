#pragma once
#include <vector>

class Trainer
{
public:
	Trainer(int x, int y, int ans);
	~Trainer();

	std::vector<int> inputs;
	int answer;

private:
	
};