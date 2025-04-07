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
	file.close();
}
void BubbleSort(int a[], int n,int &count) {
	for (int i = 0; i < n-1; i++) {
		for (int j = n - 1; j > i; j--) {
			++count;
			if (a[j] < a[j - 1]) {
				int tmp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = tmp;
			}
		}
	}
}
int main(int argc, char* argv[]) {
	int count = 0;
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
	if (sort == "bubble-sort") BubbleSort(a, n,count);
	if (!outputfile.empty()) outputinfo(outputfile, a, n,count);
}
