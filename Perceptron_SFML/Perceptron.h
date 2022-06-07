#pragma once
#include <vector>
#include <cstdlib>

class Perceptron
{
public:
	Perceptron(int numberOfInputs);
	~Perceptron();

	int feedForward(std::vector<int> inputs);
	void train(std::vector<int> inputs, int answer);

private:
	
	std::vector<int> inputs;
	std::vector<float> weights;
	float sum;
	float learningRate;

	void initWeights(int inputSize);	
	int activate(float sum);
	
};