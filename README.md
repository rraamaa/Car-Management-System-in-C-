Car Management System in C++
This repository contains a C++ application for managing car records. It is a simple console-based system that allows users to add, delete, update, and view car information, including functionalities for sorting and filtering based on various attributes. The program leverages basic file handling to store data persistently.

Features:
1. Add Car Records: Input details like ID, make, model, year, color, engine capacity, and price to create a new record.
2. Delete Car Records: Remove car records by ID.
3. Update Car Records: Modify existing records by ID.
4. View All Car Records: Display all stored records in a tabular format.
5. Filter by Price: View cars with prices below a specified value.
6. Filter by Make: Display cars matching a specific make.
7. Sort by Price: View all cars sorted in ascending order of price.
8. Sort by Year: Display cars sorted by manufacturing year.
9. Save Records: Persist all changes to a text file for future access.
10. Load Existing Records: Automatically load car data from the file at the start of the program.

Technical Details:
1. Programming Language: C++
2. File Handling: Used for persistent storage of car records in Cars.txt.
3. Sorting: Utilizes C++ STL for efficient sorting operations.
4. Custom Struct: Defines a Car struct for structured data management.
5. Menu-Driven Interface: Easy-to-use menu for navigation.
