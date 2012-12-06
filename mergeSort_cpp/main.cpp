//
//  main.cpp
//  mergeSort_cpp
//
//  Created by Andrew Breja on 12/5/12.
//  Copyright (c) 2012 Andrew Breja. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <pthread.h>
#include <semaphore.h>

using namespace std;


class Sorter
{
    public:
    
    // Constructor
    Sorter(vector<int> *givenMasterItemCollection, int givenNumberOfItems, int givenNumberOfThreads, int givenThreadId);

    int getItem();
    void incrementIndex();
    void run();
        
    private:
    
    vector<int> *workingItemCollection;
    vector<int> *masterItemCollection;
    
    int numberOfItems;
    int numberOfThreads;
    int threadId;
    
    int beginningPosition;
    int endingPosition;
    
    int indexLocation;
    
    void calculatePositions();
};


// Constructor
Sorter::Sorter(vector<int> *givenMasterItemCollection, int givenNumberOfItems, int givenNumberOfThreads, int givenThreadId)
{
    // Set given variables
    this->masterItemCollection = givenMasterItemCollection;
    this->numberOfItems = givenNumberOfItems;
    this->numberOfThreads = givenNumberOfThreads;
    this->threadId = givenThreadId;
    
    // Initialize variables
    this->indexLocation = 0;
    this->workingItemCollection = NULL;
}

// Calculate positions
void Sorter::calculatePositions()
{
    // Beginning position
    this->beginningPosition = (this->numberOfItems / this->numberOfThreads) * this->threadId;
    
    // Ending position
    this->endingPosition = this->beginningPosition + (this->numberOfItems / this->numberOfThreads) - 1;
    
    // The last thread gets the slack
    if ((this->threadId == this->numberOfThreads - 1) && (this->endingPosition < this->numberOfItems - 1))
    {
        this->endingPosition = this->numberOfItems - 1;
    }
}

// Get sorted items
int Sorter::getItem()
{
    // Get an item at the given index location
    return this->workingItemCollection[this->indexLocation];
    
}


int main(int argc, const char * argv[])
{
    vector<int> *masterItemCollection = NULL;

    // Forward declarations
    void generateIntegers(int givenCollectionSize);
    
    


    // insert code here...
    cout << "Hello, World!\n";
    return 0;
}

