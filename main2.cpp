#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Human {
private:
	char* name;
	int age;
public:
	Human() {
		name = { nullptr };
		age = 0;
	}
	Human(const char* n, int a) {
		name = new char[strlen(n) + 1];
		strcpy(name, n);
		age = a;
	}
	Human(Human& other) {
		name = new char[strlen(other.name) + 1];
		strcpy(name, other.name);
		age = other.age;
	}
	Human& operator=(Human& other) {
		if (this != &other) {
			delete[] name;
			name = new char[strlen(other.name) + 1];
			strcpy(name, other.name);
			age = other.age;
		}
		return *this;
	}
	~Human() {
		delete[] name;
		age = 0;
	}
	void print() {
		cout << "Name: " << name << " Age: " << age << endl;
	}
};

class Flat {
private:
	Human* residents;
	int numresidents;
public:
	Flat() {
		residents = { nullptr };
		numresidents = 0;
	}
	Flat(Human* r, int num) {
		numresidents = num;
		residents = new Human[numresidents];
		for (int i = 0; i < numresidents; ++i) {
			residents[i] = r[i];
		}
	}
	Flat(Flat& other) {
		numresidents = other.numresidents;
		residents = new Human[numresidents];
		for (int i = 0; i < numresidents; ++i) {
			residents[i] = other.residents[i];
		}
	}
	Flat& operator=(Flat& other) {
		if (this != &other) {
			delete[] residents;
			numresidents = other.numresidents;
			residents = new Human[numresidents];
			for (int i = 0; i < numresidents; ++i) {
				residents[i] = other.residents[i];
			}
		}
		return *this;
	}
	~Flat() {
		delete[] residents;
	}
	void print() {
		cout << "Flat with " << numresidents << " residents:" << endl;
		for (int i = 0; i < numresidents; ++i) {
			residents[i].print();
		}
	}
};

class House {
private:
	Flat* flats;
	int numflats;
public:
	House() {
		flats = { nullptr };
		numflats = 0;
	}
	House(Flat* f, int num) {
		numflats = num;
		flats = new Flat[numflats];
		for (int i = 0; i < numflats; ++i) {
			flats[i] = f[i];
		}
	}
	House(House& other) {
		numflats = other.numflats;
		flats = new Flat[numflats];
		for (int i = 0; i < numflats; ++i) {
			flats[i] = other.flats[i];
		}
	}
	House& operator=(House& other) {
		if (this != &other) {
			delete[] flats;
			numflats = other.numflats;
			flats = new Flat[numflats];
			for (int i = 0; i < numflats; ++i) {
				flats[i] = other.flats[i];
			}
		}
		return *this;
	}
	~House() {
		delete[] flats;
	}
	void print() {
		cout << "House with " << numflats << " flats:" << endl;
		for (int i = 0; i < numflats; ++i) {
			flats[i].print();
		}
	}
};

int main() {
	Human h1("Bob", 21);
	Human h2("Nika", 32);
	Human h3("Maksim", 18);

	Human group1[] = { h1, h2 };
	Flat f1(group1, 2);

	Human group2[] = { h3 };
	Flat f2(group2, 1);

	Flat flats[] = { f1,f2 };
	House house(flats, 2);

	house.print();
	return 0;
}