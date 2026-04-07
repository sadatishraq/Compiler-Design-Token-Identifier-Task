#include <iostream>
#include <fstream>
using namespace std;

bool checkKeyword(string word) {
    if (word == "int" || word == "float" || word == "double" ||
        word == "char" || word == "return" || word == "if" ||
        word == "else" || word == "while" || word == "for" ||
        word == "cout" || word == "endl") {
        return true;
    }
    return false;
}

int main() {
    ifstream file("input.txt");

    if (!file) {
        cout << "Cannot open file!" << endl;
        return 0;
    }

    string str;
    int lineCount = 1;

    while (getline(file, str)) {
        cout << "Line " << lineCount << ":" << endl;

        string word = "";

        for (int i = 0; i <= str.length(); i++) {

            char ch;
            if (i < str.length())
                ch = str[i];
            else
                ch = ' ';

            if ((ch >= 'a' && ch <= 'z') ||
                (ch >= 'A' && ch <= 'Z') ||
                (ch >= '0' && ch <= '9')) {

                word = word + ch;
            }
            else {

                if (word != "")
                {
                    if (checkKeyword(word))
                    {
                        cout << word << " : keyword" << endl;
                    }
                    else if (word[0] >= '0' && word[0] <= '9')
                    {
                        cout << word << " : number" << endl;
                    }
                    else {
                        cout << word << " : identifier" << endl;
                    }
                    word = "";
                }


                if (ch == '+' || ch == '-' || ch == '*' || ch == '/' ||
                    ch == '=' || ch == '<' || ch == '>') {

                    cout << ch << " : operator" << endl;
                }


                else if (ch == ';' || ch == ',' || ch == '(' ||
                         ch == ')' || ch == '{' || ch == '}') {

                    cout << ch << " : symbol" << endl;
                }

                else if (ch == '"')
                {
                    string text = "\"";
                    i++;

                    while (i < str.length() && str[i] != '"')
                    {
                        text = text + str[i];
                        i++;
                    }

                    text = text + "\"";
                    cout << text << " : string" << endl;
                }
            }
        }

        cout << endl;
        lineCount++;
    }

    file.close();
    return 0;
}
