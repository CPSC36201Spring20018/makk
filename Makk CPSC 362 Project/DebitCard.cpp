#include <iostream>
#include <string>

using namespace std;

struct Node
{
	string holder;
	int number;
	string status;

	Node *next;
};

class List
{
	Node *head;
public:
	List()
	{
		head = NULL;
	}

	void create(string h, int n, string s);
	void modify(int num);
	void modifyE(int num);
	void deleteDC(int num);
	string isEmpty();
	void print();
};

int main()
{
	List list;
	list.create("Kenny Chao", 8, "Enabled");
	list.create("Kenny Chao", 9, "Enabled");
	int userOpt;
	cout << "1. Disable Debit Card" << endl
		<< "2. Enable Debit Card" << endl
		<< "3. Cancel Debit Card" << endl
		<< "4. Quit" << endl;
	cout << "Choose an Option: ";
	cin >> userOpt;
	cout << endl;
	while (userOpt == 1 || userOpt == 2 || userOpt == 3)
	{
		switch (userOpt)
		{
		case 1:
			int debNum;
			if(list.isEmpty() == "false")
			{
				list.print();
				cout << "Enter in the debit card you want to disable: ";
				cin >> debNum;
				list.modify(debNum);
			}
			else
			{
				cout << "You have no saved debit cards." << endl;
			}
			break;
		case 2:
			int debNum2;
			if(list.isEmpty() == "false")
			{
				list.print();
				cout << "Enter in the debit card you want to enable: ";
				cin >> debNum2;
				list.modifyE(debNum2);
			}
			else
			{
				cout << "You have no saved debit cards." << endl;
			}
			break;
		case 3:
			int debNum3;
			if (list.isEmpty() == "false")
			{
				list.print();
				cout << "Enter in the debit card you want to delete: ";
				cin >> debNum3;
				list.deleteDC(debNum3);
			}
			else
			{
				cout << "You have no saved debit cards." << endl;
			}
			break;
		default:
			break;
		}
		cout << endl;
		cout << "1. Disable Debit Card" << endl
			<< "2. Enable Debit Card" << endl
			<< "3. Cancel Debit Card" << endl
			<< "4. Quit" << endl;
		cout << "Choose an option: ";
		cin >> userOpt;
		cout << endl;
	}
	system("pause");
	return 0;
}

void List::modify(int num)
{
	int dn = num;
	Node *temp = head;
	while (temp != NULL)
	{
		if(temp->number == dn)
		{
			if (temp->status == "Disabled")
			{
				cout << "Debit card is already disabled" << endl;
			}
			else
			{
				temp->status = "Disabled";
				cout << "Debit Card has been disabled" << endl;
			}
			break;
		}
		else
		{
			temp = temp->next;
		}
		if (temp == NULL || temp->number != dn)
		{
			cout << "There is no existing debit card with that number" << endl;
			break;
		}
	}
}

void List::modifyE(int num)
{
	int dn = num;
	Node *temp = head;
	while (temp != NULL)
	{
		if (temp->number == dn)
		{
			if (temp->status == "Enabled")
			{
				cout << "Debit card is already enabled" << endl;
			}
			else
			{
				temp->status = "Enabled";
				cout << "Debit Card has been Enabled" << endl;
			}
			break;
		}
		else
		{
			temp = temp->next;
		}
		if(temp == NULL || temp->number != dn)
		{
			cout << "There is no existing debit card with that number." << endl;
			break;
		}
	}
}

void List::deleteDC(int num)
{
	int n = num;
	Node *temp = head;
	if(temp->number != n && temp->next == NULL)
	{
		cout << "There is no existing debit card with that number." << endl;
	}
	else if(temp->number != n && temp->next->number != n)
	{
		cout << "There is no existing debit card with that number." << endl;
	}
	if(temp->number == n)
	{	
		head = head->next;
		delete temp;
		cout << "Debit card " << n << " has been deleted." << endl;
	}
	else if(temp->next != NULL && temp->next->number == n)
	{
		temp->next = NULL;
		cout << "Debit card " << n << " has been deleted." << endl;
	}
}

void List::create(string h, int n, string s)
{
	Node *newNode = new Node;
	newNode->holder = h;
	newNode->number = n;
	newNode->status = s;
	newNode->next = NULL;

	if (head == NULL)
	{
		head = newNode;
	}
	else if (head->next == NULL)
	{
		head->next = newNode;
	}
	else
	{
		Node *temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}

		temp->next = newNode;
	}
}

string List::isEmpty()
{
	string tof;
	if(head == NULL)
	{
		tof = "true";
	}
	else
	{
		tof = "false";
	}

	return tof;
}

void List::print()
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << "Debit Card Number: " << temp->number <<  "		Status: " << temp->status << endl;
		temp = temp->next;
	}
}