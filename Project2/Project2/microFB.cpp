#include "microFB.h"

using namespace std;


//Node 생성자 
Node::Node(string& name, Node* next) {
	this->name = name;
	this->next = next;
}


//Social 생성자, head와 커서는 NULL로 초기화
Social::Social(){
	head = 0;
	cursor = 0;
}

//리스트에 새로운 사람을 추가하는 함수
void Social::MakePerson(string& name) {
	//새로운 노드일 시
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

//친구 리스트용 노드
FriendNode::FriendNode(Node* newF, FriendNode* nextF) {
	fNode = newF;//친구 노드를 가리키는 포인터
	FNext = nextF;//친구 리스트의 노드를 가리키는 포인터
}

//커서를 리스트의 끝으로 보냄(꼬이는 것을 방지)
void Social::sendCursor2End() {
	Node* tmp = head;
	while (tmp->next != 0) {
		tmp = tmp->next;
	}
	cursor = tmp;
}

//해당 이름을 가진 사람이 있는지 검색.
//존재시 커서로 지정.
bool Social::Search(string& name) {
	Node* tmp;
	tmp = head;
	int a=0;
	while (tmp != 0) {
		//입력 받은 string이랑 일치하는 사람을 찾을 시
		if (name == tmp->name) {
			a = 1;
			cursor = tmp;
			break;
		}
		//못찾을 시
		else {
			tmp = tmp->next;
		}
	}
	return a;
}

//친구 맺는 함수
bool Social::MakeFriend(string& name1, string& name2) {
	Node* tmp1;//name1
	Node* tmp2;//name2
	Node* tmp3 = cursor;
	if (!isFriend(name1, name2)) {//둘이 친구가 아닐 경우
		// 같은 이름이 아닐 경우
		if (name1 != name2) {
			//커서를 name1을 향하게
			if (Search(name1)) {
				tmp1 = cursor;
				//커서를 name2을 향하게
				if (Search(name2)) {
					tmp2 = cursor;
					MakeFriendS(tmp1, tmp2);
					cursor = tmp3;
					return true;
				}
				else {//name2를 못찾았을 시
					cout << "-------------------------------------------" << endl;
					cout << "cannot find " << name2 << endl;
					cout << "-------------------------------------------" << endl;
					return false;
				}
			}
			else {//name1을 못찾았을 시
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
	//p1의 친구가 없을시...
	if (p1->myFriendHead == 0) {
		p1->myFriendHead = new FriendNode(p2,0);
		p1->myFriendCursor = p1->myFriendHead;
	}
	//친구가 있을 시
	else {
		tmp = new FriendNode(p2, 0);
		p1->myFriendCursor->FNext = tmp;
		p1->myFriendCursor = tmp;
	}

	tmp = 0;

	//p2의 친구가 없을시...
	if (p2->myFriendHead == 0) {
		p2->myFriendHead = new FriendNode(p1, 0);
		p2->myFriendCursor = p2->myFriendHead;
	}
	//p2의 친구가 있을시
	else {
		tmp = new FriendNode(p1, 0);
		p2->myFriendCursor->FNext = tmp;
		p2->myFriendCursor = tmp;
	}

	//커서 값을 다시 끝으로 보냄
	sendCursor2End();
}


bool Social::isFriend(string& name1, string& name2) {
	bool chk=0;
	Node* tmp1;
	Node* tmp2;
	FriendNode* tmp3;

	//name1의 노드를 가리키도록 커서를 보냄
	if (Search(name1)) {
		tmp1 = cursor;
	}
	//없을 시 거짓 반환
	else {
		return false;
	}
	//name2의 노드를 가리키도록 커서를 보냄
	if (Search(name2)){
		tmp2 = cursor;
	}
	else {
		return false;
	}

	tmp3 = tmp1->myFriendHead;

	//tmp2를 가리키는 노드를 찾음
	while (tmp3 != 0) {
		if (tmp3->fNode == tmp2) {
			chk = true;
			break;
		}
		tmp3 = tmp3->FriendNode::FNext;
	}

	//커서를 끝으로
	sendCursor2End();
	return chk;
}

//친구 리스트 출력
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

//리스트가 비었는지
bool Social::isEmpty() {
	if (head == 0) {
		return true;
	}
	else
		return false;
}

//멤버를 보여줌
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

//친구 해제
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


		//tmp1의 친구 제거
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

		//tmp2의 친구 제거
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