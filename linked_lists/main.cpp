#include <iostream>


class node{

	private:
		int value;
		node * next;
	public:
		// ctor
		node(int p_value):value(p_value),next(nullptr){}

		node * get_next(){
		return next;
		}
		int get_value(){
		return value;
		}
		void set_next(node * p_node){
			next = p_node;
		}

};


class linked_list{
	node * root;
	public:
	// ctor
	linked_list(int p_value){
	root = new node(p_value);
	}
	// dtor
	~linked_list(){
		// loop through all the elements and whenever you find nullptr start deleting backwards
		node * temp = root;
		node * d;
		while(temp->get_next()){
			d = temp->get_next();
			delete temp;
			temp = d;
		}
	}

	void append(int p_value){
		// create a new node
		node * new_node = new node(p_value);
		// create temp node to iterate
		node * temp = root;
		// iterate throught list_linked list until you find a node with next= nullptr;
		while(temp->get_next()){
			temp = temp->get_next();
		}
		// reached a node with next = nullptr
		temp->set_next(new_node);
	}

	void print_list(){
		// start with root and loop through all the lists with a temp
		node * temp = root;
		while(temp->get_next() != nullptr){
			std::cout<<"value is "<< temp->get_value()<<std::endl;
			temp = temp->get_next();
		}

			std::cout<<"value is "<< temp->get_value()<<std::endl;
	}
	void prepend(int p_value){
		// create a new node and set its next to root
		// then make it as root
		node * new_node = new node(p_value);
		new_node->set_next(root);
		root = new_node;
	}
	bool insert(int index, int p_value){
		// start from root loop (index -1)times.
		// set the new_node next to be the next of the index -1
		node * new_node = new node(p_value);
		node * temp = root;
		int i =0;
		while(i< index-1){
			i++;
			if(temp->get_next()!= nullptr){
				temp = temp->get_next();
			}
			else
			{
				return false;
			}
		}
		new_node->set_next(temp->get_next());
		temp->set_next(new_node);
		return true;
	}
	node * get_end(){
		node * temp = root;
		while(temp->get_next())
		{
			temp = temp->get_next();

		}
		return temp;
	}
		int get_length(){
		node * temp = root;
		int len = 0;
		while(temp->get_next())
		{
			len++;
			temp = temp->get_next();

		}
		return len;
	}
	void reverse(){
		// create two vars temp and itr
		auto x = get_length();
		node *temp = root;
		node *before = nullptr,*after = temp->get_next();
		root = get_end();
		after = temp->get_next();
		for(int i = 0; i <=x;i++){
			after = temp->get_next();
			temp->set_next(before);
			before = temp;
			temp = after;
		}
	}


};



int main()
{
	//for now let's create a single linked list
	linked_list * list = new linked_list(2);
	list->append(3);
	list->append(5);
	list->prepend(1);
	std::cout<<"--------------------------------\n"<<std::endl;
	list->print_list();
	list->insert(3,4);
	std::cout<<"--------------------------------\n"<<std::endl;
	list->print_list();
	list->reverse();
	std::cout<<"--------------------------------\n"<<std::endl;
	list->print_list();

	delete list;
	return 0;
}
