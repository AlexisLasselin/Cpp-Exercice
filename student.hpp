#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include <iostream>

class Student {
private:
    std::string name;
    int ID;
    int year_of_enrollment;
    float GPA;
    std::string major;

    // Static data member to track the number of students
    static int student_count;

public:
    // Default constructor
    Student() : name(""), ID(0), year_of_enrollment(0), GPA(0.0), major("") {
        student_count++;  // Increment count when a student is created
    }

    // Parameterized constructor
    Student(std::string n, int id, int year, float gpa, std::string m)
        : name(n), ID(id), year_of_enrollment(year), GPA(gpa), major(m) {
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
    float getGPA() const { return GPA; }
	int getYear() const { return year_of_enrollment; }

    // Setters
    void setGPA(float gpa) { GPA = gpa; }

    // Display function
    void display() const {
        std::cout << "Name: " << name << ", ID: " << ID << ", Year of Enrollment: " << year_of_enrollment << ", GPA: " << GPA << ", Major: " << major << std::endl;
    }
};

// Initialize the static data member
int Student::student_count = 0;

#endif // STUDENT_HPP
