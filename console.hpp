#include <iostream>
#include <string>
#include <vector>
#include "student.hpp"

// Function to merge two halves
void merge(std::vector<Student>& students, int left, int right, bool (*compare)(const Student&, const Student&)) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    merge(students, left, mid, compare);
    merge(students, mid + 1, right, compare);

    std::vector<Student> temp;
    int i = left, j = mid + 1;

    // Merge the two halves into temp
    while (i <= mid && j <= right) {
        if (compare(students[i], students[j])) {
            temp.push_back(students[i]);
            i++;
        } else {
            temp.push_back(students[j]);
            j++;
        }
    }

    // Copy remaining elements
    while (i <= mid) {
        temp.push_back(students[i]);
        i++;
    }
    while (j <= right) {
        temp.push_back(students[j]);
        j++;
    }

    // Copy the sorted elements back to the original array
    for (int k = left; k <= right; k++) {
        students[k] = temp[k - left];
    }
}

// Compare function for sorting by ID
bool compareByID(const Student& s1, const Student& s2) {
    return s1.getID() < s2.getID();  // Sorting by ID in ascending order
}

// Compare function for sorting by Grades (descending order)
bool compareByGrades(const Student& s1, const Student& s2) {
    return s1.getGrades() > s2.getGrades();  // Sorting by Grades in descending order
}

// Compare function for sorting by Year of Enrollment
bool compareByYear(const Student& s1, const Student& s2) {
    return s1.getYear() < s2.getYear();  // Sorting by Year in ascending order
}

void addStudent(Student students[], int& num_students) {
    std::string name;
    int ID;
    int year_of_enrollment;
    float Grades;
    std::string major;

    std::cout << "Enter student name: ";
    std::cin >> name;
    std::cout << "Enter student ID: ";
    std::cin >> ID;
    std::cout << "Enter student year of enrollment: ";
    std::cin >> year_of_enrollment;
    std::cout << "Enter student Grades: ";
    std::cin >> Grades;

    students[num_students] = Student(name, ID, year_of_enrollment, Grades);
    num_students++;
}

void removeStudent(Student students[], int& num_students) {
    if (num_students == 0) {
        std::cout << "No students to remove." << std::endl;
        return;
    }

    int ID;
    std::cout << "Enter student ID to remove: ";
    std::cin >> ID;

    for (int i = 0; i < num_students; i++) {
        if (students[i].getID() == ID) {
            for (int j = i; j < num_students - 1; j++) {
                students[j] = students[j + 1];
            }
            num_students--;
            std::cout << "Student with ID " << ID << " removed successfully." << std::endl;
            return;
        }
    }

    std::cout << "Student with ID " << ID << " not found." << std::endl;
}

void updateStudent(Student students[], int num_students) {
    if (num_students == 0) {
        std::cout << "No students to update." << std::endl;
        return;
    }

    int ID;
    std::cout << "Enter student ID to update: ";
    std::cin >> ID;

    for (int i = 0; i < num_students; i++) {
        if (students[i].getID() == ID) {
            std::string name;
            int year_of_enrollment;
            float Grades;
            std::string major;

            std::cout << "Enter new student name: ";
            std::cin >> name;
            std::cout << "Enter new student year of enrollment: ";
            std::cin >> year_of_enrollment;
            std::cout << "Enter new student Grades: ";
            std::cin >> Grades;

            students[i] = Student(name, ID, year_of_enrollment, Grades);
            std::cout << "Student with ID " << ID << " updated successfully." << std::endl;
            return;
        }
    }

    std::cout << "Student with ID " << ID << " not found." << std::endl;
}

void sortStudentsByID(Student students[], int& num_students) {
    if (num_students == 0) {
        std::cout << "No students to sort." << std::endl;
        return;
    }

    // Convert array to vector for merge sort
    std::vector<Student> studentsVec(students, students + num_students);
    merge(studentsVec, 0, studentsVec.size() - 1, compareByID);

    // Copy sorted students back into the array
    for (int i = 0; i < num_students; i++) {
        students[i] = studentsVec[i];
    }

    std::cout << "Students sorted by ID:" << std::endl;
    for (int i = 0; i < num_students; i++) {
        students[i].display();
    }
}

void sortStudentsByGrades(Student students[], int& num_students) {
    if (num_students == 0) {
        std::cout << "No students to sort." << std::endl;
        return;
    }

    // Convert array to vector for merge sort
    std::vector<Student> studentsVec(students, students + num_students);
    merge(studentsVec, 0, studentsVec.size() - 1, compareByGrades);

    // Copy sorted students back into the array
    for (int i = 0; i < num_students; i++) {
        students[i] = studentsVec[i];
    }

    std::cout << "Students sorted by Grades:" << std::endl;
    for (int i = 0; i < num_students; i++) {
        students[i].display();
    }
}

void sortStudentsByYear(Student students[], int& num_students) {
    if (num_students == 0) {
        std::cout << "No students to sort." << std::endl;
        return;
    }

    // Convert array to vector for merge sort
    std::vector<Student> studentsVec(students, students + num_students);
    merge(studentsVec, 0, studentsVec.size() - 1, compareByYear);

    // Copy sorted students back into the array
    for (int i = 0; i < num_students; i++) {
        students[i] = studentsVec[i];
    }

    std::cout << "Students sorted by Year of Enrollment:" << std::endl;
    for (int i = 0; i < num_students; i++) {
        students[i].display();
    }
}

void searchStudentByID(Student students[], int num_students) {
    if (num_students == 0) {
        std::cout << "No students to search." << std::endl;
        return;
    }

    int ID;
    std::cout << "Enter student ID to search: ";
    std::cin >> ID;

    for (int i = 0; i < num_students; i++) {
        if (students[i].getID() == ID) {
            students[i].display();
            return;
        }
    }
    std::cout << "Student with ID " << ID << " not found." << std::endl;
}

void displayStudents(Student students[], int num_students) {
    if (num_students == 0) {
        std::cout << "No students to display." << std::endl;
        return;
    }

    std::cout << "List of students:" << std::endl;
    for (int i = 0; i < num_students; i++) {
        students[i].display();
    }
}
