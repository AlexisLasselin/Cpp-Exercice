#include <iostream>
#include <string>
#include <fstream>
#include "console.hpp"

void saveStudentsToFile(Student students[], int num_students) {
    std::ofstream outFile("students_backup.txt");

    if (!outFile) {
        std::cerr << "Error opening file for saving!" << std::endl;
        return;
    }

    // Loop through students and write their data to the file
    for (int i = 0; i < num_students; ++i) {
        outFile << students[i].getID() << " "
                << students[i].getGrades() << " "
                << students[i].getYear() << " "
                << students[i].getName() << "\n";
    }

    outFile.close(); // Close the file
    std::cout << "\033[1;32mStudents have been successfully saved to the file!\033[0m\n";
}

void loadStudentsFromFile(Student students[], int &num_students) {
    std::ifstream inFile("students_backup.txt");

    if (!inFile) {
        std::cerr << "Error opening file for loading!" << std::endl;
        return;
    }

    num_students = 0;

    // Read students' data from the file and populate the array
    int id, year;
    float Grades;
    std::string name;

    while (inFile >> id >> Grades >> year) {
        std::getline(inFile, name); // Skip the newline character after Grades
        name = name.substr(1); // To remove any leading space after getline

        // Create a new Student object and store it in the array
        students[num_students++] = Student(name, id, year, Grades);
    }

    inFile.close(); // Close the file
    std::cout << "\033[1;32mStudents have been successfully loaded from the file!\033[0m\n";
}

int main() {
    const int MAX_STUDENTS = 1000;
    Student students[MAX_STUDENTS];
    int num_students = 0;
    int choice;
    bool valid_input;

    // Load students from file at the start of the program
    loadStudentsFromFile(students, num_students);

    do {
        std::cout << "\n\033[36m========================================\033[0m\n";
        std::cout << "\033[1;36m   STUDENT MANAGEMENT SYSTEM   \033[0m\n";
        std::cout << "\033[36m========================================\033[0m\n";
        std::cout << "\033[33m 1. Add Student\n";
        std::cout << " 2. Remove Student\n";
        std::cout << " 3. Update Student\n";
        std::cout << " 4. Display All Students\n";
        std::cout << " 5. Search Student by ID\n";
        std::cout << " 6. Sort Students by ID\n";
        std::cout << " 7. Sort Students by Grades\n";
        std::cout << " 8. Sort Students by Year of Enrollment\n";
        std::cout << " 9. Save Students to File\n";
        std::cout << " 10. Load Students from File\n";
        std::cout << " 11. Exit\033[0m\n";
        std::cout << "\033[36m========================================\033[0m\n";
        std::cout << "\033[34mEnter your choice: \033[0m";

        // Check if the input is valid
        valid_input = false;
        while (!valid_input) {
            std::cin >> choice;

            if (std::cin.fail()) {
                std::cin.clear(); // Clear the error flag
                std::cout << "\033[1;31mInvalid input. Please enter a valid number.\033[0m\n";
                std::cout << "\033[34mEnter your choice: \033[0m";
            } else {
                valid_input = true;
            }
        }

        std::cout << "\n";  // Add a blank line for better spacing

        switch (choice) {
            case 1:
                std::cout << "\033[1;32m--- Adding a new student ---\033[0m\n";
                addStudent(students, num_students);  // Add student function
                break;
            case 2:
                std::cout << "\033[1;31m--- Removing a student ---\033[0m\n";
                removeStudent(students, num_students);  // Remove student function
                break;
            case 3:
                std::cout << "\033[1;34m--- Updating a student ---\033[0m\n";
                updateStudent(students, num_students);  // Update student function
                break;
            case 4:
                std::cout << "\033[1;36m--- Displaying all students ---\033[0m\n";
                displayStudents(students, num_students);  // Display all students function
                break;
            case 5:
                std::cout << "\033[1;33m--- Searching for a student by ID ---\033[0m\n";
                searchStudentByID(students, num_students);  // Search student by ID function
                break;
            case 6:
                std::cout << "\033[1;36m--- Sorting students by ID ---\033[0m\n";
                sortStudentsByID(students, num_students);  // Sort students by ID function
                break;
            case 7:
                std::cout << "\033[1;36m--- Sorting students by Grades ---\033[0m\n";
                sortStudentsByGrades(students, num_students);  // Sort students by Grades function
                break;
            case 8:
                std::cout << "\033[1;36m--- Sorting students by Year of Enrollment ---\033[0m\n";
                sortStudentsByYear(students, num_students);  // Sort students by year of enrollment function
                break;
            case 9:
                std::cout << "\033[1;32m--- Saving students to file ---\033[0m\n";
                saveStudentsToFile(students, num_students);  // Save students to file function
                break;
            case 10:
                std::cout << "\033[1;32m--- Loading students from file ---\033[0m\n";
                loadStudentsFromFile(students, num_students);  // Load students from file function
                break;
            case 11:
                std::cout << "\033[1;32mExiting the program. Goodbye!\033[0m\n";
                break;
            default:
                std::cout << "\033[1;31mInvalid choice. Please try again.\033[0m\n";
        }

    } while (choice != 11);

    return 0;
}
