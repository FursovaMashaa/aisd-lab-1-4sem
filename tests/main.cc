#pragma once
#include<tree.cpp>
using namespace function;
int main()
{
	vector<int> a = { 1, 5, 7, 2, 2, 7};
	vector<int>dubl_a = findDuplicates<int>(a);
	for (int i = 0; i < size(dubl_a); i++) {
		cout << dubl_a[i] << endl;
	}
	

	cout << "---------------" << endl;
	MySet<int> tree1;
	MySet<int> tree2;
	

	tree1.insert(7);
	tree1.insert(2);
	tree1.insert(8);
	tree1.insert(20);
	tree1.insert(5);
	tree1.insert(190);
	tree1.print();
	cout << " - tree 1" << endl;
	
	tree2.insert(7);
	tree2.insert(2);
	tree2.insert(8);
	tree2.insert(20);
	tree2.insert(5);
	tree2.insert(190);
	tree2.erase(8);
	tree2.print();
	cout << " - tree 2" << endl;
	if (tree2.contains(7)) {
		cout << "7 is in the tree" << endl;
	}
	else {
		cout << "7 isn't in the tree" << endl;
	}
	if (tree2.contains(29)) {
		cout << "29 is in the tree" << endl;
	}
	else {
		cout << "29 isn't in the tree" << endl;
	}
	cout << endl;


	/*tree.fillTreeWithRandomNumbers(1000);
	tree.fillTreeWithRandomNumbers(10000);
	tree.fillTreeWithRandomNumbers(100000);

	tree.containsTreeWithRandomNumbers(1000);
	tree.containsTreeWithRandomNumbers(10000);
	tree.containsTreeWithRandomNumbers(100000);

	tree.insertTreeWithRandomNumbers(1000);
	tree.insertTreeWithRandomNumbers(10000);
	tree.insertTreeWithRandomNumbers(100000);

	tree.eraseTreeWithRandomNumbers(1000);
	tree.eraseTreeWithRandomNumbers(10000);
	tree.eraseTreeWithRandomNumbers(100000);*/
	/*cout << "done" << endl;*/
		/*Time spent filling in the tree 1000 numbers: 0.00174087 seconds
			Time spent filling in the vec 1000 numbers: 0.000335153 seconds

			Time spent filling in the tree 10000 numbers: 0.032735 seconds
			Time spent filling in the vec 10000 numbers: 0.00488475 seconds

			Time spent filling in the tree 100000 numbers: 0.105049 seconds
			Time spent filling in the vec 100000 numbers: 0.0187753 seconds

			Time taken to contains the tree with 1000 numbers: 9.039e-07 seconds
			Time taken to contains the vec with 1000 numbers: 0.000217975 seconds

			Time taken to contains the tree with 10000 numbers: 1.2142e-06 seconds
			Time taken to contains the vec with 10000 numbers: 0.00184237 seconds

			Time taken to contains the tree with 100000 numbers: 8.426e-07 seconds
			Time taken to contains the vec with 100000 numbers: 0.0179438 seconds

			Time taken to insert the tree with 1000  numbers: 1.0875e-06 seconds
			Time taken to insert the vec with 1000  numbers: 2.568e-07 seconds

			Time taken to insert the tree with 10000  numbers: 9.466e-07 seconds
			Time taken to insert the vec with 10000  numbers: 3.655e-07 seconds

			Time taken to insert the tree with 100000  numbers: 1.0586e-06 seconds
			Time taken to insert the vec with 100000  numbers: 5.927e-07 seconds

			Time taken to erase the tree with 1000 numbers: 1.4297e-06 seconds
			Time taken to erase the vec with 1000 numbers: 5.5068e-06 seconds

			Time taken to erase the tree with 10000 numbers: 1.6407e-06 seconds
			Time taken to erase the vec with 10000 numbers: 5.69672e-05 seconds

			Time taken to erase the tree with 100000 numbers: 1.3198e-06 seconds
			Time taken to erase the vec with 100000 numbers: 0.000451925 seconds*/
	return 0;
}