#include <iostream>
#include <conio.h>
using namespace std;

struct client            // Read client's data to enter the App
{
    int userID;
    string email;
    string name;
    char password;
    string address;
    int line[3];
}clienta;

struct Date
{
    int Day;
    int Month;
    int Year;
};
struct data            // Read mobilenumber's data to provide the services available to the customer
{
    long int mobilenumber;
    string  packagetype;
    float balance;
    Date  Dateofstart;
    Date Dateofrenwel;
}users[3];

long int Mobilenumber;
void changepakagetype()       // clients use this function to change package type of mobile number 
{
    string Nameofnewpackage;
    cout << "Enter Mobilenumber" "/n";
    cin >> Mobilenumber;
    cout << "Enter Name of new pakagetype";
    cin >> Nameofnewpackage;
    for (int i = 0; i < clienta.line[i]; i++)
        cin >> users[i].packagetype;
    cout << Mobilenumber << "/n" << Nameofnewpackage << endl;
}

void renewsubscription()      // clients use this function to renew subscription package type
{
    cout << "Enter Mobilenumber";
    cin >> Mobilenumber;
    for (int i = 0; i < clienta.line[i]; i++)
    {
        if (clienta.line[i] == Mobilenumber) // check or Ensure that the number entered by the client is inside the App
        {
            if (users[i].packagetype == "high")
            {
                if (users[i].balance >= 100)
                {
                    users[i].balance -= 100;

                }
                cout << "operation successful";
            }
        }

        else
            cout << "error";

        if (users[i].packagetype == "middle")
        {

            if (users[i].balance >= 50)
            {
                users[i].balance -= 50;

            }
            cout << "operation successful";
        }
        else
            cout << "error";

        if (users[i].packagetype == "low")
        {
            if (users[i].balance >= 15)
            {
                users[i].balance -= 15;
                cout << "operation successful";
            }
            cout << "operation successful";
        }

        else
            cout << "error";
    }
}

void makecall()    //This function helps the client to make a call
{
    cout << "calling";
    cin >> Mobilenumber;
    for (int i = 0; i < clienta.line[i]; i++)   //check the line from which the call was made in order to deduct the balance from it
    {
        if (users[i].balance >= 0.25)
            users[i].balance -= 0.25;
    }
    cout << "balance-=0.25" << endl;
}

void sendmessage()         //This function helps the client to send a message
{
    string Message;
    cout << "type Message";
    cin >> Message;
    for (int i = 0; i < clienta.line[i]; i++)  //check the line from which the send a message was made in order to deduct the balance from it
    {
        if (users[i].balance >= 0.25)
            users[i].balance -= 0.25;
    }
    cout << "balance -=0.25" << endl;
}

void rechargebalance()  //This function helps the client to rechargebalance in any lines 
{
    long int sr[5] = { 1515151515,4141414141,6398521478,6352417854,4521789652 };
    int value[5] = { 15,50,100,150,200 };
    long int serialnumber;
    cout << "Enter serial number";
    cin >> serialnumber;
    for (int i = 0; i < 4; i++) // check serial number which is entered with what is inside the program
    {
        if (sr[i] == serialnumber)
        {
            for (int j = 0; j < clienta.line[i]; j++)
            {
                users[j].balance += value[i];
            }

        }

    }
}

void transferbalance()  //This function helps the client to transfer balance in any lines 
{
    long int  numbertransferredtothebalance;
    int transfeerredbalance;
    cout << "Enter the number transferred to the balance " << "endl" << " Enter Transferred balance ";
    cin >> numbertransferredtothebalance;
    cin >> transfeerredbalance;

    for (int i = 0; i < clienta.line[1]; i++)  //check any line from which the balance is transferred
    {
        if (users[i].balance >= transfeerredbalance)
        {
            users[i].balance -= transfeerredbalance;
        }
    }
}

int main()
{
    Date MyDate;
    cout << "Enter userID: ";
    cin >> clienta.userID;
    cout << "Enter e-mail: ";
    cin >> clienta.email;
    cout << "Enter name:";
    cin >> clienta.name;

    char ch;
    bool isSpecial = false, isNum = false;

    cout << "Enter password :";
    while (true)
    {
        ch = _getch();
        if (ch == '\r')
        {
            break;
        }
        if (ch == '$' || ch == '%' || ch == '_' || ch == '#' || ch == '@')
        {
            isSpecial = true;
        }
        if (ch >= 47 && ch <= 58)
        {
            isNum = true;
        }
    }
    if (isSpecial && isNum)
    {
        cout << endl << "password is valid" << endl;
        cout << "Enter address:";
        cin >> clienta.address;
        int numberoflines;
        cout << "Enter number of lines :";
        cin >> numberoflines;
        if (numberoflines > 3)
        {
            cout << "error";
            return 0;
        }
        else
            for (long int Thenumbersentered = 0; Thenumbersentered < numberoflines; Thenumbersentered++)
            {
                cout << "Enter users mobilenumber";
                cin >> users[Thenumbersentered].mobilenumber;
                cout << "Enter users packagetype ";
                cin >> users[Thenumbersentered].packagetype;
                cout << "Enter users balance ";
                cin >> users[Thenumbersentered].balance;
                cout << "Enter Date of start " << endl;
                cout << "Enter Day";
                cin >> MyDate.Day;
                cout << "Enter Month";
                cin >> MyDate.Month;
                cout << "Enter Year";
                cin >> MyDate.Year;
                cout << MyDate.Day << "/" << MyDate.Month << "/" << MyDate.Year << endl;
                cout << "Enter Date of renewal date" << endl;
                cout << "Enter Day";
                cin >> MyDate.Day;
                cout << "Enter Month";
                cin >> MyDate.Month;
                cout << "Enter Year";
                cin >> MyDate.Year;
                cout << MyDate.Day << "/" << MyDate.Month << "/" << MyDate.Year << endl;

            }

        while (true)
        {
            int numberofoperation;
            cout << "numberofoperation";
            cin >> numberofoperation;
            switch (numberofoperation) //client can choose any services from App
            {
            case 1:
                changepakagetype();
                break;

            case 2:
                renewsubscription();
                break;

            case 3:
                makecall();
                break;

            case 4:
                sendmessage();
                break;

            case 5:
                rechargebalance();
                break;

            case 6:
                transferbalance();
                break;

            default:
                break;
            }

            string chek;
            cout << "Do you want to continue ?"; // check Does the user like to complete or not?
            cin >> chek;

            if (chek == "No")
            {
                break;
            }
        }
    }
    else
    {
        cout << endl << "password is not valid" << endl;
    }

    return 0;
}



