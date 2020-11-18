#include<iostream>
#include<fstream>
#include <cstring>
#include <cstdlib>
using namespace std;

/********************DECLARING FUNCTION HEADERS********************/
void PasswordScreen();

void Teacher();

// [[noreturn]] to make my code editor stop complaining about an endless loop that isn't endless 
[[noreturn]] void StudentScreen();

[[noreturn]] void PublicScreen();

class Student {
private:
    char name[50];
    char father_name[50];
    char mother_name[50];
    char birthday[15];
    char phone_number[15];
    int student_class;
    char division;
    int roll_number;
    char stream;
    float grades[5];
    char passcode[5];
    int attendance;
    float percentage;
    char letter_grade;

    // Calculates a student's percentage based on the performance from the classes
    void get_percentage() {
        percentage = (grades[0] + grades[1] + grades[2] + grades[3] + grades[4]) / 5;
    }

    // Determines a student's letter grade based on their percentage
    void get_letter_grade() {
        if (percentage >= 80)
            letter_grade = 'A';
        else if ((percentage >= 60) && (percentage <= 79))
            letter_grade = 'B';
        else if ((percentage >= 40) && (percentage <= 59))
            letter_grade = 'C';
        else if ((percentage >= 35) && (percentage <= 39))
            letter_grade = 'D';
        else if (percentage < 35)
            letter_grade = 'E';
    }

public:
    // Enter the information that is needed to create a student
    void enter_details() {
        cout << "\t\t\t  -------------------------------" << "\n";
        cout << "\t\t\t     ENTER THE STUDENT DETAILS" << "\n";
        cout << "\t\t\t  -------------------------------" << "\n\n";

        cout << "\t\tNAME OF THE STUDENT    : ";
        cin.ignore();
        cin.getline(name, 50);

        cout << "\t\tFATHER'S NAME          : ";
        cin.getline(father_name, 50);

        cout << "\t\tMOTHER'S NAME          : ";
        cin.getline(mother_name, 50);

        cout << "\t\tDATE OF BIRTH(DD/MM/YY): ";
        cin.getline(birthday, 15);

        if (birthday[2] != '/' || birthday[5] != '/'){
            cout << "Incorrect Birthday Format" << endl;
            enter_details();
        }

        cout << "\t\tTELEPHONE NUMBER (321-555-5555): ";
        cin.getline(phone_number, 13);

        if (phone_number[3] != '-' || phone_number[7] != '-'){
            cout << "Incorrect Phone Number Format" << endl;
            enter_details();
        }

        cout << "\t\tSECURITY CODE          : ";
        cin.getline(passcode, 5);

        cout << "\t\tCLASS                  : ";
        char class_string[15];
        cin.getline(class_string, 15);
        student_class = atoi(class_string);

        cout << "\t\tDIVISION               : ";
        char division_string[15];
        cin.getline(division_string, 15);
        division = atoi(division_string);

        cout << "\t\tROLL NUMBER            : ";
        char roll_num_string[15];
        cin.getline(roll_num_string, 15);
        roll_number = atoi(roll_num_string);
        cout << "\t\tDAYS PRESENT           : ";

        char attendance_string[15];
        cin.getline(attendance_string, 15);
        attendance = atoi(attendance_string);

        cout << "\n\t\tSTREAM('C' FOR COMPUTER OR 'B' FOR BIOLOGY): ";
        stream = cin.get();
        cin.get();
        cout << "\n\t\t\t  -----------------------------" << "\n";
        cout << "\t\t\t     ENTER THE SUBJECT GRADES" << "\n";
        cout << "\t\t\t  -----------------------------" << "\n\n";
        cout << "\t\t\t       PHYSICS    : ";
        char grade_string[4];
        cin.getline(grade_string, 4);
        grades[0] = atoi(grade_string);
        cout << "\t\t\t       CHEMISTRY  : ";
        cin.getline(grade_string, 4);
        grades[1] = atoi(grade_string);
        cout << "\t\t\t       MATHEMATICS: ";
        cin.getline(grade_string, 4);
        grades[2] = atoi(grade_string);
        if (stream == 'C') {
            cout << "\t\t\t       COMPUTER   : ";
            cin.getline(grade_string, 4);
            grades[3] = atoi(grade_string);
        } else {
            cout << "\t\t\t       BIOLOGY    : ";
            cin.getline(grade_string, 4);
            cin >> grades[3];
        }
        cout << "\t\t\t       ENGLISH    : ";
        cin >> grades[4];
        cout << "\n\n";
        get_percentage();
        get_letter_grade();
    }

    // Displays a student's report card, after calculating the grade
    void display_report() {
        cout << "----------------------------------------";
        cout << "---------------------------------------\n";
        cout << "                        THE EMIRATES NATIONAL SCHOOL\n\n";
        cout << "                             STUDENT REPORT CARD\n";
        cout << "----------------------------------------";
        cout << "---------------------------------------\n\n";
        cout << "                         ------------------------\n";
        cout << "                             PERSONAL DETAILS\n";
        cout << "                         ------------------------\n\n";
        cout << "NAME: " << name << "\t\t";
        cout << "CLASS: " << student_class << "\t";
        cout << "DIV: " << division << "\t\t";
        cout << "ROLL NO: " << roll_number << "\n\n";
        cout << "DATE OF BIRTH: " << birthday << "\t";
        if (stream == 'C') {
            cout << "STREAM: " << "COMPUTER" << "\t";
        } else if (stream == 'B') {
            cout << "STREAM: " << "BIOLOGY" << "\t";
        }
        cout << "TELEPHONE: " << phone_number << "\n\n";
        cout << "FATHERS NAME: " << father_name << "\t\t\t";
        cout << "MOTHERS NAME: " << mother_name << "\n\n";
        cout << "                        ----------------------------\n";
        cout << "                            ACADEMIC PERFORMANCE\n";
        cout << "                        ----------------------------\n\n";
        cout << "                 ---------------------------------------\n";
        cout << "                                  GRADES\n";
        cout << "                 ---------------------------------------\n";
        if (stream == 'C') {
            cout << "\t\t\t  PHYSICS\t" << grades[0] << "\n";
            cout << "\t\t\t  CHEMISTRY\t" << grades[1] << "\n";
            cout << "\t\t\t  MATHS\t\t" << grades[2] << "\n";
            cout << "\t\t\t  COMPUTER\t" << grades[3] << "\n";
            cout << "\t\t\t  ENGLISH\t" << grades[4] << "\n";
        } else if (stream == 'B') {
            cout << "\t\t\t  PHYSICS\t" << grades[0] << "\n";
            cout << "\t\t\t  CHEMISTRY\t" << grades[1] << "\n";
            cout << "\t\t\t  MATHS\t\t" << grades[2] << "\n";
            cout << "\t\t\t  BIOLOGY\t" << grades[3] << "\n";
            cout << "\t\t\t  ENGLISH\t" << grades[4] << "\n";
        }
        cout << "                -------------------        ------------\n";
        cout << "                 PERCENTAGE: " << percentage << "%" << "           ";
        cout << "GRADE: " << letter_grade << "\n";
        cout << "                -------------------        ------------\n\n";
    }

    //Displays all the personal information of a student
    void display_all() {
        cout << "\t\tNAME: " << name << "\n";
        cout << "\t\tFATHER: " << father_name << "\t" << "MOTHER: " << mother_name << "\n";
        cout << "\t\tROLL NO: " << roll_number << "\t" << "SECURE CODE: " << passcode << "\n";
        cout << "\t\tCLASS: " << student_class << " " << division << "\t";
        cout << "STREAM: " << stream << "\n";
        cout << "\t\tTELEPHONE NO: " << phone_number << "\n\n";
        cout << "\t\t                     GRADES" << "\n";
        cout << "\t\tPHY\tCHEM\tMATHS\tBIO/COMP\tENG" << "\n";
        cout << "\t\t" << grades[0] << "\t" << grades[1] << "\t" << grades[2] << "\t";
        cout << grades[3] << "\t\t" << grades[4] << "\n\n";
        cout << "\t\tPERCENTAGE: " << percentage << "%\t\t" << "GRADE: " << letter_grade << "\n";
        cout << "\t\tATTENDANCE: " << attendance;

    }

    friend void delete_student();

    friend void modify();

    friend void search();

    friend void search_student();

    friend void sort_grades();

    friend void sort_percentage();
};

/**************************ADDING A RECORD**************************/
/*
Calls the enter_details() function in the student class definition to input the personal
information for a student.
Once this is done, that student is then appended to the 'Record.dat' file
*/
void add() {
    Student s;
    ofstream f("Record.dat", ios::binary | ios::app);
    s.enter_details();
    f.write((char *) &s, sizeof(s));
    f.close();
}

/*************************DELETING A RECORD*************************/
/*
To delete a record, the teacher first enters the roll number of a student.
Once this is done, the list of records is searched for a student with a matching roll number
If this student is found, then they are taken out of the list
If this student is not found, then the record was not found, and the teacher returns to the Teacher() function
*/
void delete_student() {
    Student s;
    ifstream f1("Record.dat");
    ofstream f2("Temp.dat", ios::binary);
    int n, flag = 0;
    if (!f1) {
        cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tFILE NOT FOUND!";
        cout << "\n\n\n\n\n\n\n\n";
    } else {
        cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t";
        cout << "ENTER THE ROLL NUMBER OF THE STUDENT: ";
        cin >> n;
        while (f1.read((char *) &s, sizeof(s))) {
            if (n != s.roll_number) {
                f2.write((char *) &s, sizeof(s));
                flag = 1;
            }
        }
        if (flag == 0) {
            cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tRECORD NOT FOUND!";
            cout << "\n\n\n\n\n\n\n\n";
        } else {
            cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t";
            cout << "THE RECORD WAS DELETED SUCCESSFULLY";
            cout << "\n\n\n\n\n\n\n\n";
        }
    }
    f1.close();
    f2.close();
    remove("Record.dat");
    rename("Temp.dat", "Record.dat");
}

/************************MODIFYING A RECORD************************/
/*
To modify a record, the teacher needs to first enter the roll number associated with
the record of choice.
After entering a roll number, the list of records is searched to find a matching roll number,
and then that student's record is grabbed. 
After grabbing the record, the enter_details() function within the definition of the Student class is called,
and the changes are made by simulating a new student being enterred into the database
Once this is done, the old student is removed from the record, and the new temporary student takes the
place of the deleted student
If that roll number is not found, the teacher goes back to the Teacher() function.
*/
void modify() {
    Student s;
    ifstream f1("Record.dat");
    ofstream f2("Temp.dat", ios::binary);
    int n, flag = 0;
    if (!f1) {
        cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tFILE NOT FOUND!";
        cout << "\n\n\n\n\n\n\n\n";
    } else {
        cout << "ENTER THE ROLL NUMBER OF THE STUDENT: ";
        cin >> n;
        while (f1.read((char *) &s, sizeof(s))) {
            if (n == s.roll_number) {
                cout << "ENTER THE MODIFIED DETAILS OF THE STUDENT";
                s.enter_details();

                f2.write((char *) &s, sizeof(s));
                flag = 1;
                break;
            } else {
                f2.write((char *) &s, sizeof(s));
            }
        }
        if (flag == 0) {
            cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tRECORD NOT FOUND!";
            cout << "\n\n\n\n\n\n\n\n";
        }
    }
    f1.close();
    f2.close();
    remove("Record.dat");
    rename("Temp.dat", "Record.dat");
}

/******************SEARCING FOR A RECORD (TEACHER)******************/
/*
An individual with Teacher level access does not need the secure passcode to read a student's record
So, the teacher enters the roll number of a particular student, and the record with the matching roll number
is displayed using the display_report() function
If a student with the enterred roll number is not found, the teacher goes back to the Teacher() function
*/
void search() {
    Student s;
    ifstream f("Record.dat");
    int n, flag = 0;
    if (!f) {
        cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tFILE NOT FOUND!";
        cout << "\n\n\n\n\n\n\n\n";
    } else {
        cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t";
        cout << "ENTER THE ROLL NUMBER OF THE STUDENT: ";
        cin >> n;
        while (f.read((char *) &s, sizeof(s))) {
            if (n == s.roll_number) {
                flag = 1;
                s.display_report();
            }
        }
        if (flag == 0) {
            cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tRECORD NOT FOUND!";
            cout << "\n\n\n\n\n\n\n\n";
        }
    }
    f.close();
}

/******************SEARCING FOR A RECORD (STUDENT)******************/
/*
To search for a particular student's record, that students' roll number must be enterred.
If a matching number is found within the list of students, then the user must enter the passcode
associated with that student. 
If both the roll number and the secure passcode match for the found student, then that record is displayed
using the display_record() function.
If the roll number is not found, the user is pushed back to their access level function
*/
void search_student() {
    Student s;
    ifstream f("Record.dat");
    int n, flag = 0;
    char a[5];
    if (!f) {
        cout << "\t\t\t\tFILE NOT FOUND!";
        cout << "\n";
    } else {
        cout << "\t\t\t";
        cout << "ENTER YOUR ROLL NUMBER: ";
        cin >> n;
        cout << "\n\t\t\t";
        cout << "ENTER YOUR SECURE CODE: ";
        cin.ignore();
        cin.getline(a, 5);
        while (f.read((char *) &s, sizeof(s))) {
            if ((n == s.roll_number) && (strcmp(a, s.passcode) == 0)) {
                flag = 1;
                s.display_report();
            }
        }
        if (flag == 0) {
            cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tRECORD NOT FOUND!";
            cout << "\n\n\n\n\n\n\n\n";
        }
    }
    f.close();
}

/***********************SORTING BY PERCENTAGE***********************/
/*
To begin with, all the records are read, and the percentage of each student is sorted based
on ascending order of percentage. 
Once the percentages are sorted, they are then displayed, and the user returns to their access
level function
*/
void sort_percentage() {
    Student s, t[100], temp;
    ifstream f("Record.dat");
    int n = 0;
    if (!f) {
        cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tFILE NOT FOUND!";
        cout << "\n\n\n\n\n\n\n\n";
    } else {
        {
            while (f.read((char *) &s, sizeof(s))) {
                t[n++] = s;
            }
        }
        f.close();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (t[j].percentage < t[j + 1].percentage) {
                    temp = t[j];
                    t[j] = t[j + 1];
                    t[j + 1] = temp;
                }
            }
        }

/*******************DISPLAYING THE SORTED RECORDS*******************/
        cout << "\t\t\t  -----------------------------------" << "\n";
        cout << "\t\t\t     LIST OF CLASS RECORDS(SORTED)" << "\n";
        cout << "\t\t\t  -----------------------------------" << "\n\n";
        for (int i = 0; i < n; i++) {
            t[i].display_all();
            cout << "\n\n\n\t\t---------------------------------------------\n\n\n";
        }
    }
}

/**************************SORTING BY GRADES**************************/
/*
To begin with, a subject is selected to display the grades in. Once a subject is selected,
the records are then sorted.
The records are sorted based on the top five grades, and then they are displayed along with the
name of the student associated with that grade. 
Finally, the user returns back to their access level function, StudentScreen(), Teacher(), or PublicScreen(), and 
they are able to make another selection
*/
void sort_grades() {
    Student s, t[100], temp;
    ifstream f("Record.dat");
    int x, y, n = 0;
    if (!f) {
        cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tFILE NOT FOUND!";
        cout << "\n\n\n\n\n\n\n\n";
    } else {
        {
            while (f.read((char *) &s, sizeof(s))) {
                t[n++] = s;
            }
        }
        f.close();

        cout << "\n\n\n\n\n\n";
        cout << "\t\t\t  ----------------------" << "\n";
        cout << "\t\t\t     SELECT A SUBJECT" << "\n";
        cout << "\t\t\t  ----------------------" << "\n";
        cout << "\t\t\t       1. PHYSICS" << "\n";
        cout << "\t\t\t       2. CHEMISTRY" << "\n";
        cout << "\t\t\t       3. MATHS" << "\n";
        cout << "\t\t\t       4. BIOLOGY OR COMPUTER" << "\n";
        cout << "\t\t\t       5. ENGLISH" << "\n\n";
        cout << "\t\t\t     ENTER YOUR OPTION: ";
        cin >> y;
        cout << endl;
        if (y > 5) {
            cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tWRONG OPTION!";
            cout << "\n\n\n\n\n\n\n\n";
        } else
            x = y - 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (t[j].grades[x] < t[j + 1].grades[x]) {
                    temp = t[j];
                    t[j] = t[j + 1];
                    t[j + 1] = temp;
                }
            }
        }

/*******************DISPLAYING THE SORTED RECORDS*******************/
        cout << "\n\n\n\n\n\n";
        cout << "\t\t\t" << "-------------------------------" << "\n";
        cout << "\t\t\t" << "   SL. NO:" << "\t" << "GRADES" << "\t" << "NAME" << "\n";
        cout << "\t\t\t" << "-------------------------------" << "\n\n";
        for (int i = 0; i < 5; ++i) {
            cout << "\t\t\t   ";
            cout << i + 1 << ". " << "\t\t";
            cout << t[i].grades[x] << "\t" << t[i].name;
            cout << endl;
        }
        cout << "\n\n\n";
    }
}


/*
Whenever a user calls the Statistics() function, they are given the choice to order the
records by ascending order of percentage or the top five grades in each subject.
Depending on the choice, they will either go to the sort_percentage() function, or the sort_grades()
function, where their choice will be performed
*/
void statistics() {
    int n;
    cout << "\n\n\n\n\n\n\n";
    cout << "\t\t              ----------------" << "\n";
    cout << "\t\t                 STATISTICS" << "\n";
    cout << "\t\t              ----------------" << "\n";
    cout << "\t\t   1. VIEW ASCENDING ORDER OF PERCENTAGE" << "\n";
    cout << "\t\t   2. VIEW TOP FIVE GRADES IN EACH SUBJECT" << "\n\n";
    cout << "\t\t           ENTER YOUR OPTION: ";
    cin >> n;
    switch (n) {
        case 1:
            sort_percentage();
            break;
        case 2:
            sort_grades();
            break;
        default:
            cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tWRONG OPTION!";
            cout << "\n\n\n\n\n\n\n\n";
    }
}

/**********************DISPLAYING INTRODUCTION**********************/
/*
Displays some basic information about the program, like the authors and the title
of the program. This comes directly from the Sequence() function, and immediatley after 
it LoginScreen() is called to perform the functionality of the program
*/
void Intro() {
    using namespace std;
    cout << "Program originally by Joshua Joseph and Masood Al Ansar" << endl;
    cout << "Modified by Ryan Doherty, Zack Bruggen, Kiran Chandra, and Taylor Czerwinski" << endl;
    cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\tREPORT CARD MANAGEMENT SYSTEM";
}

/*******************SPLITTING INTO DIFFERENT USERS*******************/
/*
Here the user determine what kind of access they have, Teacher, Student, or Public access.
Once there access is determined, they go to the PasswordScreen(), StudentScreen(), or PublicScreen() functions, which 
decide what kind of operations they can perform. 
If they decide to exit, the program quits, or if they enter wrong the choice is presented again
*/
void LoginScreen() {
    while (true) {
        int n;
        cout << "\t\t\t      ---------------" << "\n";
        cout << "\t\t\t         MAIN MENU" << "\n";
        cout << "\t\t\t      ---------------" << "\n\n\n";
        cout << "\t\t\t     SELECT DESIGNATION" << "\n\n";
        cout << "\t\t-------------------------------------------" << "\n";
        cout << "\t\t  1. TEACHER\t2. STUDENT\t3. PUBLIC" << "\n";
        cout << "\t\t-------------------------------------------" << "\n\n";
        cout << "\t\t             (PRESS 4 TO EXIT)" << "\n\n\n";
        cout << "\t\t       ENTER AN OPTION: ";
        cin >> n;
        switch (n) {
            case 1:
                PasswordScreen();
                break;
            case 2:
                StudentScreen();
                break;
            case 3:
                PublicScreen();
                break;
            case 4:
                exit(0);
                break;
            default:
                cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tWRONG OPTION!";
        }
    }
}

/*************************TEACHER FUNCTION*************************/
/*
If a user entered the Teacher password correctly, they are granted Teacher access
As a Teacher, the user is able to add a new record, delete a record, search for a specific record,
and modify a specific record. They are also able to display all records, and display the class statistics
Depending on the choice they enter on the input, they will go to a function for the particular operations
*/
void Teacher() {
    int n = -1;
    while (n != 7) {
        cout << "\t\t\t\t  ------------" << "\n";
        cout << "\t\t\t\t      MENU" << "\n";
        cout << "\t\t\t\t  ------------" << "\n";
        cout << "\t\t\t     1. ADD A NEW RECORD" << "\n";
        cout << "\t\t\t     2. SEARCH FOR A RECORD" << "\n";
        cout << "\t\t\t     3. MODIFY A RECORD" << "\n";
        cout << "\t\t\t     4. DELETE A RECORD" << "\n";
        cout << "\t\t\t     5. DISPLAY ALL THE RECORDS" << "\n";
        cout << "\t\t\t     6. CLASS STATISTICS" << "\n";
        cout << "\t\t\t     7. GO TO MAIN MENU" << "\n\n";
        cout << "\t\t\t     ENTER YOUR OPTION: ";
        cin >> n;
        cout << n << endl;
        switch (n) {
            case 1:
                add();
                break;
            case 2:
                search();
                break;
            case 3:
                modify();
                break;
            case 4:
                delete_student();
                break;
            case 5:
                sort_percentage();
                break;
            case 6:
                statistics();
                break;
            case 7:
                LoginScreen();
                break;
            default:
                cout << "\t\t\t\tWRONG OPTION!";
        }
    }
}

/*************************STUDENT FUNCTION*************************/
/*
If a user has Student access, they are able to view class statistics, or look at their
personal record. Depending on their choice, they will either go to the 
search_student() function to check their record, or statistics() to look at the class' stats
*/
[[noreturn]] void StudentScreen() {
    while (true) {
        int n;
        cout << "\n\n\n\n\n\n\n";
        cout << "\t\t\t\t ------------" << "\n";
        cout << "\t\t\t\t     MENU" << "\n";
        cout << "\t\t\t\t ------------" << "\n";
        cout << "\t\t\t   1. SEARCH FOR YOUR RECORD" << "\n";
        cout << "\t\t\t   2. VIEW CLASS STATISTICS" << "\n";
        cout << "\t\t\t   3. GO TO MAIN MENU" << "\n\n";
        cout << "\t\t\tENTER YOUR OPTION: ";
        cin >> n;
        switch (n) {
            case 1:
                search_student();
                break;
            case 2:
                statistics();
                break;
            case 3:
                LoginScreen();
                break;
            default:
                cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tWRONG OPTION!!";
                cout << "\n\n\n\n\n\n\n\n";
        }
    }
}

/**************************PUBLIC FUNCTION**************************/
/*
If a user has Public access, they are able to view class statistics, or go back to 
the main menu. Depending on what option they choose, they will either go to the 
Statistics() function, or back to the LoginScreen() function
*/
[[noreturn]] void PublicScreen() {
    int n;
    while (true) {
        cout << "\n\n\n\n\n\n\n\n";
        cout << "\t\t\t\t ------------" << "\n";
        cout << "\t\t\t\t     MENU" << "\n";
        cout << "\t\t\t\t ------------" << "\n";
        cout << "\t\t\t   1. VIEW CLASS STATISTICS" << "\n";
        cout << "\t\t\t   2. GO TO MAIN MENU" << "\n\n";
        cout << "\t\t\t   ENTER AN OPTION: ";
        cin >> n;
        switch (n) {
            case 1:
                statistics();
                break;
            case 2:
                LoginScreen();
                break;
            default:
                cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tWRONG OPTION!!";
                cout << "\n\n\n\n\n\n\n\n";
        }
    }
}

/*************************PASSWORD FUNCTION*************************/
/*
Function to check a password if a user is a Teacher.
The user enters a password, and if it matches the stored password, then 
the user is granted Teacher access, and moves to the Teacher() function. 
Otherwise, they are able to try to reenter the password
If they do not enter the password correctly within 2 tries, they go back to the
LoginScreen() function to determine their access level
*/
void PasswordScreen() {
    char password[7];
    password[6] = '\0';
    int attempt = 0;
    bool access_granted = false;
    while (!access_granted) {
        cout << "\t\t\tENTER THE PASSWORD: ";
        cin >> password;
        if (strcmp(password, "A") == 0) {
            cout << "\t\t\tACCESS GRANTED\n";
            access_granted = true;
            Teacher();
        } else {
            if (attempt == 2) {
                cout << "ACCESS DENIED" << "\n\n\n\n\n\n\n\n";
                LoginScreen();
            }
            cout << "\t\t\t      TRY AGAIN";
            attempt++;
        }
    }
}


/***************************MAIN FUNCTION***************************/
/*
Intro() is the first function to run, which
prints out the opening information about the program.
After the opening info is printed, the LoginScreen() function is called, which is the main hub for the program.
The LoginScreen() function decides what level of access a user has, and they are able to choose to kill the program
within the LoginScreen() function
*/
int main() {
    Intro();
    LoginScreen();
    return 0;
}
