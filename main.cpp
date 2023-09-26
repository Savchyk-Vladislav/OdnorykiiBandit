#include <iostream>
#include <math.h>
#include <ctime>
using namespace std;

int main() {
	//Встановлюємо кількість випадково згенерованих чисел
	int length;
	cout << "Length your game: ";
	cin >> length;

	int bet = 0;
	int arr[length];
	int balance = 0;
	cout << "Your deposit: ";
	cin >> balance;

	while(true) {
		cout << "Your bet: ";
		cin >> bet;

		if (balance >= bet) {

		srand(time(NULL));

	    for(int i = 0; i < length; i++) {
		arr[i] = 1 + rand() % 10;
		cout << arr[i] << " ";
	    }
	   	cout << endl;

		int count = 0;
		for (int i = 0; i < length; i++) {
			if (arr[i] == 7) count++;
			else continue;
		}

		if (count == 1) {
			cout << "Your bet(" << bet << ") has been returned" << endl;
			cout << "Your balance: " << balance << endl;
			continue;
		}

		if (count == 2) {
			cout << "Your bet(" << bet << ") is doubled: " << bet * 2 << endl;
			balance = balance + bet;
			cout << "Your balance: " << balance << endl;
			continue;
		}

		if (count == 3) {
			cout << "Your bet(" << bet << ") is tripled: " << bet * 3 << endl;
			balance = balance + bet * 2;
			cout << "Your balance: " << balance << endl;
			continue;
		}

		if (count > 3) {
			cout << "Your bet(" << bet << ") is multiplied by " << count << ": " << bet * count << endl;
			balance = balance + bet * (count - 1);
			cout << "Your balance: " << balance << endl;
			continue;
		}

		else {
			int third = length / 3;
			int countNotSeven = 0;
			int temp;
			bool flag = true;
			for (int i = 0; i < length; i++) {
				temp = arr[i];
				countNotSeven = 0;
			for (int j = 0; j < length; j++) {
				if (arr[j] == temp) {
					countNotSeven++;
				}
			}
			if (countNotSeven < third) continue;
			if (countNotSeven >= third) {
				cout << "Your bet(" << bet << ") has been returned" << endl;
				cout << "Your balance: " << balance << endl;
				flag = false;
				break;
			}
		}

		if (flag == false) continue;
		if (flag == true) {
		cout << "Your bet(" << bet << ") has expired" << endl;
		balance = balance - bet;
		cout << "Your balance: " << balance << endl;
	    }
	}
}
if (balance < bet) {
			cout << "Your balance is less than your bet! :(";
			break;
		}
  }
}
