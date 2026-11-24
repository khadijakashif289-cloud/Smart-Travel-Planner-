#include <iostream>
#include<iomanip>
#include<string>
using namespace std;

// Function Prototypes
int displayMenu();
void getTripDetails(int&, int&, int&, int&, int&, string&,int&);
int selectDestination(string &destination,int &foodCost);
int selectActivities();
int calculateTripCost(int, int, int, int, int,int,int&);
void checkBudget(int, int);
void displayCostBreakdown(int, int, int, int,string,int);

// MENU DISPLAY FUNCTION
int displayMenu()
{
    int choice;

    cout << "\n===== TRIP PLANNER =====" << endl;
    cout << "1. Plan a New Trip" << endl;
    cout << "2. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    return choice;
}

// MAIN FUNCTION
int main()
{
    int choice;
    int travellers, nights, budget;
    int transportCost, activityCost, totaltripCost, foodRate,foodCost;// food rate is added in the C++ program . it is a change made from the submitted one.
    int accommodationCost, accommodationRate = 3000;
    string destination;

    do
    {
        choice = displayMenu();

        if (choice == 1)
        {
            getTripDetails(travellers, nights, budget,
                transportCost, activityCost, destination,foodRate);
           
            accommodationCost = travellers * nights * accommodationRate;

            totaltripCost = calculateTripCost(travellers, nights,
                accommodationRate,
                transportCost, activityCost, foodRate);

            checkBudget(totaltripCost, budget);

            displayCostBreakdown(accommodationCost, transportCost,
                activityCost, totaltripCost,destination,foodRate);
        }
        else if (choice == 2)
        {
            cout << "Thank you for visiting!" << endl;
        }
        else
        {
            cout << "Invalid Choice!" << endl;
        }

    } while (choice != 2);

    return 0;
}

// FUNCTION DEFINITIONS AT THE END

// FUNCTION THAT GETS THE DETAILS OF THE TRIP

void getTripDetails(int& travellers, int& nights, int& budget,
    int& transportCost, int& activityCost, string  &destination,int &foodRate)
{
    do
    {
        cout << "\nEnter number of travellers (1-5): ";
        cin >> travellers;

        if (travellers < 1 || travellers > 5)
            cout << "Invalid number of travellers!" << endl;

    } while (travellers < 1 || travellers > 5);

    do
    {
        cout << "Enter nights: ";
        cin >> nights;

        if (nights <= 0)
            cout << "Invalid nights!" << endl;

    } while (nights <= 0);

    do
    {
        cout << "Enter budget (PKR): ";
        cin >> budget;

        if (budget < 0)
            cout << "Invalid budget!" << endl;

    } while (budget < 0);

    transportCost = selectDestination(destination,foodRate);
    activityCost = selectActivities();
}



// FUNCTION TO SELECT DESTINATIONS
// DESTINATIONS ARE SET ACCORDING TO THE TEACHER'S
int selectDestination(string &destination,int &foodRate)
{
    int choice;
    int transportCost = 0;


    cout << "\n===== DESTINATIONS =====" << endl;
    cout << "1. Murree - Rs. 9000" << endl;
    cout << "2. Swat - Rs. 8000" << endl;
    cout << "3. Hunza - Rs. 12,000" << endl;
    cout << "4. Naran _ Rs. 10,000" << endl;

    do
    {
        cout << "Enter destination choice: ";
        cin >> choice;

        if (choice == 1)
        {
            destination = "Muree";
            transportCost = 9000;
            foodRate = 3000;
        }
        else if (choice == 2)
        {
            destination = "Swat";
            transportCost = 8000;
            foodRate = 2000;
        }
        else if (choice == 3)
        {
            destination = "Hunza";
            transportCost = 12000;
            foodRate = 3000;
        }
        else if (choice == 4)
        {
            destination = "Naran";
            transportCost = 10000;
            foodRate = 2500;
        }
        else
            cout << "Invalid choice!" << endl;

    } while (choice < 1 || choice > 4);

    return transportCost;
}

//FUNCTION TO SELECT THE ACTIVITES FOR THE TRIP
// ACTIVITIES ARE CHANGED ACCORDING TO THE VALUES GIVEN BY THE TEACHER ALSO THEIR COST

int selectActivities()
{
    int choice;
    int activityCost = 0;

    bool hiking = false;
    bool boating = false;
    bool sightseeing = false;
    bool meuseum = false;
    bool adventure = false;

    cout << "\n===== ACTIVITIES =====" << endl;
    cout << "1. Hiking - Rs. 1200" << endl;
    cout << "2. Boating - Rs. 1100" << endl;
    cout << "3. Sightseeing - Rs. 600" << endl;
    cout << "4. Meuseum - Rs.350" << endl;
    cout << "5. Adventure - Rs.1800" << endl;
    cout << "0. Finish" << endl;

    do
    {
        cout << "Enter activity choice: ";
        cin >> choice;

        if (choice == 1)
        {
            if (hiking == false)
            {
                activityCost += 1200;
                hiking = true;
                cout << "Hiking is selected successfully!" << endl;
            }
            else
                cout << "Hiking is already selected" << endl;
        }
        else if (choice == 2)
        {
            if (boating == false)
            {
                activityCost += 1100;
                boating = true;
                cout << "Boating is selected successfully!" << endl;
            }
            else
                cout << "Boating is already selected" << endl;
        }
        else if (choice == 3)
        {
            if (sightseeing == false)
            {
                activityCost += 600;
                sightseeing = true;
                cout << "Sightseeing is selected successfully!" << endl;
            }
            else
                cout << "Sightseeing is already selected" << endl;
        }

        else if (choice == 4)
        {
            if (meuseum == false)
            {
                activityCost += 350;
                meuseum = true;
                cout << "Museum is selected successfully!" << endl;
            }
            else
                cout << "Meuseum is already selected " << endl;
        }
        else if (choice == 5)
        {
            if (adventure == false)
            {
                activityCost += 1800;
                adventure = true;
                cout << "Adventure is selected successfully!" << endl;
            }
            else
                cout << "Adventure is already selected" << endl;
        }
            
        else if (choice == 0)
        {
            break;
        }
        else
        {
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 0);

    return activityCost;
}

//FUNTION THAT CALCULATES THE TOTAL COST OF THE TRIP
int calculateTripCost(int travellers, int nights, int accommodationRate,int foodRate,
    int transportCost, int activityCost,int &foodCost)
{
    
    foodCost = travellers * nights * foodRate;
    int accommodationCost = travellers * nights * accommodationRate;

    return accommodationCost +foodCost+ transportCost + activityCost ;
}

//FUNCTION THAT CJECKS THAT WHETHER THE COST OF TRIP IS WITHIN BUDGET OR NOT
void checkBudget(int totaltripCost, int budget)
{
    int remaining, exceeding;
    if (totaltripCost <= budget)
    {
        remaining = budget - totaltripCost;
        cout << "\nBudget Status: Within budget" << endl;
        cout << "\nRemaining amount is Rs. " << remaining << endl;
    }
    else
    {
        exceeding = totaltripCost - budget;
        cout << "\nBudget Status: Over budget" << endl;
        cout << "\nExceeding amount is Rs. " << exceeding << endl;
    }
}

// FUNCTION THE DISPLAY THE BREAKDOWN OF TOTAL COST OF THE TRIP
void displayCostBreakdown(int accommodationCost, int transportCost,
    int activityCost, int totaltripCost,string destination,int foodCost)
{
    cout << "\n===== COST BREAKDOWN =====" << endl;
    cout << "Selected Destination: " << destination << endl;
    cout << "Accommodation Cost: Rs. " << accommodationCost << endl;
    cout << "Transport Cost: Rs. " << transportCost << endl;
    cout << "Activity Cost: Rs. " << activityCost << endl;
    cout << "Food Cost: Rs. " << foodCost << endl;
    cout << "Total Trip Cost: Rs. " << totaltripCost << endl;
    
}