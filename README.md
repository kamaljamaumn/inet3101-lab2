INET 3101 Lab 2: Memory and Structures

Overview

This project is an implementation of an in-memory database using C structures and dynamic memory allocation. The program allows users to store, manage, and delete records dynamically without using arrays or file I/O. The objective of the assignment is to understand and practice manual memory management using malloc(), free(), and avoiding realloc() by manually handling memory reallocation.

Features

Dynamic Memory Management: Uses malloc() for memory allocation and manually reallocates memory instead of using realloc().

CRUD Operations:

Add new records dynamically

Delete the last added record and release memory

Display all records

Show database size

Menu-Driven Interface: Provides a user-friendly command-line interface to interact with the database.

Program Functionality

1. Print All Records

This function iterates through the dynamically allocated memory and prints all stored records, including part number, part name, size, metric, and cost.

2. Print Number of Records

Displays the total number of records currently stored in memory.

3. Print Size of Database

Calculates and prints the total memory size occupied by the records.

4. Add Record

Prompts the user for input and dynamically allocates new memory for an additional record. The data entered is stored in the structure and appended to the database.

5. Delete Record

Removes the last stored record by allocating new memory (with malloc()), copying over the remaining records, and freeing the old memory.

6. Exit

Frees all allocated memory and terminates the program safely.

Memory Management Approach

This program uses manual memory management instead of realloc(). The approach follows these steps:

Allocate Memory with malloc(): When a new record is added, a new memory block is created with sufficient space.

Manually Resize Memory: Instead of using realloc(), a new block of memory is allocated when expanding or shrinking the database. Data is copied manually using a loop.

Free Unused Memory with free(): Ensures no memory leaks by releasing unused memory when records are deleted or the program exits.

How to Compile and Run

gcc lab2.c -o lab2
./lab2

Example Usage

MENU
=======
1. Print all records
2. Print number of records
3. Print size of database
4. Add record
5. Delete record
6. Exit

Enter your choice: 4
Enter part number: 394892948
Enter part name: Poly pipe
Enter part size: 23.75
Enter part size metric: mm
Enter part cost: 8.83
Record added successfully!

Code Organization

lab2.c: Contains the main program logic, including memory allocation, menu handling, and record management functions.

Notes

The program avoids arrays and linked lists as per the assignment requirements.

Ensures proper memory deallocation to prevent memory leaks.

Uses pointers effectively to manage records in memory.

Author

Kamal Jama
