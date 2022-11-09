#include <iostream> 
using namespace std; 
int main()

{
	setlocale(LC_ALL, "Russian");
int r, a, b;
cout << "Введите радиус окружности: ";
cin >> r;
cout << "Введите ширину прямоугольника: ";
cin >> a;
cout << "Введите высоту прямоугольника: ";
cin >> b;


if (b > 2 * r) {
	cout << "Введенные данные некорректны";
}
else {
	int x, y;
	cout << "Введите координату 'x': "; cin >> x;
	cout << "Введите координату 'y': "; cin >> y;

	if (y >= 0 && y <= r && x <= r) {
		cout << "yes";
	}
	else if (y < 0 && abs(y) < a) {
		if (abs(x) <= b / 2) {
			cout << "yes";
		}
		else {
			cout << "no";
		}
	}
	else {
		cout << "no";
	}
}


return 0;
}
