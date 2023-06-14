#include "tests.h"

void Tests::testAdd()
{
	Protein p1{"Human", "Myosin-2", "MSSDSELAVFGEAA"};
	Protein p2{"Human", "Keratin", "TCGSGFGGRAFSCISACGPRPGRCC"};
	Protein p3{"Mouse", "Keratin", "MLWWEEVEDCYEREDVQKK"};
	Protein p4{"E_Coli", "tufA", "VTLIHPIAMDDGLRFAIRE"};
	Protein p5{"E_Coli", "cspE", "MSKIKGNVKWFNESKGFGFITPEDG"};

	Repository repo;
	Controller c{repo};

	c.add(p1);
	c.add(p2);
	c.add(p3);
	c.add(p4);
	c.add(p5);
	assert(c.getAll().size() == 5);
	try{
		c.add(p1);
		assert(false);
	}
	catch (...){
		assert(true);
	}
	assert(c.getAll().size() == 5);
}

void Tests::testGetByName()
{
	Protein p1{"Human", "Myosin-2", "MSSDSELAVFGEAA"};
	Protein p2{"Human", "Keratin", "TCGSGFGGRAFSCISACGPRPGRCC"};
	Protein p3{"Mouse", "Keratin", "MLWWEEVEDCYEREDVQKK"};
	Protein p4{"E_Coli", "tufA", "VTLIHPIAMDDGLRFAIRE"};
	Protein p5{"E_Coli", "cspE", "MSKIKGNVKWFNESKGFGFITPEDG"};
	std::vector<Protein> v{p1, p2, p3, p4, p5};
	Repository repo{v};
	Controller c{repo};
	
	assert(c.getByName("Keratin").size() == 2);
}

void Tests::runTests()
{
	Tests::testAdd();
	Tests::testGetByName();
}
