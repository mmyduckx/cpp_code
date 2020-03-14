//HW5 by Wanxiang Xie
//SU Net ID: wxie15  SUID: 408358088
//HW5  AVL Tree
//Due: Friday (Nov. 8) at 11:59PM
//55 points
//This homework requires more efforts. You should get started as soon as possible.

#include <iostream> //to use cout
#include <algorithm> //to use max function such as  i = max(a, b);

using namespace std;

//You need to use the following node class for each node of the AVL tree
class node {
public:
	int value;
	int height;//this is tree height. Leaf node is 1; empty node (i.e., NIL) is 0
	node* parent;
	node* l_child;
	node* r_child;
	node() {}
	node(int i) { value = i; height = 1; parent = l_child = r_child = nullptr; }

};

class avl_tree {
public:
	node* root;
	avl_tree() {
		root = nullptr;
	}

	//************************************************************************************
	//Implement the following member functions
	void add_node(int i);
	//if case of a tie, add i to the last of existing nodes with value i in the in-order sequence

	void delete_node(int i);
	//Delete the node with value i.  in case of multiple nodes with value i, delete the first node with value i in the in-order traveral sequence


	void in_order_traversal(node* p); //such as 2 5 9 11 11 14 15 15 ...

	pair<node*, int> height_update(node* p);
	/*
	This function will be invoked by add_node and delete_node.
	p points to the first node that we need to check for possible height update.  We then need to check possible height update toward root.
	All nodes whose heights need to be updated will be performed in this function.
	The function returns a pair.  If no imbalance is detected, the first of the pair will be nullptr; otherwise it will be the address of the action node.
	The second of the pair will be 0 if no imbalance is detected; otherwise its value is 1,2,3,4 for RR RL, LL, and LR pattern, respectively.
	*/

	void L_Rotate(node* p);
	//p points to the node at which the rotation will be performed.

	void R_Rotate(node* p);
	//p points to the node at which the rotation will be performed.

};

void avl_tree::in_order_traversal(node*
	p)
{
	if (p == nullptr) return;
	in_order_traversal(p->l_child);
	cout << "(" << p->value << "," << p->height << ")" << " ";
	//cout << p->value << " ";
	//cout << p->value << ":" << p->height << ":" << height_update(p).second << " ";
	in_order_traversal(p->r_child);

	if (p == root) {
		cout << endl;
	}

}

pair<node*, int> avl_tree::height_update(node* p)
{
	if (p == nullptr) return  pair<node*, int>(nullptr, 0);

	node* update = p;
	/*node* parent = p->parent;
	*/
	while (update) {
		if (update->l_child && update->r_child) {
			update->height = max(update->l_child->height, update->r_child->height) + 1;
		}
		else if (update->l_child) {
			update->height = update->l_child->height + 1;
		}
		else if (update->r_child) {
			update->height = update->r_child->height + 1;
		}
		else
			update->height = 1;

		update = update->parent;
	}

	if (p->l_child && p->r_child) {
		if (p->l_child->height - p->r_child->height > 1) { //L pattern
			if (p->l_child->l_child && p->l_child->r_child) {
				if (p->l_child->l_child->height >= p->l_child->r_child->height) { //LL
					return  pair<node*, int>(p, 3);
				}
				else //LR
				{
					return  pair<node*, int>(p, 4);
				}
			}
			else if (p->l_child->l_child) { //LL
				return  pair<node*, int>(p, 3);
			}
			else if (p->l_child->r_child) { //LR
				return  pair<node*, int>(p, 4);
			}
			else {
				return  pair<node*, int>(nullptr, 0);
			}

		}
		else if (p->l_child->height - p->r_child->height < -1) { //R pattern
			if (p->r_child->l_child && p->r_child->r_child) {
				if (p->r_child->r_child->height >= p->r_child->l_child->height) { //RR
					return  pair<node*, int>(p, 1);
				}
				else { //RL
					return  pair<node*, int>(p, 2);
				}
			}
			else if (p->r_child->l_child) { //RL
				return  pair<node*, int>(p, 2);
			}
			else if (p->r_child->r_child) { //RR
				return  pair<node*, int>(p, 1);
			}
			else
			{
				return  pair<node*, int>(nullptr, 0);
			}
		}
		else { //no violation
			return  pair<node*, int>(nullptr, 0);
		}

	}
	else if (p->l_child) {
		if (p->l_child->height > 1) { //L pattern
			if (p->l_child->l_child && p->l_child->r_child) {
				if (p->l_child->l_child->height >= p->l_child->r_child->height) { //LL
					return  pair<node*, int>(p, 3);
				}
				else //LR
				{
					return  pair<node*, int>(p, 4);
				}
			}
			else if (p->l_child->l_child) { //LL
				return  pair<node*, int>(p, 3);
			}
			else if (p->l_child->r_child) { //LR
				return  pair<node*, int>(p, 4);
			}
			else {
				return  pair<node*, int>(nullptr, 0);
			}

		}
		else
		{
			return  pair<node*, int>(nullptr, 0);
		}
	}
	else if (p->r_child) {
		if (p->r_child->height > 1) { //R pattern
			if (p->r_child->l_child && p->r_child->r_child) {
				if (p->r_child->r_child->height >= p->r_child->l_child->height) { //RR
					return  pair<node*, int>(p, 1);
				}
				else { //RL
					return  pair<node*, int>(p, 2);
				}
			}
			else if (p->r_child->l_child) { //RL
				return  pair<node*, int>(p, 2);
			}
			else if (p->r_child->r_child) { //RR
				return  pair<node*, int>(p, 1);
			}
			else
			{
				return  pair<node*, int>(nullptr, 0);
			}
		}
		else
		{
			return  pair<node*, int>(nullptr, 0);
		}
	}
	else //no violation
	{
		return  pair<node*, int>(nullptr, 0);
	}

}

void avl_tree::L_Rotate(node* p)
{
	node* p1 = p->r_child;
	p->r_child = p1->l_child;
	if (p->r_child != nullptr)
		p->r_child->parent = p;

	if (p->parent != nullptr) {
		p1->parent = p->parent;
		if (p1->value < p1->parent->value) {
			p1->parent->l_child = p1;
		}
		else {
			p1->parent->r_child = p1;
		}
	}
	else {
		p1->parent = nullptr;
		root = p1;
	}

	p1->l_child = p;
	p->parent = p1;

}

void avl_tree::R_Rotate(node* p)
{
	node* p1 = p->l_child;
	p->l_child = p1->r_child;
	if (p->l_child != nullptr)
		p->l_child->parent = p;

	if (p->parent != nullptr) {
		p1->parent = p->parent;
		if (p1->value < p1->parent->value) {
			p1->parent->l_child = p1;
		}
		else {
			p1->parent->r_child = p1;
		}
	}

	else {
		p1->parent = nullptr;
		root = p1;
	}
	p1->r_child = p;
	p->parent = p1;

}

void avl_tree::add_node(int i)
{

	if (root == nullptr) {
		root = new node(i);
	}
	else {
		node* p = root;
		node* p0 = p;
		while (p != nullptr) {
			p0 = p;
			if (i < p->value) {
				p = p->l_child;
			}
			else {
				p = p->r_child;
			}
		}
		//add node
		if (i < p0->value) {
			p0->l_child = new node(i);
			p0->l_child->parent = p0;
			height_update(p0);
		}
		else {
			p0->r_child = new node(i);
			p0->r_child->parent = p0;
			height_update(p0);
		}
		//check violation
		node* p_check = p0;
		while (p_check) {
			if (height_update(p_check).first != nullptr) {
				int pattern = height_update(p_check).second;
				node* AN = height_update(p_check).first;
				if (pattern == 1) { //RR
					L_Rotate(AN);
					height_update(AN);

				}
				else if (pattern == 2) { //RL
					R_Rotate(AN->r_child);
					height_update(AN->r_child->r_child);
					L_Rotate(AN);
					height_update(AN);
				}
				else if (pattern == 3) { //LL
					R_Rotate(AN);
					height_update(AN);
				}
				else if (pattern == 4) { //LR
					L_Rotate(AN->l_child);
					height_update(AN->l_child->l_child);
					R_Rotate(AN);
					height_update(AN);
				}
				else {}
				break;
			}
			p_check = p_check->parent;
		}
	}
}

void avl_tree::delete_node(int i)
{
	node* p = root;
	while (p) {
		if (i < p->value) {
			p = p->l_child;
		}
		else if (i > p->value) {
			p = p->r_child;
		}
		else { // i == p->value
			while (p->l_child) { //delete lchild first if found
				if (i == p->l_child->value)
					p = p->l_child;
				else
					break;
			}
			break;
		}

	}
	if (p == nullptr)  return; //not found
	else { //found p = i
		if (p->height == 1) { //p is leaf
			if (p == root) {
				delete p;
				root = nullptr;
			}
			else {
				node* p0 = p->parent;
				if (p->value < p0->value) {
					delete p0->l_child;
					p0->l_child = nullptr;
				}
				else {
					delete p0->r_child;
					p0->r_child = nullptr;
				}
				height_update(p0);

				node* p_check = p0;
				while (p_check) {
					if (height_update(p_check).first != nullptr) {
						int pattern = height_update(p_check).second;
						node* AN = height_update(p_check).first;
						if (pattern == 1) { //RR
							L_Rotate(AN);
							height_update(AN);
						}
						else if (pattern == 2) { //RL
							R_Rotate(AN->r_child);
							height_update(AN->r_child->r_child);
							L_Rotate(AN);
							height_update(AN);
						}
						else if (pattern == 3) { //LL
							R_Rotate(AN);
							height_update(AN);
						}
						else if (pattern == 4) { //LR
							L_Rotate(AN->l_child);
							height_update(AN->l_child->l_child);
							R_Rotate(AN);
							height_update(AN);
						}
						else {}
						break;
					}
					p_check = p_check->parent;
				}
			}
		}
		else if (p->height == 2 && !(p->l_child && p->r_child))
		{
			if (p->l_child) {
				p->value = p->l_child->value;
				delete p->l_child;
				p->l_child = nullptr;
			}
			else {
				p->value = p->r_child->value;
				delete p->r_child;
				p->r_child = nullptr;
			}
			height_update(p);
			//check violation
			node* p_check = p;
			while (p_check) {
				if (height_update(p_check).first != nullptr) {
					int pattern = height_update(p_check).second;
					node* AN = height_update(p_check).first;
					if (pattern == 1) { //RR
						L_Rotate(AN);
						height_update(AN);

					}
					else if (pattern == 2) { //RL
						R_Rotate(AN->r_child);
						height_update(AN->r_child->r_child);
						L_Rotate(AN);
						height_update(AN);
					}
					else if (pattern == 3) { //LL
						R_Rotate(AN);
						height_update(AN);
					}
					else if (pattern == 4) { //LR
						L_Rotate(AN->l_child);
						height_update(AN->l_child->l_child);
						R_Rotate(AN);
						height_update(AN);
					}
					else {}
					break;
				}
				p_check = p_check->parent;
			}

		}
		else {  //p->height >=2 && p has l_child and r_child || p->height > 2
			//find predecessor
			if (p->l_child && p->r_child) {
				if (p->l_child->height < p->r_child->height)  // replace with successor
				{
					// find successor
					node* p0 = p->r_child;
					node* p_suc = p->r_child;
					while (p0) {
						p_suc = p0;
						p0 = p0->l_child;
					}
					node* p_parent = p_suc->parent;

					if (p_suc->height == 1) {

						if (p_suc->value < p_parent->value) {
							p->value = p_suc->value;
							p_parent->l_child = nullptr;
						}
						else {
							p->value = p_suc->value;
							p_parent->r_child = nullptr;
						}
						delete p_suc;
					}
					else {

						if (p_suc->value < p_parent->value) {
							p->value = p_suc->value;
							p_parent->l_child = p_suc->r_child;
						}
						else {
							p->value = p_suc->value;
							p_parent->r_child = p_suc->r_child;
						}

						if (p_suc->r_child->parent)
							p_suc->r_child->parent = p_suc->parent;

						delete p_suc;
					}
					height_update(p_parent);
					//check violation
					node* p_check = p_parent;
					while (p_check) {
						if (height_update(p_check).first != nullptr) {
							int pattern = height_update(p_check).second;
							node* AN = height_update(p_check).first;
							if (pattern == 1) { //RR
								L_Rotate(AN);
								height_update(AN);

							}
							else if (pattern == 2) { //RL
								R_Rotate(AN->r_child);
								height_update(AN->r_child->r_child);
								L_Rotate(AN);
								height_update(AN);
							}
							else if (pattern == 3) { //LL
								R_Rotate(AN);
								height_update(AN);
							}
							else if (pattern == 4) { //LR
								L_Rotate(AN->l_child);
								height_update(AN->l_child->l_child);
								R_Rotate(AN);
								height_update(AN);
							}
							else {}
							break;
						}
						p_check = p_check->parent;
					}

				}
				else  // replace with predecessor
				{
					// find predecessor
					node* p0 = p->l_child;
					node* p_pre = p->l_child;
					while (p0) {
						p_pre = p0;
						p0 = p0->r_child;
					}

					node* p_parent = p_pre->parent;

					if (p_pre->height == 1) {
						/*	p->value = p_pre->value;*/

						if (p_pre->value < p_parent->value) {
							p->value = p_pre->value;
							p_parent->l_child = nullptr;
						}
						else {
							p->value = p_pre->value;
							p_parent->r_child = nullptr;
						}
						delete p_pre;
					}
					else {

						if (p_pre->value < p_parent->value) {
							p->value = p_pre->value;
							p_parent->l_child = p_pre->l_child;
						}
						else {
							p->value = p_pre->value;
							p_parent->r_child = p_pre->l_child;
						}
						if (p_pre->l_child->parent)
							p_pre->l_child->parent = p_pre->parent;
						delete p_pre;
					}
					height_update(p_parent);
					//check violation
					node* p_check = p_parent;
					while (p_check) {
						if (height_update(p_check).first != nullptr) {
							int pattern = height_update(p_check).second;
							node* AN = height_update(p_check).first;
							if (pattern == 1) { //RR
								L_Rotate(AN);
								height_update(AN);

							}
							else if (pattern == 2) { //RL
								R_Rotate(AN->r_child);
								height_update(AN->r_child->r_child);
								L_Rotate(AN);
								height_update(AN);
							}
							else if (pattern == 3) { //LL
								R_Rotate(AN);
								height_update(AN);
							}
							else if (pattern == 4) { //LR
								L_Rotate(AN->l_child);
								height_update(AN->l_child->l_child);
								R_Rotate(AN);
								height_update(AN);
							}
							else {}
							break;
						}
						p_check = p_check->parent;
					}
				}

			}
			else if (p->l_child) {
				// find predecessor
				node* p0 = p->l_child;
				node* p_pre = p->l_child;
				while (p0) {
					p_pre = p0;
					p0 = p0->r_child;
				}

				node* p_parent = p_pre->parent;

				if (p_pre->height == 1) {
					/*	p->value = p_pre->value;*/

					if (p_pre->value < p_parent->value) {
						p->value = p_pre->value;
						p_parent->l_child = nullptr;
					}
					else {
						p->value = p_pre->value;
						p_parent->r_child = nullptr;
					}
					delete p_pre;
				}
				else {

					if (p_pre->value < p_parent->value) {
						p->value = p_pre->value;
						p_parent->l_child = p_pre->l_child;
					}
					else {
						p->value = p_pre->value;
						p_parent->r_child = p_pre->l_child;
					}
					if (p_pre->l_child->parent)
						p_pre->l_child->parent = p_pre->parent;
					delete p_pre;
				}
				height_update(p_parent);
				//check violation
				node* p_check = p_parent;
				while (p_check) {
					if (height_update(p_check).first != nullptr) {
						int pattern = height_update(p_check).second;
						node* AN = height_update(p_check).first;
						if (pattern == 1) { //RR
							L_Rotate(AN);
							height_update(AN);

						}
						else if (pattern == 2) { //RL
							R_Rotate(AN->r_child);
							height_update(AN->r_child->r_child);
							L_Rotate(AN);
							height_update(AN);
						}
						else if (pattern == 3) { //LL
							R_Rotate(AN);
							height_update(AN);
						}
						else if (pattern == 4) { //LR
							L_Rotate(AN->l_child);
							height_update(AN->l_child->l_child);
							R_Rotate(AN);
							height_update(AN);
						}
						else {}
						break;
					}
					p_check = p_check->parent;
				}

			}
			else if (p->r_child) {
				// find successor
				node* p0 = p->r_child;
				node* p_suc = p->r_child;
				while (p0) {
					p_suc = p0;
					p0 = p0->l_child;
				}
				node* p_parent = p_suc->parent;

				if (p_suc->height == 1) {

					if (p_suc->value < p_parent->value) {
						p->value = p_suc->value;
						p_parent->l_child = nullptr;
					}
					else {
						p->value = p_suc->value;
						p_parent->r_child = nullptr;
					}
					delete p_suc;
				}
				else {

					if (p_suc->value < p_parent->value) {
						p->value = p_suc->value;
						p_parent->l_child = p_suc->r_child;
					}
					else {
						p->value = p_suc->value;
						p_parent->r_child = p_suc->r_child;
					}

					if (p_suc->r_child->parent)
						p_suc->r_child->parent = p_suc->parent;

					delete p_suc;
				}
				height_update(p_parent);
				//check violation
				node* p_check = p_parent;
				while (p_check) {
					if (height_update(p_check).first != nullptr) {
						int pattern = height_update(p_check).second;
						node* AN = height_update(p_check).first;
						if (pattern == 1) { //RR
							L_Rotate(AN);
							height_update(AN);

						}
						else if (pattern == 2) { //RL
							R_Rotate(AN->r_child);
							height_update(AN->r_child->r_child);
							L_Rotate(AN);
							height_update(AN);
						}
						else if (pattern == 3) { //LL
							R_Rotate(AN);
							height_update(AN);
						}
						else if (pattern == 4) { //LR
							L_Rotate(AN->l_child);
							height_update(AN->l_child->l_child);
							R_Rotate(AN);
							height_update(AN);
						}
						else {}
						break;
					}
					p_check = p_check->parent;
				}

			}
		}
	}
}


int main() {
	//Different test cases will be used during grading.
	avl_tree t1;
	t1.add_node(45);
	t1.in_order_traversal(t1.root);
	t1.delete_node(45);
	t1.in_order_traversal(t1.root);
	t1.add_node(50);
	t1.add_node(46);
	t1.add_node(30);
	t1.add_node(34);
	t1.in_order_traversal(t1.root);
	t1.delete_node(48);
	t1.in_order_traversal(t1.root);
	getchar();
	getchar();
	return 0;
}

//The following is an example showing how to return a pair.
/*
#include <iostream>
using namespace std;

pair<int *, int> f1(){
	return { new int {10}, 10 };
}
int main() {
	cout << *f1().first << " " << f1().second << endl;
	getchar();
	getchar();
	return 0;
}
*/
