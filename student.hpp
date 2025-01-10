#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include <iostream>

class Student {
private:
    std::string name;
    int ID;
    int year_of_enrollment;
    float Grades;

    // Static data member to track the number of students
    static int student_count;

public:
    // Default constructor
    Student() : name(""), ID(0), year_of_enrollment(0), Grades(0.0) {
        student_count++;  // Increment count when a student is created
    }

    // Parameterized constructor
    Student(std::string n, int id, int year, float Grades)
        : name(n), ID(id), year_of_enrollment(year), Grades(Grades) {
        student_count++;  // Increment count when a student is created
    }

    // Destructor
    ~Student() {
        student_count--;  // Decrement count when a student is destroyed
    }

    // Static function to get the current student count
    static int getStudentCount() {
        return student_count;
    }

    // Getters
    int getID() const { return ID; }
    float getGrades() const { return Grades; }
	int getYear() const { return year_of_enrollment; }
    std::string getName() const { return name; }

    // Setters
    void setGrades(float Grades) { Grades = Grades; }

    // Display function
    void display() const {
        std::cout << "Name: " << name << ", ID: " << ID << ", Year of Enrollment: " << year_of_enrollment << ", Grades: " << Grades << std::endl;
    }
};

// Initialize the static data member
int Student::student_count = 0;

#endif // STUDENT_HPP
