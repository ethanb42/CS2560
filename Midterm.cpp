#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <exception>

class Human {
private:
	std::string name;
	int age;
	char sex;
	//default constructor
	Human();
protected:
	Human(std::string n, int a, char s) {
		name = n;
		age = a;
		sex = s;
	}

//	virtual ~Human() {}
public:

	

	void setName(std::string n) {
		name = n;
	}

	void setAge(int a) {
		age = a;
	}

	void setSex(char s) {
		sex = s;
	}

	std::string getName() {
		return name;
	}

	int getAge() {
		return age;
	}

	int getSex() {
		return sex;
	}
};

class Child : public Human {
private:
	std::string momName;
	std::string dadName;
	int allowance;
	Child();
	

public:
	Child(std::string name, int age, char sex, std::string mom, std::string dad):Human(name, age, sex) {
		allowance = 0;
		momName = mom;
		dadName = dad;
	}
	
	void setAllowance(int a) {
		allowance = a;
	}

	void printParrent() {
		std::cout << getName() << "'s Dad is: " << dadName << std::endl;
		std::cout << getName() << "'s Mom is: " << momName << std::endl;
	}
	void getAllowance() {
		std::cout << getName() << "'s allowance is " << allowance << std::endl;
	}


};

class Parent : public Human {
private:
	Parent();
	std::vector<std::string> children;
public:
	Parent(std::string n, int a, char s):Human(n, a, s) {

	}

	void printChild() {
		for (auto i = children.begin(); i != children.end(); ++i)
			std::cout << *i << ' ';
	}

	void setChild(Child &c) {
	 children.push_back(c.getName());
	}

	void setChildAllowance(int a, Child &c) {
		c.setAllowance(a);
	}


};

void printInfo(Human h) {
	std::cout << "Name: " << h.getName() << " Age: " << h.getAge() << " Sex: " << h.getSex() << "\n" << std::endl;
}

int main() {

	std::cout << "Running Midterm 2 Main\n\n" << std::endl;
	Parent Homer("Homer", 36, 'M');
	Parent March("March", 34, 'F');
	Child Lisa("Lisa", 12, 'F', "March", "Homer");
	Child  Bart("Bart", 10, 'M', "March", "Homer");
	Child Maggie("Maggie", 3, 'F', "March", "Homer");

	Bart.getAllowance();
	Homer.setChildAllowance(5, Bart);
	Bart.getAllowance();
	Bart.printParrent();

	March.setChild(Bart);
	March.setChild(Maggie);
	March.setChild(Lisa);

	Homer.setChild(Bart);
	Homer.setChild(Maggie);
	Homer.setChild(Lisa);
	
	printInfo(March);
	printInfo(Lisa);

	//used to keep console open
	getchar();
	return 0;
}

