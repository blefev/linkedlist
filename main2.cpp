
#include <fstream>          // Include to use ifstream
#include "ll.h"             // Include so can access our class
using namespace std;        // Include so we don't need to put std:: infront
                            // of cout and endl

int main()
{
	LL myList;

	for(int i = 0; i <= 10; i++){
		cout << "Appending " << i << " to list." << endl;
		myList.append(i);
	}

//	cout << "List size is: "<< myList.getSize() << endl;
	myList.print();

	myList.search(10);

	myList.remove(10);

	myList.print();

	return 0;
}
