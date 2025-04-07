#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
#include<ctime>
using namespace std;
void inputinfo(const string& input, int a[], int& n) {
	fstream file;
	file.open(input);
	if (!file.is_open()) {
		cout << "Xay ra loi";
		return;
	}
	file >> n;
	srand((unsigned int)time(NULL));
	for (int i = 0; i < n; i++) {
		a[i] = rand() % n;
	}
	file.close();
}
void outputinfo(const string& output, int a[], int n,int dem) {
	fstream file;
	file.open(output);
	if (!file.is_open()) {
		cout << "Xay ra loi";
		return;
	}
	file << n << endl;
	for (int i = 0; i < n; i++) {
		file << a[i] << " ";
	}
	file << endl;
	file << dem;
	file.close();
}
int getMax(int a[], int n) {
	int max = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}
	return max;
}
void RadixSort(int a[], int n,int &dem) {
	int Count[10];
	int arr[10][1000];
	int max = getMax(a, n);
	for (int exp = 1; max / exp > 0; exp = exp * 10) {
		for (int i = 0; i < 10; i++) {
			Count[i] = 0;
		}
		for (int i = 0; i < n; i++) {
			++dem;
			int digit = (a[i] / exp) % 10;
			arr[digit][Count[digit]++] = a[i];
		}
		int index=0;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < Count[i]; j++) {
				a[index++] = arr[i][j];
			}
		}
	}
}
int main(int argc, char* argv[]) {
	int dem = 0;
	string inputfile, outputfile, sort;
	int a[20], n;
	for (int i = 1; i < argc; i++) {
		if (strcmp(argv[i], "-a") == 0) {
			sort = argv[i + 1];
			++i;
		}
		else if (strcmp(argv[i], "-i") == 0) {
			inputfile = argv[i + 1];
			++i;
		}
		else if (strcmp(argv[i], "-o") == 0) {
			outputfile = argv[i + 1];
			++i;
		}
	}
	if (!inputfile.empty()) inputinfo(inputfile, a, n);
	if (sort == "radix-sort") RadixSort(a, n,dem);
	if (!outputfile.empty()) outputinfo(outputfile, a, n,dem);
}
