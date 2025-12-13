#include <cstring>
#include <fstream>
#include <iostream>
using namespace ::std;

// reads in a C++ program from a cpp file, and put it to the array program
void load(char (*program)[100], int& numLines);

// deletes the comment beginning with "//" from sourceLine if any
void delComment(char sourceLine[]);

// deletes all string constants from sourceLine
void delStrConsts(char sourceLine[]);

// deletes all character constants from sourceLine
void delCharConsts(char sourceLine[]);

// extracts all identifiers from sourceLine, and put them into the array identifiers
void extractIdentifiers(char sourceLine[], char identifiers[][32], int& numIdentifiers);

// stores all non-keyword strings in the array identifiers into a text file
void store(char (*identifiers)[32], int numIdentifiers);

// returns true if and only if str is a C++ keyword
bool keyword(char str[]);

// returns true if and only if identifiers[ pos ] belongs to identifiers[ 0 .. pos-1 ]
bool duplicate(char (*identifiers)[32], int pos);

const char keywords[][20] = {"auto", "break", "case", "char", "const", "continue", "default", "define", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while", "bool", "catch", "class", "const_cast", "delete", "dynamic_cast", "explicit", "false", "friend", "inline", "mutable", "namespace", "new", "operator", "private", "protected", "public", "reinterpret_cast", "static_cast", "template", "this", "throw", "true", "try", "typeid", "typename", "using", "virtual", "include"};

int main() {
    char (*program)[100] = new char[500][100];
    int numLines = 0;

    // reads in a C++ program from a cpp file, and put it to the array program
    load(program, numLines);

    char (*identifiers)[32] = new char[500][32];
    int numIdentifiers = 0;

    for (int i = 0; i < numLines; i++) {
        delComment(program[i]);     // deletes the comment beginning with "//" from program[ i ]
        delStrConsts(program[i]);   // deletes all string constants from program[ i ]
        delCharConsts(program[i]);  // deletes all character constants from program[ i ]

        if (strcmp(program[i], "") != 0)
            extractIdentifiers(program[i], identifiers, numIdentifiers);
        // extracts all identifiers from program[ i ], and put them into the array identifiers
    }

    // stores all non-keyword strings in the array identifiers into a text file
    store(identifiers, numIdentifiers);

    delete[] program;
    delete[] identifiers;
}

void load(char (*program)[100], int& numLines) {
    string filename;
    cin >> filename;
    ifstream file(filename);
    if (!file.good()) {
        file.close();
        cout << "open file '" << filename << "' error!" << endl;
        return;
    }
    while (file.getline(program[numLines], 100))
        numLines++;
    file.close();
}

void delComment(char sourceLine[]) {
    size_t length = strlen(sourceLine);
    if (length > 1)
        for (size_t i = 0; i < length - 1; i++)
            if (sourceLine[i] == '/' && sourceLine[i + 1] == '/') {
                sourceLine[i] = '\0';
                return;
            }
}

void delStrConsts(char sourceLine[]) {
    size_t length = strlen(sourceLine);
    bool in_str = false;
    for (size_t i = 0; i < length; i++) {
        if (sourceLine[i] == '"') {
            if (in_str && (i == 0 || sourceLine[i - 1] != '\\')) {
                in_str = false;
                sourceLine[i] = ' ';
            } else
                in_str = true;
        }
        if (in_str && sourceLine[i] != '\\')
            sourceLine[i] = ' ';
    }
}

void delCharConsts(char sourceLine[]) {
    size_t length = strlen(sourceLine);
    for (size_t i = 0; i < length; i++) {
        if (sourceLine[i] == '\'') {
            sourceLine[i] = ' ';
            i++;
            while (i < length && sourceLine[i] != '\'') {
                sourceLine[i] = ' ';
                i++;
            }
            if (i < length && sourceLine[i] == '\'')
                sourceLine[i] = ' ';
        }
    }
}

bool isIdentifierChar(char ch, bool isFirstChar) {
    if (isFirstChar)
        return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch == '_');
    else
        return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9') || (ch == '_');
}

void extractIdentifiers(char sourceLine[], char identifiers[][32], int& numIdentifiers) {
    size_t length = strlen(sourceLine);
    char buffer[32];
    for (size_t i = 0; i < length; i++) {
        if (isIdentifierChar(sourceLine[i], true)) {
            size_t j = 0;
            buffer[j++] = sourceLine[i++];
            while (i < length && isIdentifierChar(sourceLine[i], false) && j < 31)
                buffer[j++] = sourceLine[i++];
            buffer[j] = '\0';
            if (!keyword(buffer))
                strcpy(identifiers[numIdentifiers++], buffer);
            i--;
        }
    }
}

void store(char (*identifiers)[32], int numIdentifiers) {
    ofstream file("identifiers.txt");
    if (!file.good()) {
        file.close();
        cout << "open file 'identifiers.txt' error!" << endl;
        return;
    }
    for (int i = 0; i < numIdentifiers; i++)
        if (!duplicate(identifiers, i))
            file << identifiers[i] << endl;
    file.close();
}

bool keyword(char str[]) {
    size_t numKeywords = sizeof(keywords) / 20;
    for (size_t i = 0; i < numKeywords; i++)
        if (strcmp(keywords[i], str) == 0)
            return true;

    return false;
}

bool duplicate(char (*identifiers)[32], int pos) {
    for (int i = 0; i < pos; i++)
        if (strcmp(identifiers[i], identifiers[pos]) == 0)
            return true;

    return false;
}
