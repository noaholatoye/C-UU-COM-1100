//
//  main.cpp
//  UU-COM-110
//
//  Created by Noah Olatoye on 25/02/2019.
//  Copyright © 2019 Noah Olatoye. All rights reserved.
//

# include <iostream>
# include <limits.h>
using namespace std;

int main ()
{
    int people = 10;
    int array [people], maxNbr=0, minNbr=INT_MAX,
    sumNbr=0, tmpNbr, indexMax=0, indexMin=0, indexAve=0, indexSort=0;
    float aveNbr=0;
    
    //get 10 value input from user
    for (int i=0 ; i<people; i++)
    {
        std::cout << "Person " << i + 1 << " : ";
        cin >> array[i];
    }
    
    // Loop to store for the highest, lowest and average runs
    for (int i=0 ; i<people; i++)
    {
        maxNbr = max(maxNbr,array[i]);
        minNbr = min(minNbr,array[i]);
        sumNbr += array[i];
        
        // get the index of highest and lowest runs
        if(maxNbr == array[i])
            indexMax = i + 1;
        else if(minNbr == array[i]){
            indexMin = i +1;
        }
    }
    
    // loop to get the average
    aveNbr = (float(sumNbr)/people);
    for(int i=0;i<people;i++)
    {
        for(int j=i;j<people;j++)
            if(array[i]>array[j])
            {
                tmpNbr = array[i];
                array[i] = array[j];
                array[j] = tmpNbr;
            }
        // get the index of average run
        if(aveNbr == array[i])
            indexAve = i + 1;
    }
    
    // Print the value to the page (highest, lowest and average runs)
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "----------------------------------------------------\n";
    std::cout << "Run the least kilometres:\n";
    std::cout << "Person "<< indexMin  << " : run the minimum of " << minNbr << " kilometres" << std::endl;
    std::cout << std::endl;
    std::cout << "----------------------------------------------------\n";
    std::cout << "Run the most kilometres:\n";
    std::cout << "Person "<< indexMax << " : run the maximum of " << maxNbr << " kilometres" << std::endl;
    std::cout << std::endl;
    std::cout << "----------------------------------------------------\n";
    std::cout << "Run the average kilometres:\n";
    std::cout << "Person "<< indexAve  << " : run the avarage of " << aveNbr << " kilometres" << std::endl;
    
    
    std::cout << std::endl;
    std::cout << "----------------------------------------------------\n";
    std::cout << "Ouput list with the order of kilometres :\n";
    std::cout << "----------------------------------------------------\n";
    std::cout << std::endl;
    //sorting - Descending ORDER
    for(int i=0;i<people;i++)
    {
        for(int j=i+1;j<people;j++)
        {
            if(array[i]<array[j])
            {
                int temp  =array[i];
                array[i]=array[j];
                array[j]=temp;
                indexSort = j;
            }
        }
        
    }
    
    
    //print sorted array elements
    std::cout<<"Sorted (Descending Order) Array elements:"<<std::endl;
    for(int i=0;i<people;i++){
        std::cout << "Person " << indexSort << " : run " << array[i] << " Kilometres" <<"\t";
        std::cout<<std::endl;
    }
    return 0;
}
