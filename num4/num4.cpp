#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
struct Alumnus {
	string _bio;
	string _university;
	string _speciality;
	size_t _year_of_ending;
	Alumnus() = default;
	Alumnus(const string& Bio,
		const string& University,
		const string& Speciality,
		size_t YearOfEnding)
		: _bio(Bio), _university(University),
		_speciality(Speciality),
		_year_of_ending(YearOfEnding) {}
	bool operator < (const Alumnus& rhs) const {
		return _bio < rhs._bio;
	}
};
ostream& operator << (ostream& out, const Alumnus& al) {
	out << al._bio << " " << al._university << " " << al._speciality << " "
		<< al._year_of_ending;
	return out;
}
istream& operator >> (istream& is, Alumnus& al) {
	string surname, name, patronymic;
	is >> surname >> name >> patronymic;
	al._bio = surname + " " + name + " " + patronymic;
	is >> al._university >> al._speciality >> al._year_of_ending;
	return is;
}
void read_alumnus(vector<Alumnus>& students, ifstream& in) {
	Alumnus al;
	for (; in >> al;) {
		students.push_back(al);
	}
}
vector<Alumnus> read_bin(const std::string& path) {
	vector<Alumnus> readed;
	ifstream binary_file(path, ios::binary);
	if (binary_file.is_open()) {
		read_alumnus(readed, binary_file);
	}
	binary_file.close();
	return readed;
}

int main() {
	ifstream in("Alumnies.txt", ios::in);
	if (in.is_open() == false) {
		cerr << "FILE NOT FOUND" << endl;
		exit(1);
	}
	vector<Alumnus> students;
	// Чтение из файла
	read_alumnus(students, in);
	in.close();
	// Сортировка
	sort(students.begin(), students.end());
	cout << "sorting:" << endl;
	for (auto& al : students) {
		cout << al << endl;
	}
	cout << "Searching:" << endl;
	// Поиск
	string bio;
	cout << "Enter search bio" << endl;
	getline(cin, bio);
	Alumnus a{ bio, "", "",0 };
	auto p = equal_range(students.begin(), students.end(), a);
	for (auto i = p.first; i != p.second; ++i)
		std::cout << *i << endl;
	cout << "Writing binaries:" << endl;
	{
		ofstream binary_file("bin_data.bin", ios::out | ios::out |
			ios::binary);
		if (binary_file.is_open()) {
			for (Alumnus al : students) {
				binary_file << al;
			}
		}
		binary_file.close();
	}
	cout << "Reading binaries:" << endl;
	{
		vector<Alumnus> readed = read_bin("bin_data.bin");
		for (auto al : readed) {
			cout << al << endl;
		}
	}
	return 0;
}