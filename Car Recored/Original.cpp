#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

const int MAX_SIZE = 100; // Maximum number of car records
const string FILE_NAME = "Cars.txt";

ofstream out;
ifstream in;

struct Car {
    int id;
    string make;
    string model;
    int year;
    string color;
    int engine;
    int price;
};

void displayMenu() {
    cout << "1) Add a car record" << endl;
    cout << "2) Delete a car record" << endl;
    cout << "3) Update a car record" << endl;
    cout << "4) View all car records" << endl;
    cout << "5) View cars with price less than value" << endl;
    cout << "6) View cars by car make" << endl;
    cout << "7) View all cars sorted by price" << endl;
    cout << "8) View all cars sorted by year" << endl;
    cout << "9) Save" << endl;
    cout << "10) Quit" << endl;
}

void loadData(Car c[], int& size) {
    ifstream in("Cars.txt");
    if (!in) {
        cout << "No existing data file found." << endl;
        size = 0;
        return;
    }

    in >> size;
    for (int i = 0; i < size; ++i) {
        in >> c[i].id >> c[i].make >> c[i].model >> c[i].year
            >> c[i].color >> c[i].engine >> c[i].price;
    }
    in.close();
}

void saveData(const Car c[], int size) {
    ofstream out("Cars.txt");
    out << size << endl;
    for (int i = 0; i < size; ++i) {
        out << c[i].id << "\t" << c[i].make << "\t" << c[i].model << "\t" << c[i].year << "\t"
            << c[i].color << "\t" << c[i].engine << "\t" << c[i].price << endl;
    }
    out.close();
}

void addRecord(Car cars[], int& size) {
    if (size >= MAX_SIZE) {
        cout << "Cannot add more records. Maximum capacity reached." << endl;
        return;
    }

    Car newCar;
    cout << "Enter car details (id make model year color engine price): ";
    cin >> newCar.id >> newCar.make >> newCar.model >> newCar.year
        >> newCar.color >> newCar.engine >> newCar.price;

    // Open the file in append mode to add the new record
    ofstream out("Cars.txt", ios::app);
    if (!out) {
        cout << "Error opening file for writing." << endl;
        return;
    }

    // Write the new car details to the file
    out << newCar.id << " " << newCar.make << " " << newCar.model << " "
        << newCar.year << " " << newCar.color << " " << newCar.engine << " "
        << newCar.price << endl;

    // Add the new car to the array
    cars[size++] = newCar;
    cout << "Car record added successfully." << endl;
    out.close();
}


void deleteRecord(Car cars[], int& size) {
    int id;
    cout << "Enter car ID to delete: ";
    cin >> id;
    int index = -1;
    for (int i = 0; i < size; ++i) {
        if (cars[i].id == id) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        cars[index] = cars[--size]; // Replace with last element and reduce size
        cout << "Car record deleted successfully." << endl;
    }
    else {
        cout << "Car with ID " << id << " not found." << endl;
    }
}

void updateRecord(Car cars[], int size) {
    int id;
    cout << "Enter car ID to update: ";
    cin >> id;
    for (int i = 0; i < size; ++i) {
        if (cars[i].id == id) {
            cout << "Enter new details (make model year color engine price): ";
            cin >> cars[i].make >> cars[i].model >> cars[i].year >> cars[i].color >> cars[i].engine >> cars[i].price;
            cout << "Car record updated successfully." << endl;
            return;
        }
    }
    cout << "Car with ID " << id << " not found." << endl;
}

void displayRecords(const Car cars[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << cars[i].id << " " << cars[i].make << " " << cars[i].model << " " << cars[i].year << " "
            << cars[i].color << " " << cars[i].engine << " " << cars[i].price << endl;
    }
}

void displayByPrice(const Car cars[], int size) {
    int price;
    cout << "Enter price value: ";
    cin >> price;
    for (int i = 0; i < size; ++i) {
        if (cars[i].price < price) {
            cout << cars[i].id << " " << cars[i].make << " " << cars[i].model << " " << cars[i].year << " "
                << cars[i].color << " " << cars[i].engine << " " << cars[i].price << endl;
        }
    }
}

void displayByMake(const Car cars[], int size) {
    string make;
    cout << "Enter car make: ";
    cin >> make;
    for (int i = 0; i < size; ++i) {
        if (cars[i].make == make) {
            cout << cars[i].id << " " << cars[i].make << " " << cars[i].model << " " << cars[i].year << " "
                << cars[i].color << " " << cars[i].engine << " " << cars[i].price << endl;
        }
    }
}

void displaySortedByPrice(const Car cars[], int size) {
    // Create a temporary array to avoid modifying the original array
    Car sortedCars[MAX_SIZE];
    for (int i = 0; i < size; ++i) {
        sortedCars[i] = cars[i];
    }

    // Sort the temporary array by price
    sort(sortedCars, sortedCars + size, [](const Car& a, const Car& b) { return a.price < b.price; });

    // Open a file to write the sorted records
    ofstream outFile("Cars.txt");
    if (!outFile) {
        cout << "Error opening file for writing." << endl;
        return;
    }

    // Write the sorted records to the file
    for (int i = 0; i < size; ++i) {
        outFile << sortedCars[i].id << " " << sortedCars[i].make << " " << sortedCars[i].model << " " << sortedCars[i].year << " "
            << sortedCars[i].color << " " << sortedCars[i].engine << " " << sortedCars[i].price << endl;
    }

    outFile.close();
    cout << "Sorted car records have been written to file" << endl;
}


void displaySortedByYear(Car cars[], int size) {
    sort(cars, cars + size, [](const Car& a, const Car& b) { return a.year < b.year; });
    displayRecords(cars, size);
}

int main() {
    Car cars[MAX_SIZE];
    int size = 5;
    loadData(cars, size);

    int choice;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addRecord(cars, size);
            break;
        case 2:
            deleteRecord(cars, size);
            break;
        case 3:
            updateRecord(cars, size);
            break;
        case 4:
            displayRecords(cars, size);
            break;
        case 5:
            displayByPrice(cars, size);
            break;
        case 6:
            displayByMake(cars, size);
            break;
        case 7:
            displaySortedByPrice(cars, size);
            break;
        case 8:
            displaySortedByYear(cars, size);
            break;
        case 9:
            saveData(cars, size);
            break;
        case 10:
            cout << "Quitting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 10);

    return 0;

}
