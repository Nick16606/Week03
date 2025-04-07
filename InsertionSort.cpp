#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
#include<ctime>
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
	file.close();
}
void InsertionSort(int a[], int n,int &count) {
	int pos, x;
	for (int i = 0; i < n - 1; i++) {
		pos = i;
		x = a[i + 1];
		while (pos >= 0) {
			++count;
			if (x < a[pos]) {
				a[pos + 1] = a[pos];
				--pos;
			}
			else break;
		}
		a[pos + 1] = x;
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
	if (sort == "insertion-sort") InsertionSort(a, n,count);
	if (!outputfile.empty()) outputinfo(outputfile, a, n,count);
}
