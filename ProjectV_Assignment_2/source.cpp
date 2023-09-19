#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

#define _PRE_RELEASE

using namespace std;

struct StudentData
{
	string first;
	string last;

#ifdef _PRE_RELEASE
	string email;
#endif // _PRE_RELEASE
};

vector<StudentData> student_data;

void read_data(string file_name) {
	fstream file;

	file.open(file_name);

	if (file.is_open()) {
		while (!file.eof()) {
			string line;
			getline(file, line);

			if (!line.empty()) {
				stringstream line_stream(line);
				StudentData student;

				getline(line_stream, student.last, ',');
				getline(line_stream, student.first, ',');

#ifdef _PRE_RELEASE
				getline(line_stream, student.email, ',');
#endif // _PRE_RELEASE

				student_data.push_back(student); 

#if defined(_DEBUG) && defined(_PRE_RELEASE)
				std::cout << student.last << ',' << student.first << ',' << student.email << std::endl;
#elif _DEBUG
				std::cout << student.last << ',' << student.first << std::endl;
#endif // DEBUG && PRE_RELEASE
			}
		}
	}
}

int main() {
#ifdef _PRE_RELEASE
	std::cout << "Application is running pre-release source code." << std::endl;
	read_data("C:\\Users\\Mostafa\\Desktop\\StudentData_Emails1.txt");
#else
	std::cout << "Application is running standard source code." << std::endl;
	read_data("C:\\Users\\Mostafa\\Desktop\\StudentData.txt");
#endif // _PRE_RELEASE

	return 0;
}
