/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
Full Name  : Hyunjoo Han
Student ID#: 132749227
Email      : hhan39@myseneca.ca
Section    : NEE

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"


//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
        "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
            "Number: %05d\n"
            "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
            patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords)
    {
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
            "---------- ----- ----- --------------- --------------------\n");
    }
    else
    {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
            "----- ----- --------------- --------------------\n");
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient,
    const struct Appointment* appoint,
    int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
            appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
        patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
    int selection;

    do {
        printf("Veterinary Clinic System\n"
            "=========================\n"
            "1) PATIENT     Management\n"
            "2) APPOINTMENT Management\n"
            "-------------------------\n"
            "0) Exit System\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            menuAppointment(data);
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Patient Management\n"
            "=========================\n"
            "1) VIEW   Patient Data\n"
            "2) SEARCH Patients\n"
            "3) ADD    Patient\n"
            "4) EDIT   Patient\n"
            "5) REMOVE Patient\n"
            "-------------------------\n"
            "0) Previous menu\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do {
        printf("Edit Patient (%05d)\n"
            "=========================\n"
            "1) NAME : %s\n"
            "2) PHONE: ", patient->patientNumber, patient->name);

        displayFormattedPhone(patient->phone.number);

        printf("\n"
            "-------------------------\n"
            "0) Previous menu\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}


// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData* data)
{
    int selection;

    do {
        printf("Appointment Management\n"
            "==============================\n"
            "1) VIEW   ALL Appointments\n"
            "2) VIEW   Appointments by DATE\n"
            "3) ADD    Appointment\n"
            "4) REMOVE Appointment\n"
            "------------------------------\n"
            "0) Previous menu\n"
            "------------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 1:
            viewAllAppointments(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 2:
            viewAppointmentSchedule(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments,
                data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 4:
            removeAppointment(data->appointments, data->maxAppointments,
                data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        }
    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
// ---------------------------------------------------------------------------


// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (Copy your code from MS#2)
void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
    int i, noRecordFound = 1;

    if (fmt == FMT_TABLE) //display table header depends on the 'fmt' argument
    {
        displayPatientTableHeader();
    }

    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber != 0) //check if the value of patient number is not 0 and display the data
        {
            displayPatientData(&patient[i], fmt);
            noRecordFound = 0;
        }
    }

    if (noRecordFound) //if the value of patient number is 0, display error message
    {
        printf("*** No records found ***\n");
    }
    printf("\n");
}


// Search for a patient record based on patient number or phone number
// (Copy your code from MS#2)
void searchPatientData(const struct Patient patient[], int max)
{
    int exit = 1;
    int option;
    while (exit == 1)
    {
        printf("Search Options\n");
        printf("==========================\n");
        printf("1) By patient number\n");
        printf("2) By phone number\n");
        printf("..........................\n");
        printf("0) Previous menu\n");
        printf("..........................\n");
        printf("Selection: ");
        scanf("%d", &option);
        if (option == 1)
        {
            searchPatientByPatientNumber(patient, max);
            suspend();
        }
        else if (option == 2)
        {
            searchPatientByPhoneNumber(patient, max);
            suspend();
        }
        else if (option == 0)
        {
            printf("\n");
            exit = 0;
        }
    }
}

// Add a new patient record to the patient array
// (Copy your code from MS#2)
void addPatient(struct Patient patient[], int max)
{
    int i;
    int spaceForNew = 0, spaceIndex = 0;
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber != 0)
        {
            spaceForNew++;
        }
        else
        {
            if (spaceIndex == 0)
            {
                spaceIndex = i;
            }
        }
    }
    if (spaceForNew < max)
    {
        patient[spaceIndex].patientNumber = nextPatientNumber(patient, max);
        inputPatient(&patient[spaceIndex]);
        printf("*** New patient record added ***\n\n");
    }
    else
    {
        printf("ERROR: Patient listing is FULL!\n\n");
    }
}

// Edit a patient record from the patient array
// (Copy your code from MS#2)
void editPatient(struct Patient patient[], int max)
{
    int i;
    int pNum;
    printf("Enter the patient number: ");
    pNum = inputInt();
    printf("\n");
    i = findPatientIndexByPatientNum(pNum, patient, max);
    if (i == -1)
    {
        printf("ERROR: Patient record not found!\n");
    }
    else
    {
        menuPatientEdit(&patient[i]);
    }
}

// Remove a patient record from the patient array
// (Copy your code from MS#2)
void removePatient(struct Patient patient[], int max)
{
    int i, pNum;
   // char remove;
    printf("Enter the patient number: ");
    pNum = inputInt();
    printf("\n");
    i = findPatientIndexByPatientNum(pNum, patient, max);
    if (i == -1)
    {
        printf("ERROR: Patient record not found!\n\n");
    }
    else
    {
        displayPatientData(&patient[i], FMT_FORM);
        printf("\n");
        printf("Are you sure you want to remove this patient record? (y/n): ");
        //remove = inputCharOption("yn");
        if (inputCharOption("yn") == 'n')
        {
            printf("Operation aborted.\n\n");
            clearInputBuffer();
        }
        else if (inputCharOption("yn") == 'y')
        {
            patient[i].patientNumber = 0;
            printf("Patient record has been removed!\n\n");
            clearInputBuffer();
        }
    }
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
// Todo:

void viewAllAppointments(struct ClinicData* data)
{
    int i, j;

    displayScheduleTableHeader(&data->appointments->date, VIEW_ALL_APPOINTMENTS);
    
    //printing the appointments
    for (i = 0; i < data->maxAppointments; i++) 
    {
        for (j = 0; j < data->maxPatient; j++) 
        {
            if (data->appointments[i].patientNumber && data->patients[j].patientNumber) 
            {
                if (data->appointments[i].patientNumber == data->patients[j].patientNumber) 
                {
                    displayScheduleData(&data->patients[j], &data->appointments[i], 1);
                }
            }
        }
    }
    printf("\n");
}

// View appointment schedule for the user input date
// Todo:
void viewAppointmentSchedule(struct ClinicData* data)
{
    struct Date viewDate;
    int i, j;

    InputDate(&viewDate);
    //Take input from user to view the appointment for specific date
    printf("\n");
    
    displayScheduleTableHeader(&viewDate, VIEW_SCHEDULE_APPOINTMENT);
    
    //printing the appointments
    for (i = 0; i < data->maxAppointments; i++)
    {
        for (j = 0; j < data->maxPatient; j++)
        {
            if (data->appointments[i].patientNumber && data->patients[j].patientNumber)
            {
                if (data->appointments[i].patientNumber == data->patients[j].patientNumber)
                {
                    if (data->appointments[i].date.year == viewDate.year && data->appointments[i].date.month == viewDate.month && data->appointments[i].date.day == viewDate.day)
                    {
                        displayScheduleData(&data->patients[j], &data->appointments[i], 0);
                    }
                }
            }
        }
    }

    printf("\n");
}

// Add an appointment record to the appointment array
// Todo:
void addAppointment(struct Appointment* appoint, int maxAppointments, struct Patient* patient, int maxPatient)
{
    int i;
    int tmpPatientnum;
    int slotCheck;
    struct Date addDate;
    struct Time addTime;
    int freeSlot = 0;
    int a = 0;

    for (i = 0; i < maxAppointments; i++)
    {
        if (appoint[i].patientNumber < 1)
            //check if there is any empty space to store
        {
            freeSlot++;
            a = i;//the index value to store new patient
        }
        if (freeSlot == 1)
        {
            i = maxAppointments;
        }
    }

    if (freeSlot == 0)
        //check if there is any empty spaces
    {
        puts("ERROR: Patient listing is FULL!\n");
    }
    else
    {
        printf("Patient Number: ");
        tmpPatientnum = inputIntPositive();

        do
        {
            slotCheck = 0;
            InputDate(&addDate);
            //calling additional function for date input
            TimeForAppointment(&addTime);
            for (i = 0; i < maxAppointments; i++)
            //check if there is same record in data
            {
                if ((appoint[i].date.year == addDate.year) && (appoint[i].date.month == addDate.month) && (appoint[i].date.day == addDate.day) 
                    && (appoint[i].time.hour == addTime.hour) && (appoint[i].time.min == addTime.min))
                {
                    slotCheck++;
                }
            }

            if (slotCheck != 0)
            {
                puts("\nERROR: Appointment timeslot is not available!\n");
            }
            else//storing the values
            {
                appoint[a].date.year = addDate.year;
                appoint[a].date.month = addDate.month;
                appoint[a].date.day = addDate.day;
                appoint[a].time.hour = addTime.hour;
                appoint[a].time.min = addTime.min;
                appoint[a].patientNumber = tmpPatientnum;
            }
        } while (slotCheck != 0);
        puts("\n*** Appointment scheduled! ***\n");
    }
    SortAppointments(appoint, maxAppointments);
}

// Remove an appointment record from the appointment array
// Todo:
void removeAppointment(struct Appointment* appoint, int maxAppointments, struct Patient* patient, int maxPatient)
{
    int i = 0;
    int patientRecord; 
    int patientNum;
    int check = 0;
    char yesORno;
    struct Date appointDate;
    
    printf("Patient Number: ");
    patientNum = inputIntPositive();
    patientRecord = findPatientIndexByPatientNum(patientNum, patient, maxPatient);
   
    if (patientRecord == -1)
    {
        puts("ERROR: Patient record not found!\n");
    }
    else
    {
        InputDate(&appointDate);
        //calling additional function for date input

        printf("\nName  : %s\n", patient[patientRecord].name);
        printf("Number: %05d\n", patient[patientRecord].patientNumber);
        printf("Phone : ");
        displayFormattedPhone(patient[patientRecord].phone.number);
        printf(" (%s)\n", patient[patientRecord].phone.description);

        printf("Are you sure you want to remove this appointment (y,n): ");
        scanf(" %c", &yesORno);
        if (yesORno == 'y')
        {
            while (check == 0 && i < maxAppointments)
            {
                if ((appoint[i].patientNumber == patientNum) && (appoint[i].date.day == appointDate.day) && 
                    (appoint[i].date.month == appointDate.month) && (appoint[i].date.year == appointDate.year))
                    //check if the input matches data
                {
                    check = 1;
                    //it matches which means it will exit the loop.
                    appoint[i].patientNumber =  0 ;
                    //removing the appointment by emptying the space
                }
                i++;
            }             
            puts("\nAppointment record has been removed!\n");
            clearInputBuffer();
        }
        else
        {
            puts("Cancelled\n");
        }
    }
}

//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (Copy your code from MS#2)
void searchPatientByPatientNumber(const struct Patient patient[], int max)
{
    int patientNum, indexPatient;
    printf("\n");
    printf("Search by patient number: ");
    patientNum = inputInt(); //user input for patient number
    indexPatient = findPatientIndexByPatientNum(patientNum, patient, max);
    //find the index by Calling function with user input
    if (indexPatient == -1)
        //return value was -1 means no record
    {
        printf("\n");
        printf("*** No records found ***\n");
        printf("\n");
    }
    else
    {
        printf("\n");
        displayPatientData(&patient[indexPatient], FMT_FORM);
        printf("\n");
    }

}

// Search and display patient records by phone number (tabular)
// (Copy your code from MS#2)
void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
    char phoneNum[PHONE_LEN + 1];
    int i, found;
    int j = 0;

    printf("\n");
    printf("Search by phone number: ");
    inputCString(phoneNum, 10, 10);
    printf("\n");
    displayPatientTableHeader();
    for (i = 0; i < max; i++)
    {
        found = strcmp(phoneNum, patient[i].phone.number);
        if (found == 0)
        {
            displayPatientData(&patient[i], FMT_TABLE);
            j++; // indicate there is patient found or not
        }
    }
    if (j == 0)
    {
        printf("\n*** No records found ***\n");
    }
    printf("\n");
    clearInputBuffer();
}

// Get the next highest patient number
// (Copy your code from MS#2)
int nextPatientNumber(const struct Patient patient[], int max)
{
    int i, nextPatientNum;
    int largest = 0;
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber > largest)
        {
            largest = patient[i].patientNumber;
        }
    }
    nextPatientNum = largest + 1;
    return nextPatientNum;
}

// Find the patient array index by patient number (returns -1 if not found)
// (Copy your code from MS#2)
int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int max)
{
    int i;
    for (i = 0; i < max; i++)
    {

        if (patient[i].patientNumber == patientNumber)
        {
            return i;
        }
    }
    return -1;
}

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (Copy your code from MS#2)
void inputPatient(struct Patient* patient)
{
    printf("Patient Data Input\n");
    printf("------------------\n");
    printf("Number: %05d\n", patient->patientNumber);
    printf("Name  : ");
    inputCString(patient->name, 1, NAME_LEN);
    printf("\n");
    inputPhoneData(&patient->phone);
}

// Get user input for phone contact information
// (Copy your code from MS#2)
void inputPhoneData(struct Phone* phone)
{
    int selection;
    printf("Phone Information\n");
    printf("-----------------\n");
    printf("How will the patient like to be contacted?\n");
    printf("1. Cell\n");
    printf("2. Home\n");
    printf("3. Work\n");
    printf("4. TBD\n");
    printf("Selection: ");
    scanf("%d", &selection);
    switch (selection)
    {
    case 1:
        strcpy(phone->description, "CELL");
        printf("\n");
        printf("Contact: %s\n", phone->description);
        printf("Number : ");
        inputCString(phone->number, 10, 10);
        clearInputBuffer();
        printf("\n");
        break;
    case 2:
        strcpy(phone->description, "HOME");
        printf("\n");
        printf("Contact: %s\n", phone->description);
        printf("Number : ");
        inputCString(phone->number, 10, 10);
        clearInputBuffer();
        printf("\n");
        break;
    case 3:
        strcpy(phone->description, "WORK");
        printf("\n");
        printf("Contact: %s\n", phone->description);
        printf("Number : ");
        inputCString(phone->number, 10, 10);
        clearInputBuffer();
        printf("\n");
        break;
    case 4:
        strcpy(phone->description, "TBD");
        strcpy(phone->number, "");
        clearInputBuffer();
        printf("\n");
        break;
    default:
        printf("\n");
    }
}


//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
/// ToDo:
int importPatients(const char* datafile, struct Patient patients[], int max)
{
    int i = 0;
    FILE* fp = NULL;
    fp = fopen(datafile, "r");
    //opening the file(first argument file) for reading
    if (fp != NULL)//checking if opening was success
    {
        while (i < max && fscanf(fp, " %d|%15[^|]|%4[^|]|%10[^\n]\n", 
            &patients[i].patientNumber, patients[i].name, patients[i].phone.description, patients[i].phone.number) != EOF)
        {

            i++; //counting the number of patients importing
        }
        fclose(fp);
    }
    else
    {
        printf("Failed to open file\n");
    }


    return i;
    //returning total number of patients
}

// Import appointment data from file into an Appointment array (returns # of records read)
// ToDo:
int importAppointments(const char* datafile, struct Appointment appoints[], int max)
{
    int i= 0; 
    FILE* fp = NULL;

    fp = fopen(datafile, "r");
    //opening the file(first argument file) for reading
    if (fp != NULL) //checking if opening was success
    {
        while (i < max && fscanf(fp, "%d,%d,%d,%d,%d,%d", &appoints[i].patientNumber, &appoints[i].date.year, &appoints[i].date.month, 
            &appoints[i].date.day, &appoints[i].time.hour, &appoints[i].time.min) != EOF)
        {
            i++;//counting the number of record importing
        }
        fclose(fp);
    }
    else
    {
        printf("Failed to open file\n");
    }

    SortAppointments(appoints, max);

    return i;
    //returning total number of records
}

//////////////////////////////////////
// MY FUNCTIONS
//////////////////////////////////////

void InputDate(struct Date* inputDate)
{
    int dayRange = 0;

    printf("Year        : ");
    inputDate->year = inputIntPositive();

    printf("Month (1-12): ");
    inputDate->month = inputIntRange(1, 12);

    if (inputDate->month == 2 && inputDate->year % 4 == 0)
        //checking for leap year
    {
        dayRange = 29;
        printf("Day (1-%d)  : ", dayRange);
    }
    else if (inputDate->month == 4 || inputDate->month == 9 || inputDate->month == 11)
        //months that has 30 days
    {
        dayRange = 30;
        printf("Day (1-%d)  : ", dayRange);
    }
    else if (inputDate->month == 2)
        //Feb has 28 days
    {
        dayRange = 28;
        printf("Day (1-%d)  : ", dayRange);
    }
    else
    {
        dayRange = 31;
        printf("Day (1-%d)  : ", dayRange);
    }//printing day-range depends on the month

    inputDate->day = inputIntRange(1, dayRange);
}

void TimeForAppointment(struct Time* appointmentTime)
{
    int flag = 0;

    do
    {
        flag = 0;
        printf("Hour (0-23)  : ");
        appointmentTime->hour = inputIntRange(0, 23);
        printf("Minute (0-59): ");
        appointmentTime->min = inputIntRange(0, 59);

        if (appointmentTime->hour == CLOSING_HOUR)
        {
            if (appointmentTime->min == 0)
            {
                flag++;
            }
        }// When 'hour' is on the Closing Hour, 'minute; should be 0
        if (appointmentTime->hour >= OPENING_HOUR && appointmentTime->hour <= CLOSING_HOUR - 1)
        {

            if (appointmentTime->min % MINUTE_INTERVAL == 0)
            {
                flag++;
            }
        }// after check if 'hour' is between opening & closing hour, check 'minutes' if its in 30 minutes interval
        if (flag == 0)
        {
            printf("ERROR: Time must be between %d:00 and %d:00 in %d minute intervals.\n\n", OPENING_HOUR, CLOSING_HOUR, MINUTE_INTERVAL);
        }
    } while (flag == 0); 
    
}

void SortAppointments(struct Appointment appoints[], int max)
{
    int i = 0, j = 0, swap;
    struct Appointment appointTmp = { 0 };

    for (i = 0; i < max; i++)
    {
        for (j = 0; j < max; j++)
        {
            swap = 0;
            if (appoints[i].date.year < appoints[j].date.year)
                //Checking the order of years
            {
                swap = 1;
            }

            if (appoints[i].date.year == appoints[j].date.year && appoints[i].date.month < appoints[j].date.month)
                //Checking the order of months
            {
                swap = 1;
            }

            if (appoints[i].date.year == appoints[j].date.year && appoints[i].date.month == appoints[j].date.month
                && appoints[i].date.day < appoints[j].date.day)
                //Checking the order of days
            {
                swap = 1;
            }

            if (appoints[i].date.year == appoints[j].date.year && appoints[i].date.month == appoints[j].date.month
                && appoints[i].date.day == appoints[j].date.day && appoints[i].time.hour < appoints[j].time.hour)
                //Checking the order of hour
            {
                swap = 1;
            }

            if (appoints[i].date.year == appoints[j].date.year && appoints[i].date.month == appoints[j].date.month
                && appoints[i].date.day == appoints[j].date.day && appoints[i].time.hour == appoints[j].time.hour
                && appoints[i].time.min < appoints[j].time.min)
                //Checking the order of minues
            {
                swap = 1;
            }

            if (swap) //if any of conditions above was true, Swan in order to sort them
            {
                appointTmp = appoints[i];
                appoints[i] = appoints[j];
                appoints[j] = appointTmp;
            }

        }

    }

}