#include<stdio.h>

/*---------------------------------------------Concept of Padding---------------------------------------------*/
//Padding is done to access memory easily by accessing it through even addresses
//Paddinng depends on order of members. Below mentioned example explains it well
//Total size is always multiple of longest datatype
void main()
{
    struct C1           //                                              Memory Representation of A
    {                   //                                              |1|2|3|4|5|6|7|8|
        char a;         //size of char : 1 byte  (padding 7 byte)       |c|-|-|-|-|-|-|-|
        double b;       //size of double : 8 byte   (padding 0 byte)    |d|d|d|d|d|d|d|d|
        int c;          //size of int : 4 byte      (padding 4 byte)    |i|i|i|i|-|-|-|-|
    } A;                //Total byte should be : 1 + 8 + 4 = 13 byte

    printf("Size of A: %d\n", sizeof(A));     //prints 24 byte. (Total padding : 11 byte)

    struct C2           //                                              Memory Representation of B
    {                   //                                              |1|2|3|4|5|6|7|8|
        double b;       //size of double : 8 byte   (padding 0 byte)    |d|d|d|d|d|d|d|d|
        char a;         //size of char : 1 byte  (padding 0 byte)       |c|i|i|i|i|-|-|-|
        int c;          //size of int : 4 byte      (padding 3 byte)
    } B;                //Total byte should be : 1 + 8 + 4 = 13 byte

    printf("Size of B: %d\n", sizeof(B));     //prints 16 byte. (Total padding : 03 byte)
}