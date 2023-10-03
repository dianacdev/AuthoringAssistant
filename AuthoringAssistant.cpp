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

void GetNumOfNonWSCharacters(string sample_text){
   //This function counts the number of non-whitespace characters.
   //Using the isspace() builtin function - returns a 0 if its a normal character otherwise a nonzero value for a whitespace character.
   int character_count = 0;
   for (int i=0; i < sample_text.length(); i++){
      if (!isspace(sample_text[i])){
         character_count++; 
      }
   }
   cout << "Number of non-whitespace characters: "<< character_count << endl;
}

string ShortenSpace(string sample_text){
   //Removes all double spaces in the text and returns the sample_text
   for (int i=0; i<sample_text.length(); i++){
      if(isspace(sample_text[i]) && isspace(sample_text[i+1])){
         sample_text.erase(sample_text.begin() + i);
      }
   }
   return sample_text;
}

void GetNumOfWords(string sample_text){
   //Counts the number of words in the sample text.
   //Counts the number of whitespaces and adds one that is the number of words in the document.
   int words = 0;
   sample_text = ShortenSpace(sample_text); //removing double spaces
   for (int i=0; i<sample_text.length(); i++){
      if(isspace(sample_text[i])){
         words++;
      }
   }
   words = words + 1;
   cout << "Number of words: "<< words << endl;
}

void FindText(){
   //TODO: Function Placeholder
}

void ReplaceExclamation(){
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
         GetNumOfNonWSCharacters(sample_text);
         cout <<endl;
         ExecuteMenu(selection, sample_text);
      break;
   case 'w': // Number of words
         GetNumOfWords(sample_text);
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
      sample_text = ShortenSpace(sample_text);
      cout<<"Edited text: "<< sample_text<<endl<<endl; 
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