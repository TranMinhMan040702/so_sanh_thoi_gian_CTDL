#include<iostream>
#include<time.h>
#include <iomanip>

using namespace std;
void xoa(int arr[], int n, int sdt) {
	int vt = -1;
	for (int i = 0; i < n; i++) {
		if (arr[i] == sdt) {
			vt = i;
			break;
		}
	}
	if (vt == -1) {
		cout << "\n\tKhong co phan tu can xoa";
	}
	else {
		for (int i = vt; i < n; i++) {
			arr[i] = arr[i + 1];
		}
		n--;
	}
}

void xuat(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << "\n";
	}
}

void timKiem(int arr[], int n, int sdt) {
	for (int i = 0; i < n; i++) {
		if (arr[i] == sdt) {
			cout << arr[i] << "\n";
		}
	}
}

// tính thời gian trong Menu 
void menu(int arr[], int& n) {
	int luachon;
	while (true) {
		system("cls");
		cout << "\n\n\t\t===========================MENU==============================";
		cout << "\n\n\t\t1. Them";
		cout << "\n\n\t\t2. Xoa";
		cout << "\n\n\t\t3. Truy cap";
		cout << "\n\n\t\t4. Tim kiem";
		cout << "\n\n\t\t5. Xuat";
		cout << "\n\n\t\t===========================END==============================";

		cout << "\n\tNhap lua chon: ";
		cin >> luachon;
		if (luachon == 1) {
			double max = INT_MIN;
			double min = INT_MAX;
			double mean = 0;
			for (int i = 0; i < 1000; i++)
			{
					clock_t start, end;
					double cputime;
					start = clock();
					arr[i] = i;
					end = clock();
					cputime = double(end - start) / CLOCKS_PER_SEC;
					cout << cputime << "\n";
					if (max < cputime)
					{
						max = cputime;
					}
					if (min > cputime)
					{
						min = cputime;
					}
					mean += cputime;
			}
			cout << "max:" << max << "\n";
			cout << "min:" << min << "\n";
			cout << "mean:" << mean / 1000;
			
			system("pause");
		}
		else if (luachon == 2) 
{
			double max = INT_MIN;
			double min = INT_MAX;
			double mean = 0;
			for (int i = 0; i < 1000; i++)
			{
			clock_t start, end;
			double cputime;
			start = clock();
			xoa(arr, 1000, i);
			end = clock();
			cputime = double(end - start) / CLOCKS_PER_SEC;
			cout << cputime << "\n";
			if (max < cputime)
			{
				max = cputime;
			}
			if (min > cputime)
			{
				min = cputime;
			}
			mean += cputime;
			}
			cout << "max:" << max << "\n";
			cout << "min:" << min << "\n";
			cout << "mean:" << mean / 1000;

			system("pause");

		}
		else if (luachon == 4) {
			double max = INT_MIN;
			double min = INT_MAX;
			double mean = 0;
			for (int i = 0; i < 1000; i++)
			{
			clock_t start, end;
			double cputime;
			start = clock();
			timKiem(arr, n, i);
			end = clock();
			cputime = double(end - start) / CLOCKS_PER_SEC;
			cout << cputime << "\n";
			if (max < cputime)
			{
				max = cputime;
			}
			if (min > cputime)
			{
				min = cputime;
			}
			mean += cputime;
			}
			cout << "max:" << max << "\n";
			cout << "min:" << min << "\n";
			cout << "mean:" << mean / 1000;

			system("pause");
		}
		else if (luachon == 5) {
			cout << "\n\n\t\t";
			xuat(arr, n);
			system("pause");
		}
	}
}


int main() {
	int arr[10000];
	int n = 1000;
	menu(arr, n);
}