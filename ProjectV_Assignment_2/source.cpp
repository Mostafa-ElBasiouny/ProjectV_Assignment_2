#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

struct StudentData
{
	string first;
	string last;
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

				student_data.push_back(student);
			}
		}
	}
}

int main() {
	read_data("C:\\Users\\Mostafa\\Desktop\\StudentData.txt");

	return 0;
}
