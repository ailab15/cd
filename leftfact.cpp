#include<iostream>
#include<string>
using namespace std;

int main() {
    string parentNonTerminal, production, production1, production2, temp;
    int productionSizes[10] = {}; // Array to store sizes of productions
    char nonTerminal;
    int numProductions;

    // Getting input from user
    cout << "Enter the Parent Non-Terminal: ";
    cin >> nonTerminal;
    parentNonTerminal.push_back(nonTerminal);
    production1 += parentNonTerminal + "\'->";
    production2 += parentNonTerminal + "\'\'->";
    parentNonTerminal += "->";

    cout << "Enter the number of productions: ";
    cin >> numProductions;

    // Getting productions from user
    for(int i = 0; i < numProductions; i++) {
        cout << "Enter Production " << i + 1 << ": ";
        cin >> temp;
        productionSizes[i] = temp.size();
        parentNonTerminal += temp;
        if(i != numProductions - 1)
            parentNonTerminal += "|";
    }

    // Displaying the production rule
    cout << "Production Rule: " << parentNonTerminal << endl;

    // Left factoring algorithm
    char currentChar = parentNonTerminal[3]; // Assuming the first production starts at index 3
    for(int i = 0, k = 3; i < numProductions; i++) {
        if(currentChar == parentNonTerminal[k]) {
            if(parentNonTerminal[k + 1] == '|') {
                production1 += "#";
                parentNonTerminal.insert(k + 1, 1, parentNonTerminal[0]);
                parentNonTerminal.insert(k + 2, 1, '\'');
                k += 4;
            } else {
                production1 += "|" + parentNonTerminal.substr(k + 1, productionSizes[i] - 1);
                parentNonTerminal.erase(k - 1, productionSizes[i] + 1);
            }
        } else {
            while(parentNonTerminal[k++] != '|');
        }
    }

    // Left factoring for the second time
    char currentChar2 = production1[6]; // Assuming the first production starts at index 6
    for(int i = 0, k = 6; i < numProductions - 1; i++) {
        if(currentChar2 == production1[k]) {
            if(production1[k + 1] == '|') {
                production2 += "#";
                production1.insert(k + 1, 1, production1[0]);
                production1.insert(k + 2, 2, '\'');
                k += 5;
            } else {
                temp.clear();
                for(int s = k + 1; s < production1.length(); s++)
                    temp.push_back(production1[s]);
                production2 += "|" + temp;
                production1.erase(k - 1, temp.length() + 2);
            }
        }
    }

    // Erasing extra '|' from the end of production2
    production2.erase(production2.size() - 1);

    // Displaying the productions after left factoring
    cout << "After Left Factoring: " << endl;
    cout << parentNonTerminal << endl;
    cout << production1 << endl;
    cout << production2 << endl;

    return 0;
}
