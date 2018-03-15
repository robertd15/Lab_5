//Robert Dyer
//Manish Goel , CIS 22C Winter 18
//Lab 5
//Partners: John Le and Stephen Lee
//

//Lab 5 Pseudocode

//1. Start program

//2. Declare variables for file input and output streams to read input from file

//3. Read input from source file and use it to populate the tree

//4.

#include <iostream>
#include <string>
#include <fstream>

#include "Person.h"
#include "BST.h"

using namespace std;

int main()
{
	//Name tree object
	BST<Person> nameSearchTree(false);

	//Birthday tree object
	BST<Person> bdaySearchTree(true);

	//Variables for file streams
	ifstream infile;
	ofstream outfile;

	//Variables to hold Person attributes
	string fnameholder;
	string lnameholder;
	string birthdayholder;

	bool isBirthday;

	//Open the input file for reading
	infile.open("PersonDatabase.txt");

	//Populate people nodes into name tree
	while (infile)
	{
		infile >> fnameholder;
		infile >> lnameholder;
		infile >> birthdayholder;

		Person tempPerson(fnameholder, lnameholder, birthdayholder);
		nameSearchTree.insert(tempPerson);
		bdaySearchTree.insert(tempPerson);
	}

	//Write out data to file
	outfile.open("BSTNameOutput.txt");

	nameSearchTree.display(outfile);


}


//#include <iostream>
//
//#include "BST.h"
//#include "Person.h"
//
//using namespace std;
//
//int main() {
//
//    Person *mark = new Person("Mark", "Zuckerberg", "19840514");
//    Person *bill = new Person("Bill", "Gates", "19551028");
//    Person *steve = new Person("Steve", "Jobs", "19550224");


/*
BST<Person> *root = new BST<Person>();
root->add(*mark);
root->add(*bill);
root->add(*steve);
*/
//cout << *mark;

//root->print();

//    BST<int> t;
//    t.insert(20);
//    t.insert(25);
//    t.insert(15);
//    t.insert(10);
//    t.insert(30);
//    t.display();
//    t.remove(20);
//    t.display();
//    t.remove(25);
//    t.display();
//    t.remove(30);
//    t.display();
//
//    system("pause");
//    return 0;
//}
