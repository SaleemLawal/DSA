/*****************************************
** File:    Sequencer.cpp
** This file contains the functions that help with perfoming actions to a sequence
**
***********************************************/
#include "Sequencer.h"

// Name: Sequencer (constructor)
// Desc: Creates a new sequencer to hold one or more DNA/mRNA strands make of
//       multiples of three nucleotides
// Preconditions:  Populates m_fileName from passed information from call
//                 For example: ./proj3 proj3_data1.txt
// Postconditions: A sequencer created to populate DNA/mRNA strands
Sequencer::Sequencer(string fileName){
	m_fileName = fileName;
}

// Name:  Sequencer (destructor)
// Desc: Deallocates all dynamic aspects of a Sequencer
// Preconditions: There are an existing DNA/mRNA strand(s) (linked list)
// Postconditions: All vectors are cleared of DNA and mRNA strands
//                 Indicates that the strands have been deallocated
Sequencer::~Sequencer(){
	cout << "Starting mDNA strands deletion\n";
	for (unsigned int i = 0; i < m_DNA.size(); i++){
		delete m_DNA[i];
	}
	cout << "Deleting DNA Strands\n";
	cout << "Starting mRNA strands deletion\n";
	for (unsigned int i = 0; i < m_mRNA.size(); i++){
		delete m_mRNA[i];
	}
	cout << "Deleting mRNA Strands\n";
}

// Name: StartSequencing
// Desc: Calls ReadFile and continually calls main menu until the user exits
// Preconditions: m_fileName has been populated
// Postconditions: m_DNA has been populated (after ReadFile concludes)
void Sequencer::StartSequencing(){
	const int FIVE = 5;
	int choice = 0;
	bool checker = true;
	
	ReadFile();
	choice = MainMenu();
	// runs while user choice isn't 5
	while (checker){
		if (choice == FIVE){
			checker = false;
		}else{
			choice = MainMenu();
		}
	}
	cout << "Exiting program\n";
}

// Name: DisplayStrands
// Desc: Displays each strand in both mDNA and mRNA
//       Displays numbered type (For example, DNA 1) then the name of the strand.
//       Finally, displays the strand with arrows between each nucleotide
// Preconditions: At least one linked list is in mDNA (may have mRNA)
// Postconditions: Displays DNA strand from one of the vectors
void Sequencer::DisplayStrands(){
	// loops through the DNA vector and display the info @ the index
	for (unsigned int i = 0; i < m_DNA.size(); i++){
		cout << "DNA " << i + 1 << endl;
		cout << "***" << m_DNA[i]->GetName() << "***"<< endl;
		cout << *m_DNA.at(i);
		cout << "END\n";
	}
	// loops through the mRNA vector and display the info @ the index
	if (m_mRNA.size() != 0){
		for (unsigned int i = 0; i < m_mRNA.size(); i++){
			cout << "mRNA " << i + 1 << endl;
			cout << "***" << m_mRNA[i]->GetName() << "***"<< endl;
			cout << *m_mRNA.at(i);
			cout << "END\n";
		}
	}
}

// Name: ReadFile
// Desc: Reads in a file of DNA strands that has the name on one line then
//       the sequence on the next
//       All sequences will be an indeterminate length (always evenly divisible by three though).
//       There are an indeterminate number of sequences in a file.
//       Hint: Read in the entire sequence into a string then go char
//       by char until you hit a new line break. Then insert to the m_DNA vector
// Preconditions:` Valid file name of characters (Filled with a name and then A, T, G, or C)
// Postconditions: Populates each DNA strand and puts in m_DNA
void Sequencer::ReadFile(){
	fstream file(m_fileName);
	// checks to see if the file is open
	if (file.is_open()){
		cout << "Opened file\n";
		string line;
		while (getline(file, line)){
			string name;
			unsigned int i = 0;
			// loop through until the the first comma is met
			while (line[i] != ','){
				// if the char @ that index isnt , add to the name string
				name += line[i];
				i++;
			}
			// creates a new strand pointer and insert the name
			Strand* new_strand = new Strand(name);
			for (; i < size(line); i++){
				if (line[i] != ','){
					new_strand->InsertEnd(line[i]);
				}
			}
			m_DNA.push_back(new_strand);
		}
		cout <<int( m_DNA.size()) << " Strands loaded.\n";
	}
	file.close();
}

// Name:  MainMenu
// Desc: Displays the main menu and manages exiting.
//       Returns 5 if the user chooses to quit, else returns 0
// Preconditions: m_DNA populated
// Postconditions: Indicates the user has quit the program
int Sequencer::MainMenu(){
	const int FIVE = 5, FOUR = 4, THREE = 3, TWO = 2, ONE = 1;
	int userInput = 0;
	bool checker = true;
	// runs while input isn tbetween 1 and 5
	while (checker){
		if (userInput >= 1 and userInput <= FIVE){
			checker = false;
		}else{
			cout << "\nWhat would you like to do?:\n" << "1. Display Strands\n" << "2. Reverse Strand\n" <<
				 "3. Transcribe DNA to mRNA\n" << "4. Translate mRNA to Amino Acids\n" << "5. Exit\n";
			cin >> userInput;
		}
	}
	switch(userInput){
		case ONE:
			DisplayStrands();
			break;
		case TWO:
			ReverseSequence();
			break;
		case THREE:
			Transcribe();
			break;
		case FOUR:
			Translate();
			break;
	}
	if (userInput == FIVE){
		return FIVE;
	}
	return 0;
}

// Name: ChooseDNA
// Desc: Asks the user to choose one strand to use from loaded DNA strands
// Preconditions: Populated m_DNA
// Postconditions: Returns index of chosen strand
int Sequencer::ChooseDNA(){
	bool check = true;
	unsigned int index;
	cout << "Which strand to work with?\n";
	// runs while index isnt within range of the m_DNA
	while (check){
		cout << "Choose 1 - " << m_DNA.size() << endl;
		cin >> index;
		if (index > 0 and index <= m_DNA.size()){
			check = false;
		}
	}
	return int(index);
}

// Name: ChooseMRNA
// Desc: Asks the user to choose one strand to use from translated mRNA strands
// Preconditions: Populated m_mRNA
// Postconditions: Returns index of chosen strand
int Sequencer::ChooseMRNA(){
	if (m_mRNA.size() == 0){
		cout << "No mRNA to reverse; transcribe first\n";
		return 0;
	}else{
		bool check = true;
		unsigned int index;
		cout << "Which strand to work with?\n";
		// runs while index isnt within the range
		while (check){
			cout << "Choose " << m_DNA.size() << " - " << m_mRNA.size() << endl;
			cin >> index;
			if (index > m_DNA.size() and index <= m_mRNA.size()){
				check = false;
			}
		}
		return int(index);
	}
}

// Name: ReverseSequence
// Desc: User chooses to reverse either DNA or mRNA to reverse
//       Then calls either ChooseDNA or ChooseMRNA which returns index of strand
//       Calls ReverseStrand on chosen location
// Preconditions: Populated m_DNA or m_mRNA
// Postconditions: Reverses a specific strand replacing in place
void Sequencer::ReverseSequence(){
	const int TWO = 2;
	int reverse_type = 0, choice = 0;
	bool check_range = true;
	// runs while input isnt 1 or 2
	while (check_range){
		cout << "Which type of strand to reverse?\n1. DNA\n2. mRNA\n";
		cin >> reverse_type;
		if (reverse_type >= 1 and reverse_type <= TWO){
			check_range = false;
		}
	}
	// reverse the sequence
	switch (reverse_type) {
		case 1:
			choice = ChooseDNA();
			m_DNA[choice - 1]->ReverseSequence();
			cout << "Done reversing DNA " << choice<<"'s strand.\n";
			break;
		case 2:
			choice = ChooseMRNA();
			if (choice != 0){
				m_mRNA[choice - 1]->ReverseSequence();
				cout << "Done reversing RNA " << choice <<"'s strand.\n";
			}
			break;
	}
}

// Name: Transcribe
// Desc: Iterates through each DNA strand in m_DNA to transcribe to m_mRNA
// A->U, T->A, C->G, G->C (DNA to mRNA)
// Can be called multiple times (will result in multiple mRNA strands)
// Puts the transcribed mRNA strand into m_mRNA
// Note: if this function is called more than once on the same strands of DNA,
// it will add duplicate strands into m_mRNA!
// Preconditions: Populated m_DNA
// Postconditions: Transcribes each strand of m_DNA to m_mRNA
void Sequencer::Transcribe(){
	int count = 0;
	for (unsigned int i = 0; i < m_DNA.size(); i++){
		// creates a pointer that is traversed through and transcribed into mRNA
		Strand* curr = new Strand(m_DNA[i]->GetName());
		for (int j = 0; j < m_DNA[i]->GetSize(); j++){
			if (m_DNA[i]->GetData(j) == 'A'){
				curr->InsertEnd('U');
			} else if (m_DNA[i]->GetData(j) == 'T'){
				curr->InsertEnd('A');
			}else if (m_DNA[i]->GetData(j) == 'C'){
				curr->InsertEnd('G');
			}else if (m_DNA[i]->GetData(j) == 'G'){
				curr->InsertEnd('C');
			}
		}
		m_mRNA.push_back(curr);
		count++;
	}
	cout << count << " strands of DNA successfully transcribed into new mRNA strands\n";
}

// Name: Translate
// Desc: Iterates through a chosen mRNA strand and converts to amino acids
// For every three nucleotides in strand, passes them three at a time to Convert
// Displays each amino acid but does not store the amino acids in the class
// Preconditions: Populated m_mRNA
// Postconditions: Translates a specific strand of mRNA to amino acids
void Sequencer::Translate(){
	const int THREE = 3;
	unsigned int choice;
	bool check_range = true;
	
	if(m_mRNA.size() == 0){
		cout << "No mRNA to translate; transcribe first\n";
		return;
	}
	while (check_range){
		cout << "Which strand to work with?\n" << "Choose 1 - " << m_mRNA.size() << endl;
		cin >> choice;
		if (choice >= 1 and choice <= m_mRNA.size()){
			check_range = false;
		}
	}
	choice--;
	cout << "***" <<m_mRNA[choice]->GetName() << "***\n";
	int i = 0;
	for (; i < m_mRNA[choice]->GetSize();){
		string name;
		// every three char, it finds the corresponding codon
		while (name.size() != THREE){
			name += m_mRNA[choice]->GetData(i);
			i++;
		}
		cout << name << "->"<< Convert(name) << endl;
	}
	cout << "Done translating mRNA " << choice + 1 <<"'s strand.\n";
	
}

// Name: Convert (Provided)
// Desc: Converts codon (three nodes) into an amino acid
// Preconditions: Passed exactly three U, A, G, or C
// Postconditions: Returns the string name of each amino acid
string Sequencer::Convert(const string trinucleotide){
	if((trinucleotide=="AUU")||(trinucleotide=="AUC")||(trinucleotide=="AUA"))
		return ("Isoleucine");
	else if((trinucleotide=="CUU")||(trinucleotide=="CUC")||(trinucleotide=="CUA")||
			(trinucleotide=="CUG")|| (trinucleotide=="UUA")||(trinucleotide=="UUG"))
		return ("Leucine");
	else if((trinucleotide=="GUU")||(trinucleotide=="GUC")||
			(trinucleotide=="GUA")||(trinucleotide=="GUG"))
		return ("Valine");
	else if((trinucleotide=="UUU")||(trinucleotide=="UUC"))
		return ("Phenylalanine");
	else if((trinucleotide=="AUG"))
		return ("Methionine (START)");
	else if((trinucleotide=="UGU")||(trinucleotide=="UGC"))
		return ("Cysteine");
	else if((trinucleotide=="GCU")||(trinucleotide=="GCC")||
			(trinucleotide=="GCA")||(trinucleotide=="GCG"))
		return ("Alanine");
	else if((trinucleotide=="GGU")||(trinucleotide=="GGC")||
			(trinucleotide=="GGA")||(trinucleotide=="GGG"))
		return ("Glycine");
	else if((trinucleotide=="CCU")||(trinucleotide=="CCC")||
			(trinucleotide=="CCA")||(trinucleotide=="CCG"))
		return ("Proline");
	else if((trinucleotide=="ACU")||(trinucleotide=="ACC")||
			(trinucleotide=="ACA")||(trinucleotide=="ACG"))
		return ("Threonine");
	else if((trinucleotide=="UCU")||(trinucleotide=="UCC")||
			(trinucleotide=="UCA")||(trinucleotide=="UCG")||
			(trinucleotide=="AGU")||(trinucleotide=="AGC"))
		return ("Serine");
	else if((trinucleotide=="UAU")||(trinucleotide=="UAC"))
		return ("Tyrosine");
	else if((trinucleotide=="UGG"))
		return ("Tryptophan");
	else if((trinucleotide=="CAA")||(trinucleotide=="CAG"))
		return ("Glutamine");
	else if((trinucleotide=="AAU")||(trinucleotide=="AAC"))
		return ("Asparagine");
	else if((trinucleotide=="CAU")||(trinucleotide=="CAC"))
		return ("Histidine");
	else if((trinucleotide=="GAA")||(trinucleotide=="GAG"))
		return ("Glutamic acid");
	else if((trinucleotide=="GAU")||(trinucleotide=="GAC"))
		return ("Aspartic acid");
	else if((trinucleotide=="AAA")||(trinucleotide=="AAG"))
		return ("Lysine");
	else if((trinucleotide=="CGU")||(trinucleotide=="CGC")||(trinucleotide=="CGA")||
			(trinucleotide=="CGG")||(trinucleotide=="AGA")||(trinucleotide=="AGG"))
		return ("Arginine");
	else if((trinucleotide=="UAA")||(trinucleotide=="UAG")||(trinucleotide=="UGA"))
		return ("Stop");
	else
		cout << "returning unknown" << endl;
	return ("Unknown");
}
