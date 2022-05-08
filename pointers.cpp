///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  Lab 10c - Pointers - EE 205 - Spr 2022
///
/// Explore pointers for fun and profit
///
/// Usage:  pointers
///
/// Result:
///   Just a little story...
///
/// Example:
///   $ pointers
///
/// Compilation:
///   $ g++ -o pointers -Wall -Wextra pointers.cpp
///   This program will only compile in C++ (with g++) not in C (with gcc)
///
/// @file pointers.cpp
/// @version 1.0
///
/// @see https://c-for-dummies.com/caio/pointer-cheatsheet.php
/// @see https://www.codecademy.com/learn/learn-c-plus-plus/modules/learn-cpp-references-and-pointers/cheatsheet
/// @see https://en.wikipedia.org/wiki/Pointer_(computer_programming)
///
/// @author Baishen Wang <baishen@hawaii.edu>
/// @date   17_Apr_2022
///////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <sstream>
using namespace std;

// In this lab, we will use a little Hungarian Notation.
// For example, variables that start with 'p' such as 'pMyChar' means that
// it's a pointer.
// For more information, checkout:
//    https://web.mst.edu/~cpp/common/hungarian.html
//    https://en.wikipedia.org/wiki/Hungarian_notation


// Tell a story about basic datatypes
void firstStory() {
    cout << "The first story" << endl;

    // Allocate 4 variables... one char, short, int and a long
    // The first one has been done for you, it's just commented out...
    char  myChar;
    // Now you do the other 3 (and delete this comment line)
    short myShort;

    int myInt;

    long myLong;

    // Using cout and sizeof(), print the size of the 4 basic datatypes:
    //    char, short, int and long
    cout << "  Sizeof a char is "  << sizeof( myChar )  << " byte"  << endl;
    cout << "  Sizeof a short is " << sizeof( myShort ) << " bytes" << endl;
    cout << "  Sizeof an int is " << sizeof( myInt ) << " bytes" << endl;
    cout << "  Sizeof a long is " << sizeof( myLong ) << " bytes" << endl;

    cout << endl;


    // Allocate 4 pointers, a pointer to a char, short, int and a long
    char*  pMyChar;
    short* pMyShort;

    int* pMyInt;

    long* pMyLong;

    // Using cout and sizeof(), print the size of the 4 pointers
    cout << "  Sizeof a char* is "  << sizeof( pMyChar )  << " bytes" << endl;
    cout << "  Sizeof a short* is " << sizeof( pMyShort ) << " bytes" << endl;
    cout << "  Sizeof a int* is " << sizeof( pMyInt ) << " bytes" << endl;
    cout << "  Sizeof a long* is " << sizeof( pMyLong ) << " bytes" << endl;


    cout << endl;
}


// Tell a story about declaring and accessing pointers.  Also, compare the
// the contents of a pointer with the address of the variable it's pointing
// to.
void secondStory() {
    cout << "The second story" << endl;

    // Allocate 4 variables (char, short, int & long).  Initialize them to
    // 100, 200, 300 and 400.
    char  myChar  = 100;  // This is the letter 'd' in ASCII

    short myShort = 200;

    int myInt = 300;

    long myLong = 400;

    // Allocate 2 pointers (char & short) using the type* name notation:
    char*  pMyChar;
    short* pMyShort;

    // Allocate 2 pointers (int & long) using the type *name notation;
    int   *pMyInt;
    long *pMyLong;

    // Using the & (address of), set each of the pointers to point to their
    // respective variable
    pMyChar  = &myChar;
    pMyShort = &myShort;
    pMyInt = &myInt;
    pMyLong = &myLong;

    // Using cout and the *name notation, use the pointer to print the value
    cout << "  The value that pMyChar points to is "  << *pMyChar  << endl;
    cout << "  The value that pMyShort points to is " << *pMyShort << endl;
    cout << "  The value that pMyInt points to is " << *pMyInt << endl;
    cout << "  The value that pMyLong points to is " << *pMyLong << endl;

    cout << endl;

    // Using cout, print the address of each integer datatype on one one line
    // ...and the value of each pointer on the next.
    //
    // Note:  Casting memory addresses to void* is one way to get cout to
    //        print addresses.
    cout << "  The address of myChar is " << (void*)&myChar << endl;
    cout << "   The value of pMyChar is " << (void*)pMyChar << endl;
    cout << "  The address of myShort is " << (void*)&myShort << endl;
    cout << "   The value of pMyShort is " << (void*)pMyShort << endl;
    cout << "  The address of myInt is " << (void*)&myInt << endl;
    cout << "   The value of pMyInt is " << (void*)pMyInt << endl;
    cout << "  The address of myLong is " << (void*)&myLong << endl;
    cout << "   The value of pMyLong is " << (void*)pMyLong << endl;
    cout << endl;

}


// INTERMISSION
//
// Create 4 pointers (the usual datatypes) in "global" space
// The 's' means static.  The 'p' means pointer.
//
// Initialize them all to NULL
static char*  spMyChar  = NULL ;
static short* spMyShort = NULL ;
static int*   spMyInt   = NULL ;
static long*  spMyLong  = NULL ;


// Let's work with dynamic memory
//
// For each of the datatypes, do the following:
//  1.  If the static pointer == NULL, then
//          Use malloc() to allocate that data on the heap
//          ...and set it to 100, 200, 300 or 400 (like above)
//      Else
//          (if we are here, then the pointer is valid)
//          So, add 5 to the data
//  2.  Print the value
void thirdStory() {
    cout << "The third story" << endl;

    // Step 1
    if( spMyChar == NULL ) {
        spMyChar = (char*) malloc (sizeof( char ));
        *spMyChar = 100;  // remember, 100 maps to 'd' in ASCII
    } else {
        *spMyChar +=5;
    }
    if( spMyShort == NULL ) {
        spMyShort = (short*) malloc (sizeof( short ));
        *spMyShort = 200;
    } else {
        *spMyShort +=5;
    }
    if( spMyInt == NULL ) {
        spMyInt = (int*) malloc (sizeof( int ));
        *spMyInt = 300;
    } else {
        *spMyInt +=5;
    }
    if( spMyLong == NULL ) {
        spMyLong = (long*) malloc (sizeof( long ));
        *spMyLong = 400;
    } else {
        *spMyLong +=5;
    }



    // Step 2
    cout << "  The value pointed to by spMyChar is "  << *spMyChar  << endl;
    cout << "  The value pointed to by spMyShort is " << *spMyShort << endl;
    cout << "  The value pointed to by spMyInt is " << *spMyInt << endl;
    cout << "  The value pointed to by spMyLong is " << *spMyLong << endl;

    cout << endl;
}


// Let's cleanup our dynamic memory
//
// For each of the datatypes, do the following:
//  1.  If the static pointer == NULL, then
//          print "  foo is NULL"
//      Else
//          free the memory under the pointer
//          Set the pointer to NULL
//          Print a message
void fourthStory() {
    cout << "The fourth story" << endl;

    if( spMyChar == NULL ) {
        cout << "  spMyChar is NULL" << endl;
    } else {
        free( spMyChar );  // Release the memory from the heap
        spMyChar = NULL;   // Set the pointer back to NULL
        cout << "  Released memory under spMyChar" << endl;
    }
    if( spMyShort == NULL ) {
        cout << "  spMyShort is NULL" << endl;
    } else {
        free( spMyShort );
        spMyShort = NULL;
        cout << "  Released memory under spMyShort" << endl;
    }
    if( spMyInt == NULL ) {
        cout << "  spMyInt is NULL" << endl;
    } else {
        free( spMyInt );
        spMyInt = NULL;
        cout << "  Released memory under spMyInt" << endl;
    }
    if( spMyLong == NULL ) {
        cout << "  spMyLong is NULL" << endl;
    } else {
        free( spMyLong );
        spMyLong = NULL;
        cout << "  Released memory under spMyLong" << endl;
    }

    cout << endl;
}


// Pointers to objects are just like pointers to native data types.
void fifthStory() {
    cout << "The fifth story" << endl;

// Step 1:
// Research a class called std::stringbuf
// Add the appropriate #include at the top of the file

// Step 2:
// Instantiate an instance of std::stringbuf into a variable called myObject
    std::stringbuf myObject;

// Step 3:
// Create a pointer object to a std::stringbuf
    std::stringbuf *pMyObject;
// Step 4:
// Set the pointer you created in Step 3 = to the address of myObject
    pMyObject = &myObject;

// Step 5:
// Print the size of the pointer
// Print the address stored in the pointer (see, it's just like the other pointers)
    cout << "  Sizeof a pointer to some object is " << sizeof( pMyObject ) << "bytes" << endl;
    cout << "  The value of pMyObject is " << &pMyObject << endl;

// Step 6:
// Use the sgetc() method of std::stringbuf and the *name form of the pointer
    cout << "  The result of sgetc() is " << (*pMyObject).sgetc() << endl;

// Step 7:
// Now, on your own use the in_avail() method of std::stringbuf (look it up online!) and
// print the result
    cout << " The result of in_avail() is " << pMyObject->in_avail() << endl;
    cout << endl;
}


// For our sixth story, we will look into passing data by reference...
// Type out the two "square" functions from the slides...  Call the first one
// square( long a ) and the second one squareRef( long* a ).

// Add the two square functions here
long square( long a ) {
    a = a * a;
    return a;
}
long squareRef( long* a ) {
    *a = *a * *a;
    return *a;
}


// Done with the two square functions



void sixthStory() {
    cout << "The sixth story" << endl;

    long a = 4;  // This will be called by value
    long b = 4;  // This will be called by reference

    // Write cout string that prints:
    cout << "  The square of 4 is << " << square(a) << endl;
    cout << "  The variable a is called by value, so it's still " << a << endl;


    // Write cout string that prints:
    cout << "  The square of 4 is << " << squareRef( &b ) << endl;
    cout << "  The variable b is called by reference, so it's now " << b << endl;

    cout << endl;
}


int main() {
    firstStory()  ;
    secondStory() ;
    thirdStory()  ;
    thirdStory()  ;   // Call it again
    thirdStory()  ;   // ...and one more time
    fourthStory() ;
    fourthStory() ;   // Call it one more time
    fifthStory()  ;
    sixthStory()  ;
}
