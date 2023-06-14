#include "ui.h"
int main()
{
	Car c1{4, new ElectricEngine{ 1000, 100 } };
	Car c2{ 2, new TurboEngine{ 1000 } };
	Car c3{ 4, new ElectricEngine{ 1000, 500 } };
	std::vector<Car> cars{c1, c2, c3};
	Service s{ cars };
	UI ui{ s };
	ui.run();
	return 0;
}