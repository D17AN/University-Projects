#include "tests.h"


void Test::runTests(){
	VectorTest().runTests();
	UtilsTest().runTests();
	TrenchCoatValidationTests().runTests();
	TrenchCoatTests().runTests();
	RepositoryTests().runTests();
	ControllerAdministratorTests().runTests();
	BasketTests().runTests();
	ControllerUserTests().runTests();
}


void VectorTest::runTests(){
	this->testAdd();
	this->testRemove();
	this->testRemovePosition();
	this->testSearch();
	this->testGet();
	this->testDereferencingOperator();
	this->testAssignmentOperator();
	this->testEqualityOperator();
	this->testCopyConstructor();
}

void VectorTest::testAdd(){
	Vector<int> v;
	for (int i = 0; i < 100; i++){
		v.add(i);
	}

	for (int i = 0; i < 100; i++){
		assert(v[i] == i);
	}
}

void VectorTest::testRemove(){
	Vector<int> v;
	for (int i = 0; i < 20; i++){
		v.add(i);
	}

	//remove all the even elements
	for (int i = 0; i < v.getSize(); i++){
		if (v[i] % 2 == 0){
			v.remove(v[i]);
			i--;
		}
	}

	//we try to remove all the even elements, which were previously deleted
	//if there's a succesfull remove, then the test will fail, otherwise will pass
	for (int i = 0; i < 20; i++){
		if(i % 2 == 0){
			try{
				v.remove(i);
				assert(false);
			}
			catch (VectorException& e){
				assert(true);
				assert(strstr(e.what(), "The element doesn't exist!") != 0);
			}
		}
	}


	for (int i = 0; i < v.getSize(); i++){
		assert(v[i] % 2 != 0);
	}

	assert(v.getSize() == 10);
}


void VectorTest::testRemovePosition(){
	Vector<int> v;
	for (int i = 0; i < 20; i++){
		v.add(i);
	}

	//remove 10th element
	int val = v[v.getSize() / 2];
	v.removePosition(v.getSize() / 2);
	assert(v[v.getSize() / 2] != val);

	
	assert(v.getSize() == 19);

	//try to remove an position out of bound, if the remove is successful the test fails
	try{
		v.removePosition(-1);
		assert(false);
	}
	catch (MyException& e){
		assert(true);
		assert(strstr(e.what(), "Index out of bound!") != 0);
	}
}

void VectorTest::testSearch(){
	Vector<int> v;
	for (int i = 0; i < 20; i++){
		v.add(i);
	}

	for (int i = 0; i < 20; i++){
		assert(v.search(i) == i);
	}

	for (int i = 20; i < 30; i++){
		assert(v.search(i) == -1);
	}
}

void VectorTest::testGet(){
	Vector<int> v;
	for (int i = 0; i < 10; i++){
		v.add(i);
	}
	Vector<int>* u = &v.get();
	assert(u == &v);
}

void VectorTest::testDereferencingOperator(){
	Vector<int> v;
	for (int i = 0; i < 10; i++){
		v.add(i);
	}

	for (int i = 0; i < 10; i++){
		assert(v[i] == i);
	}

	try{
		v[-1];
		assert(false);
	}
	catch (...){
		assert(true);
	}
}

void VectorTest::testAssignmentOperator(){
	Vector<int> v;
	for (int i = 0; i < 20; i++){
		v.add(i);
	}

	Vector<int> q;
	for (int i = 0; i < 10; i++){
		q.add(i + 20);
	}
	
	v = q;
	assert(v.getSize() == 10);
	for (int i = 0; i < 10; i++){
		assert(v[i] == i + 20);
	}

	assert(&v == &(v = v));
}


void VectorTest::testEqualityOperator(){
	Vector<int> v, u;
	for (int i = 0; i < 20; i++){
		v.add(i);
		u.add(i);
	}
	assert(u == v);
	u.add(13);
	v.add(14);
	assert(false == (u == v));
	v.removePosition(v.getSize() - 1);
	assert(false == (u == v));
}


void VectorTest::testCopyConstructor(){
	Vector<int> v;
	for (int i = 0; i < 20; i++){
		v.add(i);
	}

	Vector<int> u{v};
	Vector<int> q;
	assert(u == v);
}


void UtilsTest::runTests(){
	this->testTokenize();
	this->testFormatSentece();
}


void UtilsTest::testTokenize(){
	std::string s{"   IS   A beautiful Day || Fly ME TO thE  Moon | RememBer  "};
	std::vector<std::string> tokens = Utils::tokenize(s, '|');
	assert(tokens.size() == 3);
	assert(tokens[0] == "is a beautiful day");
	assert(tokens[1] == "fly me to the moon");
	assert(tokens[2] == "remember");
}

void UtilsTest::testFormatSentece(){
	std::string s{"  Is a  beautiful day  "};
	Utils::formatSentence(s);
	assert(s == "is a beautiful day");
	s.clear();
	s = "   ";
	Utils::formatSentence(s);
	assert(s == "");

	std::string s2{"A"};
	Utils::formatSentence(s2);
	assert(s2 == "a");
}


void TrenchCoatValidationTests::runTests(){
	this->testIsSizeValid();
	this->testIsColorValid();
	this->testIsPriceValid();
	this->testIsQuantityValid();
	this->testIsPhotographLinkValid();
}


void TrenchCoatValidationTests::testIsSizeValid(){
	assert(TrenchCoatValidator::isSizeValid("s") == true);
	assert(TrenchCoatValidator::isSizeValid("m") == true);
	assert(TrenchCoatValidator::isSizeValid("l") == true);
	assert(TrenchCoatValidator::isSizeValid("xl") == true);
	assert(TrenchCoatValidator::isSizeValid("xxl") == false);
}


void TrenchCoatValidationTests::testIsColorValid(){
	assert(TrenchCoatValidator::isColorValid("blue") == true);
}


void TrenchCoatValidationTests::testIsPriceValid(){
	assert(TrenchCoatValidator::isPriceValid(12) == true);
	assert(TrenchCoatValidator::isPriceValid(-1) == false);
}


void TrenchCoatValidationTests::testIsQuantityValid(){
	assert(TrenchCoatValidator::isQuantityValid(10) == true);
	assert(TrenchCoatValidator::isQuantityValid(-1) == false);
}


void TrenchCoatValidationTests::testIsPhotographLinkValid(){
	assert(TrenchCoatValidator::isPhotographLinkValid("www.photograph.com"));
}


void TrenchCoatTests::runTests(){
	this->testCopyConstructor();
	this->testGetSize();
	this->testGetColor();
	this->testGetPrice();
	this->testGetQuantity();
	this->testGetPhotographLink();
	this->testSetPrice();
	this->testSetQuantity();
	this->testEqualityOperator();
	this->testInequalityOperator();
	this->testAssignmentOperator();
	this->testInsertionOperator();
	this->testExtractionOperator();
}


void TrenchCoatTests::testCopyConstructor(){
	TrenchCoat c1{"xl", "blue", 159, 12, "www.mycoat.com"};
	TrenchCoat c2{c1};
	assert(c2.getSize() == "xl");
	assert(c2.getColor() == "blue");
	assert(c2.getPrice() == 159);
	assert(c2.getQuantity() == 12);
	assert(c2.getPhotographLink() == "www.mycoat.com");
}


void TrenchCoatTests::testGetSize(){
	TrenchCoat c1{"xl", "blue", 159, 12, "www.mycoat.com"};
	assert(c1.getSize() == "xl");
	assert(c1.getSize() != "xxl");
}


void TrenchCoatTests::testGetColor(){
	TrenchCoat c1{"xl", "blue", 159, 12, "www.mycoat.com"};
	assert(c1.getColor() == "blue");
	assert(c1.getColor() != "red");
}


void TrenchCoatTests::testGetPrice(){
	TrenchCoat c1{"xl", "blue", 159, 12, "www.mycoat.com"};
	assert(c1.getPrice() == 159);
	assert(c1.getPrice() != 158);
}


void TrenchCoatTests::testGetQuantity(){
	TrenchCoat c1{"xl", "blue", 159, 12, "www.mycoat.com"};
	assert(c1.getQuantity() == 12);
	assert(c1.getQuantity() != 11);
}


void TrenchCoatTests::testGetPhotographLink(){
	TrenchCoat c1{"xl", "blue", 159, 12, "www.mycoat.com"};
	assert(c1.getPhotographLink() == "www.mycoat.com");
	assert(c1.getPhotographLink() != "www.mycot.com");
}


void TrenchCoatTests::testSetPrice(){
	TrenchCoat c1{"xl", "blue", 159, 12, "www.mycoat.com"};
	assert(c1.getPrice() == 159);
	c1.setPrice(160);
	assert(c1.getPrice() == 160);
}


void TrenchCoatTests::testSetQuantity(){
	TrenchCoat c1{"xl", "blue", 159, 12, "www.mycoat.com"};
	assert(c1.getQuantity() == 12);
	c1.setQuantity(13);
	assert(c1.getQuantity() == 13);
}


void TrenchCoatTests::testEqualityOperator(){
	TrenchCoat c1{"xl", "blue", 159, 12, "www.mycoat.com"};
	TrenchCoat c2{"xl", "blue", 159, 12, "www.mycoat.com"};
	assert(c1 == c2);
	TrenchCoat c3{"xxl", "blue", 159, 12, "www.mycoat.com"};
	assert((c1 == c3) == false);
}


void TrenchCoatTests::testInequalityOperator(){
	TrenchCoat c1{"xl", "blue", 159, 12, "www.mycoat.com"};
	TrenchCoat c3{"xxl", "blue", 159, 12, "www.mycoat.com"};
	assert(c1 != c3);
	TrenchCoat c2{"xl", "blue", 159, 12, "www.mycoat.com"};
	assert((c1 != c2) == false);
}


void TrenchCoatTests::testAssignmentOperator(){
	TrenchCoat c1{"xl", "blue", 159, 12, "www.mycoat.com"};
	TrenchCoat c3{"xl", "red", 159, 12, "www.mycoat.com"};
	assert(c1.getColor() == "blue");
	assert(c1 != c3);
	c1 = c3;
	assert(c1.getColor() == "red");
	assert(c1 == c3);
	c1 = c1;
	assert(c1.getColor() == "red");
	assert(c1 == c3);
}


void TrenchCoatTests::testInsertionOperator(){
	std::ostringstream os{""};
	TrenchCoat c1{"xl", "blue", 159, 12, "www.mycoat.com"};
	os << c1;
	assert(os.str() == "xl|blue|159|12|www.mycoat.com");
}


void TrenchCoatTests::testExtractionOperator(){
	std::istringstream is{"xl   |   blue   |159   |12   |www.mycoat.com    "};
	TrenchCoat c1;
	TrenchCoat c2{"xl", "blue", 159, 12, "www.mycoat.com"};
	is >> c1;
	assert(c1 == c2);

	//not enough tokens
	is.clear();
	is.str("xl | blue | 159 | 12 |\n");
	try{
		is >> c1;
		assert(false);
	}
	catch (TrenchCoatException& e){
		assert(true);
		assert(strstr(e.what(), "Not enough fields, 5 fields are requiered!") != 0);
	}

	//failed price conversion, field not an number
	is.clear();
	is.str("xl | blue | something other than price | 12 | www.mycoat.com");
	try{
		is >> c1;
		assert(false);
	}
	catch (TrenchCoatException& e){
		assert(true);
		assert(strstr(e.what(), "Illegal conversion! The price must be an int number!") != 0);
	}

	//failed price conversion, field out of range
	is.clear();
	is.str("xl | blue | 1000000000000000000000000000000000000 | 12 | www.mycoat.com");
	try{
		is >> c1;
		assert(false);
	}
	catch (TrenchCoatException& e){
		assert(true);
		assert(strstr(e.what(), "Value of price out of the data type range!") != 0);
	}

	//failed quantity conversion, field not an number
	is.clear();
	is.str("xl | blue | 10 | something other than quantity | www.mycoat.com");
	try{
		is >> c1;
		assert(false);
	}
	catch (TrenchCoatException& e){
		assert(true);
		assert(strstr(e.what(), "Illegal conversion! The quantity must be an int number!") != 0);
	}

	//failed quantity conversion, field out of range
	is.clear();
	is.str("xl | blue | 10 | 1000000000000000000000000000000000000 | www.mycoat.com");
	try{
		is >> c1;
		assert(false);
	}
	catch (TrenchCoatException& e){
		assert(true);
		assert(strstr(e.what(), "Value of quantity out of the data type range!") != 0);
	}

	//validation errors
	//errors for size, color, price, quantity, photographLink
	is.clear();
	is.str("xxl | | -1 | -1 | ");
	try{
		is >> c1;
		assert(false);
	}
	catch (TrenchCoatException& e){
		assert(true);
		assert(strstr(e.what(), "Invalid size! The size must be s, m, l, or xl.\nInvalid color!\nInvalid price! The price must be a positive number.\nInvalid quantity! The quantity must be a positive integer.\nInvalid photograph link\n"));
	}
}



void RepositoryTests::runTests(){
	this->testLoadFromFileConstructor();
	this->testCopyConstructor();
	this->testAdd();
	this->testRemove();
	this->testUpdate();
}


void RepositoryTests::testLoadFromFileConstructor(){
	try{
		std::string filename = "testLoadFromFileConstructor.txt";
		std::fstream file{filename, std::ios::out | std::ios::trunc};
		TrenchCoat tc1{"s", "red", 99, 10, "https://www.example.com/tc1.jpg"};
		TrenchCoat tc2{"m", "green", 129, 15, "https://www.example.com/tc2.jpg"};
		TrenchCoat tc3{"l", "blue", 149, 20, "https://www.example.com/tc3.jpg"};
		file << tc1 << "\n" << tc2 << "\n" << tc3;
		file.close();
		Repository repo(filename);
		assert(true);
		assert(repo.get().getSize() == 3);
		assert(repo.get()[0] == tc1);
		assert(repo.get()[1] == tc2);
		assert(repo.get()[2] == tc3);
	}
	catch (RepositoryException& e){
		assert(false);
	}

	try{
		Repository repo("somethingOutrageous.txt");
		assert(false);
	}
	catch (RepositoryException& e){
		assert(strstr(e.what(), "File could not be opened!") != 0);
	}

	try{
		std::string filename = "testLoadFromFileConstructor.txt";
		std::fstream file{filename, std::ios::out | std::ios::trunc};
		file << "token1|token2|\ntoken1|token2|10|30|something";
		Repository repo(filename);
		assert(false);
	}
	catch (RepositoryException& e){
		assert(strstr(e.what(), "Couldn't load from file ") != 0);
	}
}


void RepositoryTests::testCopyConstructor(){
	Repository repo1;
	TrenchCoat tc1{"xl", "blue", 100, 10, "www.mylink.com"};
	repo1.add(tc1);
	assert(repo1.get().getSize() == 1);
	
	Repository repo2{repo1};
	assert(repo2.get().getSize() == 1);
	assert(repo2.get()[0] == repo1.get()[0]);
}


void RepositoryTests::testAdd(){
	Repository repo;
	TrenchCoat tc1{"xl", "blue", 100, 10, "www.mylink.com"};
	repo.add(tc1);
	assert(repo.get()[0] == tc1);
	repo.add(tc1);
	
	assert(repo.get().getSize() == 1);

	assert(repo.get()[0].getQuantity() == 20);
}


void RepositoryTests::testRemove(){
	Repository repo;
	TrenchCoat tc1{"xl", "blue", 100, 10, "www.mylink.com"};
	repo.add(tc1);
	TrenchCoat tc2{"l", "blue", 100, 10, "www.mylink.com"};
	try{
		repo.remove(tc2, 10);
		assert(false);
	}
	catch (RepositoryException& e){
		assert(true);
		assert(strstr(e.what(), "The TrenchCoat to be deleted doesn't exists!"));
	}
	repo.remove(tc1, 9);
	assert(repo.get().getSize() == 1);
	assert(repo.get()[0].getQuantity() == 1);
	repo.remove(tc1, 10);
	assert(repo.get().getSize() == 0);


}


void RepositoryTests::testUpdate(){
	Repository repo;
	TrenchCoat tc1{"xl", "blue", 100, 10, "www.mylink.com"};
	repo.add(tc1);
	TrenchCoat tc2{"l", "blue", 100, 10, "www.mylink.com"};
	try{
		repo.update(tc2, 101, 10);
		assert(false);
	}
	catch (RepositoryException& e){
		assert(true);
		assert(strstr(e.what(), "The TrenchCoat to be updated doesn't exists!") != 0);
	}

	repo.update(tc1, 101, 10);
	assert(repo.get()[0].getPrice() != 100);
	assert(repo.get()[0].getPrice() == 101);
}


void BasketTests::runTests(){
	this->testAdd();
	this->testGet();
	this->testTotal();
}


void BasketTests::testAdd(){
	Basket b;
	TrenchCoat tc1{"xl", "blue", 100, 10, "www.mylink.com"};
	b.add(tc1);
	assert(b.get()[0].getQuantity() == 1);
	b.add(tc1);
	assert(b.get()[0].getQuantity() == 2);

}

void BasketTests::testGet(){
}

void BasketTests::testTotal(){
}

void ControllerAdministratorTests::runTests(){
	this->testAdd();
	this->testRemove();
	this->testUpdate();
}


void ControllerAdministratorTests::testAdd(){
	Repository repo;
	ControllerAdministrator c{repo};
	TrenchCoat tc1{"xl", "blue", 100, 10, "www.mylink.com"};
	c.add(tc1);
	assert(c.get()[0] == tc1);
	assert(repo.get()[0] == tc1);
	c.add(tc1);

	assert(c.get().getSize() == 1);
	assert(repo.get().getSize() == 1);

	assert(c.get()[0].getQuantity() == 20);
	assert(repo.get()[0].getQuantity() == 20);
}


void ControllerAdministratorTests::testRemove(){
	Repository repo;
	ControllerAdministrator c{repo};
	TrenchCoat tc1{"xl", "blue", 100, 10, "www.mylink.com"};
	c.add(tc1);
	TrenchCoat tc2{"l", "blue", 100, 10, "www.mylink.com"};
	try{
		c.remove(tc2, 10);
		assert(false);
	}
	catch (RepositoryException& e){
		assert(true);
		assert(strstr(e.what(), "The TrenchCoat to be deleted doesn't exists!"));
	}
	c.remove(tc1, 9);
	assert(c.get().getSize() == 1);
	assert(repo.get().getSize() == 1);
	assert(c.get()[0].getQuantity() == 1);
	assert(repo.get()[0].getQuantity() == 1);
	c.remove(tc1, 10);
	assert(c.get().getSize() == 0);
	assert(repo.get().getSize() == 0);
}


void ControllerAdministratorTests::testUpdate(){
	Repository repo;
	ControllerAdministrator c{repo};
	TrenchCoat tc1{"xl", "blue", 100, 10, "www.mylink.com"};
	repo.add(tc1);
	TrenchCoat tc2{"l", "blue", 100, 10, "www.mylink.com"};
	try{
		c.update(tc2, 101, 10);
		assert(false);
	}
	catch (RepositoryException& e){
		assert(true);
		assert(strstr(e.what(), "The TrenchCoat to be updated doesn't exists!") != 0);
	}

	c.update(tc1, 101, 10);
	assert(c.get()[0].getPrice() != 100);
	assert(c.get()[0].getPrice() == 101);
	assert(repo.get()[0].getPrice() != 100);
	assert(repo.get()[0].getPrice() == 101);
}


void ControllerUserTests::runTests(){
	this->testAddToBasket();
	this->testGetRepo();
	this->testGetBasket();
	this->testGetBasketTotal();
}


void ControllerUserTests::testAddToBasket(){
	Repository repo;
	Basket basket;
	ControllerUser cu{repo, basket};
	TrenchCoat tc1{"xl", "red", 1000, 10, "www.photo1.com"};
	TrenchCoat tc2{"l", "red", 1000, 10, "www.photo2.com"};
	repo.add(tc1);
	repo.add(tc2);
	assert(cu.getRepo("").getSize() == 2);
	cu.addToBasket(tc1);
	cu.addToBasket(tc1);
	assert(cu.getBasket().getSize() == 1);
	assert(cu.getBasket()[0].getQuantity() == 2);
	assert(basket.get().getSize() == 1);
	cu.addToBasket(tc2);
	assert(cu.getBasket().getSize() == 2);
}

void ControllerUserTests::testGetRepo(){
	Repository repo;
	Basket basket;
	ControllerUser cu{repo, basket};
	TrenchCoat tc1{"xl", "red", 1000, 10, "www.photo1.com"};
	TrenchCoat tc2{"l", "red", 1000, 10, "www.photo2.com"};
	repo.add(tc1);
	repo.add(tc2);
	assert(cu.getRepo("").getSize() == 2);
	assert(cu.getRepo("l").getSize() == 1);
}

void ControllerUserTests::testGetBasket(){
	Repository repo;
	Basket basket;
	ControllerUser cu{repo, basket};
	TrenchCoat tc1{"xl", "red", 1000, 10, "www.photo1.com"};
	TrenchCoat tc2{"l", "red", 1000, 10, "www.photo2.com"};
	repo.add(tc1);
	repo.add(tc2);
	cu.addToBasket(tc1);
	cu.addToBasket(tc1);
	assert(cu.getBasket().getSize() == 1);
}

void ControllerUserTests::testGetBasketTotal(){
	Repository repo;
	Basket basket;
	ControllerUser cu{repo, basket};
	TrenchCoat tc1{"xl", "red", 1000, 10, "www.photo1.com"};
	TrenchCoat tc2{"l", "red", 1000, 10, "www.photo2.com"};
	repo.add(tc1);
	repo.add(tc2);
	cu.addToBasket(tc1);
	cu.addToBasket(tc1);

	assert(cu.getBasket().getSize() == 1);
	
	cu.addToBasket(tc2);
	
	assert(cu.getBasketTotal() == 3000);

}


