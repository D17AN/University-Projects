#include "ui.h"
#include "tests.h"

int main(){
	Tests::runTests();


	Protein p1{ "Human", "Myosin-2", "MSSDSELAVFGEAA" };
	Protein p2{"Human", "Keratin", "TCGSGFGGRAFSCISACGPRPGRCC" };
	Protein p3{"Mouse", "Keratin", "MLWWEEVEDCYEREDVQKK"};
	Protein p4{"E_Coli", "tufA", "VTLIHPIAMDDGLRFAIRE"};
	Protein p5{"E_Coli", "cspE", "MSKIKGNVKWFNESKGFGFITPEDG"};
	std::vector<Protein> v{p1, p2, p3, p4, p5};
	Repository repo{v};
	Controller c{repo};
	UI ui{c};
	ui.run();
	return 0;
}