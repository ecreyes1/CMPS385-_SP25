// CMPS 385_Assignment 6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//declaring libraries
#include <iostream>
#include<iomanip>
#include <string>
using namespace std;
//size of hash table
const int SIZE = 10;
//status of each record
enum Status { EMPTY, OCCUPIED, DELETED };

//hash values key,value

struct hashValue{
    int key;
    int value;
    Status status;
    hashValue() {
        key = -1;
        value = -1;
        status = EMPTY;
    }

};
//creating table
hashValue hashTable[SIZE];



int HashDel(int key)
{
    //indexing hashtable vales
    int hashIndex = key % SIZE;
    for (int i = 0; i < SIZE; ++i)
    {
        //linear probing
        int index = (hashIndex + 
            i) % SIZE;
        //empty value
        if (hashTable[index].status == EMPTY)
        {
            return -1;
        }

        if (hashTable[index].status == OCCUPIED && hashTable[index].key == key)
        {
            //changed status
            hashTable[index].status =DELETED;
            return index;

        }

    }
    return -1;

}
int HashIns(int key, int value) 
{//indexing hashtable vales
    int hashIndex = key % SIZE;
    for (int i = 0; i < SIZE; i++)
    {
        //linear probing
        int index = (hashIndex + i) % SIZE;
        if (hashTable[index].status == EMPTY|| hashTable[index].status == DELETED)
        {//updates value for key and status
            hashTable[index].key = key;
            hashTable[index].value = value;
            hashTable[index].status = OCCUPIED;
            return index;

        }
        if (hashTable[index].status == OCCUPIED && hashTable[index].key == key) {

            hashTable[index].value = value;
            return 0;

        }


    }
    return -1;



}
//displays table
void DisplayHashTable()
{
    for (int i = 0; i < SIZE; i++) {
        string statusVal;
        switch (hashTable[i].status) 
        {
        case EMPTY: statusVal = "EMPTY"; break;
        case OCCUPIED: statusVal = "FULL"; break;
        case DELETED: statusVal = "DELETED"; break;

        }
        cout << i << "\t" << statusVal;


        if (hashTable[i].status == OCCUPIED) {
            cout << "\t"  << hashTable[i].key << "\t " << hashTable[i].value;
        }

        cout << "\n";

}


}
int main()
{
    cout << "After Insetrion: \n" << endl;
    HashIns(99, 11);
    HashIns(55, 39);
    HashIns(61, 27);

    DisplayHashTable(); 
    cout << endl;
    cout << "After deletion: \n" << endl ;

    HashDel(99);
    HashDel(61); 

    DisplayHashTable();

    return 0;
    
}

