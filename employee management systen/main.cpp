#include<iostream>
using namespace std;
string id[30], name[30],address[50],  dob[30], mobile_no[30], doj[30],marstatus[30], workd[30],  workl[40], ctc[30], socialins[30], email[30];
int total = 0;// to store all data

void enter(){
    int ch = 0;
    std::cout << "How Many Employees Data Do You Want To Enter?" << std::endl;
    std::cin >> ch;
    if(total ==0){
        total = ch + total;
        for(int i =0; i<ch;i++){
            std::cout << "\nEnter the Data of the Employee " << i + 1 << std::endl;
            std::cout << endl;
            std::cout << "** PERSONAL DETAILS **" << std::endl;
            std::cout << endl;
            std::cout << "Enter Name: " << std::endl;

            std::cin >> name[i];

            std::cout << "Enter Address: " << std::endl;

            std::cin >> address[i];

            std::cout << "Enter Date of Birth: " << std::endl;

            std::cin >> dob[i];

            std::cout << "Is Employee Married?: " << std::endl;

            std::cin >> marstatus[i];

            std::cout << "** WORK DETAILS **" << std::endl
                     << std::endl;

            std::cout << "Enter Id: " << std::endl;

            std::cin >> id[i];

            std::cout << "Enter Date of Joing: " << std::endl;

            std::cin >> doj[i];

            std::cout << "Work Department: " << std::endl;

            std::cin >> workd[i];

            std::cout << "Enter Work Location: " << std::endl;

            std::cin >> workl[i];

            std::cout << "Enter CTC: " << std::endl;

            std::cin >> ctc[i];

            std::cout << "Enter Social Insurance Id: " << std::endl;

            std::cin >> socialins[i];

            std::cout << "** CONTACT DETAILS **" << std::endl
                     << std::endl;

            std::cout << "Enter Mobile NO: " << std::endl;

            std::cin >> mobile_no[i];

            std::cout << "Enter Email: " << std::endl;

            std::cin >> email[i];
            std::cout<<"Enter "
        }
    }
    else
    {
        for (int i = total; i < ch + total; i++) 
        {
            std::cout << "\nEnter the Data of Employee " << i + 1 << std::endl
                     << std::endl;
            std::cout << "** PERSONAL DETAILS **" << std::endl
                     << std::endl;

            std::cout << "Enter Name: " << std::endl;

            std::cin >> name[i];

            std::cout << "Enter Address: " << std::endl;

            std::cin >> address[i];

            std::cout << "Enter Date of Birth: " << std::endl;

            std::cin >> dob[i];

            std::cout << "Is Employee Married?: " << std::endl;

            std::cin >> marstatus[i];

            std::cout << "** WORK DETAILS **" << std::endl
                     << std::endl;

            std::cout << "Enter Id: " << std::endl;

            std::cin >> id[i];

            std::cout << "Enter Date of Joing: " << std::endl;

            std::cin >> doj[i];

            std::cout << "Work Department: " << std::endl;

            std::cin >> workd[i];

            std::cout << "Enter Work Location: " << std::endl;

            std::cin >> workl[i];

            std::cout << "Enter CTC: " << std::endl;

            std::cin >> ctc[i];

            std::cout << "Enter Social Insurance Id: " << std::endl;

            std::cin >> socialins[i];

            std::cout << "** CONTACT DETAILS **" << std::endl
                     << std::endl;

            std::cout << "Enter Mobile NO: " << std::endl;

            std::cin >> mobile_no[i];

            std::cout << "Enter Email: " << std::endl;

            std::cin >> email[i];
        }

        total = ch + total; 
    }
}

void show()
{
    if (total == 0)
    {
        std::cout << "No Data is Entered" << std::endl;
    }
    else
    {
        for (int i = 0; i < total; i++)
               {
            std::cout << "** RESULT FOR SHOW DATA **" << std::endl;

            std::cout << "\nData of Employee: " << i + 1 << std::endl
                     << std::endl;
            std::cout << "** PERSONAL DETAILS **" << std::endl
                     << std::endl;

            std::cout << "Full Name: " << name[i] << std::endl;
            std::cout << "Address: " << address[i] << std::endl;
            std::cout << "Date of Birth: " << dob[i] << std::endl;
            std::cout << "Maritual Status: " << marstatus[i] << std::endl
                     << std::endl;

            std::cout << "** WORK DETAILS **" << std::endl
                     << std::endl;

            std::cout << "Id: " << id[i] << std::endl;
            std::cout << "Date of Joing: " << doj[i] << std::endl;
            std::cout << "Work Department: " << workd[i] << std::endl;
            std::cout << "Work Location: " << workl[i] << std::endl;
            std::cout << "CTC: " << ctc[i] << std::endl;
            std::cout << "Social Insurance: " << socialins[i] << std::endl
                     << std::endl;

            std::cout << "** CONTACT DETAILS **" << std::endl
                     << std::endl;
            std::cout << "Mobile NO: " << mobile_no[i] << std::endl;
            std::cout << "Email Id: " << email[i] << std::endl;
        }
    }
}

void search()
{
    if (total == 0)
    {
        std::cout << "No data is entered" << std::endl;
    }
    else
    {
        string idd;

        std::cout << "Enter the id of Employee you want to Search: " << std::endl;

        std::cin >> idd;

        for (int i = 0; i < total; i++)
        {
            if (idd == id[i])
            {
                std::cout << "RESULT FOR EMPLOYEE ID: " << idd << std::endl;

                std::cout << "** PERSONAL DETAILS **" << std::endl
                         << std::endl;

                std::cout << "Full Name: " << name[i] << std::endl;
                std::cout << "Address: " << address[i] << std::endl;
                std::cout << "Date of Birth: " << dob[i] << std::endl;
                std::cout << "Maritual Status: " << marstatus[i] << std::endl
                         << std::endl;

                std::cout << "** WORK DETAILS **" << std::endl
                         << std::endl;

                std::cout << "Id: " << id[i] << std::endl;
                std::cout << "Date of Joing: " << doj[i] << std::endl;
                std::cout << "Work Department: " << workd[i] << std::endl;
                std::cout << "Work Location: " << workl[i] << std::endl;
                std::cout << "CTC: " << ctc[i] << std::endl;
                std::cout << "Social Insurance: " << socialins[i] << std::endl
                         << std::endl;

                std::cout << "** CONTACT DETAILS **" << std::endl
                         << std::endl;
                std::cout << "Mobile NO: " << mobile_no[i] << std::endl;
                std::cout << "Email Id: " << email[i] << std::endl;
            }
        }
    }
}

void update()
{
    if (total == 0)
    {
        std::cout << "No data is entered" << std::endl;
    }
    else
    {
        string rollno;

        std::cout << "Enter the Id of Employee which you want to update" << std::endl;

        std::cin >> rollno;

        for (int i = 0; i < total; i++)
        {
            if (rollno == id[i])
            {
                std::cout << "\nPrevious Data: " << std::endl
                         << std::endl;

                std::cout << "Data of Employee " << i + 1 << std::endl;

                std::cout << "** PERSONAL DETAILS **" << std::endl;

                std::cout << "Full Name: " << name[i] << std::endl;
                std::cout << "Address: " << address[i] << std::endl;
                std::cout << "Date of Birth: " << dob[i] << std::endl;
                std::cout << "Maritual Status: " << marstatus[i] << std::endl
                         << std::endl;

                std::cout << "** WORK DETAILS **" << std::endl
                         << std::endl;

                std::cout << "Id: " << id[i] << std::endl;
                std::cout << "Date of Joing: " << doj[i] << std::endl;
                std::cout << "Work Department: " << workd[i] << std::endl;
                std::cout << "Work Location: " << workl[i] << std::endl;
                std::cout << "CTC: " << ctc[i] << std::endl;
                std::cout << "Social Insurance: " << socialins[i] << std::endl
                         << std::endl;

                std::cout << "** CONTACT DETAILS **" << std::endl
                         << std::endl;
                std::cout << "Mobile NO: " << mobile_no[i] << std::endl;
                std::cout << "Email Id: " << email[i] << std::endl;

                std::cout << "\nEnter New Data: " << std::endl
                         << std::endl;

                std::cout << "** PERSONAL DETAILS **" << std::endl
                         << std::endl;

                std::cout << "Enter Name: " << std::endl;

                std::cin >> name[i];

                std::cout << "Enter Address: " << std::endl;

                std::cin >> address[i];

                std::cout << "Enter Date of Birth: " << std::endl;

                std::cin >> dob[i];

                std::cout << "Is Employee Married?: " << std::endl;

                std::cin >> marstatus[i];

                std::cout << "** WORK DETAILS **" << std::endl
                         << std::endl;

                std::cout << "Enter Id: " << std::endl;

                std::cin >> id[i];

                std::cout << "Enter Date of Joing: " << std::endl;

                std::cin >> doj[i];

                std::cout << "Work Department: " << std::endl;

                std::cin >> workd[i];

                std::cout << "Enter Work Location: " << std::endl;

                std::cin >> workl[i];

                std::cout << "Enter CTC: " << std::endl;

                std::cin >> ctc[i];

                std::cout << "Enter Social Insurance Id: " << std::endl;

                std::cin >> socialins[i];

                std::cout << "** CONTACT DETAILS **" << std::endl
                         << std::endl;

                std::cout << "Enter Mobile NO: " << std::endl;

                std::cin >> mobile_no[i];

                std::cout << "Enter Email: " << std::endl;

                std::cin >> email[i];

                std::cout << "\nUpdated Data: " << std::endl
                         << std::endl;

                std::cout << "** PERSONAL DETAILS **" << std::endl
                         << std::endl;

                std::cout << "Full Name: " << name[i] << std::endl;
                std::cout << "Address: " << address[i] << std::endl;
                std::cout << "Date of Birth: " << dob[i] << std::endl;
                std::cout << "Maritual Status: " << marstatus[i] << std::endl
                         << std::endl;

                std::cout << "** WORK DETAILS **" << std::endl
                         << std::endl;

                std::cout << "Id: " << id[i] << std::endl;
                std::cout << "Date of Joing: " << doj[i] << std::endl;
                std::cout << "Work Department: " << workd[i] << std::endl;
                std::cout << "Work Location: " << workl[i] << std::endl;
                std::cout << "CTC: " << ctc[i] << std::endl;
                std::cout << "Social Insurance: " << socialins[i] << std::endl
                         << std::endl;

                std::cout << "** CONTACT DETAILS **" << std::endl
                         << std::endl;
                std::cout << "Mobile NO: " << mobile_no[i] << std::endl;
                std::cout << "Email Id: " << email[i] << std::endl;
            }
        }
    }
}

void deletee()
{
    if (total == 0)
    {
        std::cout << "No data is entered" << std::endl;
    }
    else
    {
        string rollno;

        std::cout << "Enter the Id of Employee which you want to delete" << std::endl;

        std::cin >> rollno;

        for (int i = 0; i < total; i++)
        {
            if (rollno == id[i])
            {
                std::cout << "\nData of Employee " << i + 1 << std::endl
                         << std::endl;

                std::cout << "** PERSONAL DETAILS **" << std::endl
                         << std::endl;

                std::cout << "Full Name: " << name[i] << std::endl;
                std::cout << "Address: " << address[i] << std::endl;
                std::cout << "Date of Birth: " << dob[i] << std::endl;
                std::cout << "Maritual Status: " << marstatus[i] << std::endl
                         << std::endl;

                std::cout << "** WORK DETAILS **" << std::endl
                         << std::endl;

                std::cout << "Id: " << id[i] << std::endl;
                std::cout << "Date of Joing: " << doj[i] << std::endl;
                std::cout << "Work Department: " << workd[i] << std::endl;
                std::cout << "Work Location: " << workl[i] << std::endl;
                std::cout << "CTC: " << ctc[i] << std::endl;
                std::cout << "Social Insurance: " << socialins[i] << std::endl
                         << std::endl;

                std::cout << "** CONTACT DETAILS **" << std::endl
                         << std::endl;
                std::cout << "Mobile NO: " << mobile_no[i] << std::endl;
                std::cout << "Email Id: " << email[i] << std::endl;

                for (int j = i; j < total - 1; j++)
                {
                    name[j] = name[j + 1];
                    address[j] = address[j + 1];
                    dob[j] = dob[j + 1];
                    marstatus[j] = marstatus[j + 1];
                    id[j] = id[j + 1];
                    doj[j] = doj[j + 1];
                    workd[j] = workd[j + 1];
                    workl[j] = workl[j + 1];
                    ctc[j] = ctc[j + 1];
                    socialins[j] = socialins[j + 1];
                    mobile_no[j] = mobile_no[j + 1];
                    email[j] = email[j + 1];
                }

                total--;
                std::cout << "\nData Deleted Successfully" << std::endl;
            }
        }
    }
}

int main()
{
    int ch;
    while (true)
    {
        std::cout << "1. Enter Employee Data" << std::endl;
        std::cout << "2. Show Employee Data" << std::endl;
        std::cout << "3. Search Employee Data" << std::endl;
        std::cout << "4. Update Employee Data" << std::endl;
        std::cout << "5. Delete Employee Data" << std::endl;
        std::cout << "6. Exit" << std::endl;

        std::cout << "Enter your choice: " << std::endl;

        std::cin >> ch;

        switch (ch)
        {
        case 1:
            enter();
            break;
        case 2:
            show();
            break;
        case 3:
            search();
            break;
        case 4:
            update();
            break;
        case 5:
            deletee();
            break;
        case 6:
            exit(0);
            break;
        default:
            std::cout << "Invalid choice" << std::endl;
        }
    }
    return 0;
}