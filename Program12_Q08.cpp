#include<iostream>
#include<cstring>//allows use of strlen function
#include<stdlib.h>//allows use of atoi function
using namespace std;
//function prototypes
int find_sum(int [], int);
int find_highest(int [], int);
int find_lowest(int [], int);
//main function
int main()
{
    const int MAX_CHAR = 100;//const to declare max size of user input in cstring
    char userInput[MAX_CHAR],//cstring to store user input
         charNum;//char variable
    //int variables initialized to 0
    int length = 0,
        number = 0;
    //ask user for input
    cout << "Please enter a series of single digit numbers with no spaces" << endl;
    cout << "or other special characters. Your limit is 100 numbers." << endl << endl;
    //stores user input in cstring so each item can be read individually
    cin.get(userInput, MAX_CHAR);
    cout << endl;
    //use strlen function to determine the length of the user's input
    length = strlen(userInput);
    //create int array to store user input after converting to int
    int inputAsNum[length];
    //convert each element of the cstring to an int and store in int array
    for(int i = 0; i < length; i++)
    {
        charNum = userInput[i];
        number = atoi(&charNum);//use atoi function to convert char to int
        inputAsNum[i] = number;
    }
    //call function find_sum and store returned value in sum variable
    int sum = find_sum(inputAsNum, length);
    //call function find_highest and store returned value in highest variable
    int highest = find_highest(inputAsNum, length);
    //call function find_lowest and store returned value in lowest variable
    int lowest = find_lowest(inputAsNum, length);
    //display results
    cout << "The total of your numbers is " << sum << "." << endl;
    cout << "The highest number entered was " << highest << "." << endl;
    cout << "The lowest number entered was " << lowest << "." << endl;
    return 0;
}
//function to find sum of numbers entered by user
int find_sum(int input[], int len)
{
    int total = 0;
    for(int i = 0; i < len; i++)
    {
        total += input[i];
    }
    return total;
}
//function to find highest number entered by user
int find_highest(int input[], int len)
{
    int high = input[0];
    for(int i = 0; i < len; i++)
    {
        if(input[i] > high)
        {
            high = input[i];
        }
    }
    return high;
}
//function to find lowest value entered by user
int find_lowest(int input[], int len)
{
    int low = input[0];
    for(int i = 0; i < len; i++)
    {
        if(input[i] < low)
        {
            low = input[i];
        }
    }
    return low;
}