#include <iostream>
#include <string>
using namespace std;

//Prints the menu options
void PrintMenu(){
   cout << "MENU" << endl;
   cout << "c - Number of non-whitespace characters" << endl;
   cout << "w - Number of words" << endl;
   cout << "f - Find text" << endl;
   cout << "r - Replace all !'s" << endl;
   cout << "s - Shorten spaces" << endl;
   cout << "q - Quit" << endl;

   cout << endl<< "Choose an option:" << endl;
}

void GetNumOfNonWSCharacters(){
   // TODO: Function Placeholder
}

void GetNumOfWords(){
   //TODO: Function Placeholder
}

void FindText(){
   //TODO: Function Placeholder
}

void ReplaceExclamation(){
   //TODO: Function Placeholder
}

void ShortenSpace(){
   //TODO: Function Placeholder
}

//Prints the Menu and gets users selection. Recurisive call to itself if selection is not q (Quit)
void ExecuteMenu(char selection, string sample_text)
{
   PrintMenu();
   cin >> selection;

   switch (selection)
   {
   case 'c': // Number of non-whitespace characters
         cout <<endl;
         ExecuteMenu(selection, sample_text);
      break;
   case 'w': // Number of words
         cout <<endl;
         ExecuteMenu(selection, sample_text);
      break;
   case 'f': // Find text
         cout <<endl;
         ExecuteMenu(selection, sample_text);
      break;
   case 'r': // Replace all !'s
         cout <<endl;
         ExecuteMenu(selection, sample_text);
      break;
   case 's': // Shorten spaces
      ExecuteMenu(selection, sample_text);
      break;
   case 'q': // Quit Program
      break;

   default:
      ExecuteMenu(selection, sample_text);
      break;
   }
}

int main() {
   char selection;
   string sample_text;
   // Getting users sample text
   cout <<"Enter a sample text:" << endl;
   getline(cin, sample_text); // Using getline to gather multiple lines of text as long as there is not a newline character.

   cout << endl << "You entered: "<< sample_text <<endl;
   cout << endl;
   //calling the menu function
   ExecuteMenu(selection, sample_text);

   return 0;
}