#include<iostream>
#include<fstream>
#include<ctime>
#include<cstdlib>
#include<cstring>
using namespace std;
void inputinfo(const string& input, int a[], int &n) {
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
void outputinfo(const string& output, int a[], int n,int count) {
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
	file << count;
}
void selectionsort(int a[], int n,int &count) {
	int min;
	for (int i = 0; i < n - 1; i++){
		min = i;
		for (int j = i + 1; j < n; j++) {
			++count;
			if (a[min] > a[j]) {
				min = j;
			}
		}
		int tmp = a[min];
		a[min] = a[i];
		a[i] = tmp;
	}
}
int main(int argc, char* argv[]) {
	int count = 0;
	string inputfile, outputfile, Sort;
	int n, a[400];
	for (int i = 1; i < argc; i++) {
		if (strcmp(argv[i], "-a" ) == 0 && i + 1 < argc) {
			Sort = argv[i + 1];
			++i;
		}
		else if (strcmp(argv[i], "-i") == 0 && i + 1 < argc) {
			inputfile = argv[i + 1];
			++i;
		}
		else if (strcmp(argv[i], "-o") == 0 && i + 1 < argc) {
			outputfile = argv[i + 1];
			++i;
		}
	}
	if (!inputfile.empty()) {
		inputinfo(inputfile, a, n);
	}
	if (Sort == "selection-sort") {
		selectionsort(a, n,count);
	}
	if (!outputfile.empty()) {
		outputinfo(outputfile, a, n,count);
	}
	return 0;
}