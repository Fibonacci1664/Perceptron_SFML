#include "Perceptron.h"

/*
* Inputs:
* x     Input
* y     Input
* bias  Input
*
*
*/

Perceptron::Perceptron(int numberOfInputs)
{
	sum = 0;
	learningRate = 0.01f;

	initWeights(numberOfInputs);
}

Perceptron::~Perceptron()
{

}

void Perceptron::initWeights(int inputSize)
{
	constexpr int FLOAT_MIN = 0;
	constexpr int FLOAT_MAX = 1;

	for (int i = 0; i < inputSize; ++i)
	{
		float randWeight = FLOAT_MIN + (float)(rand()) / ((float)(RAND_MAX / (FLOAT_MAX - FLOAT_MIN)));

		// 50/50 chance to negate the random weight
		if (rand() % 2 == 0)
		{
			randWeight = -randWeight;
		}

		weights.push_back(randWeight);
	}
}

int Perceptron::feedForward(std::vector<int> inputs)
{
	sum = 0;

	for (int i = 0; i < weights.size(); ++i)
	{
		sum += inputs[i] * weights[i];
	}

	return activate(sum);
}

int Perceptron::activate(float sum)
{
	if (sum > 0)
	{
		return 1;
	}

	return -1;
}

void Perceptron::train(std::vector<int> inputs, int answer)
{
	int guess = feedForward(inputs);
	float error = answer - guess;

	for (int i = 0; i < weights.size(); ++i)
	{
		weights[i] += learningRate * error * inputs[i];
	}
}
