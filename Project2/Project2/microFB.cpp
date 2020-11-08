#include "microFB.h"

using namespace std;


//Node ������ 
Node::Node(string& name, Node* next) {
	this->name = name;
	this->next = next;
}


//Social ������, head�� Ŀ���� NULL�� �ʱ�ȭ
Social::Social(){
	head = 0;
	cursor = 0;
}

//����Ʈ�� ���ο� ����� �߰��ϴ� �Լ�
void Social::MakePerson(string& name) {
	//���ο� ����� ��
	if (head == 0) {
		Node* newP = new Node(name, NULL); 
		head = newP;
		cursor = newP;
		cout << endl << "success!" << " Welcome " << name << "!" << endl << endl;
	}
	else {
		Node* newP = new Node(name, NULL);
		cursor->next = newP;
		cursor = newP;
		cout << endl << "success!" <<" Welcome "<<name<<"!"<<endl << endl;
	}
}

//ģ�� ����Ʈ�� ���
FriendNode::FriendNode(Node* newF, FriendNode* nextF) {
	fNode = newF;//ģ�� ��带 ����Ű�� ������
	FNext = nextF;//ģ�� ����Ʈ�� ��带 ����Ű�� ������
}

//Ŀ���� ����Ʈ�� ������ ����(���̴� ���� ����)
void Social::sendCursor2End() {
	Node* tmp = head;
	while (tmp->next != 0) {
		tmp = tmp->next;
	}
	cursor = tmp;
}

//�ش� �̸��� ���� ����� �ִ��� �˻�.
//����� Ŀ���� ����.
bool Social::Search(string& name) {
	Node* tmp;
	tmp = head;
	int a=0;
	while (tmp != 0) {
		//�Է� ���� string�̶� ��ġ�ϴ� ����� ã�� ��
		if (name == tmp->name) {
			a = 1;
			cursor = tmp;
			break;
		}
		//��ã�� ��
		else {
			tmp = tmp->next;
		}
	}
	return a;
}

//ģ�� �δ� �Լ�
bool Social::MakeFriend(string& name1, string& name2) {
	Node* tmp1;//name1
	Node* tmp2;//name2
	Node* tmp3 = cursor;
	if (!isFriend(name1, name2)) {//���� ģ���� �ƴ� ���
		// ���� �̸��� �ƴ� ���
		if (name1 != name2) {
			//Ŀ���� name1�� ���ϰ�
			if (Search(name1)) {
				tmp1 = cursor;
				//Ŀ���� name2�� ���ϰ�
				if (Search(name2)) {
					tmp2 = cursor;
					MakeFriendS(tmp1, tmp2);
					cursor = tmp3;
					return true;
				}
				else {//name2�� ��ã���� ��
					cout << "-------------------------------------------" << endl;
					cout << "cannot find " << name2 << endl;
					cout << "-------------------------------------------" << endl;
					return false;
				}
			}
			else {//name1�� ��ã���� ��
				cout << "-------------------------------------------" << endl;
				cout << "cannot find " << name1 << endl;
				cout << "-------------------------------------------" << endl;
				return false;
			}
		}
		else {
			cout << "-------------------------------------------" << endl;
			cout << "You Entered the Same Name! " << endl;
			cout << "-------------------------------------------" << endl;
			return false;
		}
	}
	else {
		cout << "-------------------------------------------" << endl;
		cout << name1 << " and " << name2 << " are Already Friends!" << endl;
		cout << "-------------------------------------------" << endl;
		return false;
	}
}


void Social::MakeFriendS(Node* p1, Node* p2) {
	FriendNode* tmp;
	//p1�� ģ���� ������...
	if (p1->myFriendHead == 0) {
		p1->myFriendHead = new FriendNode(p2,0);
		p1->myFriendCursor = p1->myFriendHead;
	}
	//ģ���� ���� ��
	else {
		tmp = new FriendNode(p2, 0);
		p1->myFriendCursor->FNext = tmp;
		p1->myFriendCursor = tmp;
	}

	tmp = 0;

	//p2�� ģ���� ������...
	if (p2->myFriendHead == 0) {
		p2->myFriendHead = new FriendNode(p1, 0);
		p2->myFriendCursor = p2->myFriendHead;
	}
	//p2�� ģ���� ������
	else {
		tmp = new FriendNode(p1, 0);
		p2->myFriendCursor->FNext = tmp;
		p2->myFriendCursor = tmp;
	}

	//Ŀ�� ���� �ٽ� ������ ����
	sendCursor2End();
}


bool Social::isFriend(string& name1, string& name2) {
	bool chk=0;
	Node* tmp1;
	Node* tmp2;
	FriendNode* tmp3;

	//name1�� ��带 ����Ű���� Ŀ���� ����
	if (Search(name1)) {
		tmp1 = cursor;
	}
	//���� �� ���� ��ȯ
	else {
		return false;
	}
	//name2�� ��带 ����Ű���� Ŀ���� ����
	if (Search(name2)){
		tmp2 = cursor;
	}
	else {
		return false;
	}

	tmp3 = tmp1->myFriendHead;

	//tmp2�� ����Ű�� ��带 ã��
	while (tmp3 != 0) {
		if (tmp3->fNode == tmp2) {
			chk = true;
			break;
		}
		tmp3 = tmp3->FriendNode::FNext;
	}

	//Ŀ���� ������
	sendCursor2End();
	return chk;
}

//ģ�� ����Ʈ ���
void Social::printFriend(string& name) {
	FriendNode* tmp;
	int cnt = 1;
	if (Search(name)) {

		cout << endl << "               " << name << "'s Friend List" << endl;
		cout << "-------------------------------------------" << endl;
		tmp = cursor->myFriendHead;
		while (tmp != 0) {
			cout <<cnt++<<". "<<tmp->fNode->name << endl;
			tmp = tmp->FNext;
			
		}
		cout << "-------------------------------------------" << endl;
	}
	else {
		cout << "No Such Name " << endl;
	}
	sendCursor2End();
}

//����Ʈ�� �������
bool Social::isEmpty() {
	if (head == 0) {
		return true;
	}
	else
		return false;
}

//����� ������
void Social::showMem()
{
	int cnt=1;
	Node* tmp = head;
	cout << "               Member List" << endl;
	cout << "-------------------------------------------" << endl;
	if (isEmpty() != 1) {
		while (tmp != 0) {
			cout <<" "<<cnt++<<". "<<tmp->name<< endl;
			tmp = tmp->next;
		}
	}
	else {
		cout << "  Empty" << endl;
	}
	cout << "-------------------------------------------" << endl;
}

//ģ�� ����
bool Social::UnFriend(string& name1, string& name2) {
	bool chk = 0;
	Node* tmp1;
	Node* tmp2;
	FriendNode* tmp3;
	FriendNode* Ptmp3=0;
	if (isFriend(name1,name2)) {
		if (Search(name1)) {
			tmp1 = cursor;
		}
		else {
			cout << "-------------------------------------------" << endl;
			cout << "cannot find " << name1 << endl;
			cout << "-------------------------------------------" << endl;
			return false;
		}
		if (Search(name2)) {
			tmp2 = cursor;
		}
		else {
			cout << "-------------------------------------------" << endl;
			cout << "cannot find " << name2 << endl;
			cout << "-------------------------------------------" << endl;
			return false;
		}


		//tmp1�� ģ�� ����
		tmp3 = tmp1->myFriendHead;
		while (tmp3 != 0) {
			if (tmp3->fNode == tmp2) {
				if (tmp3 == tmp1->myFriendHead) {
					tmp1->myFriendHead = tmp3->FNext;
					delete tmp3;
				}
				else {
					Ptmp3->FNext = tmp3->FNext;
					delete tmp3;
				}
				break;
			}
			Ptmp3 = tmp3;
			tmp3 = tmp3->FNext;
		}

		//tmp2�� ģ�� ����
		tmp3 = tmp2->myFriendHead;
		while (tmp3 != 0) {
			if (tmp3->fNode == tmp1) {
				if (tmp3 == tmp2->myFriendHead) {
					tmp2->myFriendHead = tmp3->FNext;
					delete tmp3;
					sendCursor2End();
					return true;
				}
				else {
					Ptmp3->FNext = tmp3->FNext;
					delete tmp3;
					sendCursor2End();
					return true;
				}
				break;
			}
			Ptmp3 = tmp3;
			tmp3 = tmp3->FNext;
		}
	}
	else {
		cout << "-------------------------------------------" << endl;
		cout << "You Entered the Wrong Value! " << endl;
		cout << "-------------------------------------------" << endl;
		return false;
	}

}