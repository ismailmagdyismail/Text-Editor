#include "profile.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
//-------------------------------
string fileName;
vector<string>text;

//-------------------------------

void menu()
{
    // displays menu to the user
    cout<<"\n>>>Menu\n";
    cout<<"1-Add new text to the end of the file\n";
    cout<<"2-Display content of the text file\n";
    cout<<"3-Empty File\n";
    cout<<"4-Encrypt File\n";
    cout<<"5-Decrypt File\n";
    cout<<"6-Merge with another file\n";
    cout<<"7-Count the number of words in the File\n";
    cout<<"8-Count the number of characters in the File\n";
    cout<<"9-Count the number of lines in the File\n";
    cout<<"10-Search for a word in the file\n";
    cout<<"11-Count the number of times a word exists in the file\n";
    cout<<"12-Turn the file content to upper case\n";
    cout<<"13-Turn the file content to lower case\n";
    cout<<"14-Turn the file content to 1st caps\n";
    cout<<"15-SAVE\n";
    cout<<"16-Open another file\n";
    cout<<"17-EXIT\n";
}

//-------------------------------
void loadText(const string& name)
{
    // load all the text from the file
    char line[1000];
    ifstream file;
    file.open(name);

    while (!file.eof())
    {
        file.getline(line,1000);
        text.push_back(line);
        if(text.back().empty()||text.back()==" ")
            text.pop_back();
    }
    file.close();
}

//-------------------------------

void getFileName()
{
    // get the name of the file that the user wants to open
    cout<<">>>Enter file name : ";
    string name;cin>>name;
    name+=".txt";
    ifstream file;
    file.open(name);

    //if there is no such file , it creates a new file with the chosen name
    if(!file)
    {
        cout<<"\n>>>A new file has with the name "<<name<<" been created for you :)\n";
        file.close();
        ofstream newFile;
        newFile.open(name);
        newFile.close();
        fileName=name;
    }
    // else open the file of that name
    else
    {
        file.close();
        cout<<"\n>>>File opened successfully :)\n";
        fileName=name;
        loadText(fileName);
    }
}

//-------------------------------

void appendText()
{
    // add text to the end of the file
    cin.ignore();

    string word;
    while (true)
    {
        cout<<">>>Enter a line(s) of text to add to the file or press (Ctrl+D)for mac or (Ctrl+Z)for windows to stop : ";
        getline(cin,word);
        if(word=="NULL")
            break;
        else
        {
            text.push_back(word);
        }
    }
}

//-------------------------------

void displayFile()
{
    for (const string & i : text)
    {
        cout<<i<<endl;
    }
}

//-------------------------------

void emptyFile()
{
    text.clear();
}

//-------------------------------
void encryptFile()
{
    cout<<"\n>>>File Encrypted and secure\n";
    for (string & i : text)
    {
        if(i==" ")
            continue;
        else
        {
            for (char & j : i)
            {
                if(j!=' ')
                    j++;
            }
        }
    }
}

//-------------------------------

void decryptFile()
{
    cout<<"\n>>>File Decrypted\n";
    for (string & i : text)
    {
        if(i==" ")
            continue;
        else
        {
            for (char & j : i)
            {
                j--;
            }
        }
    }
}

//-------------------------------

void mergeFiles()
{
    string name;
    cout<<">>>Enter the name of the file you want to merge : ";
    cin>>name;
    name+=".txt";
    ifstream file;
    file.open(name);
    if(file)
    {
        file.close();
        loadText(name);
        cout<<"\n>>>Files merged successfully\n";
    }
    else
    {
        file.close();
        cout<<"\n>>>Invalid file Name\n";
    }
}

//-------------------------------

void countWords()
{
    int counter=0;
    for (const auto & i : text)
    {
        for (int j = 0; j <i.size()-1; ++j)
        {
            if(i[j]==' '&& isalpha(i[j+1])&& isalpha(i[j-1]))
                counter++;
        }
    }
    cout<<"\n>>>There are "<<counter+text.size()<<" words in this File\n";
}

//-------------------------------

void countCharacters()
{
    int counter=0;
    for (const auto & i : text)
    {
        for (const char& j : i)
        {
            if(isalpha(j))
                counter++;
        }
    }
    cout<<"\n>>>There are "<<counter<<" characters int this file\n";
}

//-------------------------------

void countLines()
{
    cout<<"\n>>>There are "<<text.size()<<" lines in this File\n";
}

//-------------------------------

void countWordOccurrence()
{
    int counter = 0;
    string word;
    cout<<">>>Enter the word you that you want to know number of its occurrences : ";
    cin>>word;
    cin.ignore();
    for (const auto & i : text)
    {
        for (int j = 0; j <i.size(); ++j)
        {
            if(word==i.substr(j,word.size()))
            {
                if((i[j+word.size()]==' '||j+word.size()==i.size())&&(i[j-1]==' '||j==0))
                    counter++;
            }
        }
    }
    if(counter)
        cout<<"\n>>>The word "<<word<<" was Repeated "<<counter<<" times in the file \n";
    else
        cout<<"\n>>>The word "<<word<<" doesn't exist in this file \n";
}

//-------------------------------

void toUpper()
{
    for (auto & i : text)
    {
        for (char& j : i)
        {
            if(isalpha(j))
                j=toupper(j);
        }
    }
}

//-------------------------------

void toLower()
{
    for (auto & i : text)
    {
        for (char& j : i)
        {
            if(isalpha(j))
                j=tolower(j);
        }
    }
}

//-------------------------------

void firstCaps()
{
    for (auto & i : text)
    {
        for (int j = 0; j <i.size(); ++j)
        {
            if((j==0||i[j-1]==' ')&&i[j]!=' ')
                i[j]= toupper(i[j]);
        }
    }
}

//-------------------------------

void findWord()
{
    int counter = 0;
    string word;
    cout<<">>>Enter the word you that you want to know search for : ";
    cin>>word;
    cin.ignore();
    for (const auto & i : text)
    {
        for (int j = 0; j <i.size(); ++j)
        {
            if(word==i.substr(j,word.size()))
            {
                if((i[j+word.size()]==' '||j+word.size()==i.size())&&(i[j-1]==' '||j==0))
                    counter++;
            }
        }
    }
    if(counter)
        cout<<"\n>>>The word "<<word<<" was found :)\n";
    else
        cout<<"\n>>>The word "<<word<<" doesn't exist in this file :(\n";
}
//-------------------------------

void saveFile()
{
    ofstream file;
    file.open(fileName);
    for (const auto & i : text)
    {
        file<<i<<endl;
    }
    cout<<"\n>>>File saved successfully :)\n";
    file.close();
}

//-------------------------------

void checkChoice()
{
    cout<<">>>Enter your choice : ";
    string choice;cin>>choice;
    while (choice.size()>2||choice[0]>'9'||choice[0]=='0'||choice[1]>'7'||choice.empty())
    {
        cout<<">>>Enter a valid choice : \n";
        cin>>choice;
    }
    if(choice=="1")
    {
        appendText();
        menu();
        checkChoice();
    }
    else if(choice=="2")
    {
        displayFile();
        menu();
        checkChoice();
    }
    else if(choice=="3")
    {
        emptyFile();
        menu();
        checkChoice();
    }
    else if(choice=="4")
    {
        encryptFile();
        menu();
        checkChoice();
    }
    else if(choice=="5")
    {
        decryptFile();
        menu();
        checkChoice();
    }
    else if(choice=="6")
    {
        mergeFiles();
        menu();
        checkChoice();
    }
    else if(choice=="7")
    {
        countWords();
        menu();
        checkChoice();
    }
    else if(choice=="8")
    {
        countCharacters();
        menu();
        checkChoice();
    }
    else if(choice=="9")
    {
        countLines();
        menu();
        checkChoice();
    }
    else if(choice=="10")
    {
        findWord();
        menu();
        checkChoice();
    }
    else if(choice=="11")
    {
        countWordOccurrence();
        menu();
        checkChoice();
    }
    else if(choice=="12")
    {
        toUpper();
        menu();
        checkChoice();
    }
    else if(choice=="13")
    {
        toLower();
        menu();
        checkChoice();
    }
    else if(choice=="14")
    {
        firstCaps();
        menu();
        checkChoice();
    }
    else if(choice=="15")
    {
        saveFile();
        menu();
        checkChoice();
    }
    else if(choice=="16")
    {
        cout<<"\n>>>Do you want to save the current file ?\n";
        cout<<"1-YES\n";
        cout<<"2-NO\n";
        int answer;
        cin>>answer;
        if(answer==1)
        {
            saveFile();
        }
        text.clear();
        getFileName();
        menu();
        checkChoice();
    }
    else if(choice=="17")
    {
        cout<<"\n>>>Do you want to save the current file ?\n";
        cout<<"1-YES\n";
        cout<<"2-NO\n";
        int answer;
        cin>>answer;
        if(answer==1)
        {
            saveFile();
        }
        exit(0);
    }
}