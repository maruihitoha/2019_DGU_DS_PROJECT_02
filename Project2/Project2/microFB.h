#ifndef MICROFB_H
#define MICROFB_H
#pragma once
#include <iostream>
#include <string>
using namespace std;

class FriendNode;
class Node {
public:
	Node(string& name, Node* next);
	string name;
	FriendNode* myFriendHead=0;
	FriendNode* myFriendCursor=0;
	Node* next;
	friend class Social;
	friend class FriendNode;
	friend class Node;
};

class FriendNode {	
public:
	FriendNode(Node* newF, FriendNode* nextF);
	Node* fNode;
	FriendNode* FNext;
	
};

class Social {
public:
	Social();
	void MakePerson(string& name);
	bool MakeFriend(string& name1, string& name2);
	bool Search(string& name);
	void MakeFriendS(Node* p1, Node* p2);
	bool UnFriend(string& name1, string& name2);
	void printFriend(string& name);
	bool isFriend(string& name1, string& name2);
	void showMem();
	bool isEmpty();
	void sendCursor2End();

	
private:
	Node* head;
	Node* cursor;

};

#endif // !MICROFB_H