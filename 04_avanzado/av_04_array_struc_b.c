#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_OF_STRINGS 5
#define MAX_CHARS 28
#define SALES_DEP_EMPLOY 2

typedef struct Address
{
    char street[45];
    int number;
    char door[14];
}
Address;

typedef struct Salary
{
    // General labor agreement
    int general;
    // Overtime hours pay
    int overtime;
    // Pay for extraordinary benefits
    int extra;
}
Salary;

typedef struct Confidential
{
    char civil_status[25];
    // Disability percentage recognized by the labor administration
    float percentage;
    char **computer_skills;
}
Confidential;

typedef struct Employee
{
    char name[50];
    Address adr;
    Salary sal;
    Confidential con;
    char hire_date[10]; // Example 20/10/2012, 2012/20/10, 2012/10/20
}
Employee;

void read_data(Employee *s);
void print_data(Employee *s);
void free_willy(Employee *s);
void separation_line(void);
void clean_stdin(void);

int main(void)
{ 
    Employee sales_agents[SALES_DEP_EMPLOY];

    read_data(sales_agents);
    print_data(sales_agents);
    free_willy(sales_agents);
}

void read_data(Employee *s)
{
    for (int i = 0; i < SALES_DEP_EMPLOY; i++)
    {
        printf("Name: ");
        scanf(" %[^\n]s", s[i].name);
        clean_stdin();
        printf("Street: ");
        scanf(" %[^\n]s", s[i].adr.street);
        clean_stdin();
        printf("Number: ");
        scanf("%i", &s[i].adr.number);
        printf("Door: ");
        scanf(" %[^\n]s", s[i].adr.door);
        clean_stdin();

        printf("2023 salary: ");
        scanf("%i", &s[i].sal.general);
        printf("2023 overtime hours pay: ");
        scanf("%i", &s[i].sal.overtime);
        printf("2023 extraordinary benefits: ");
        scanf("%i", &s[i].sal.extra);

        printf("Civil status: ");
        scanf(" %[^\n]s", s[i].con.civil_status);
        clean_stdin();

        printf("Hire date: ");
        scanf(" %[^\n]s", s[i].hire_date);
        clean_stdin();

        printf("Disability: ");
        scanf("%f", &(s[i].con.percentage));
        s[i].con.computer_skills = (char **)malloc(NUM_OF_STRINGS * sizeof(char *));

        for (int j = 0; j < NUM_OF_STRINGS; j++)
        {
            // Allocate a new buffer for each element in array
            s[i].con.computer_skills[j] = (char *)malloc(MAX_CHARS * sizeof(char));
            printf("Skill %i: ", j + 1);
            scanf(" %[^\n]s", s[i].con.computer_skills[j]);
            clean_stdin();
        }   
    }
}

// This function is a demonstration, not all employee data is printed
void print_data(Employee *s)
{
    for (int i = 0; i < SALES_DEP_EMPLOY; i++)
    {
        printf("Data:\n%s\n%s %i %s\n%i\n%i\n%i\nTotal salary: %i\n%s\n%f\nHire date: %s\n",
        s[i].name, s[i].adr.street, s[i].adr.number, s[i].adr.door,
        s[i].sal.general, s[i].sal.overtime, s[i].sal.extra,
        s[i].sal.general + s[i].sal.overtime + s[i].sal.extra,
        s[i].con.civil_status, s[i].con.percentage, s[i].hire_date);

        for (int j = 0; j < NUM_OF_STRINGS; j++)
        {
            printf("Skill %i : %s\n", j + 1, s[i].con.computer_skills[j]);
        }

        separation_line();
    }
}

void free_willy(Employee *s)
{
    for (int i = 0; i < SALES_DEP_EMPLOY; i++)
    {   
        for (int j = 0; j < NUM_OF_STRINGS; j++)
        {
            free(s[i].con.computer_skills[j]);
        }
        
        free(s[i].con.computer_skills);
    }
}

void separation_line(void)
{
    int hyphen_number = 6;
    for (int i = 0; i < hyphen_number; i++)
    {
        printf("-");
    }
    printf("\n");
}

void clean_stdin(void)
{
    int c;
    do
    {
        c = getchar();
    }
    while (c != '\n' && c != EOF);
}
