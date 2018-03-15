MainProgram: Main.cpp Node.cpp BTree5.cpp  BTreeNode.cpp AVL.cpp
	g++ -std=c++11 -o MainProgram Node.cpp BTreeNode.cpp Main.cpp BTree5.cpp AVL.cpp -lstdc++fs