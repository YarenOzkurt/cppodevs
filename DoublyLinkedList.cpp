//
// "Bağlı Listelerle Polinomların Toplanması" Konulu Veri Yapıları Uygulaması
//
// 90. satırdaki sumPolynomials() adlı fonksiyonu tamamlayınız ve
// 141-143. satırlarla doğru çalışıp çalışmadığını test ediniz. 
//


#include <string>
#include <iostream>
using namespace std;

struct DoublyNode
{
	int coef;						// polynom coefficient (5x^12 deki 5)
	int expo;						// polynom exponent   (5x^12 deki 12)
	DoublyNode* next;				// next item in the list
	DoublyNode* prev;				// previous item in the list
};

struct DoublyLinkedList
{
	DoublyNode* header;										// pointer to the header of list
	DoublyNode* trailer;									// pointer to the trailer of list

	DoublyLinkedList();										// empty list constructor

	bool empty() const;										// is list empty?
	void add(DoublyNode* v, const int& c, const int& e);	// insert new node before v
	void addBack(const int& c, const int& e);				// add to back of list
	void printH2T();

	DoublyLinkedList* sumPolynomials(DoublyLinkedList* list2);
};

DoublyLinkedList::DoublyLinkedList()				// constructor
{
	header			= new DoublyNode;				// create sentinels
	trailer			= new DoublyNode;
	header->next	= trailer;						// have them point to each other
	trailer->prev	= header;
}

bool DoublyLinkedList::empty() const				// is list empty?
{
	return (header->next == trailer);
}

void DoublyLinkedList::addBack(const int& c, const int& e)		// add to back of list
{
	add(trailer, c, e);
}

void DoublyLinkedList::add(DoublyNode* v, const int& c, const int& e)	// insert new node before v
{
	DoublyNode* u	= new DoublyNode;
	u->coef			= c;
	u->expo			= e;

	u->next			= v;								
	u->prev			= v->prev;							  

	v->prev->next	= u;								
	v->prev			= u;								
}

void DoublyLinkedList::printH2T()
{
	if (empty())
	{
		cout << "List is empty !" << endl;
		return;
	}

	DoublyNode* first = header;
	while (!(first->next == trailer))
	{
		if (first->next->expo == 0) 
			cout << first->next->coef;
		else
		if (first->next->coef == 1) 
			cout << "x^" << first->next->expo << " + ";
		else
			cout << first->next->coef << "x^" << first->next->expo << " + ";

		first = first->next;
	}
}

DoublyLinkedList* DoublyLinkedList::sumPolynomials(DoublyLinkedList* list2)
{
	DoublyLinkedList* polySum = new DoublyLinkedList();

	DoublyNode* plist1 = this->header->next;
	DoublyNode* plist2 = list2->header->next;

	while ( (plist1 != this->trailer) || (plist2 != list2->trailer) )
	{
		if(plist1 == this->trailer)
		{
			while (plist2 != list2->trailer)
			{
				polySum->addBack(plist2->coef, plist2->expo);
				plist2 = plist2->next;
			}

			return polySum;
		}

		if(plist2 == list2->trailer)
		{
			while (plist1 != this->trailer)
			{
				polySum->addBack(plist1->coef, plist1->expo);
				plist1 = plist1->next;
			}

			return polySum;
		}

		if(plist1->expo == plist2->expo)
		{
			int sum = (plist1->coef)+(plist2->coef);
			plist1->coef=sum;
			polySum->addBack(plist1->coef, plist1->expo);
			plist1 = plist1->next;
			plist2 = plist2->next;			
		}
		else if(plist1->expo>plist2->expo)
		{
			polySum->addBack(plist1->coef, plist1->expo);
			plist1 = plist1->next;
		}	
		else 
		{
			polySum->addBack(plist2->coef,plist2->expo);
			plist2=plist2->next;
		}
	}
return polySum;
}

int main()
{
	DoublyLinkedList* list1 = new DoublyLinkedList();
	DoublyLinkedList* list2 = new DoublyLinkedList();

	FILE* f = fopen("polynoms.txt", "r");

	int coef = 0;
	int expo = 0;

	while (true)
	{
		fscanf(f, "%d", &coef);
		fscanf(f, "%d", &expo);

		if (coef != -1) list1->addBack(coef, expo);
		else
			break;
	}

	cout << endl;

	cout << "Polinom 1 : ";
	list1->printH2T();

	cout << endl;

	while (true)
	{
		fscanf(f, "%d", &coef);
		fscanf(f, "%d", &expo);

		if (coef != -1) list2->addBack(coef, expo);
		else
			break;
	}

	cout << "Polinom 2 : ";
	list2->printH2T();

	cout << endl;

	DoublyLinkedList* polySum = list1->sumPolynomials(list2);
	cout << "polySum   : ";
	polySum->printH2T();


}
