// Use this file to try out any of your code
// use "make demo" to run this code anytime
#include <iostream>
using namespace std;

#include "BSTLab1.cpp"

int main()
{
	Node* root = createTree();
	
	cout<< "Size of tree is 12; your output is: "<< treeSize(root) <<endl;
	cout << "Height of tree is 4; your output is: " << treeHeight(root) << endl;
	
	if (searchTree(99, root))
		cout << " Well Done! 99 is in the binary search tree" << endl;
	else
		cout << "Incorrect!" << endl;

	if (!searchTree(1, root))
		cout << " Well Done! 1 is not in the binary search tree" << endl;
	else
		cout << "Incorrect!" << endl;
}