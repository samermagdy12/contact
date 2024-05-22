#include <conio.h>
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
  string alpha;
  int nOfchar;
  string chnameFirstLetter;
  int namesfound;
  int position = 0;
  char ch;

  string arr[] = {"Adam", "Aisha", "Ahmed", "Amina", "Amir",
                  "Bahaa", "Baraa", "Basma", "Bilal", "Bushra",
                  "Dahlia", "Dina", "David", "Dana", "Daniel",
                  "Esraa", "Emily", "Elie", "Eman", "Elias",
                  "Faten", "Fares", "Fatima", "Farah", "Fadi",
                  "Gabriel", "Grace", "Ghassan", "Ghada", "George",
                  "Hayat", "Hussain", "Hana", "Hassan", "Hadeel",
                  "Imad", "Ivy", "Isra", "Ibrahim", "Inaya",
                  "Joseph", "Julia", "Jawad", "Jana", "Jamal",
                  "Kareen", "Khaled", "Karim", "Kinda", "Kiana",
                  "Leila", "Luca", "Lara", "Layla", "Laith",
                  "Mark", "Maya", "Mariam", "Mohammed", "Mustafa",
                  "Nada", "Nassim", "Nadia", "Nabil", "Nour",
                  "Osman", "Omar", "Olivia", "Ola", "Othman",
                  "Pari", "Paul", "Paula", "Peter", "Pamela",
                  "Quan", "Queenie", "Qasim", "Qamar", "Qais",
                  "Rayan", "Rita", "Rafik", "Rana", "Rami",
                  "Sami", "Samir", "Sara", "Said", "Selma",
                  "Tarek", "Tamara", "Tala", "Tara", "Tariq",
                  "Uthman", "Usama", "Ula", "Umar", "Umaima",
                  "Vinny", "Vivek", "Vera", "Vanessa", "Victor",
                  "Waleed", "Wendy", "Wasim", "Walid", "Wafa",
                  "Yara", "Yasin", "Yasmin", "Youssef", "Yara",
                  "Zain", "Zaina", "Zara", "Ziad", "Zaid"};

  cout << "\nEnter First Letter(s) of Name to Print (Esc to Exit): ";
  while (true)
  {
    ch = _getch();

    alpha[0] = toupper(alpha[0]);

    if (ch == 27)
      break;

    if (ch == -32)
    {
      ch = _getch();

      switch (ch)
      {
      case 75:
        if (position > 0)
        {
          position--;
        }
        break;
      case 77:
        if (position < alpha.length())
        {
          position++;
        }
        break;
      default:
        break;
      }
    }
    else if (ch == '\b')
    {
      system("CLS");
      cout << "\nEnter First Letter(s) of Name to Print (Esc to Exit): ";
      alpha.erase(position - 1, 1);
      position--;
      cout << alpha << "|";
      continue;
    }
    else if (isprint(ch))
    {
      alpha.insert(position, 1, ch);
      position++;
    }

    system("CLS");
    cout << "\nEnter First Letter(s) of Name to Print (Esc to Exit): ";
    cout << alpha.substr(0, position) << "|" << alpha.substr(position) << endl;

    namesfound = 0;

    for (int i = 0; i < sizeof(arr) / sizeof(string); i++)
    {
      if (arr[i].compare(0, position, alpha) == 0)
      {
        namesfound++;
        cout << "\n"
             << arr[i];
      }
    }
    if (namesfound == 0)
    {
      cout << "No names found that start with " << alpha << "\n";
    }
  }

  return 0;
}
