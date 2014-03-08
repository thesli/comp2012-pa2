/*
 * main.cpp
 *
 *      Author: Peter (cspeter@cse.ust.hk)
 *
 *      The sample test case of the StringSet class
 *
 */

#include "stringset.h"
#include <iostream>
#include <fstream>
using namespace std;

void printSetContent(const StringSet& s ) {
	cout << "Content = " << s << endl ;
}
void printSetSizeAndCapacity(const StringSet& s ) {

	cout << "Size = " << s.getSize() << " ; " << " Capacity = " << s.getCapacity() << endl ;

}
string boolToStr(bool b) {
	return b ? "Yes" : "No";
}
void arrayToStringSet(const string arr[], int n, StringSet& s) {
	for (int i=0; i<n; i++) {
		s.insert( arr[i] ) ;
	}
}


int main() {

	const string strPeter = "Peter";
	const string strJohn = "John";
	const string strAnn = "Ann";
	const string strMary = "Mary";
	const string strGary = "Gary";
	const string strCandy = "Candy";


	cout << "=== Case 1: Empty Set ===" << endl ;
	StringSet set1;
	set1.sort();
	if (set1.isEmpty() ) {
		printSetContent(set1);
		printSetSizeAndCapacity(set1);
	}
	cout << "=== Case 2: A set with a single item ===" << endl ;
	StringSet set2(strPeter);
	printSetContent(set2);
	printSetSizeAndCapacity(set2);

	cout << "=== Case 3: Copy constructor, insert and sort operations ===" << endl ;
	StringSet set3(set2);
	printSetContent(set3);



	cout << "Insert " << strPeter << " ? " << boolToStr( set3.insert(strPeter) ) << endl;
	cout << "Insert " << strJohn << " ? " << boolToStr( set3.insert(strJohn) ) << endl ;
	cout << "Insert " << strAnn << " ? " << boolToStr( set3.insert(strAnn) ) << endl ;
	cout << "Insert " << strMary << " ? " << boolToStr( set3.insert(strMary) ) << endl ;
	cout << "Insert " << strJohn << " ? " << boolToStr( set3.insert(strJohn) ) << endl ;

	cout << "Before sorting: " ;
	printSetContent(set3);
	set3.sort();
	cout << "After sorting : " ;
	printSetContent(set3);

	cout << "=== Case 4: Assignment operator (=) and remove operations ===" << endl ;

	StringSet set4; // empty set
	set4 = set3; // assignment operator (=)
	printSetContent(set4);
	cout << "Remove " << strPeter << " ? " << boolToStr( set4.remove(strPeter) ) << endl;
	cout << "Remove " << strPeter << " ? " << boolToStr( set4.remove(strPeter) ) << endl;
	cout << "Remove " << strAnn << " ? " << boolToStr( set4.remove(strAnn) ) << endl;
	set4.sort();
	printSetContent(set4);
	cout << "Remove " << strJohn << " ? " << boolToStr( set4.remove(strJohn) ) << endl;
	cout << "Remove " << strMary << " ? " << boolToStr( set4.remove(strMary) ) << endl;
	set4.sort();
	printSetContent(set4);

	cout << "=== Case 5: Set comparision (e.g. ==, !=) ===" << endl ;

	StringSet set5_empty1 ; // empty set 1
	StringSet set5_empty2 ; // empty set 2
	cout << "Two empty sets are equal? " << boolToStr(set5_empty1==set5_empty2) << endl ;
	cout << "Two empty sets are different? " << boolToStr(set5_empty1!=set5_empty2) << endl ;
	StringSet set5_order1; // set1 = {Peter,Ann}
	set5_order1.insert(strPeter);
	set5_order1.insert(strAnn);
	StringSet set5_order2; // set2 = {Ann,Peter}
	set5_order2.insert(strAnn);
	set5_order2.insert(strPeter);
	cout << "Order 1 ";
	printSetContent(set5_order1);
	cout << "Order 2 ";
	printSetContent(set5_order2);
	cout << "Two sets are equal? " << boolToStr(set5_order1==set5_order2) << endl ;
	cout << "Two sets are different? " << boolToStr(set5_order2!=set5_order1) << endl ;
	cout << "Insert " << strJohn << " ? " << boolToStr( set5_order1.insert(strJohn) ) << endl ;
	cout << "Two sets are equal? " << boolToStr(set5_order1==set5_order2) << endl ;
	cout << "Two sets are different? " << boolToStr(set5_order2!=set5_order1) << endl ;

	cout << "=== Case 6: Set union, intersect and difference ===" << endl ;

	string arrayA[3] = {strPeter, strAnn, strMary};
	string arrayB[4] = {strAnn, strJohn, strGary, strCandy};

	StringSet set6a, set6b;
	arrayToStringSet(arrayA, 3, set6a);
	arrayToStringSet(arrayB, 4, set6b);

	set6a.sort();
	set6b.sort();

	cout << "Set A ";
	printSetContent(set6a);
	cout << "Set B ";
	printSetContent(set6b);

	StringSet setUnion, setInter, setDiff;

	setUnion = set6a;
	setUnion += set6b;

	setInter = set6a;
	setInter ^= set6b;

	setDiff = set6a;
	setDiff -= set6b ;

	setUnion.sort();
	setInter.sort();
	setDiff.sort();

	cout << "A += B ";
	printSetContent(setUnion);
	cout << "A ^= B ";
	printSetContent(setInter);
	cout << "A -= B ";
	printSetContent(setDiff);

	cout << "=== Case 7: Binary operators for union, intersect and difference ===" << endl ;

	StringSet set7a = set6a;
	StringSet set7b = set6b;
	cout << "Set A ";
	printSetContent(set7a);
	cout << "Set B ";
	printSetContent(set7b);

	setUnion = set7b + set7a ;
	setInter = set7b ^ set7a ;
	setDiff = set7b - set7a ;

	setUnion.sort();
	setInter.sort();
	setDiff.sort();

	cout << "B + A ";
	printSetContent(setUnion);
	cout << "B ^ A ";
	printSetContent(setInter);
	cout << "B - A ";
	printSetContent(setDiff);

	cout << "=== Case 8: Size and capacity ===" << endl ;
	StringSet set8;
	printSetSizeAndCapacity(set8);
	cout << "Insert " << strPeter << " ? " << boolToStr( set8.insert(strPeter) ) << endl;
	printSetSizeAndCapacity(set8);
	cout << "Insert " << strJohn << " ? " << boolToStr( set8.insert(strJohn) ) << endl;
	printSetSizeAndCapacity(set8);
	cout << "Insert " << strJohn << " ? " << boolToStr( set8.insert(strJohn) ) << endl;
	printSetSizeAndCapacity(set8);
	cout << "Insert " << strAnn << " ? " << boolToStr( set8.insert(strAnn) ) << endl;
	printSetSizeAndCapacity(set8);

	cout << "Remove " << strGary << " ? " << boolToStr( set8.remove(strGary) ) << endl;
	printSetSizeAndCapacity(set8);
	cout << "Remove " << strPeter << " ? " << boolToStr( set8.remove(strPeter) ) << endl;
	printSetSizeAndCapacity(set8);
	printSetContent(set8);
	cout << "Remove " << strJohn << " ? " << boolToStr( set8.remove(strJohn) ) << endl;
	printSetSizeAndCapacity(set8);
	printSetContent(set8);

	cout << "Remove " << strAnn << " ? " << boolToStr( set8.remove(strAnn) ) << endl;
	printSetSizeAndCapacity(set8);
	printSetContent(set8);
	cout << "Insert " << strPeter << " ? " << boolToStr( set8.insert(strPeter) ) << endl;
	printSetSizeAndCapacity(set8);
	printSetContent(set8);

	cout << "=== Case 9: File input ===" << endl ;

	cout << "From sample.txt (2 duplicated items): " << endl;
	StringSet set9FromSample = readSetFromFile("sample.txt");
	set9FromSample.sort();
	printSetSizeAndCapacity(set9FromSample);
	printSetContent(set9FromSample);
	writeSetToFile("output_sample.txt", set9FromSample);

	/*

	// For advanced data sets:

	cout << "From coutries.txt: " << endl;
	StringSet set9FromCountries = readSetFromFile("countries.txt");
	set9FromCountries.sort();
	writeSetToFile("output_countries.txt", set9FromCountries);


	cout << "=== Case 10: Large Data set ===" << endl ;
	cout << "From cities.txt: " << endl ;
	StringSet set10 = readSetFromFile("cities.txt");
	set10.sort();
	writeSetToFile("output_cities.txt", set10);

	 */

	return 0;
}

