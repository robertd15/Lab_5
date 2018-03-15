#pragma once

#include <iostream>
#include <string>

class Person {
private:
	std::string fname;    // First Name
	std::string lname;    // Last Name
	std::string birthday;        // Birthday

public:
	/*Default Constructor*/
	Person() :fname{ "" }, lname{ "" }, birthday{ -1 } {
		// Insert any extra default conditions here
	}

	/*Constructor 1*/
	Person(std::string fname, std::string lname)
		:fname{ fname }, lname{ lname }, birthday{ -1 }
	{
		// Insert any extra conditions here
	}

	/*Constructor 2*/
	Person(std::string fname, std::string lname, std::string birthday)
		:fname{ fname }, lname{ lname }, birthday{ birthday }
	{
		// Insert any extra conditions here
	}

	std::string getFName() {
		return fname;
	}

	void setFName(std::string fname) {
		this->fname = fname;
	}

	std::string getLName() {
		return lname;
	}

	void setLName(std::string lname) {
		this->lname = lname;
	}

	std::string getBirthday() {
		return birthday;
	}

	void setBirthday(std::string birthday) {
		this->birthday = birthday;
	}

	//    bool operator>(const Person& other) {
	//        if (this->fname >= other.fname)
	//            return true;
	//        return false;
	//    }

	friend std::ostream& operator<<(std::ostream& os, const Person& person) {
		os << person.fname << ' ' << person.lname << ',' << person.birthday;
		return os;
	}

	bool operator >(const Person &persComp)
	{
		bool greaterthan;

		if  (birthday > persComp.birthday || fname > persComp.fname)
			greaterthan = true;
		else if (fname == persComp.fname && lname > persComp.lname)
			greaterthan = true;
		else
			greaterthan = false;

		return greaterthan;
	}

	bool operator < (const Person &persComp)
	{
		bool lessthan;

		if (birthday < persComp.birthday || fname < persComp.fname)
			lessthan = true;
		else if (fname == persComp.fname && lname < persComp.lname)
			lessthan = true;
		else
			lessthan = false;

		return lessthan;
	}

	bool operator == (const Person &persComp)
	{
		bool equalto;

		if ((fname == persComp.fname && lname == persComp.lname) || birthday == persComp.birthday)
			equalto = true;
		else
			equalto = false;

		return equalto;
	}

	bool operator >= (const Person &persComp)
	{
		bool greaterthanequal;

		if (*this > persComp || *this == persComp)
			greaterthanequal = true;
		else
			greaterthanequal = false;

		return greaterthanequal;
	}

	bool operator <= (const Person &persComp)
	{
		bool lessthanequal;

		if (*this < persComp || *this == persComp)
			lessthanequal = true;
		else
			lessthanequal = false;

		return lessthanequal;
	}


};




//#pragma once
//
//#include <string>
//
//class Person {
//private:
//    std::string fname;    // First Name
//    std::string lname;    // Last Name
//    int birthday;        // Birthday
//
//public:
//    /*Default Constructor*/
//    Person():fname{ "" }, lname{ "" }, birthday{ -1 } {
//        // Insert any extra default conditions here
//    }
//
//    /*Constructor 1*/
//    Person(std::string fname, std::string lname)
//    :fname{fname}, lname{lname}, birthday{-1}
//    {
//        // Insert any extra conditions here
//    }
//
//    /*Constructor 2*/
//    Person(std::string fname, std::string lname, int birthday)
//    :fname{fname}, lname{lname}, birthday{birthday}
//    {
//        // Insert any extra conditions here
//    }
//
//    std::string getFName() {
//        return fname;
//    }
//
//    void setFName(std::string fname) {
//        this->fname = fname;
//    }
//
//    std::string getLName() {
//        return lname;
//    }
//
//    void setLName(std::string lname) {
//        this->lname = lname;
//    }
//
//    int getBirthday() {
//        return birthday;
//    }
//
//    void setBirthday(int birthday) {
//        this->birthday = birthday;
//    }
//};