/*
 * Node.cpp
 *
 *  Created on: Mar 31, 2020
 *      Author: Hussein okasha
 */

#include "Node.h"
#include <iostream>
using namespace std;
Node::Node() {
	left=nullptr;
	right=nullptr;
	data=0;
}
Node::Node(int data):data{data}{
	left=nullptr;
	right=nullptr;
}

Node::~Node() {
	// TODO Auto-generated destructor stub
}

