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
   ifstream inf("test5.cpp");
   if (!inf)
   {
      cout<<"File could not be opend.\n";
      exit(1);
   }
   string tmp;
   while (getline(inf,tmp)) program.push_back(tmp);
   inf.close();
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
   bool instr=false;
   for (int i=0;i<sourceLine.size();++i)
   {
      if (sourceLine[i]=='"' && (!i || sourceLine[i-1]!='\\'))
      {
         instr=!instr;
         sourceLine[i]=' ';
      }
      else if (instr)
      {
        if (sourceLine[i]=='\\') sourceLine[i+1]=' ';
        sourceLine[i]=' ';
      }
   }
}

void delCharConsts( string &sourceLine )
{
   bool inch=false;
   for (int i=0;i<sourceLine.size();++i)
   {
      if (sourceLine[i]=='\'' && (!i || sourceLine[i-1]!='\\'))
      {
         inch=!inch;
         sourceLine[i]=' ';
      }
      else if (inch)
      {
        if (sourceLine[i]=='\\') sourceLine[i+1]=' ';
        sourceLine[i]=' ';
      }
   }
}

void extractIdentifiers( string &sourceLine, vector< string > &identifiers )
{
   int n=sourceLine.size();
   for (int i=0;i<n;++i)
   {
      int j=i;
      int ts=0;
      char tmp[32]{};
      if (isalpha(sourceLine[i]) || sourceLine[i]=='_')
      {
         while (j<n && (isalnum(sourceLine[j]) || sourceLine[j]=='_'))  if (ts<31) tmp[ts++]=sourceLine[j++];
         i=j-1;
         tmp[ts]='\0';
         if (!keyword(tmp) && ts>0)
         {
            identifiers.push_back(tmp);
            if (duplicate(identifiers,identifiers.size()-1)) identifiers.pop_back();
         }
      }
   }
}

void store( vector< string > &identifiers )
{
   ofstream outf("identifiers.txt");
   if (!outf)
   {
      cout<<"File could not be opend.\n";
      exit(1);
   }
   for (int i=0;i<identifiers.size();++i) outf<<identifiers[i]<<"\n";
   outf.close();
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