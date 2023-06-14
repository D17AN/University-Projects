#include "ExtendedTest.h"
#include "ShortTest.h"

#include "FixedCapBiMap.h"


#include <iostream>
using namespace std;


int main() {
	testAll();
	testAllExtended();

//    FixedCapBiMap m(10);
//
//    cout << "Add (1, 2)" << m.add(1, 2) << endl;
//    cout << "Add (1, 3)" << m.add(1, 3) << endl;
//    cout << "Add (1, 4)" << m.add(1, 4) << endl;
//    cout << "Add (2, 4)" << m.add(2, 4) << endl;
//    cout << "Add (2, 4)" << m.add(2, 4) << endl;
//
//    ValuePair res = m.search(1);
//    cout << "Search for values under 1: " << res.first << ", " << res.second << endl;
//
//    cout << "Remove (1, 3) " << m.remove(1, 3) << endl;
//    res = m.search(1);
//    cout << "Search for values under 1: " << res.first << ", " << res.second << endl;
//    cout << "Remove (3, 3) " << m.remove(3, 3) << endl;


	cout << "That's all!" << endl;
	system("pause");
	return 0;
}


