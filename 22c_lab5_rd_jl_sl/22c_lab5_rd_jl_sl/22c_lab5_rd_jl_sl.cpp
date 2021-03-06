//Robert Dyer
//Manish Goel , CIS 22C Winter 18
//Lab 5
//Partners: John Le and Stephen Lee
//

//Lab 5 Pseudocode

//1. Start program

//2. Declare variables for menu choices options as well as other miscellaneous variables

//3. Declare variables for tree objects of type person; one to search names and another to search birthdays

//4. Declare variables for file input and output streams to read input from file

//5. Declare holder variables for the first name, last name, and birthday of a Person that will be inserted into the tree

//6. Open the input file, then populate the nodes in the tree

//7. 

#include <iostream>
#include <string>
#include <fstream>

#include "Person.h"
#include "BST.h"

using namespace std;

int main()
{
	//looping or not
	bool inloop = true;

	//Name tree object
	BST<Person> nameSearchTree;

	//Birthday tree object
	BST<Person> bdaySearchTree;

	//Variables for file streams
	ifstream infile;
	ofstream outfile1, outfile2;

	//Variable for file path
	string path;

	//Variables to hold Person attributes
	string fnameholder;
	string lnameholder;
	string birthdayholder;

	//Opening the input File
	cout << "Please enter the path to your desired input file:" << endl << endl;
	cin >> path;
	cin.ignore();
	cout << endl << endl;
	infile.open(path);

	if (infile)
		cout << "File opened successfully" << endl << endl;

	while (!infile)
	{
		cout << "An incorrect path was entered please try again" << endl << endl;
		cin >> path;
		cin.ignore();
		cout << endl << endl;
		infile.open(path);
		if (infile)
			cout << "File opened successfully" << endl << endl;
	}

	//Opening the first output file
	cout << "Please enter the path to the desired name search output location:" << endl << endl;
	cin >> path;
	cin.ignore();
	cout << endl << endl;
	outfile1.open(path);
	if (outfile1)
		cout << "File created successfully" << endl << endl;

	while (!outfile1)
	{
		cout << "An incorrect path was entered please try again" << endl << endl;
		cin >> path;
		cin.ignore();
		cout << endl << endl;
		outfile1.open(path);
		if (outfile1)
			cout << "File created successfully" << endl << endl;
	}

	//Opening the second output file
	cout << "Please enter the path to the desired birthday search output location:" << endl << endl;
	cin >> path;
	cin.ignore();
	cout << endl << endl;
	outfile2.open(path);
	if (outfile2)
		cout << "File created successfully" << endl << endl;

	while (!outfile2)
	{
		cout << "An incorrect path was entered please try again" << endl << endl;
		cin >> path;
		cin.ignore();
		cout << endl << endl;
		outfile2.open(path);
		if (outfile2)
			cout << "File created successfully" << endl << endl;
	}

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

	while (inloop)
	{
		int choice = 0;
		int choice2 = 0;

		cout << "Please choose one of the following options" << endl << endl;
		cout << "1. Add" << endl << endl;
		cout << "2. Delete" << endl << endl;
		cout << "3. Modify" << endl << endl;
		cout << "4. Search" << endl << endl;
		cout << "5. Exit" << endl << endl;

		cin >> choice;
		cin.ignore();
		cout << endl << endl;

		if (choice < 1 || choice > 5)
		{
			cout << "One of the following options was not chosen" << endl << endl;
		}

		else
		{
			if (choice == 1)
			{
				cout << "Enter the first name" << endl << endl;
				cin >> fnameholder;
				cin.ignore();
				cout << endl << endl;

				cout << "Enter the last name" << endl << endl;
				cin >> lnameholder;
				cin.ignore();
				cout << endl << endl;

				cout << "Enter the birth date in the format yyyymmdd" << endl << endl;
				cin >> birthdayholder;
				cin.ignore();
				cout << endl << endl;

				Person temporary(fnameholder, lnameholder, birthdayholder);

				nameSearchTree.insert(temporary);
				bdaySearchTree.insert(temporary);

				cout << temporary << " was added to the search tree" << endl << endl;
			}

			if (choice == 2)
			{
				cout << "Enter the first name" << endl << endl;
				cin >> fnameholder;
				cin.ignore();
				cout << endl << endl;

				cout << "Enter the last name" << endl << endl;
				cin >> lnameholder;
				cin.ignore();
				cout << endl << endl;

				cout << "Enter the birth date in the format yyyymmdd" << endl << endl;
				cin >> birthdayholder;
				cin.ignore();
				cout << endl << endl;

				Person temporary(fnameholder, lnameholder, birthdayholder);

				bdaySearchTree.remove(temporary);
				nameSearchTree.remove(temporary);

				cout << temporary << " was removed from the tree" << endl << endl;
			}

			if (choice == 3)
			{
				cout << "Enter the first name" << endl << endl;
				cin >> fnameholder;
				cin.ignore();
				cout << endl << endl;

				cout << "Enter the last name" << endl << endl;
				cin >> lnameholder;
				cin.ignore();
				cout << endl << endl;

				cout << "Enter the birth date in the format yyyymmdd" << endl << endl;
				cin >> birthdayholder;
				cin.ignore();
				cout << endl << endl;

				Person temporary(fnameholder, lnameholder, birthdayholder);

				bdaySearchTree.search(temporary);
				nameSearchTree.search(temporary);
			}

			if (choice == 4)
			{
				cout << "Enter the first name" << endl << endl;
				cin >> fnameholder;
				cin.ignore();
				cout << endl << endl;

				cout << "Enter the last name" << endl << endl;
				cin >> lnameholder;
				cin.ignore();
				cout << endl << endl;

				cout << "Enter the birth date in the format yyyymmdd" << endl << endl;
				cin >> birthdayholder;
				cin.ignore();
				cout << endl << endl;

				Person temporary(fnameholder, lnameholder, birthdayholder);

				bdaySearchTree.search(temporary);
				nameSearchTree.search(temporary);
			}

			if (choice == 5)
			{
				inloop = false;
			}
		}
	}

	nameSearchTree.displayName(outfile1);
	cout << endl << endl;
	outfile1 << endl << endl;

	//This must be changed to breadth first traversal
	bdaySearchTree.displayName(outfile2);
	cout << endl << endl;
	outfile2 << endl << endl;

	infile.close();
	outfile1.close();
	outfile2.close();

	cin.get();
	return 0;
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

