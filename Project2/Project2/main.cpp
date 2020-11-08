#include "microFB.h"

using namespace std;
int main() {
	Social FaceBook;
	string inputN1;
	string inputN2;
	char cmd = 'S';
	cout << "-------------------------------------------" << endl;
	cout << "|              Micro FaceBook              |" << endl;
	cout << "-------------------------------------------" << endl;
	cout << "|P : Create Person                         |" << endl;
	cout << "|F : Make Them Friends                     |" << endl;
	cout << "|U : Unfriend                              |" << endl;
	cout << "|L : Print Out Friends of Specific Person  |" << endl;
	cout << "|Q : Check if Two People are Friends       |" << endl;
	cout << "|X : Exit Programm                         |" << endl;
	cout << "-------------------------------------------" << endl;

	do
	{
		cout << "Input Command and Press Enter >>";
		cin >> cmd;
		switch (cmd) {
		
		case 'p':case 'P':
			getchar();
			cout << "-------------------------------------------" << endl;
			cout << "Enter Name Of The Member You Want To Add" << endl;
			cout << ">>";
			getline(cin, inputN1);
			FaceBook.MakePerson(inputN1); 
			break;


		case 'f':case 'F':
			cout << "Enter Two Members To Make Them Friend" << endl;
			cout << "-------------------------------------------" << endl;
			getchar();
			cout << "Enter First Member" << endl<<">>";
			getline(cin, inputN1);
			cout << "Enter Second Member"  << endl<<">>";
			getline(cin, inputN2);
			if (FaceBook.MakeFriend(inputN1, inputN2)) {
				cout << "-------------------------------------------" << endl;
				cout << "Success! "<<endl<<inputN1<<" and "<<inputN2<<" are friends!" << endl<<endl;
				cout << "-------------------------------------------" << endl;
			}
			else {
				cout << "-------------------------------------------" << endl;
				cout << "fail" << endl;
				cout << "-------------------------------------------" << endl;
			}
			break;


		case 'u':case 'U':
			cout << "Enter Two Members To Unfriend" << endl;
			cout << "-------------------------------------------" << endl;
			getchar();
			cout << "Enter First Member" << endl << ">>";
			getline(cin, inputN1);
			cout << "Enter Second Member" << endl << ">>";
			getline(cin, inputN2);
			if (FaceBook.UnFriend(inputN1, inputN2)) {
				cout << "-------------------------------------------" << endl;
				cout << "unfriend success" << endl;
				cout << "-------------------------------------------" << endl;
			}
			else {
				cout << "-------------------------------------------" << endl;
				cout << "wrong input name or not friend" << endl;
				cout << "-------------------------------------------" << endl;
			}
			break;


		case 'l':case 'L':
			cout << "Enter Name " << endl;
			getchar();
			cout << ">>";
			getline(cin, inputN1);
			FaceBook.printFriend(inputN1);
			break;


		case 'q':case'Q':
		{
			cout << "Enter Two Names To Check If They Are Friends " << endl;
			getchar();
			cout << "Enter First Member" << endl << ">>";
			getline(cin, inputN1);
			cout << "Enter Second Member" << endl << ">>";
			getline(cin, inputN2);
			if (FaceBook.isFriend(inputN1, inputN2)) {
				cout << "-------------------------------------------" << endl;
				cout << "YES" << endl;
				cout << "-------------------------------------------" << endl;
			}
			else {
				cout << "-------------------------------------------" << endl;
				cout << "NO" << endl;
				cout << "-------------------------------------------" << endl;
			}
		}
			break;
		case 'x':case'X':
			break;
		default:
			cout << "-------------------------------------------" << endl;
			cout << "Wrong Command!" << endl;
			cout << "-------------------------------------------" << endl;
			
		}
		FaceBook.showMem();
	} while ((cmd != 'x') && (cmd != 'X'));

	
}
