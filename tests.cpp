// test file - do not modify
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <ctime>
#include <iostream>
using namespace std;

#include "BSTLab1.cpp" 

Node* secondTree() {
	Node* root = new Node(6);
	root->left = new Node(2);
	root->right = new Node(12);

	root->left->left = new Node(-1);
	root->left->right = new Node(4);

	root->right->left = new Node(9);
	root->right->right = new Node(16);

	root->left->left->left = new Node(-3);
	root->left->left->right = new Node(1);

	root->left->right->left = new Node(3);
	root->left->right->right = new Node(5);

	root->right->left->left = new Node(8);
	root->right->left->right = new Node(11);

	root->right->right->left = new Node(13);
	root->right->right->right = new Node(20);

    return root;
}

TEST_CASE("Node") {
    // Test needs to be updated
    Node myNode = Node(7); 
    Node *otherNode = new Node(10);
    myNode.left = otherNode;
    myNode.right = otherNode;

    REQUIRE_NOTHROW(Node(-2));

    cout << "Node value: " << myNode.key << endl;
    REQUIRE(myNode.left == otherNode);
    REQUIRE(myNode.right == otherNode);

    delete otherNode;
}

TEST_CASE("createTree") {
    Node *root = createTree();
	REQUIRE_NOTHROW(createTree());
}

TEST_CASE("searchTree") {
    Node *root = createTree();
    Node *root2 = secondTree();

    // found
    CHECK(searchTree(99, root));
    CHECK(searchTree(12, root2));

    // not found
    CHECK(!searchTree(1, root));
    CHECK(!searchTree(10, root2));
}

TEST_CASE("treeSize") {
    Node *root = createTree();
    Node *root2 = secondTree();
    Node *nullRoot = nullptr;

    CHECK(treeSize(root) == 12);
    CHECK(treeSize(root2) == 15);
    REQUIRE_NOTHROW(treeSize(nullRoot));

    CHECK(!treeSize(nullRoot));
    nullRoot = new Node(7);

    CHECK(treeSize(nullRoot) == 1);

    delete nullRoot;
}

TEST_CASE("treeHeight") {
    Node *root = createTree();
    Node *root2 = secondTree();
    Node *nullRoot = new Node(7);
    Node *newNode = new Node(10);

    CHECK(treeHeight(root) == 4);
    CHECK(treeHeight(root2) == 3);

    CHECK(!treeHeight(nullRoot));

    nullRoot->left = newNode;

    CHECK(treeHeight(nullRoot) == 1);

    delete nullRoot;
    delete newNode;
}