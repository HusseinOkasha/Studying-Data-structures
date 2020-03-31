/*
 * Node.h
 *
 *  Created on: Mar 31, 2020
 *      Author: Hussein Okasha
 */

#ifndef NODE_H_
#define NODE_H_

class Node {
public:
	int data;
	Node *left;
	Node *right;
	Node();
	Node(int data);
	~Node();
};

#endif /* NODE_H_ */
