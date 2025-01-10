#include <iostream>
#include <string>
#include "student.hpp"

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

void sortStudentsByID(Student students[], int num_students) {
	if (num_students == 0) {
		std::cout << "No students to sort." << std::endl;
		return;
	}

    for (int i = 0; i < num_students - 1; i++) {
        for (int j = 0; j < num_students - i - 1; j++) {
            if (students[j].getID() > students[j + 1].getID()) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    std::cout << "Students sorted by ID:" << std::endl;
    for (int i = 0; i < num_students; i++) {
        students[i].display();
    }
}

void sortStudentsByGrades(Student students[], int num_students) {
	if (num_students == 0) {
		std::cout << "No students to sort." << std::endl;
		return;
	}

    for (int i = 0; i < num_students - 1; i++) {
        for (int j = 0; j < num_students - i - 1; j++) {
            if (students[j].getGrades() < students[j + 1].getGrades()) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    std::cout << "Students sorted by Grades:" << std::endl;
    for (int i = 0; i < num_students; i++) {
        students[i].display();
    }
}

void sortStudentsByYear(Student students[], int num_students) {
	if (num_students == 0) {
		std::cout << "No students to sort." << std::endl;
		return;
	}

	for (int i = 0; i < num_students - 1; i++) {
		for (int j = 0; j < num_students - i - 1; j++) {
			if (students[j].getYear() > students[j + 1].getYear()) {
				Student temp = students[j];
				students[j] = students[j + 1];
				students[j + 1] = temp;
			}
		}
	}

	std::cout << "Students sorted by year of enrollment:" << std::endl;
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