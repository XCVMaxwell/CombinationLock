#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {
    LinkedList list;

    list.Add('R', 20);
    list.Add('L', 21);
    list.Add('R', 22);
    list.Add('L', 23);
    list.Add('R', 24);
    list.Add('L', 25);
    list.Add('R', 26);

    cout << "The list contains the following numbers: " << endl << endl;
    cout << list;

    // test 2: delete a node
    cout << "\nDeleting...." << endl;

    list.DeleteValue('L', 23);
    list.DeleteNode(4);

    cout << "The list contains the following numbers: " << endl << endl;
    cout << list;

    // test 3: insert a node
    cout << "\nInserting...." << endl;

    // tests to insert after valid node
    list.InsertAfterValue('R', 15, 'R', 20);

    // test to insert after non-existent node
    list.InsertAfterValue('L', 16, 'L', 25);
    list.InsertBeforeNode(6, 'L', 30);

    cout << "The list contains the following numbers: " << endl << endl;
    cout << list;

    cin.ignore();
    return 0;
}
