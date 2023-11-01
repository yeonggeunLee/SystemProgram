#include <iostream>
#include <map>
#include <string>

struct Student {
    int midterm_score;
    int final_score;
};

int main() {
    int num_students;
    std::cout << "Enter the number of students: ";
    std::cin >> num_students;

    std::map<std::string, Student> students;

    for (int i = 0; i < num_students; i++) {
        std::string name;
        int midterm_score, final_score;
        std::cout << "Enter student name: ";
        std::cin >> name;
        std::cout << "Enter midterm score: ";
        std::cin >> midterm_score;
        std::cout << "Enter final score: ";
        std::cin >> final_score;

        students[name] = {midterm_score, final_score};
    }

    std::cout << "Student Information:" << std::endl;
    for (const auto& student : students) {
        std::cout << "Name: " << student.first << ", Midterm: " << student.second.midterm_score << ", Final: " << student.second.final_score << std::endl;
    }

    std::string search_name;
    std::cout << "Enter a name to search: ";
    std::cin >> search_name;
    auto it = students.find(search_name);
    if (it != students.end()) {
        std::cout << "Student found: Name: " << it->first << ", Midterm: " << it->second.midterm_score << ", Final: " << it->second.final_score << std::endl;
    } else {
        std::cout << "Student not found." << std::endl;
    }

    return 0;
}

