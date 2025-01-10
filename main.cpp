#include <iostream>
#include <string>
#include "console.hpp"

int main() {
    const int MAX_STUDENTS = 1000;
    Student students[MAX_STUDENTS];
    int num_students = 0;
    int choice;
    bool valid_input;

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
        std::cout << " 7. Sort Students by GPA\n";
        std::cout << " 8. Sort Students by Year of Enrollment\n";
        std::cout << " 9. Exit\033[0m\n";
        std::cout << "\033[36m========================================\033[0m\n";
        std::cout << "\033[34mEnter your choice: \033[0m";

        // Check if the input is valid
        valid_input = false;
        while (!valid_input) {
            std::cin >> choice;

            if (std::cin.fail()) {
                std::cin.clear(); // clear the error flag
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
                std::cout << "\033[1;36m--- Sorting students by GPA ---\033[0m\n";
                sortStudentsByGPA(students, num_students);  // Sort students by GPA function
                break;
            case 8:
                std::cout << "\033[1;36m--- Sorting students by Year of Enrollment ---\033[0m\n";
                sortStudentsByYear(students, num_students);  // Sort students by year of enrollment function
                break;
            case 9:
                std::cout << "\033[1;32mExiting the program. Goodbye!\033[0m\n";
                break;
            default:
                std::cout << "\033[1;31mInvalid choice. Please try again.\033[0m\n";
        }

    } while (choice != 9);

    return 0;
}
