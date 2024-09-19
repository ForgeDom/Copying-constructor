#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Human {
private:
    char* name;
    int age;
public:
    Human() : name(nullptr), age(0) {}
    Human(const char* n, int a) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        age = a;
    }
    Human(const Human& other) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        age = other.age;
    }
    Human& operator=(const Human& other) {
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
    }
    void print() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
    void setName(const char* n) {
        delete[] name;
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }
    void setAge(int a) {
        age = a;
    }
};

class Flat {
private:
    Human* residents;
    int numresidents;
public:
    Flat() : residents(nullptr), numresidents(0) {}
    Flat(Human* r, int num) {
        numresidents = num;
        residents = new Human[numresidents];
        for (int i = 0; i < numresidents; ++i) {
            residents[i] = r[i];
        }
    }
    Flat(const Flat& other) {
        numresidents = other.numresidents;
        residents = new Human[numresidents];
        for (int i = 0; i < numresidents; ++i) {
            residents[i] = other.residents[i];
        }
    }
    Flat& operator=(const Flat& other) {
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

    void addResident(const Human& newResident) {
        Human* newResidents = new Human[numresidents + 1];
        for (int i = 0; i < numresidents; ++i) {
            newResidents[i] = residents[i];
        }
        newResidents[numresidents] = newResident;
        delete[] residents;
        residents = newResidents;
        numresidents++;
    }

    void removeResident(int index) {
        if (index < 0 || index >= numresidents) {
            cout << "Invalid index!" << endl;
            return;
        }
        Human* newResidents = new Human[numresidents - 1];
        for (int i = 0, j = 0; i < numresidents; ++i) {
            if (i != index) {
                newResidents[j++] = residents[i];
            }
        }
        delete[] residents;
        residents = newResidents;
        numresidents--;
    }

    void print() const {
        cout << "Flat with " << numresidents << " residents:" << endl;
        for (int i = 0; i < numresidents; ++i) {
            residents[i].print();
        }
    }

    int getNumResidents() const {
        return numresidents;
    }

    Human getResident(int index) const {
        if (index >= 0 && index < numresidents) {
            return residents[index];
        }
        return Human();
    }
};

class House {
private:
    Flat* flats;
    int numflats;
public:
    House() : flats(nullptr), numflats(0) {}
    House(Flat* f, int num) {
        numflats = num;
        flats = new Flat[numflats];
        for (int i = 0; i < numflats; ++i) {
            flats[i] = f[i];
        }
    }
    House(const House& other) {
        numflats = other.numflats;
        flats = new Flat[numflats];
        for (int i = 0; i < numflats; ++i) {
            flats[i] = other.flats[i];
        }
    }
    House& operator=(const House& other) {
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

    void addFlat(const Flat& newFlat) {
        Flat* newFlats = new Flat[numflats + 1];
        for (int i = 0; i < numflats; ++i) {
            newFlats[i] = flats[i];
        }
        newFlats[numflats] = newFlat;
        delete[] flats;
        flats = newFlats;
        numflats++;
    }

    void removeFlat(int index) {
        if (index < 0 || index >= numflats) {
            cout << "Invalid index!" << endl;
            return;
        }
        Flat* newFlats = new Flat[numflats - 1];
        for (int i = 0, j = 0; i < numflats; ++i) {
            if (i != index) {
                newFlats[j++] = flats[i];
            }
        }
        delete[] flats;
        flats = newFlats;
        numflats--;
    }

    void print() const {
        cout << "House with " << numflats << " flats:" << endl;
        for (int i = 0; i < numflats; ++i) {
            flats[i].print();
        }
    }

    int getNumFlats() const {
        return numflats;
    }

    Flat getFlat(int index) const {
        if (index >= 0 && index < numflats) {
            return flats[index];
        }
        return Flat();
    }
};

void displayMenu() {
    cout << "Menu:" << endl;
    cout << "1. Add a resident to a flat" << endl;
    cout << "2. Remove a resident from a flat" << endl;
    cout << "3. Add a flat to the house" << endl;
    cout << "4. Remove a flat from the house" << endl;
    cout << "5. Print house details" << endl;
    cout << "6. Exit" << endl;
}

int main() {
    House house;
    bool running = true;

    while (running) {
        displayMenu();
        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "Enter flat index: ";
            int flatIndex;
            cin >> flatIndex;

            if (flatIndex >= 0 && flatIndex < house.getNumFlats()) {
                cout << "Enter resident name: ";
                char name[20];
                cin >> name;
                cout << "Enter resident age: ";
                int age;
                cin >> age;

                Human newResident(name, age);
                house.getFlat(flatIndex).addResident(newResident);
            }
            else {
                cout << "Invalid flat index!" << endl;
            }
            break;
        }
        case 2: {
            cout << "Enter flat index: ";
            int flatIndex;
            cin >> flatIndex;

            if (flatIndex >= 0 && flatIndex < house.getNumFlats()) {
                cout << "Enter resident index: ";
                int residentIndex;
                cin >> residentIndex;

                house.getFlat(flatIndex).removeResident(residentIndex);
            }
            else {
                cout << "Invalid flat index!" << endl;
            }
            break;
        }
        case 3: {
            cout << "Enter number of residents in the new flat: ";
            int numResidents;
            cin >> numResidents;

            Human* residents = new Human[numResidents];
            for (int i = 0; i < numResidents; ++i) {
                cout << "Enter resident " << i + 1 << " name: ";
                char name[100];
                cin >> name;
                cout << "Enter resident " << i + 1 << " age: ";
                int age;
                cin >> age;

                residents[i] = Human(name, age);
            }

            Flat newFlat(residents, numResidents);
            delete[] residents;

            house.addFlat(newFlat);
            break;
        }
        case 4: {
            cout << "Enter flat index: ";
            int flatIndex;
            cin >> flatIndex;

            house.removeFlat(flatIndex);
            break;
        }
        case 5: {
            house.print();
            break;
        }
        case 6: {
            running = false;
            break;
        }
        default:
            cout << "Try again." << endl;
            break;
        }
    }

    return 0;
}
