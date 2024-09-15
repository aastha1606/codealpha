#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Function to calculate the GPA for a semester
double calculateGPA(const vector<double> &grades, const vector<int> &credits) {
    double totalGradePoints = 0;
    int totalCredits = 0;

    for (size_t i = 0; i < grades.size(); ++i) {
        totalGradePoints += grades[i] * credits[i]; // Grade points = grade * course credits
        totalCredits += credits[i];                 // Sum of credits
    }

    return totalGradePoints / totalCredits; // GPA = total grade points / total credits
}

// Function to calculate CGPA based on multiple semesters
double calculateCGPA(const vector<double> &gpas, const vector<int> &semCredits) {
    double totalGPA = 0;
    int totalCredits = 0;

    for (size_t i = 0; i < gpas.size(); ++i) {
        totalGPA += gpas[i] * semCredits[i]; // Sum of (GPA * total credits for each semester)
        totalCredits += semCredits[i];       // Sum of all semester credits
    }

    return totalGPA / totalCredits; // CGPA = total GPA points / total credits
}

int main() {
    int numCourses, numSemesters;
    vector<double> gpas;       // To store GPA of each semester
    vector<int> semCredits;    // To store total credits of each semester

    cout << "Enter the number of semesters: ";
    cin >> numSemesters;

    // Loop through each semester to calculate GPA
    for (int sem = 0; sem < numSemesters; ++sem) {
        cout << "\nSemester " << sem + 1 << ":\n";

        cout << "Enter the number of courses: ";
        cin >> numCourses;

        vector<double> grades(numCourses);
        vector<int> credits(numCourses);

        // Input grades and credits for each course
        for (int i = 0; i < numCourses; ++i) {
            cout << "Enter grade for course " << i + 1 << ": ";
            cin >> grades[i];

            cout << "Enter credit for course " << i + 1 << ": ";
            cin >> credits[i];
        }

        // Calculate GPA for the semester
        double semesterGPA = calculateGPA(grades, credits);
        int semesterCredits = 0;

        for (int i = 0; i < numCourses; ++i) {
            semesterCredits += credits[i];
        }

        gpas.push_back(semesterGPA);  // Add GPA to the list of GPAs
        semCredits.push_back(semesterCredits); // Add total credits of this semester

        cout << fixed << setprecision(2);
        cout << "GPA for Semester " << sem + 1 << ": " << semesterGPA << endl;
    }

    // Calculate CGPA
    double CGPA = calculateCGPA(gpas, semCredits);

    cout << fixed << setprecision(2);
    cout << "\nOverall CGPA: " << CGPA << endl;

    return 0;
}