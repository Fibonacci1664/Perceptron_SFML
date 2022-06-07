#include <cstdlib>
#include "Application.h"

int main()
{
    std::srand(std::time(nullptr)); // use current time as seed for random generator

    Application app(600, 600);
    app.update();

    system("Pause");
     
	return 0;
}