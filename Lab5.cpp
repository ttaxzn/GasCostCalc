#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double GetMiles()
{
    double miles;
    cout << "Enter miles: " << endl;
    cin >> miles;
    if(!cin)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw runtime_error("Invalid input receieved, you must enter a decimal number.");
    }
    if(miles<=0)
    {
        throw runtime_error("Miles cannot be less than zero.");
    }
    else
    {
        return miles;
    }
}

double GetGallons()
{
    double gallons;
    cout << "Enter gallons: " << endl;
    cin >> gallons;
    if(!cin)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw runtime_error("Invalid input receieved, you must enter a decimal number.");
    }
    if(gallons<=0)
    {
        throw runtime_error("Gallons cannot be less than zero.");
    }
    else
    {
        return gallons;
    }
}
double GetMPG(vector<double>miles, vector<double> gallons)
{
    double milestotal;
    double gallonstotal;
    double MPG;
    int i;
    if(miles.size()==0 || gallons.size()==0)
    {
        throw runtime_error("No values recorded. MPG is nan.");
    }
    else
    {
    for(i=0; i<miles.size(); i++)
    {
        milestotal=milestotal+miles.at(i);
    }
    for(i=0; i<gallons.size(); i++)
    {
        gallonstotal=gallonstotal+gallons.at(i);
    }
    MPG=milestotal/gallonstotal;
    return MPG;
    }
}
int main()
{
    vector <double> miles;
    vector <double> gallons;
    double milesinput;
    double gallonsinput;
    char quitCmd='a';
    while(quitCmd!='q')
    {
    try
    {
    milesinput=GetMiles();
    gallonsinput=GetGallons();
    miles.push_back(milesinput);
    gallons.push_back(gallonsinput);
    cout << "MPG: " << GetMPG(miles, gallons)  << " mi/gal" << endl;
    cout << "Want to enter another tank? (Press any key to continue, q to quit)" << endl;
    cin >> quitCmd;
    }
    
    catch(runtime_error &excpt)
    {
        cout << excpt.what() << endl;
    }
    }

    return 0;
}