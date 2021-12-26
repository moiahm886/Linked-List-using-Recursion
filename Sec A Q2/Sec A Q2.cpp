#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node* Next;
};
Node* Newnode(int val)
{
	Node* New = new Node();
	New->data = val;
	New->Next = NULL;
	return New;

}
Node* insertion(Node* head, int val)
{
	if (head == NULL)
	{
		return Newnode(val);
	}
	else
	{
		head->Next = insertion(head->Next, val);
	}
	return head;
}

int totalcount(Node* head)
{
	if(head == NULL)
	{
		return 0;
	}
	else
	{
		return 1 + totalcount(head->Next);
	}
}
int minimum(struct Node* head)
{
	int min = INT_MAX;
	while (head != NULL)
	{
		if (head->data < min)
		{
			min = head->data;
		}
		head = head->Next;
	}
	return min;
}
void search(struct Node* head,int val)
{
	Node* N = head;
	int count = 1;
	if (head == NULL)
	{
		cout << "list is empty\n";
		return;
	}
	while (N != NULL)
	{
		if (N->data == val)
		{
			cout << "value found at Node Number " << count << endl;
		}
		N = N->Next;
		count++;

	}
}
void swap(struct Node* head, int val1, int val2)
{
	Node* N = head;
	Node* M=NULL;
	Node* K=NULL;
	Node* Temp = new Node();
	while (N != NULL)
	{
		if (N->data == val1)
		{
			M = N;
		}
		if (N->data == val2)
		{
			K = N;
		}
		N = N->Next;
	}
	if (K != NULL && M != NULL)
	{
		Temp->data = K->data;
		K->data = M->data;
		M->data = Temp->data;
	}
}
void display(Node* head)
{

	if (head == NULL)
	{
		return;
	}
	
	cout << head->data << " ";
	display(head->Next);
}
int main()
{
	Node* head = NULL;
	head=insertion(head,9);
	head=insertion(head, 45);
	head = insertion(head, 32);
	head = insertion(head, 7);
	cout << "Count of node is " << totalcount(head) << endl;
	cout << "The minimum value is "<< minimum(head) << endl;
	search(head,32);
	display(head);
	cout << endl;
	swap(head, 9, 32);
	cout << "After swapping 9 and 32\n";
	display(head);
	cout << endl;
	system("pause");
}