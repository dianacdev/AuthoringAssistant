#include <iostream>
#include <string>
using namespace std;
string find_word;


//Prints the menu options
void PrintMenu(){
   cout << "MENU" << endl;
   cout << "c - Number of non-whitespace characters" << endl;
   cout << "w - Number of words" << endl;
   cout << "f - Find text" << endl;
   cout << "r - Replace all !'s" << endl;
   cout << "s - Shorten spaces" << endl;
   cout << "q - Quit" << endl;
}

int GetNumOfNonWSCharacters(string sample_text){
   //This function counts the number of non-whitespace characters.
   //Using the isspace() builtin function - returns a 0 if its a normal character otherwise a nonzero value for a whitespace character.
   int character_count = 0;
   for (int i=0; i < sample_text.length(); i++){
      if (!isspace(sample_text[i])){
         character_count++; 
      }
   }
   return character_count;
}

string ShortenSpace(string sample_text){
   //Removes all double spaces in the text and returns the sample_text
   string new_text = " ";
   for (int i=0; i<sample_text.length(); i++){
      if(isspace(sample_text[i])){
         while (isspace(sample_text[i]))
         i++;
         i--;
         new_text += " ";
      }
      else{
         new_text += sample_text[i];
      }
   }
   sample_text = new_text;
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
   cout << "Number of words: "<< words << endl;
}

int FindText(string find, string sample_text){
   int found = 0;
   int position = 0;
   int i;
   while ((i = sample_text.find(find, position)) != string::npos)
   {
      found++;
      position = i +1;
   }
   return found;
}

string ReplaceExclamation(string sample_text){
   int position = 0;
   int i;
   while ((i = sample_text.find('!', position)) != string::npos)
   {
      sample_text[i] = '.';
      position = i +1;
   }
   return sample_text;
}


//Prints the Menu and gets users selection. Recurisive call to itself if selection is not q (Quit)
void ExecuteMenu(char selection, string sample_text)
{
   PrintMenu();
   cout << endl<< "Choose an option:" << endl;
   cin >> selection;

   switch (selection)
   {
   case 'c': // Number of non-whitespace characters
         cout << "Number of non-whitespace characters: "<< GetNumOfNonWSCharacters(sample_text) << endl;
         cout <<endl;
         ExecuteMenu(selection, sample_text);
      break;
   case 'w': // Number of words
         GetNumOfWords(sample_text);
         cout <<endl;
         ExecuteMenu(selection, sample_text);
      break;
   case 'f': // Find text
         cout <<"Enter a word or phrase to be found:"<<endl;
         cin.ignore();
         getline(cin, find_word);
         cout << '"'<<find_word<<'"'<< " instances: "<< FindText(find_word, sample_text) <<endl;
         cout <<endl;
         ExecuteMenu(selection, sample_text);
      break;
   case 'r': // Replace all !'s
         sample_text = ReplaceExclamation(sample_text);
         cout << "Edited text: "<< sample_text<<endl;
         cout <<endl;
         ExecuteMenu(selection, sample_text);
      break;
   case 's': // Shorten spaces
      sample_text = ShortenSpace(sample_text);
      cout<<"Edited text:"<< sample_text<<endl<<endl; 
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