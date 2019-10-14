//
// "Bağlı Listelerle Polinomların Toplanması" Konulu Veri Yapıları Uygulaması
//
// 82. satırdaki sumPolynomials() adlı fonksiyonu tamamlayınız ve
// 133-135. satırlarla doğru çalışıp çalışmadığını test ediniz. 
//


#include <string>
#include <iostream>
using namespace std;

struct SinglyNode
{
    int coef;						// polynom coefficient (5x^12 deki 5)
    int expo;						// polynom exponent    (5x^12 deki 12)
    SinglyNode* next;				// next item in the list
};

struct SinglyLinkedList
{
    SinglyNode* head;									// pointer to the head of list

    SinglyLinkedList();									// empty list constructor

    bool empty() const;									// is list empty?
    void addBack(const int& e, const int& i);			// add to back of list
    void print();

    SinglyLinkedList* sumPolynomials(SinglyLinkedList* list2);
};

SinglyLinkedList::SinglyLinkedList()							// constructor
{
    head = NULL;
}

bool SinglyLinkedList::empty() const							// is list empty?
{
    return head == NULL;
}

void SinglyLinkedList::addBack(const int& e, const int& i)
{
    SinglyNode* v	= new SinglyNode;
    v->coef			= e;
    v->expo			= i;
    v->next			= NULL;

    if (head == NULL) head = v;
    else
    {
        SinglyNode* first = head;
        while (first->next != NULL) first = first->next;
        first->next = v;
    }
}

void SinglyLinkedList::print()
{
    if (empty())
    {
        cout << "List is empty !" << endl;
        return;
    }

    SinglyNode* first = head;
    while (first != NULL)
    {
        if (first->expo == 0)
            cout << first->coef ;
        else
        if (first->coef == 1)
            cout << "x^" << first->expo << " + ";
        else
            cout << first->coef << "x^" << first->expo << " + ";

        first = first->next;
    }
}

SinglyLinkedList* SinglyLinkedList::sumPolynomials(SinglyLinkedList* list2)
{
    SinglyLinkedList* polySum = new SinglyLinkedList();

    SinglyNode* plist1 = this->head;
    SinglyNode* plist2 = list2->head;

    while ((plist1 != NULL) || (plist2 != NULL))
    {
        if (plist1 == NULL)
        {
            while (plist2 != NULL)
            {
                polySum->addBack(plist2->coef, plist2->expo);
                plist2 = plist2->next;
            }

            return polySum;
        }

        if (plist2 == NULL)
        {
            while (plist1 != NULL)
            {
                polySum->addBack(plist1->coef, plist1->expo);
                plist1 = plist1->next;
            }

            return polySum;
        }


        if(plist1->expo==plist2->expo)
        {
            int sum = (plist1->coef)+(plist2->coef);
            plist1->coef=sum;
            polySum->addBack(plist1->coef, plist1->expo);
            plist2= plist2->next;
            plist1 = plist1->next;

        }
        else if(plist1->expo>plist2->expo)
        {
            polySum->addBack(plist1->coef,plist1->expo);
            plist1=plist1->next;
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
    SinglyLinkedList* list1 = new SinglyLinkedList();
    SinglyLinkedList* list2 = new SinglyLinkedList();

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
    list1->print();

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
    list2->print();

    cout << endl;

    SinglyLinkedList* polySum = list1->sumPolynomials(list2);
    cout<<endl;
    cout << "polySum   : ";
    polySum->print();


}
