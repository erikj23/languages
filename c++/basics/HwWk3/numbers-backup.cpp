
#include <iostream>
using namespace std;

void numbers(int from, int to) {
	
	cout << endl;
	
	++to;
	
	for(from; from < to; ++from) {
		
		int catl(from);
		int count(0);
		
		while(catl != 0) {
			
			++count;
			
			if(catl % 3 == 0) catl += 4;
			else if (catl % 4 == 0) catl /= 2;
			else --catl;
			
		}
		
		cout << from << " -> " << count << endl;
		
	}
	
}

int start() {

	cout << endl;
	
	int from(0);
	int to(0);
	
	do {
		
		cout << "Enter a posative integer range." << endl;
		cout << "from=";
		cin >> from;
		cout << "to=";
		cin >> to;
	
	} while(from < 1 or to <= from);
	
	numbers(from, to);
	
	cout << endl;

	return 0;
}

int main() {
	
	return start();
}
