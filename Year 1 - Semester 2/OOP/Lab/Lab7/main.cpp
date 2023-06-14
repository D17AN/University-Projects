#include "ui.h"
#include <crtdbg.h>
int main() {
	UI::run();
	_CrtDumpMemoryLeaks();
	return 0;
}