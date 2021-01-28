// DSA-Application.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
using namespace std;
#include "MedicalRecordList.h"
#include "SearchMedicalRecord.h"
#include "Patients.h"
#include "Queue.h"
#include <iostream>



int main()
{
    static int queuenumber = 1;

    // Add new Patients
    Patients P1 = Patients("Lim Koh Fee", "S0981234J", "Visited 10 times, Had previous heart attacks, Stroke from stress, Fell down stairs, vomit blood, allergic to nearly all drugs except penicillin");
    Patients P2 = Patients("Wang Si Liew", "S1023384T", "Visited 2 times, had spine surgery after car crash, not allergic to any drugs, partially blind and deaf");
    Patients P3 = Patients("Xiao Lah Zhi", "S9985242G", "Visited 1 time, Had deep open wound");
    Patients P4 = Patients("Pris Hel Mee", "S2342352Y", "Visited 3 time, Had flu jab");

    // Add new List
    MedicalRecordList MRL1;

    //Populate the lsit
    MRL1.add(P1);
    MRL1.add(P2);
    MRL1.add(P3);
    MRL1.add(P4);

    // Print List
    MRL1.print();

    // Search medical record by IC
    MRL1.search("S1023384T"); 

    // Add new queue
    Queue Booking;

    //if (user press enqueue option, and successfully added, increase queue number by 1)
    // Add patient to queue
    Booking.enqueue(P1,queuenumber);
    Booking.enqueue(P2,queuenumber);
    queuenumber++;
    Booking.enqueue(P3,queuenumber);
    queuenumber++;
    Booking.enqueue(P4, queuenumber);
    queuenumber++;

    // Add Front patient variable
    Patients Front;

    // Put front patient from queue into variable Front
    Booking.getFront(Front);

    // Print Front patient variable's name
    cout << "\n" << Front.getName() << "\n" ;


    Booking.dequeue(Front);
    string FrontQueuePatient = Front.getName();
    cout << "\nCurrent Number: " << Booking.displayfrontQueueNum() << "\t Patient: " << FrontQueuePatient;

    Booking.dequeue(Front);
    FrontQueuePatient = Front.getName();
    cout << "\nCurrent Number: " << Booking.displayfrontQueueNum() << "\t Patient: " << FrontQueuePatient;

    Booking.dequeue(Front);
    FrontQueuePatient = Front.getName();
    cout << "\nCurrent Number: " << Booking.displayfrontQueueNum() << "\t Patient: " << FrontQueuePatient;

   

    int Lastqueue = Booking.displayfrontQueueNum()+1;
    Booking.dequeue(Front);
    FrontQueuePatient = Front.getName();
    cout << "\nCurrent Number: " << Lastqueue << "\t Patient: " << FrontQueuePatient;
}

