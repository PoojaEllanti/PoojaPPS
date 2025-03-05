# PoojaPPS
Project in C about Calendar Application
// C program to print the month by month  
// calendar for the given year  
  
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

// Function that returns the index of the  
// day for date DD/MM/YYYY  
int dayNumber(int day, int month, int year)  
{  
  
    static int t[] = { 0, 3, 2, 5, 0, 3,  
                    5, 1, 4, 6, 2, 4 };  
    year -= month < 3;  
    return (year + year / 4  
            - year / 100  
            + year / 400  
            + t[month - 1] + day)  
        % 7;  
}  
  
// Function that returns the name of the  
// month for the given month Number  
// January - 0, February - 1 and so on  
char* getMonthName(int monthNumber)  
{  
    char* month;  
  
    switch (monthNumber) {  
    case 0:  
        month = "January";  
        break;  
    case 1:  
        month = "February";  
        break;  
    case 2:  
        month = "March";  
        break;  
    case 3:  
        month = "April";  
        break;  
    case 4:  
        month = "May";  
        break;  
    case 5:  
        month = "June";  
        break;  
    case 6:  
        month = "July";  
        break;  
    case 7:  
        month = "August";  
        break;  
    case 8:  
        month = "September";  
        break;  
    case 9:  
        month = "October";  
        break;  
    case 10:  
        month = "November";  
        break;  
    case 11:  
        month = "December";  
        break;  
    }  
    return month;  
}  
  
// Function to return the number of days  
// in a month  
int numberOfDays(int monthNumber, int year)  
{  
    // January  
    if (monthNumber == 0)  
        return (31);  
  
    // February  
    if (monthNumber == 1) {  
        // If the year is leap then Feb  
        // has 29 days  
        if (year % 400 == 0  
            || (year % 4 == 0  
                && year % 100 != 0))  
            return (29);  
        else
            return (28);  
    }  
  
    // March  
    if (monthNumber == 2)  
        return (31);  
  
    // April  
    if (monthNumber == 3)  
        return (30);  
  
    // May  
    if (monthNumber == 4)  
        return (31);  
  
    // June  
    if (monthNumber == 5)  
        return (30);  
  
    // July  
    if (monthNumber == 6)  
        return (31);  
  
    // August  
    if (monthNumber == 7)  
        return (31);  
  
    // September  
    if (monthNumber == 8)  
        return (30);  
  
    // October  
    if (monthNumber == 9)  
        return (31);  
  
    // November  
    if (monthNumber == 10)  
        return (30);  
  
    // December  
    if (monthNumber == 11)  
        return (31);  
}  
  
// Function to print the calendar of  
// the given year  
void printCalendar(int year)  
{  
    printf("     Calendar - %d\n\n", year);  
    int days;  
  
    // Index of the day from 0 to 6  
    int current = dayNumber(1, 1, year);  
  
    // i for Iterate through months  
    // j for Iterate through days  
    // of the month - i  
    for (int i = 0; i < 12; i++) {  
        days = numberOfDays(i, year);  
  
        // Print the current month name  
        printf("\n ------------%s-------------\n",  
            getMonthName(i));  
  
        // Print the columns  
        printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");  
  
        // Print appropriate spaces  
        int k;  
        for (k = 0; k < current; k++)  
            printf("     ");  
  
        for (int j = 1; j <= days; j++) {  
            printf("%5d", j);  
  
            if (++k > 6) {  
                k = 0;  
                printf("\n");  
            }  
        }  
  
        if (k)  
            printf("\n");  
  
        current = k;  
    }  
  
    return;  
}  
//Events

// Define a structure to represent a calendar event
struct Event {
    char date[11];  // Assuming YYYY-MM-DD format
    char details[100];
};

// Function to add an event to the calendar
void addEvent(struct Event calendar[], int *eventCount, char date[], char details[]) {
    if (*eventCount < 100) {  // Assuming a maximum of 100 events
        strcpy(calendar[*eventCount].date, date);
        strcpy(calendar[*eventCount].details, details);
        (*eventCount)++;
      //  printf("Event added successfully.\n");
    } else {
        printf("Calendar is full. Cannot add more events.\n");
    }
}

// Function to display all events on a given date
void displayEvents(struct Event calendar[], int eventCount, char date[]) {
    printf("Alerts/Events %s:\n", date);
    char yeard[30];
    for (int i = 0; i < eventCount; ++i) {
        strncpy(yeard, calendar[i].date, 4);
       // if (strcmp(calendar[i].date, date) == 0) {
        if (strcmp(yeard, date) == 0) {
            strcat(calendar[i].date, calendar[i].details);
            printf("- %s\n", calendar[i].date);
        }
    }
}


// Driver Code  
int main()  
{  
    int year;
	printf("Enter The Year: ");
    scanf("%d",&year);	
    

 
 //evemts
 
 //add events
    struct Event calendar[100];
    int eventCount = 0;
    addEvent(calendar, &eventCount, "2022-01-26", "India Republic Day");
    addEvent(calendar, &eventCount, "2022-08-15", "Independence Day");
    addEvent(calendar, &eventCount, "2022-10-02", "Gandhi Jayanthi");
    
    addEvent(calendar, &eventCount, "2023-01-26", "India Republic Day");
    addEvent(calendar, &eventCount, "2023-08-15", "Independence Day");
    addEvent(calendar, &eventCount, "2023-10-02", "Gandhi Jayanthi");
    
    addEvent(calendar, &eventCount, "2024-01-26", "India Republic Day");
    addEvent(calendar, &eventCount, "2024-08-15", "Independence Day");
    addEvent(calendar, &eventCount, "2024-10-02", "Gandhi Jayanthi");
 
 //display events

    //displayEvents(calendar, eventCount, "2023-01-26");
    displayEvents(calendar, eventCount, "2023");
  
      // Function Call  
    printCalendar(year);   
    return 0;  }
