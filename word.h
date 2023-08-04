#ifndef SDDS_WORD_H
#define SDDS_WORD_H
namespace sdds
{
    struct wordStruct
    {
        char word[64];
        char typeWord[8][64];
        char defination[8][1024];
        int defNum;

    };

    void displayStruct(struct wordStruct w, int num = 0);


}


#endif // SDDS_WORD_H