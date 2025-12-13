#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace::std;

 // reads in a C++ program from a cpp file, and put it to the vector program
void load( vector< string > &program );

// deletes the comment beginning with "//" from sourceLine if any
void delComment( string &sourceLine );

// deletes all string constants from sourceLine
void delStrConsts( string &sourceLine );

// deletes all character constants from sourceLine
void delCharConsts( string &sourceLine );

// extracts all identifiers from sourceLine, and
// put them into the vector identifiers
void extractIdentifiers( string &sourceLine, vector< string > &identifiers );

// stores all non-keyword strings in the vector identifiers into a text file
void store( vector< string > &identifiers );

// return true if and only if "str" is a C++ keyword
bool keyword( string str );

// returns true iff identifiers[ pos ] belongs to identifiers[ 0 .. pos-1 ]
bool duplicate( vector< string > &identifiers, int pos );

const string keywords[] = { "auto", "break", "case", "char", "const",
                            "continue", "default", "define","do", "double",
                            "else", "enum", "extern", "float", "for",
                            "goto", "if", "int", "long", "register",
                            "return", "short", "signed", "sizeof",
                            "static", "struct", "switch", "typedef",
                            "union", "unsigned", "void", "volatile",
                            "while", "bool", "catch", "class",
                            "const_cast", "delete", "dynamic_cast",
                            "explicit", "false", "friend", "inline",
                            "mutable", "namespace", "new", "operator",
                            "private", "protected", "public",
                            "reinterpret_cast", "static_cast", "template",
                            "this", "throw", "true", "try", "typeid",
                            "typename", "using", "virtual", "include" };

int main()
{
   vector< string > program;

   // reads in a C++ program from a cpp file, and put it to the vector program
   load( program );

   vector< string > identifiers;
   string null;

   for( size_t i = 0; i < program.size(); i++ )
   {
      delComment( program[ i ] ); // deletes the comment beginning with "//" from program[ i ]
      delStrConsts( program[ i ] ); // deletes all string constants from program[ i ]
      delCharConsts( program[ i ] ); // deletes all character constants from program[ i ]

      if( program[ i ] != null )
         extractIdentifiers( program[ i ], identifiers );
         // extracts all identifiers from program[ i ], and put them into the vector identifiers
   }

   // stores all non-keyword strings in the vector identifiers into a text file
   store( identifiers );
}

void load( vector< string > &program )
{
    
    string s;
    cin >> s;

    ifstream inFile(s);
    if(!inFile)
    {
        cout << "File could not be opend.\n";
        exit(1);
    }
    string str;
    while(getline(inFile, str))
        program.push_back(str);
}

void delComment( string &sourceLine )
{
   size_t length = sourceLine.size();
   if( length > 1 )
      for( size_t i = 0; i < length - 1; i++ )
         if( sourceLine[ i ] == '/' && sourceLine[ i + 1 ] == '/' )
         {
            sourceLine.erase( i, length );
            break;
         }
}

void delStrConsts( string &sourceLine )
{
    bool inString = false;
    for(int i = 0 ; i < sourceLine.size() ; i++)
    {
        if(sourceLine[i] == '"' && (i == 0 || sourceLine[i - 1] != '\\'))
        {
            inString = !inString;
            sourceLine[i] = ' ';
        }
        else if(inString)
        {
            if(sourceLine[i] == '\\')
                sourceLine[i + 1] = ' ';
            sourceLine[i] = ' ';
        }
    }
}

void delCharConsts( string &sourceLine )
{
    bool inChar = false;
    for(int i = 0 ; i < sourceLine.size() ; i++)
    {
        if(sourceLine[i] == '\'' && (i == 0 || sourceLine[i - 1] != '\\'))
        {
            inChar = !inChar;
            sourceLine[i] = ' ';
        }
        else if(inChar)
        {
            if(sourceLine[i] == '\\')
                sourceLine[i + 1] = ' ';
            sourceLine[i] = ' ';
        }
    }
}
void extractIdentifiers( string &sourceLine, vector< string > &identifiers )
{
    for (int i = 0 ; i < sourceLine.size() ; i++)
    {
        if (isalpha(sourceLine[i]) || sourceLine[i] == '_')
        {
            char temp[32]{};
            int t = 0;

            int j = i;
            while (j < sourceLine.size() && (isalnum(sourceLine[j]) || sourceLine[j] == '_'))
            {
                if (t < 31)
                    temp[t++] = sourceLine[j++];
            }
            temp[t] = '\0';
            i = j - 1;
            if (t == 0) continue;
            if (!keyword(temp))
            {
                identifiers.push_back(temp);
                if (duplicate(identifiers, identifiers.size() - 1))
                    identifiers.pop_back();
            }
        }
    }
}

void store( vector< string > &identifiers )
{
    ofstream outFile("identifiers.txt");
    if(!outFile)
    {
        cout << "File could not be opend.\n";
        exit(1);
    }
    for(int i = 0 ; i < identifiers.size() ; i++)
        outFile << identifiers[i] << "\n";
    outFile.close();
}

bool keyword( string str )
{
   const int numKeywords = 62;
   for( int i = 0; i < numKeywords; i++ )
      if( keywords[ i ] == str )
         return true;

   return false;
}

bool duplicate( vector< string > &identifiers, int pos )
{
   for( int i = 0; i < pos; i++ )
      if( identifiers[ i ] == identifiers[ pos ] )
         return true;

   return false;
}