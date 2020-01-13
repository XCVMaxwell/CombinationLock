#include <iostream>
#include <regex>
#include <fstream>
#include "LinkedList.h"

using namespace std;

// Adds 7 items to linked list with value 0.
// PARAM 1: Linked list that holds combination.
void initializeLinkedList(LinkedList& list) {
    for (int i = 0; i <= 6; i++)
        list.Add(0);
}

// Loops through all linked list items and sets their value to 0.
// PARAM 1: Linked list that holds combination.
void resetCombination(LinkedList& list) {
    Node* currNode = list.first;

    while (currNode != nullptr) {
        currNode->number = 0;

        currNode = currNode->next;
    }
}

// Prints the combination from the linked list by looping through all items and cout-ing their the direction and their value.
// Also puts a < next to the current working item.
// PARAM 1: Linked list that holds combination.
// PARAM 2: Index of the current working value in combination.
void printCombination(const LinkedList& list, const int& workingIndex) {
    Node* currNode = list.first;

    int index = 0;
    while (currNode != nullptr) {
        index++;

        string direction = (index % 2 == 1) ? "R" : "L";

        cout << index << ": " << direction << currNode->number;
        if (workingIndex == index) cout << " <";
        cout << endl;

        currNode = currNode->next;
    }
}

// Changes and character to uppercase removing the need to account for both uppercase and lower case in my logic.
// PARAM 1: String holding the user inputted command.
char charToUpper(string character) {
    char* c = &character[0];
    return (c[0] >= 'a' && c[0] <= 'z') ? c[0] - 32 : c[0];
}

// Parses the user input using regex groups. Regex doesn't allow any commands other than 'QEGSDR' and no number over 49.
// Regex also allows white space between the command and sub-command.
// PARAM 1: User inputted command and possible sub-command.
// PARAM 2: Variable to set value of parsed command.
// PARAM 3: Variable to set value of parsed sub-command.
void parseCommand(const string& str, string& command, string& subCommand) {
    regex regx("([QEGSDRqegsdr])\\s*([0-4]?\\d)?");
    smatch match;

    if (regex_match(str, match, regx)) {
        subCommand = match[2];
        command = charToUpper(match[1]);
    }
    else {
        cout << "Error parsing command! Please make sure you're using any of (Q, E, G, S, D, R) and, if required, no number larger than 49." << endl;
    }
}

// Writes combination to file.
// PARAM 1: Linked list that holds combination.
// PARAM 2: String that holds user inputted file name to be written to.
void writeToFile(LinkedList& list, const string& fileName) {
    ofstream file;
    file.open(fileName);
    file << list;
    file.close();
}

// Command vs. Sub-command.
// Command - Q, E, G, S, D and R are considered commands.
// Sub-command is whatever comes after a command. In this case that's the the combination number.
int main(int argc, char* argv[]) {
    if (argc == 2) {
        string fileName = argv[1];
        LinkedList list;
        initializeLinkedList(list);

        string command;
        string subCommand;
        int workingValue = 1;
        while (command != "Q") {
            if (command == "G" && !subCommand.empty()) {
                if (stoi(subCommand) > 0 && stoi(subCommand) <= 7) {
                    workingValue = stoi(subCommand);
                    subCommand = "";
                }
                else {
                    cout << "Invalid working value! Please try again with 1-7." << endl;
                }
            } else if (command == "S" && !subCommand.empty()) {
                list.ChangeValue(workingValue - 1, stoi(subCommand));
            } else if (command == "D") {
                list.ChangeValue(workingValue - 1, 0);
            } else if (command == "R") {
                resetCombination(list);
            } else if (command == "E") {
                writeToFile(list, fileName);
                break;
            }

            printCombination(list, workingValue);
            getline(cin, command);
            parseCommand(command, command, subCommand);
        }
    }
    else {
        cerr << "Usage: " << argv[0] << " FILENAME" << endl;

        return 1;
    }
}
