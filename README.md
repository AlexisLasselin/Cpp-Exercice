# C++ exercise - George's Class - January 2025

## Given the following rules

```text
Here follows a short description of our in-class exercise, to be reviewed on Monday 13/1:
Simple data handling (input, updating, retrieval and removal) using C++ Data Structures and Binary Search

For this exercise you will need to:
- Build a data type of your choice (class, struct), to represent one real-world set of entities (e.g. Students, Cars, Products, etc.). Think of appropriate attributes in each case (e.g. year of enrolment, name, etc.)
- Create instances/objects of your data type and store them in a Data Structure of your choice (e.g. list, vector, BST). Optimally, the data structure should follow your own implementation. Data can be randomly generated.
- Implement addition, retrieval, updating and removal functionalities, through a simple console menu.
- Implement a version of Merge Sort, to sort your data structure based on a "sortable" attribute (e.g. year of enrolment, name)
- Support any function that depends on search (retrieval, updating and removal), with your implementation of Binary Search (or, optionally, a suitable tree structure).
- Maintain a public remote repository on GitHub, with just the necessary documentation on how to build and run your code. Include a short description about what your project does and what limitations it may have (bugs, unfinished tasks, etc.).

You should submit your work by Sunday 12/1, 12:00 PM, as a link to your repository, by sending me a private message here, on Slack.
Good luck!
```

## Description

This project is a simple data handling exercise, using C++ Data Structures and Binary Search. The main goal is to implement a simple console menu that allows the user to add, retrieve, update and remove data from a data structure. The data structure used in this project is a Binary Search Tree (BST), which is implemented from scratch. The data type used to represent the entities is a `Student` class, which has the following attributes: `id`, `name`, `year`, `grade`.

The project also includes a simple implementation of Merge Sort, to sort the data structure based on the `id`, `year` or `grade` attributes. The project supports search functionalities, such as retrieval, updating and removal, using Binary Search.

## How to Build

To build the project, you can use any C++ compiler that supports C++11 standard. You can compile the project using the following command:

```bash
g++ main.cpp -o main

./main
```

## How to Use

Once you run the executable, you will see a simple console menu that allows you to interact with the data structure. You can choose to add a new student, retrieve a student by id, update a student by id, remove a student by id, display all students, sort students by id, year or grade, and exit the program.

The program will guide you through the process and provide feedback on the operations performed.

## Limitations

The project is a simple exercise and may have the following limitations:

- The BST implementation is basic and may not be optimized for all cases.
- The Merge Sort implementation is simple and may not be the most efficient for large datasets.
- The project does not include error handling for invalid inputs.
- The project does not include extensive testing for all functionalities.
- The project does not include a detailed performance analysis.
