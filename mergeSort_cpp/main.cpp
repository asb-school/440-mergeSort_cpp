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
    
    vector<int> workingItemCollection;
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
    try
    {
        return this->workingItemCollection.at(this->indexLocation);
    }
    catch (int e)
    {
        return 9999;
    }
    
}

// Set index location
void Sorter::incrementIndex()
{
    this->indexLocation++;
}

void Sorter::run()
{
    // Calculate beginning and ending positions
    this->calculatePositions();
    
    // For each - using beginning and ending positions
    for (int iteratorIndex = this->beginningPosition; iteratorIndex <= this->endingPosition; iteratorIndex++)
    {
        // Copy to temporary local array
        this->workingItemCollection.push_back(this->masterItemCollection->at(iteratorIndex));
    }
    
    // Sort working item collection
    sort(this->workingItemCollection);
}

// Generate random numbers
void generateIntegers(int givenCollectionSize)
{
    
}


int main(int argc, const char * argv[])
{
    // Variables
    vector<int> masterItemCollection;

    int collectionSize = 0;
    int numberOfThreads = 0;
    int lowerstNumber = 0;
    bool notSorted = true;
    
    vector<int> sortedItemList;
    vector<Sorter> sorterList;
    
    
    // Get command line parameters
    if (argc != 2)
    {
    	collectionSize = atoi(argv[1]);
    	numberOfThreads = atoi(argv[2]);
    }
    else
    {
    	cout << "USAGE: arg1: collection size, arg2: number of threads\n";
	return 0;
    }

    // Generate random numbers in the master item collection
    generateIntegers(collectionSize);

    // Debug
    cout << "Unsorted list: \n";

    for (masterItemCollection.begin(), masterItemCollection.end())
    {
        cout << "lala";
    }
    
    
    // THREADING

    // Merge individual items into a giant sorted list
    while (notSorted)
    {
    	// Reset lowest number
    	lowerstNumber = 9999;

    	// For each list
    	for (vector<Sorter>::iterator currentSorter = sorterList.begin(); currentSorter < sorterList.end(); currentSorter++)
    	{
    		// Is item from list a lower number than the current lowest number
    		if (currentSorter.getItem() < lowerstNumber)
    		{
    			lowerstNumber = currentSorter.getItem();
    		}
    	}
    }

    // insert code here...
    cout << "Hello, World!\n";
    return 0;
}

