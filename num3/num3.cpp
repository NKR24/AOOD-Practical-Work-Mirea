#include <iostream>
#include <string>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	string s;
	int lastIndexOfDot, amountOfLetters = 0, amountOfChars = 0;
	cout << "Введите адресс электронной почти: ";
	getline(cin, s);
	size_t found = s.find('@');

		if (found != string::npos) {
			for (int i = s.size(); i > 0; i--) {
				if (s[i] == '.') {
					lastIndexOfDot = i;
					break;
				}
				else {
					continue;
				}
			}
			for (int j = lastIndexOfDot + 1; j < s.size(); j++) {
				if ((s[j] >= 'A' && s[j] <= 'Z') || (s[j] >= 'a' && s[j] <= 'z')) {
					amountOfLetters += 1;
				}
				amountOfChars += 1;
			}
			if (amountOfLetters == amountOfChars) {
				cout << "Почта удовлетворяет условиям";
			}
			else {
				cout << "Почта не удовлетворяет условиям";
			}
		}
		else {
			cout << "Почта должна содержать @";
		}
}