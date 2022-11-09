#include <iostream>
#include <vector>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int n, m;
	cin >> n >> m;
	if (n < 2 || n > 100 || m < 2 || m > 50) {
		cout << "Неверные входные данные" << endl;
	}
	else {
		vector < vector <int> > a(n, vector <int>(m));
		vector<int> lastDigits(n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
			{
				cin >> a[i][j];
			}
		}

			for (int i = 0; i < n; i++)
			{
				lastDigits[i] = a[i][m - 1];
			}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n - 1; j++) {
				if (lastDigits[j] > lastDigits[j + 1]) {
					int temp = lastDigits[j + 1];
					lastDigits[j + 1] = lastDigits[j];
					lastDigits[j] = temp;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			a[i][m - 1] = lastDigits[i];
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
			{
				cout << a[i][j] << " ";
			}
			cout << endl;
		}
		return 0;
	}
}