#define _CRT_SECURE_NO_WARNINGS
#include "dictionary.h"
#include <fstream>
#include <string.h>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

namespace sdds
{
    struct dictionary
    {
        struct wordStruct words[10];
        int wordNum = 0;
    };
    struct dictionary dict;

    int LoadDictionary(const char* filename)
    {
        dict.wordNum = 0;
        ifstream file;
        file.open(filename);
        if (file.fail())
        {
            return 1;
        }
        while (!file.eof())
        {
            string line;
            getline(file, line);
            const char* wordTemp = line.c_str();

            while (true)
            {
                string line1, line2, line3;
                if (file.eof())
                {
                    break;
                }
                getline(file, line1);
                if (line1[0] != '\t')
                {
                    break;
                }

                stringstream ss(line1);
                char c = ' ';
                while (true)
                {
                    ss >> c;
                    if (c != ' ')
                    {
                        ss.putback(c);
                        break;
                    }

                }
                getline(ss, line2, ':');

                const char* typeTemp = line2.c_str();
                getline(ss, line3);
                line3.erase(0, 1);
                const char* def = line3.c_str();


                AddWord(wordTemp, typeTemp, def);
            }



        }
        file.close();
        return 0;
    }
    void SaveDictionary(const char* filename)
    {
        ofstream file;
        file.open(filename);
        for (int i = 0; i < dict.wordNum; i++)
        {
            file << (char*)dict.words[i].word << "\n";
            for (int j = 0; j < dict.words[i].defNum; j++)
            {
                file << "\t" << (char*)dict.words[i].typeWord[j] << ": " << (char*)dict.words[i].defination[j] << "\n";
            }
            file << "\n";
        }

        file.close();
    }
    void DisplayWord(const char* word)
    {
        for (int i = 0; i < dict.wordNum; i++)
        {
            if (strcmp(word, dict.words[i].word) == 0)
            {
                cout << "FOUND: ";
                displayStruct(dict.words[i]);
                return;
            }
        }
        cout << "NOT FOUND: word [" << word << "] is not in the dictionary.\n";

    }
    void AddWord(const char* word, const char* type, const char* definition)
    {
        for (int i = 0; i < dict.wordNum; i++)
        {
            if (strcmp(word, dict.words[i].word) == 0)
            {
                int numT = dict.words[i].defNum;
                strcpy(dict.words[i].typeWord[numT], type);
                strcpy(dict.words[i].defination[numT], definition);
                dict.words[i].defNum += 1;
                return;
            }
        }
        int dT = dict.wordNum;
        strcpy(dict.words[dT].word, word);
        dict.words[dT].defNum = 1;
        strcpy(dict.words[dT].typeWord[0], type);
        strcpy(dict.words[dT].defination[0], definition);
        dict.wordNum += 1;
        return;
    }
    int UpdateDefinition(const char* word, const char* type, const char* definition)
    {
        for (int i = 0; i < dict.wordNum; i++)
        {
            if (strcmp(word, dict.words[i].word) == 0)
            {
                cout << "The word ";
                displayStruct(dict.words[i], 1);
                cout << "Which one to update? ";
                int updateNum;
                cin >> updateNum;
                updateNum -= 1;
                strcpy(dict.words[i].typeWord[updateNum], type);
                strcpy(dict.words[i].defination[updateNum], definition);
                return 1;
            }
        }
        return 0;
    }
}