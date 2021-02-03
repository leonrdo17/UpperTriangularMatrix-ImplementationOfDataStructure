#include <iostream>
#include<string>
using namespace std;

struct rowcolumn {

	int n;
	int m;
	int num;
	rowcolumn* next;

};

class UTM {

	rowcolumn* head;
	rowcolumn* tail;
	int size;
	int value;


public:

	int maxQue = 0;
	int matrixSize;
	int values;


	UTM() {

		this->head = NULL;
		this->tail = NULL;
		this->size = 0;
		this->value = 0;

	}


	~UTM() {

		rowcolumn* current = head;
		if (current == NULL) {

			cout << "The matrix have been restarted! \n";

		}

		else {

			while (head != NULL) {

				current = current->next;
				delete head;
				head = current;

			}

			size = 0;

		}

	}


	void inputElements() {

		rowcolumn* newNode = new rowcolumn();
		rowcolumn* current = head;
		int insert;
		values = matrixSize;

		for (int i = 0; i < matrixSize; i++) {

			for (int j = 0; j < matrixSize; j++) {

				if (j < i) {

					newNode = head;
					while (newNode != NULL) {

						if (newNode->m == i && newNode->m == j) {
							newNode->num;
						}

						else
						{
							newNode = newNode->next;
						}

					}

					newNode = new rowcolumn;
					newNode->n = i;
					newNode->m = j;
					newNode->num = 0;
					newNode->next = NULL;

					tail->next = newNode;
					tail = newNode;
				}

				else {

					cout << "Insert the value in column " << i + 1 << " and row " << j + 1 << " : ";
					cin >> insert;

					if (head == NULL) {
						newNode = new rowcolumn;
						newNode->n = i;
						newNode->m = j;
						newNode->num = insert;
						newNode->next = NULL;
						head = newNode;
						tail = newNode;
					}
					else {

						newNode = head;
						while (newNode != NULL) {
							if (newNode->n == i && newNode->m == j) {

								newNode->num = insert;

							}
							else {

								newNode = newNode->next;
							}
						}

						newNode = new rowcolumn;
						newNode->n = i;
						newNode->m = j;
						newNode->num = insert;
						newNode->next = NULL;
						tail->next = newNode;
						tail = newNode;
					}
				}
			}
		}
	}



	void displayMatrix() {

		rowcolumn* current = head;
		if (current == NULL) {

			cout << "No matrix found in the list. \n" << endl;

		}
		else {

			while (current != NULL)
			{
				if (current->m == values - 1) {

					cout << current->num << endl;
					current = current->next;

				}
				else {

					cout << current->num << " ";
					current = current->next;

				}
			}
			cout << endl;
		}

	}

	void sumUTM(UTM& A, UTM& B)
	{
		for (int i = 0; i < matrixSize; i++)
		{
			for (int j = 0; j < matrixSize; j++)
			{
				bool check = false;
				rowcolumn* current = A.head;
				while (current != NULL) {

					if (current->m == j && current->n == i) {

						A.value = current->num;
						check = true;

					}

					current = current->next;
				}

				if (check == false) {

					A.value = 0;

				}

				rowcolumn* newcurrent = B.head;
				while (newcurrent != NULL) {

					if (newcurrent->m == j && newcurrent->n == i) {

						B.value = newcurrent->num;
						check = true;

					}

					newcurrent = newcurrent->next;
				}

				if (check == false) {

					B.value = 0;

				}

				int value = A.value + B.value;
				cout << value << " ";
			}cout << "\n";
		}
	}
};


int main() {

	UTM A;
	UTM B;
	int userMatrixSize;
	int action;
	do {
		cout << "Insert your Upper Triangle Matrix size! \n";
		cin >> userMatrixSize;
		if (userMatrixSize >= 1) {

			A.matrixSize = userMatrixSize;
			B.matrixSize = userMatrixSize;

		}
		else
		{
			cout << "Size not acceptable! \n";
		}

	} while (userMatrixSize < 1);

	do {

		cout << "UPPER TRIANGULAR MATRIX\n";
		cout << "1.Create first upper triangular matrix\n";
		cout << "2.Create second upper triangular matrix\n";
		cout << "3.Display both upper triangluar matrix\n";
		cout << "4.Sum of the both upper triangular matrix\n";
		cout << "5.Restart\n";
		cout << "6.Exit\n";
		cout << "Please select the action:  " << endl;
		cin >> action;

		switch (action)
		{
		case 1:

			while (A.maxQue == 0) {

				A.inputElements();
				A.maxQue++;

			}

			cout << "The first matrix have been created!\n";
			cout << "Please proceed to the next step\n" << endl;
			break;

		case 2:

			while (B.maxQue == 0) {

				B.inputElements();
				B.maxQue++;

			}

			cout << "The second matrix have been created!\n";
			cout << "Please proceed to the next step\n" << endl;
			break;

		case 3:

			cout << "First Matrix\n";
			A.displayMatrix();
			cout << "Second Matrix\n";
			B.displayMatrix();
			break;

		case 4:

			cout << "The sum of the both matrix is \n";
			A.sumUTM(A, B);
			break;

		case 5:

			A.~UTM();
			A.maxQue = 0;
			B.~UTM();
			B.maxQue = 0;
			cout << "System Restarted!" << endl;
			break;

		case 6:

			break;

		}
	} while (action != 6);

}
