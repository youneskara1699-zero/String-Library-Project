#include <iostream>
#include <vector>
#include <cctype>  // Added for ispunct, isupper, islower, etc.

using namespace std;

class clsString 
{
private:
    string Value;

public:
    clsString()
    {
        Value = "";
    }

    clsString(string value)
    {
        Value = value;
    }

    void setValue(string value) {
        Value = value;
    }

    string getValue() {
        return Value;
    }
   
    static short length(string S1)
    {
        return S1.length();
    };

    short length()
    {
        return Value.length();
    };

    static short countWords(string S1)
    {
        string delim = " "; // delimiter  
        short Counter = 0;
        short pos = 0;
        string sWord; // define a string variable  

        // use find() function to get the position of the delimiters  
        while ((pos = S1.find(delim)) != std::string::npos)
        {
            sWord = S1.substr(0, pos); // store the word   
            if (sWord != "")
            {
                Counter++;
            }

            //erase() until positon and move to next word.
            S1.erase(0, pos + delim.length());
        }

        if (S1 != "")
        {
            Counter++; // it counts the last word of the string.
        }

        return Counter;
    }

    short countWords()
    {
        return countWords(Value);
    };

    static string upperFirstLetterOfEachWord(string S1)
    {
        bool isFirstLetter = true;

        for (short i = 0; i < S1.length(); i++)
        {
            if (S1[i] != ' ' && isFirstLetter)
            {
                S1[i] = toupper(S1[i]);
            }

            isFirstLetter = (S1[i] == ' ' ? true : false);
        }

        return S1;
    }

    void upperFirstLetterOfEachWord()
    {
        // no need to return value , this function will directly update the object value  
        Value = upperFirstLetterOfEachWord(Value);
    }

    static string lowerFirstLetterOfEachWord(string S1)
    {
        bool isFirstLetter = true;

        for (short i = 0; i < S1.length(); i++)
        {
            if (S1[i] != ' ' && isFirstLetter)
            {
                S1[i] = tolower(S1[i]);
            }

            isFirstLetter = (S1[i] == ' ' ? true : false);
        }

        return S1;
    }

    void lowerFirstLetterOfEachWord()
    {
        // no need to return value , this function will directly update the object value  
        Value = lowerFirstLetterOfEachWord(Value);
    }
    
    static string upperAllString(string S1)
    {
        for (short i = 0; i < S1.length(); i++)
        {
            S1[i] = toupper(S1[i]);
        }
        return S1;
    }

    void upperAllString()
    {
        Value = upperAllString(Value);
    }

    static string lowerAllString(string S1)
    {
        for (short i = 0; i < S1.length(); i++)
        {
            S1[i] = tolower(S1[i]);
        }
        return S1;
    }

    void lowerAllString()
    {
        Value = lowerAllString(Value);
    }

    static char invertLetterCase(char char1)
    {
        return isupper(char1) ? tolower(char1) : toupper(char1);
    }

    static string invertAllLettersCase(string S1)
    {
        for (short i = 0; i < S1.length(); i++)
        {
            S1[i] = invertLetterCase(S1[i]);
        }
        return S1;
    }

    void invertAllLettersCase()
    {
        Value = invertAllLettersCase(Value);
    }

    enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 2 };

    static short countLetters(string S1, enWhatToCount WhatToCount = All)
    {
        if (WhatToCount == All)
        {
            return S1.length();
        }

        short Counter = 0;

        for (short i = 0; i < S1.length(); i++)
        {
            if (WhatToCount == CapitalLetters && isupper(S1[i]))
                Counter++;

            if (WhatToCount == SmallLetters && islower(S1[i]))
                Counter++;
        }

        return Counter;
    }

    short countLetters(enWhatToCount WhatToCount = All)
    {
        return countLetters(Value, WhatToCount);
    }
  
    static short countCapitalLetters(string S1)
    {
        short Counter = 0;

        for (short i = 0; i < S1.length(); i++)
        {
            if (isupper(S1[i]))
                Counter++;
        }

        return Counter;
    }

    short countCapitalLetters()
    {
        return countCapitalLetters(Value);
    }

    static short countSmallLetters(string S1)
    {
        short Counter = 0;

        for (short i = 0; i < S1.length(); i++)
        {
            if (islower(S1[i]))
                Counter++;
        }

        return Counter;
    }

    short countSmallLetters()
    {
        return countSmallLetters(Value);
    }
   
    static short countSpecificLetter(string S1, char Letter, bool MatchCase = true)
    {
        short Counter = 0;

        for (short i = 0; i < S1.length(); i++)
        {
            if (MatchCase)
            {
                if (S1[i] == Letter)
                    Counter++;
            }
            else
            {
                if (tolower(S1[i]) == tolower(Letter))
                    Counter++;
            }
        }

        return Counter;
    }

    short countSpecificLetter(char Letter, bool MatchCase = true)
    {
        return countSpecificLetter(Value, Letter, MatchCase);
    }

    static bool isVowel(char Ch1)
    {
        Ch1 = tolower(Ch1);

        return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));
    }

    static short countVowels(string S1)
    {
        short Counter = 0;

        for (short i = 0; i < S1.length(); i++)
        {
            if (isVowel(S1[i]))
                Counter++;
        }

        return Counter;
    }

    short countVowels()
    {
        return countVowels(Value);
    }

    static vector<string> split(string S1, string Delim)
    {
        vector<string> vString;

        short pos = 0;
        string sWord; // define a string variable  

        // use find() function to get the position of the delimiters  
        while ((pos = S1.find(Delim)) != std::string::npos)
        {
            sWord = S1.substr(0, pos); // store the word   
            if (sWord != "")
            {
                vString.push_back(sWord);
            }

            S1.erase(0, pos + Delim.length());  /* erase() until positon and move to next word. */
        }

        if (S1 != "")
        {
            vString.push_back(S1); // it adds last word of the string.
        }

        return vString;
    }

    vector<string> split(string Delim)
    {
        return split(Value, Delim);
    }

    static string trimLeft(string S1)
    {
        for (short i = 0; i < S1.length(); i++)
        {
            if (S1[i] != ' ')
            {
                return S1.substr(i, S1.length() - i);
            }
        }
        return "";
    }

    void trimLeft()
    {
        Value = trimLeft(Value);
    }

    static string trimRight(string S1)
    {
        for (short i = S1.length() - 1; i >= 0; i--)
        {
            if (S1[i] != ' ')
            {
                return S1.substr(0, i + 1);
            }
        }
        return "";
    }
 
    void trimRight()
    {
        Value = trimRight(Value);
    }

    static string trim(string S1)
    {
        return (trimLeft(trimRight(S1)));
    }

    void trim()
    {
        Value = trim(Value);
    }

    static string joinString(vector<string> vString, string Delim)
    {
        string S1 = "";

        for (string& s : vString)
        {
            S1 = S1 + s + Delim;
        }

        return S1.substr(0, S1.length() - Delim.length());
    }

    static string joinString(string arrString[], short Length, string Delim)
    {
        string S1 = "";

        for (short i = 0; i < Length; i++)
        {
            S1 = S1 + arrString[i] + Delim;
        }

        return S1.substr(0, S1.length() - Delim.length());
    }

    static string reverseWordsInString(string S1)
    {
        vector<string> vString;
        string S2 = "";

        vString = split(S1, " ");

        // declare iterator
        vector<string>::reverse_iterator iter = vString.rbegin();

        while (iter != vString.rend())
        {
            S2 += *iter + " ";
            ++iter;
        }

        if (!S2.empty()) {
            S2 = S2.substr(0, S2.length() - 1); //remove last space.
        }

        return S2;
    }

    void reverseWordsInString()
    {
        Value = reverseWordsInString(Value);
    }

    static string replaceWord(string S1, string StringToReplace, string sReplaceTo, bool MatchCase = true)
    {
        vector<string> vString = split(S1, " ");

        for (string& s : vString)
        {
            if (MatchCase)
            {
                if (s == StringToReplace)
                {
                    s = sReplaceTo;
                }
            }
            else
            {
                if (lowerAllString(s) == lowerAllString(StringToReplace))
                {
                    s = sReplaceTo;
                }
            }
        }

        return joinString(vString, " ");
    }

    string replaceWord(string StringToReplace, string sReplaceTo, bool MatchCase = true)
    {
        return replaceWord(Value, StringToReplace, sReplaceTo, MatchCase);
    }

    static string removePunctuations(string S1)
    {
        string S2 = "";

        for (short i = 0; i < S1.length(); i++)
        {
            if (!ispunct(S1[i]))
            {
                S2 += S1[i];
            }
        }

        return S2;
    }

    void removePunctuations()
    {
        Value = removePunctuations(Value);
    }
};

int main()
{
    clsString String1;
    clsString String2("Mohammed");

    String1.setValue("Ali Ahmed");

    cout << "String1 = " << String1.getValue() << endl;
    cout << "String2 = " << String2.getValue() << endl;

    cout << "Number of words: " << String1.countWords() << endl;

    cout << "Number of words: "
         << clsString::countWords("Fadi ahmed rateb omer") << endl;

    cout << "Number of words: "
         << clsString::countWords("Mohammed Saqer Abu-Hadhoud") << endl;

    //---------------
    clsString String3("hi how are you?");

    cout << "String 3 = " << String3.getValue() << endl;
    cout << "String Length = " << String3.length() << endl;

    String3.upperFirstLetterOfEachWord();
    cout << String3.getValue() << endl;

    String3.lowerFirstLetterOfEachWord();
    cout << String3.getValue() << endl;

    String3.upperAllString();
    cout << String3.getValue() << endl;

    String3.lowerAllString();
    cout << String3.getValue() << endl;

    cout << "After inverting a : "
         << clsString::invertLetterCase('a') << endl;

    String3.setValue("AbCdEfg");
    String3.invertAllLettersCase();
    cout << String3.getValue() << endl;

    String3.invertAllLettersCase();
    cout << String3.getValue() << endl;

    cout << "Capital Letters count : "
         << clsString::countLetters("Mohammed Abu-Hadhoud",
                                    clsString::CapitalLetters)
         << endl << endl;

    String3.setValue("Welcome to Jordan");
    cout << String3.getValue() << endl;

    cout << "Capital Letters count :" << String3.countCapitalLetters() << endl;
    cout << "Small Letters count :" << String3.countSmallLetters() << endl;
    cout << "vowels count :" << String3.countVowels() << endl;
    cout << "letter E count :" << String3.countSpecificLetter('E', false) << endl;

    cout << "is letter u vowel? " << clsString::isVowel('a') << endl;
    cout << "Words Count = " << String3.countWords() << endl;

    vector<string> vString = String3.split(" ");

    cout << "\nTokens = " << vString.size() << endl;
    for (string& s : vString)
        cout << s << endl;

    //Trims
    String3.setValue("    Mohammed Abu-Hahdoud     ");
    cout << "\nString     = " << String3.getValue();

    String3.setValue("    Mohammed Abu-Hahdoud     ");
    String3.trimLeft();
    cout << "\n\nTrim Left  = " << String3.getValue();

    String3.setValue("    Mohammed Abu-Hahdoud     ");
    String3.trimRight();
    cout << "\nTrim Right = " << String3.getValue();

    String3.setValue("    Mohammed Abu-Hahdoud     ");
    String3.trim();
    cout << "\nTrim       = " << String3.getValue();

    //Join
    vector<string> vString1 = { "Mohammed","Faid","Ali","Maher" };
    cout << "\n\nJoin String From Vector: \n";
    cout << clsString::joinString(vString1, " ");

    string arrString[] = { "Mohammed","Faid","Ali","Maher" };
    cout << "\n\nJoin String From array: \n";
    cout << clsString::joinString(arrString, 4, " ");

    String3.setValue("Mohammed Saqer Abu-Hahdoud");
    cout << "\n\nString     = " << String3.getValue();

    String3.reverseWordsInString();
    cout << "\nReverse Words : " << String3.getValue() << endl;

    String3.setValue("Mohammed Saqer Abu-Hahdoud");
    cout << "\nReplace : " << String3.replaceWord("Mohammed", "Sari") << endl;

    String3.setValue("This is: a sample text, with punctuations.");
    cout << "\n\nString     = " << String3.getValue();

    String3.removePunctuations();
    cout << "\nRemove Punctuations : " << String3.getValue() << endl;

    // Test the new countLetters method
    String3.setValue("Hello World");
    cout << "\n\nTest countLetters: " << endl;
    cout << "Total letters: " << String3.countLetters() << endl;
    cout << "Capital letters: " << String3.countLetters(clsString::CapitalLetters) << endl;
    cout << "Small letters: " << String3.countLetters(clsString::SmallLetters) << endl;

    system("pause>0");
    return 0;
}