#include "Trainer.h"

Trainer::Trainer(int x, int y, int ans)
{
	inputs.push_back(x);
	inputs.push_back(y);
	inputs.push_back(1);	// Bias

	answer = ans;
}

Trainer::~Trainer()
{

}
