#include <iostream>
using namespace std;
class Tvector
{
public:
	Tvector();

private:

};

Tvector::Tvector()
{
};
int main(){
	setlocale(LC_ALL, "Russian");
	int n, vibor;
	Tvector *ob;
	cout << "Введите размерность = ";
	cin >> n;
	ob = new Tvector[n];
	while (1) { //добавляем меню
		cout << "\n vvedite nomer punkta:\n";
		cout << "vvod------>1" << endl
			<< "kol-vo room----->2" << endl
			<< "interval------>3" << endl
			<< "square------>4" << endl
			<< "vivod------>5" << endl
			<< "exit------>6" << endl;
		cin >> vibor;
		switch (vibor) {
		case 1:
		case 2:
			
		case 3:
			
		case 4:
			
		case 5:
		case 6:
			cout << "Good-Bye!";
			delete[] ob; //высвобождаем память
			break;
		}
	}
	system("pause");
	return 0;
}
