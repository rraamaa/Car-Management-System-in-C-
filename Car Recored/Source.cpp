#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

const int max_size = 100; // Maximum number of car records


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




