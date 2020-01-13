#include <iostream>
#include <regex>
#include <fstream>
#include "LinkedList.h"

using namespace std;

void initializeLinkedList(LinkedList& list) {
    for (int i = 0; i <= 6; i++)
        list.Add(0);
}

void resetCombination(LinkedList& list) {
    Node* currNode = list.first;

    while (currNode != nullptr) {
        currNode->number = 0;

        currNode = currNode->next;
    }
}

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

char charToUpper(string character) {
    char* c = &character[0];
    return (c[0] >= 'a' && c[0] <= 'z') ? c[0] - 32 : c[0];
}

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

void writeToFile(LinkedList& list, const string& fileName) {
    ofstream file;
    file.open(fileName);
    file << list;
    file.close();
}

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
