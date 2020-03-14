//HW6 by Wanxiang Xie
//SU Net ID: wxie15  SUID: 408358088
//CSE674 HW6  Due: 11:59PM, Nov. 26 (Tuesday)
#include <iostream>
using namespace std;

class node {
public:
	node* p_parent;
	node* p_Lchild;
	node* p_Rchild;
	int value;
	bool color; //true: red, false: black
	node() { p_parent = p_Lchild = p_Rchild = nullptr; }
	node(int i) { value = i; p_parent = p_Lchild = p_Rchild = nullptr; }
};

class tree {
public:
	node* root;
	tree() { root = nullptr; }

	//For insert, the new node should be the last of nodes with the same value in the order of 
	//inorder traversal.  (The same as HW5.)
	void insert_node(int i);
	void insert_R_rotate(node* p);//For insert_node, R-rotate at node pointed by p
	void insert_L_rotate(node* p);//for insert_node, L-rotate at node pointed by p
	//All other siutions of insert_node should be directly implemented inside add_node


	//For delete, the deleted node shoud be the first of nodes with the same value in the order of
	//inorder traversal. (The same as HW5).
	//For replacement, always recursively replace it with predecessor, unless there is no predecessor. (In this
	//case, replace it with sucessor.)


	void delete_node(int i);
	void delete_1(node* p); //case 1 of delete_node; p points to the parent of double black node
	void delete_1_R_rotate(node* p);//R_totate used in case 1 of delete_node; p points to the parent of double black node
	void delete_1_L_rotate(node* p);//L_totate used in case 1 of delete_node; p points to the parent of double black node
	void delete_2A(node* p); //case 2A of delete_node; p points to the parent of double black node
	void delete_2B(node* p);//case 2B of delete_node; p points to the parent of double black node
	void delete_3(node* p);
	void Print_tree(int stage);
	//case 3 of delete_node; p points to the parent of double black node
	//All other cases of delete_node should be directly implemented inside the delete_node.

	//For the following, during traveral, print (value, color) of each node.
	void InorderPrint(node* p);
	void PostorderPrint(node* p);
	void PreorderPrint(node* p);
};

void tree::InorderPrint(node* p)
{
	if (p == nullptr) return;
	InorderPrint(p->p_Lchild);
	cout << "(" << p->value << "," << p->color << ")" << " ";
	InorderPrint(p->p_Rchild);
	if (p == root) {
		cout << endl;
	}
		
}

void tree::PostorderPrint(node* p)
{
	if (p == nullptr) return;
	PostorderPrint(p->p_Lchild);
	PostorderPrint(p->p_Rchild);
	cout << "(" << p->value << "," << p->color << ")" << " ";

}

void tree::PreorderPrint(node* p)
{
	if (p == nullptr) return;
	cout << "(" << p->value << "," << p->color << ")" << " ";
	PreorderPrint(p->p_Lchild);
	PreorderPrint(p->p_Rchild);

}

void tree::insert_node(int i)
{
	if (root == nullptr)
	{
		root = new node(i);
		//root->color = true;
	}
	else
	{
		node* p = root;
		node* p0 = p;
		while (p != nullptr) {
			p0 = p;
			if (i < p->value) {
				p = p->p_Lchild;
			}
			else {
				p = p->p_Rchild;
			}
		}

		//1 add red node
		if (i < p0->value) { //add lchild
			p0->p_Lchild = new node(i);
			p = p0->p_Lchild;
			p->p_parent = p0;
			p->color = true;
		}
		else  //add rchild
		{
			p0->p_Rchild = new node(i);
			p = p0->p_Rchild;
			p->p_parent = p0;
			p->color = true;
		}

		////////////////////
			while (p->p_parent != nullptr) { 
				// 2 if p is root, change it to black
				if (p == root)
					p->color = false;

				///3 if parent is red
				if (p->p_parent->color == true) {

					if (p->p_parent->p_parent) { // g node is existed

						node* grandpa = p->p_parent->p_parent;
						node* parent = p->p_parent;
						node* uncle;
						if (parent->value < grandpa->value) {
							uncle = grandpa->p_Rchild;
						}
						else
						{
							uncle = grandpa->p_Lchild;
						}

						auto u_color = [uncle]() {
							if (uncle == nullptr)
								return false;
							else
								return uncle->color;
						};

						if (u_color() == false) { //3.1 uncle node is black
							if (parent->value < grandpa->value)
							{
								if (p->value < parent->value) { //LL
									insert_R_rotate(grandpa);
									grandpa->color = true;
									parent->color = false;
									return;
								}
								else //LR
								{
									insert_L_rotate(parent);
									parent = p;
									insert_R_rotate(grandpa);
									grandpa->color = true;
									parent->color = false;
									return;
								}
							}
							else
							{
								if (p->value < parent->value) { //RL
									insert_R_rotate(parent);
									parent = p;
									insert_L_rotate(grandpa);
									//cout << "g:" << grandpa->value << " p:" << parent->value << " x:"<< p->value<<endl;
									grandpa->color = true;
									parent->color = false;
									return;

								}
								else //RR
								{
									insert_L_rotate(grandpa);
									grandpa->color = true;
									parent->color = false;
									return;
								}
							}
						}
						else //3.2  uncle node is red
						{
							//cout << "g:" << grandpa->value << " p:" << parent->value << " x:" << p->value << " u:" << uncle->value << endl;
							uncle->color = false;
							parent->color = false;
							grandpa->color = true;
							if (grandpa == root) {
								grandpa->color = false;
								return;
							}
							else //treat g as x
							{
								p = grandpa;
							}
						}
					}
					else { return; }
				}
				else { return; }  // parent is black
			}
			
	}
}

void tree::insert_R_rotate(node* p)
{
	node* p1 = p->p_Lchild;
	p->p_Lchild = p1->p_Rchild;
	if (p->p_Lchild != nullptr)
		p->p_Lchild->p_parent = p;

	if (p->p_parent != nullptr) {
		p1->p_parent = p->p_parent;
		if (p1->value < p1->p_parent->value) {
			p1->p_parent->p_Lchild = p1;
		}
		else {
			p1->p_parent->p_Rchild = p1;
		}
	}
	else {
		p1->p_parent = nullptr;
		root = p1;
	}
	p1->p_Rchild = p;
	p->p_parent = p1;
}

void tree::insert_L_rotate(node* p)
{
	node* p1 = p->p_Rchild;
	p->p_Rchild = p1->p_Lchild;
	if (p->p_Rchild != nullptr)
		p->p_Rchild->p_parent = p;

	if (p->p_parent != nullptr) {
		p1->p_parent = p->p_parent;
		if (p1->value < p1->p_parent->value) {
			p1->p_parent->p_Lchild = p1;
		}
		else {
			p1->p_parent->p_Rchild = p1;
		}
	}
	else {
		p1->p_parent = nullptr;
		root = p1;
	}
	p1->p_Lchild = p;
	p->p_parent = p1;

}

void tree::delete_node(int i)
{
	node* p = root;
	while (p)
	{
		if(i < p->value) {
			p = p->p_Lchild;
		}
		else if (i > p->value) {
		p = p->p_Rchild;
		}
		else { // i == p->value
			while (p->p_Lchild) { //delete rchild first if found
				if (i == p->p_Lchild->value)
					p = p->p_Lchild;
				else
					break;
			}
			break;
		}
	}
	if (p == nullptr) return; //not found delete node
	else
	{
		
		auto case2 = [](node* p) {
			if (p->p_Lchild == nullptr && p->p_Rchild == nullptr)
				return false;
			else if (p->p_Lchild && p->p_Rchild)
				return false;
			else {
				if (p->p_Lchild) {
					if (p->p_Lchild->p_Lchild == nullptr && p->p_Lchild->p_Rchild == nullptr) {
						if (p->color == p->p_Lchild->color) {
							return false;
						}
						else {
							return true;
						}
					}
					else
						return false;
				}
				else {
					if (p->p_Rchild->p_Lchild == nullptr && p->p_Rchild->p_Rchild == nullptr) {
						if (p->color == p->p_Rchild->color) {
							return false;
						}
						else {
							return true;
						}
					}
					else
						return false;
				}
			}
		};

		auto case3 = [](node* p) {
			if (p->color == false) {
				if (p->p_Lchild == nullptr && p->p_Rchild == nullptr) return true; // black leaf node
				else if (p->p_Lchild && p->p_Rchild) return false;
				else //black black
				{
					if(p->p_Lchild){
						if (p->p_Lchild->p_Lchild == nullptr && p->p_Lchild->p_Rchild == nullptr) {
							if (p->color == p->p_Lchild->color) { 
								return true;
							}
							else 
								return false;
						}
						else
							return false;
					}
					else
					{
						if (p->p_Rchild->p_Lchild == nullptr && p->p_Rchild->p_Rchild == nullptr) {
							if (p->color == p->p_Rchild->color) {
								return true;
							}
							else
								return false;
						}
						else
							return false;
					}
				}
			}
			else return false;
		};

		if (p->p_Lchild==nullptr && p->p_Rchild==nullptr && p->color == true) // case 1: delete red leaf node
		{
			//cout << "do delete red leaf node directly" << endl;
			 node* p0 = p->p_parent;
			 if (p0->p_Lchild == p) {
				 delete p;
				 p0->p_Lchild = nullptr;
			 }
			 else { //p0->p_Rchild == p
				 delete p;
				 p0->p_Rchild = nullptr;
			 }
			 
		}
		else if(case2(p)) //case 2 a singel leaf as child and the two have different colors
		{
			//cout << "do case2" << endl;
			//int replace_value;
			if (p->p_Lchild) {
				//replace_value = p->p_Lchild->value;
				p->value = p->p_Lchild->value;
				p->color = false;

				delete p->p_Lchild;
				p->p_Lchild = nullptr;

			}
			else
			{
				//replace_value = p->p_Rchild->value;
				p->value = p->p_Rchild->value;
				p->color = false;

				delete p->p_Rchild;
				p->p_Rchild = nullptr;
			}
			//p->value = replace_value;
		}
		else if(case3(p))  //case 3 
		{
			//cout << "do case3" << endl;

			if (p == root) {
				if (p->p_Lchild == nullptr && p->p_Rchild == nullptr) { // it is a leaf node
					delete p;
					root = nullptr;
					return;
				}
				else
				{
					if (p->p_Lchild) {
						p->value = p->p_Lchild->value;
						delete p->p_Lchild;
						p->p_Lchild = nullptr;
					}
					else //p->p_Rchild
					{
						p->value = p->p_Rchild->value;
						delete p->p_Rchild;
						p->p_Rchild = nullptr;
					}
					return;
				}
			}
			else { // p has parent
				node* parent = p->p_parent;
				bool sibling_color = false;
				node* sibling = nullptr;
				if (p->p_Lchild == nullptr && p->p_Rchild == nullptr) { 
					//cout << "delete black leaf node" << endl;

					if (parent->p_Lchild == p) {
						delete p;
						parent->p_Lchild = nullptr;
						if (parent->p_Rchild)
							sibling = parent->p_Rchild;
							//sibling_color = parent->p_Rchild->color;
					}
					else
					{
						delete p;
						parent->p_Rchild = nullptr;
						if (parent->p_Lchild)
							sibling = parent->p_Lchild;
							//sibling_color = parent->p_Lchild->color;
					}
					p = parent; //black or red

				}
				else
				{
					//cout << "do black black delete" << endl;

					if (p->p_Lchild) {
						p->value = p->p_Lchild->value;
						delete p->p_Lchild;
						p->p_Lchild = nullptr;
						if (p->p_Rchild)
							sibling = parent->p_Rchild;
							//sibling_color = p->p_Rchild->color;

					}
					else
					{
						p->value = p->p_Rchild->value;
						delete p->p_Rchild;
						p->p_Rchild = nullptr;
						if (p->p_Lchild)
							sibling = p->p_Lchild;
							//sibling_color = p->p_Lchild->color;
					}

				}
				
				//////////do violation; p is parent of nil double black
	
				auto color = [](node* p) {
					if (p == nullptr)
						return false;
					else
						return p->color;
					
				};

				auto delete2 = [color](node* p) {
					if (p == nullptr)
						return true;
					else if (color(p->p_Lchild) == false && color(p->p_Rchild) == false)
						return true;
					else
						return false;
				};

				while (true) {
					if (color(sibling) == false) { //sibling of double black is black
					//case1
						if (delete2(sibling) == false) {
							//cout << "do delete_1 violation:";
							if (p->p_Lchild == sibling) {
								if (color(sibling->p_Lchild) == true) { //LL pattern
									//cout << "LL pattern" << endl;
									delete_1_R_rotate(p);
									sibling->color = p->color;
									sibling->p_Lchild->color = false;
									p->color = false;
								}
								else //LR pattern
								{
									//do first rotate
									//cout << "LR pattern" << endl;
									sibling->p_Rchild->color = false;
									delete_1_L_rotate(sibling);
									sibling->color = true;

									sibling = p->p_Lchild;

									//do second rotate
									//LL pattern
									delete_1_R_rotate(p);
									sibling->color = p->color;
									sibling->p_Lchild->color = false;
									p->color = false;
								}

							}
							else
							{
								if (color(sibling->p_Rchild) == true) { //RR pattern
									//cout << "RR pattern" << endl;
									delete_1_L_rotate(p);
									//cout << "p:" << p->value << " s:" << sibling->value << endl;
									sibling->color = p->color;
									sibling->p_Rchild->color = false;
									p->color = false;
								}
								else //RL pattern
								{
									//do first rotate
									//cout << "RL pattern" << endl;
									sibling->p_Lchild->color = false;
									delete_1_R_rotate(sibling);
									sibling->color = true;

									sibling = p->p_Rchild;
									//cout << "p:" << p->value << " s:" << sibling->value << endl; 

									//do second rotate
									//RR pattern
									delete_1_L_rotate(p);
									sibling->color = p->color;
									sibling->p_Rchild->color = false;
									p->color = false;
									//cout << "p:" << p->value << " s:" << sibling->value << endl;

								}
							}
							return;
						}
						else //case2 
						{
							if (color(p) == false) { //2a
								//cout << "do delete_2a violation" << endl;
								node* doubleblack = p;
								delete_2A(p);
								p = p->p_parent;
								if (p == nullptr) return;
								//change sibling	
								if (p->p_Lchild == doubleblack) sibling = p->p_Rchild;
								else sibling = p->p_Lchild;

							}
							else //2b
							{
								//cout << "do delete_2b violation" << endl;
								delete_2B(p);
								return;
							}
						}
					}
					else { //case 3
						//cout << "do delete_3 violation" << endl;
						delete_3(p);
						return;
					}
				}


			}
		}
		else // need to find predecessor or successor
		{
			//cout << "do replace" << endl;
			node* p_replace = p;

			if (p_replace->p_Lchild) { // if predecessor is existed
				p_replace = p_replace->p_Lchild;
				while (p_replace->p_Rchild) {
					p_replace = p_replace->p_Rchild;
				}

			}
			else //find successor
			{
	
				p_replace = p_replace->p_Rchild;
				while (p_replace->p_Lchild) {
					p_replace = p_replace->p_Lchild;
				}
			}
			//replace by predecessor or successor 
			int replace_value = p_replace->value;
			delete_node(p_replace->value);//delete predecessor or successor
			p->value = replace_value;
		}
	}

}

void tree::delete_1(node* p)
{
}

void tree::delete_1_L_rotate(node* p)
{
	node* p1 = p->p_Rchild;
	p->p_Rchild = p1->p_Lchild;
	if (p->p_Rchild != nullptr)
		p->p_Rchild->p_parent = p;

	if (p->p_parent != nullptr) {
		p1->p_parent = p->p_parent;
		if (p1->value < p1->p_parent->value) {
			p1->p_parent->p_Lchild = p1;
		}
		else {
			p1->p_parent->p_Rchild = p1;
		}
	}
	else {
		p1->p_parent = nullptr;
		root = p1;
	}
	p1->p_Lchild = p;
	p->p_parent = p1;

}

void tree::delete_1_R_rotate(node* p)
{
	node* p1 = p->p_Lchild;
	p->p_Lchild = p1->p_Rchild;
	if (p->p_Lchild != nullptr)
		p->p_Lchild->p_parent = p;

	if (p->p_parent != nullptr) {
		p1->p_parent = p->p_parent;
		if (p1->value < p1->p_parent->value) {
			p1->p_parent->p_Lchild = p1;
		}
		else {
			p1->p_parent->p_Rchild = p1;
		}
	}
	else {
		p1->p_parent = nullptr;
		root = p1;
	}
	p1->p_Rchild = p;
	p->p_parent = p1;
}

void tree::delete_2A(node* p)
{
	if (p->p_Lchild) {
		p->p_Lchild->color = true;
	}
	else if (p->p_Rchild) {
		p->p_Rchild->color = true;
	}
	//p = p->p_parent; ///!

}

void tree::delete_2B(node* p)
{
	p->color = false;
	if (p->p_Lchild)
		p->p_Lchild->color = true;
	else if(p->p_Rchild)
	{
		p->p_Rchild->color = true;
	}

}

void tree::delete_3(node* p)
{

	//perform a roate, and let it become condition 1 or condition 2
	node* s;

	if (p->p_Lchild && p->p_Lchild->color ==true) { // L
		s = p->p_Lchild;
		if (s->p_Lchild) { //LL pattern
			delete_1_R_rotate(p);
			p->color = true;
			s->color = false;
			//update sibling
			s = s->p_Lchild;
		}
		else if(s->p_Rchild)//LR pattern
		{

			//do first rotate
			//cout << "LR pattern" << endl;
			s->p_Rchild->color = true;
			delete_1_L_rotate(s);
			s->color = false;

			//update sibling
			s = p->p_Lchild;
			//do second rotate
			//LL pattern
			delete_1_R_rotate(p);
			p->color = true;
			s->color = false;
			//update sibling
			s = s->p_Lchild;

		}

	}
	else { // R
		s = p->p_Rchild;
		if (s->p_Rchild) { //RR pattern
			delete_1_L_rotate(p);
			p->color = true;
			s->color = false;
			//update sibling
			s = s->p_Rchild;
		}
		else if(s->p_Lchild) //RL pattern
		{
			//do first rotate
			//cout << "RL pattern" << endl;
			s->p_Lchild->color = true;
			delete_1_R_rotate(s);
			s->color = false;
			//update sibling
			s = p->p_Rchild;
			//do second rotate
			//RR pattern
			delete_1_L_rotate(p);
			p->color = true;
			s->color = false;
			//update sibling
			s = s->p_Rchild;
		}
	}
	//decide it is contition 1 or condition 2

	node* sibling = s;
	auto color = [](node* p) {
		if (p == nullptr)
			return false;
		else
			return p->color;

	};

	auto delete2 = [color](node* p) {
		if (p == nullptr)
			return true;
		else if (color(p->p_Lchild) == false && color(p->p_Rchild) == false)
			return true;
		else
			return false;
	};
	while (true) {
		if (color(sibling) == false) { //sibling of double black is black
		//case1
			if (delete2(sibling) == false) {
				//cout << "do delete_1 violation:";
				if (p->p_Rchild == nullptr) {
					if (color(sibling->p_Lchild) == true) { //LL pattern
						//cout << "LL pattern" << endl;
						delete_1_R_rotate(p);
						sibling->color = p->color;
						sibling->p_Lchild->color = false;
						p->color = false;
					}
					else //LR pattern
					{
						//do first rotate
						//cout << "LR pattern" << endl;
						sibling->p_Rchild->color = false;
						delete_1_L_rotate(sibling);
						sibling->color = true;

						sibling = p->p_Lchild;

						//do second rotate
						//LL pattern
						delete_1_R_rotate(p);
						sibling->color = p->color;
						sibling->p_Lchild->color = false;
						p->color = false;
					}

				}
				else
				{
					if (color(sibling->p_Rchild) == true) { //RR pattern
						//cout << "RR pattern" << endl;
						delete_1_L_rotate(p);
						//cout << "p:" << p->value << " s:" << sibling->value << endl;
						sibling->color = p->color;
						sibling->p_Rchild->color = false;
						p->color = false;
					}
					else //RL pattern
					{
						//do first rotate
						//cout << "RL pattern" << endl;
						sibling->p_Lchild->color = false;
						delete_1_R_rotate(sibling);
						sibling->color = true;

						sibling = p->p_Rchild;
						//cout << "p:" << p->value << " s:" << sibling->value << endl; 

						//do second rotate
						//RR pattern
						delete_1_L_rotate(p);
						sibling->color = p->color;
						sibling->p_Rchild->color = false;
						p->color = false;
						//cout << "p:" << p->value << " s:" << sibling->value << endl;

					}

				}

				return;
			}
			else //case2 
			{
				if (color(p) == false) { //2a
					//cout << "do delete_2a violation" << endl;
					node* doubleblack = p;
					delete_2A(p);
					p = p->p_parent;
					if (p == nullptr) return;
					//change sibling	
					if (p->p_Lchild == doubleblack) sibling = p->p_Rchild;
					else sibling = p->p_Lchild;

				}
				else //2b
				{
					//cout << "do delete_2b violation" << endl;
					delete_2B(p);
					return;
				}
			}
		}
		else { //case 3
			//cout << "do delete_3 violation" << endl;
			delete_3(p);
			return;
		}
	}

}
void tree::Print_tree(int stage)
{
	auto twoto = [](int i) {
		int sum = 1;
		while (i) { sum *= 2; i--; }
		return sum;
	};
	auto judgeside = [](int left, int num, int right) {
		int length = right - left + 1;
		if (num < (left + length / 2))return 1; else return 0;
	};
	auto judgelev = [twoto](int i) {
		int level = 1;
		while (twoto(level) - 1 <= i) { level++; }
		return level;
	};
	auto moveto = [twoto, judgeside, judgelev, this](int i) {
		if (i == 0)return root; else;
		node* p = root;
		int level = judgelev(i);
		int left = twoto(level - 1) - 1;
		int right = twoto(level) - 2;
		while (1) {
			if (p == nullptr)break; else;
			if (judgeside(left, i, right)) {
				p = p->p_Lchild;
				if (right - left == 1)break; else;
				right = right - (right - left + 1) / 2;
			}
			else {
				p = p->p_Rchild;
				if (right - left == 1)break; else;
				left = left + (right - left + 1) / 2;
			}
		}
		return p;
	};
	auto print = [](node* p) {
		if (p == nullptr) { cout << "       "; return; }
		else;
		if (p->value < 10)cout << "  "; else;
		if (p->value >= 10 && p->value < 100)cout << " "; else;
		cout << "(" << p->value << "," << p->color << ")";

	};
	cout << "RB_tree:" << endl << endl;
	if (root == nullptr)return; else;
	int n, k, m, width, stage2;
	stage2 = stage;
	width = 7;
	n = 0;

	for (int i = 1; i <= twoto(stage) - 1; i *= 2)
	{
		m = twoto(stage2 - 1) - 1;
		for (int j = 0; j < i; j++)
		{
			if (j == 0)for (int k = 0; k < width * m / 2; k++)cout << " "; else;
			print(moveto(n));
			if (j != i - 1)for (int k = 0; k < width * m; k++)cout << " ";
			n++;
		}
		stage2--;
		cout << endl;
	}
	cout << endl;
}

//12   1   9   2   0   11   7   19   4   15   18   5   14   13   10   16   6   3   8   17
int main() {
	tree t1;
	t1.insert_node(12);
	t1.InorderPrint(t1.root);
	t1.insert_node(1);
	t1.InorderPrint(t1.root);
	t1.insert_node(9);
	t1.InorderPrint(t1.root);
	t1.insert_node(2);
	t1.InorderPrint(t1.root);
	t1.insert_node(0);
	t1.InorderPrint(t1.root);
	t1.insert_node(11);
	t1.InorderPrint(t1.root);
	t1.insert_node(7);
	t1.InorderPrint(t1.root);
	t1.insert_node(19);
	t1.InorderPrint(t1.root);
	t1.insert_node(4);
	t1.InorderPrint(t1.root);
	t1.insert_node(15);
	t1.InorderPrint(t1.root);
	t1.insert_node(18);
	t1.InorderPrint(t1.root);
	t1.insert_node(5);
	t1.InorderPrint(t1.root);
	t1.insert_node(14);
	t1.InorderPrint(t1.root);
	t1.insert_node(13);
	t1.InorderPrint(t1.root);
	t1.insert_node(10);
	t1.InorderPrint(t1.root);
	t1.insert_node(16);
	t1.InorderPrint(t1.root);
	t1.insert_node(6);
	t1.InorderPrint(t1.root);
	t1.insert_node(3);
	t1.InorderPrint(t1.root);
	t1.insert_node(8);
	t1.InorderPrint(t1.root);
	t1.insert_node(17);
	t1.InorderPrint(t1.root);
	
	t1.PreorderPrint(t1.root);
	cout << endl;
	t1.PostorderPrint(t1.root);
	cout << endl;
	t1.delete_node(12);
	t1.InorderPrint(t1.root);
	t1.delete_node(1);
	t1.InorderPrint(t1.root);
	t1.delete_node(9);
	t1.InorderPrint(t1.root);
	t1.delete_node(3);
	t1.InorderPrint(t1.root);
	t1.delete_node(0);
	t1.InorderPrint(t1.root);
	t1.delete_node(2);
	t1.InorderPrint(t1.root);
	t1.delete_node(5);
	t1.InorderPrint(t1.root);
	t1.delete_node(4);
	t1.InorderPrint(t1.root);
	t1.delete_node(15);
	t1.delete_node(17);
	t1.InorderPrint(t1.root);
	t1.delete_node(7);
	t1.InorderPrint(t1.root);
	t1.delete_node(19);
	t1.InorderPrint(t1.root);
	t1.delete_node(14);
	t1.InorderPrint(t1.root);
	t1.delete_node(18);
	t1.InorderPrint(t1.root);
	t1.delete_node(11);
	t1.InorderPrint(t1.root);
	t1.delete_node(8);
	t1.InorderPrint(t1.root);
	t1.delete_node(16);
	t1.InorderPrint(t1.root);
	t1.delete_node(10);
	t1.InorderPrint(t1.root);
	t1.delete_node(6);
	t1.InorderPrint(t1.root);
	t1.delete_node(13);
	t1.InorderPrint(t1.root);
	cin.get();
	return 0;
}

