#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node *nextNode;
    Node()
    {
        value = 0;
        nextNode = NULL;
    }
    Node(int value)
    {
        this -> value = value;
        nextNode = NULL;
    }
};
Node* addLastNode(Node *head, int value)
{
    if(head == NULL)
    {
        Node* tmp = new Node(value);
        head = tmp;
        return head;
    }
    // them code cua ban o day
    Node *walk = head;
    while(walk -> nextNode != NULL)
    {
        walk = walk -> nextNode;
    }
    Node* tmp = new Node();
    tmp -> value = value;
    tmp -> nextNode = NULL;
    walk -> nextNode = tmp;
    return head;
}
int josephus(Node* head, int numOfPeople, int pass)
{
	int choice = 1;
	Node* walk = head;
	while(walk -> nextNode != NULL) {
		if (choice == pass - 1) {
			if(walk -> nextNode -> nextNode -> value == walk -> value) {
				walk -> nextNode = NULL;
			} else {
				walk -> nextNode = walk -> nextNode -> nextNode;
				choice = 1;
				walk = walk -> nextNode;
			}
		}
		else
		{
			walk = walk -> nextNode;
			choice++;
		}
	}
	return walk -> value;
}
int josephus(int n, int k)
{
    if(n==1)
    {
        //Base case.
        return 1;
    }
    else
    {
        //recursive step.
        return (josephus(n-1,k)+k-1)%n+1;
    }
}
int main()
{
    int n, p;
    cin >> n >> p;
    Node* head = new Node(1);
    for(int i = 2; i <= n; i++)
    {
        head = addLastNode(head, i);
    }
    Node* walk = head;
    while(walk -> nextNode != NULL)
    {
        walk = walk -> nextNode;
    }
    walk -> nextNode = head;
    cout << josephus(head, n, p) << " " << josephus(n, p);
    return 0;
}
