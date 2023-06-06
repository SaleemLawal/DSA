/*****************************************
** File:    Strand.cpp
** This file contains the functions that help with perfoming actions to strands 
** such as getting their data and inserting them into a list
**
***********************************************/
#include "Strand.h"

// Name: Strand() - Default Constructor
// Desc: Used to build a new empty strand (m_head, m_tail = nullptr and size = 0)
// Preconditions: None
// Postconditions: Creates a new strand with a default name
Strand::Strand(){
	m_head = nullptr;
	m_tail = nullptr;
	m_size = 0;
}

// Name: Strand(string) - Overloaded Constructor
// Desc: Used to build a new empty strand with the name passed
//       with m_head, m_tail = nullptr; size = 0;
// Preconditions: None
// Postconditions: Creates a new strand with passed name
Strand::Strand(string name){
	m_name = name;
	m_head = nullptr;
	m_tail = nullptr;
	m_size = 0;
}

// Name: ~Strand() - Destructor
// Desc: Used to destruct a strand
// Preconditions: There is an existing strand with at least one node
// Postconditions: Strand is deallocated (including all dynamically allocated nodes)
//                 to have no memory leaks!
Strand::~Strand(){
	Node* currentNode = m_head;
	while (currentNode != nullptr){
		Node* next = currentNode -> m_next;
		delete currentNode;
		currentNode = next;
	}
	m_head = nullptr;
	m_tail = nullptr;
	m_size = 0;
}

// Name: InsertEnd
// Desc: Takes in a char. Creates a new node.
//       Inserts node at the end of the strand. Increases size.
// Preconditions: Requires a strand
// Postconditions: Strand is larger.
void Strand::InsertEnd(char data){
	Node* newNode = new Node;
	newNode -> m_data = data;
	newNode -> m_next = nullptr;
	// checks if list is empty
	if (m_head == nullptr){
		m_head = newNode;
		m_tail = newNode;
	} else{
		m_tail -> m_next = newNode;
		m_tail = newNode;
	}
	m_size++;
}

// Name: GetName()
// Preconditions: Requires a strand
// Postconditions: Returns m_name;
string Strand::GetName(){
	return m_name;
}

// Name: GetSize()
// Preconditions: Requires a strand
// Postconditions: Returns m_size;
int Strand::GetSize(){
	return m_size;
}

// Name: ReverseSequence
// Preconditions: Reverses the strand
// Postconditions: Strand sequence is reversed in place; nothing returned
void Strand::ReverseSequence(){
	Node *curr = nullptr, *prev = nullptr, *next = nullptr;
	if (m_head == nullptr){
		cout<<"Empty"<<endl;
		return;
	}
	if (m_head->m_next == nullptr){
		return;
	}
	curr = m_head;
	prev = curr->m_next;
	next = prev->m_next;
	curr->m_next = nullptr;
	prev->m_next = curr;
	
	while (next != nullptr){
		curr = prev;
		prev = next;
		next = next->m_next;
		prev->m_next = curr;
	}
	m_head = prev;
}

// Name: GetData
// Desc: Returns the data at a specific location in the strand.
//       Iterates to node and returns char.
// Preconditions: Requires a DNA sequence
// Postconditions: Returns a single char from a node
char Strand::GetData(int nodeNum){
	Node* current = m_head;
	int counter = 0;
	while(current != nullptr){
		if (counter == nodeNum){
			return current -> m_data;
		}
		current = current -> m_next;
		counter++;
	}
	return '\0';
}

// Name: operator<<
// Desc: Overloaded << operator to return ostream from strand
//       Iterates over the entire strand and builds an output stream
//       (Called like cout << *m_DNA.at(i); in Sequencer)
// Preconditions: Requires a strand
// Postconditions: Returns an output stream (does not cout the output)
ostream &operator<< (ostream &output, Strand &myStrand){
	for (int j = 0; j < myStrand.GetSize(); j++){
		output << myStrand.GetData(j) << "->";
	}
	return output;
}