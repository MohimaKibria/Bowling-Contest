#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

#define rounds 5
const int contest=10;
char z = '*', s = ' ';
const string scores = "BowlingScores.txt";//avoid hardcoding file name

bool GetBowlingData(char bowlern[][contest], int points[][rounds], int & plo);
void GetAverageScore( int points[][rounds],double average[], int plo);
void PrettyPrintResults(char bowlern[][contest], int points[][rounds], double average[], int plo);
//order in which each funtion should work

int main() 
{
  cout << setw(68) << setfill('*') << z << endl;
  cout << setw(20) << setfill('*') << z << " What's The Average Score? " << setw(21) << setfill('*') << z << endl;
  cout << setw(68) << setfill(z) << z << endl; //intro to program using manipulators in order to prevent hard-coding.
int plo = 0;
bool GetBowlingData(char bowlern[][contest], int points[][rounds], int & plo);
void GetAverageScore( int points[][rounds],double average[], int plo);
void PrettyPrintResults(char bowlern[][contest], int points[][rounds], double average[], int plo);
  cout << endl;
double average[contest];
int points[contest][rounds];
char bowlern[contest][contest];
if(GetBowlingData(bowlern, points, plo))
{
GetAverageScore(points, average, plo);
PrettyPrintResults(bowlern, points, average, plo);
}
return 0;
  }
bool GetBowlingData(char bowlern[][contest], int points[][rounds], int & plo)
{
  ifstream fs;
  fs.open(scores);//opens txt file that will read the input data in the file

    while(!fs.eof())
    {
    fs >> bowlern [plo]>> points [plo][0] >> points [plo][1]>> points[plo][2]>> points [plo][3];
    plo++;
    }
    return true;
  } //this function opens the file and stores data 

void GetAverageScore( int points[][rounds],double average[], int plo)
{  int fa = 0;
  for(int fa = 0; fa < plo;++fa)
  {
    average[fa] = 0;
      for(int d=0; d<rounds; d++)
      {
        average[fa] = average[fa] + points[fa][d];
      }
average[fa]  = average[fa] / rounds;
  }//this function calculates the average scores
}
void PrettyPrintResults(char bowlern[][contest], int points[][rounds], double average[], int plo){
cout<<"Players"<<setw(5) << setfill(' ') << s << "Round#1"<< setw(5) << setfill(' ') << s << "Round#2" << setw(5) << setfill(' ') << s <<"Round#3"<< setw(5) << setfill(' ') << s <<"Round#4" << setw(5) << setfill(' ') << s <<"Round#5" << setw(5) << setfill(' ') << s << "Average" << endl;//outputs each round of scores with spaces inbetween
for(int fa=0; fa<plo; fa++)
{
  cout<<left<<setw(15)<<bowlern[fa]<<"\t";
  for(int d=0; d<rounds; d++)
      cout<<points[fa][d]<<setw(7) << setfill(' ') << s <<"\t";
      cout<<average[fa]<<endl;
  
  //outputs points and averages with spaces inbetween inorder to align with each round
}
  
}
