#include <stdio.h>

struct student {
    char name[50];
    char major [20];
    double gpa;
};

int main() {
    int i = 0;
    int j;
    int max_value = 20;
    int menu;
    struct student murid[20];

    do{
    printf("Welcome to simple student database (%i/20)\n", i);
    printf("1. Show all students\n");
    printf("2. Input new students\n");
    printf("3. Exit\n");
    printf("Choose: "); scanf("%i%*c", &menu);
    fflush(stdin);

    switch (menu)
    {
        case 1 :
            if (i == 0){
                printf("Database is still empty\n");
                printf("\n");
                }
            else{
                printf("              List of Student Information           \n");
                printf("----------------------------------------------------\n");
                printf("|No.|         Name         |     Major     |  GPA  |\n" );
                printf("----------------------------------------------------\n");
                for (j = 0; j < i; j++){
                printf("|%2i.| %-20s | %-13s | %-5.2lf |\n", j+1, murid[j].name, murid[j].major, murid[j].gpa);
                }
                printf("----------------------------------------------------\n");
                printf ("\n\n");
            }
                break;
        case 2 :
            if(i == max_value){
                printf("Database is full\n");
                printf("\n");
            }
            else {
            printf("\n");
            printf("------------------------------- \n");
            printf("   Insert Student Information   \n");
            printf("------------------------------- \n");
            printf("Name  : "); scanf("%s", &murid[i].name);
            printf("Major : "); scanf("%s", &murid[i].major);
            printf("GPA   : "); scanf("%lf", &murid[i].gpa);
            printf("Inserting data\n");
            printf("New students added\n\n");
            i++;
            }
            break;
        case 3:
            printf("Thank you and good bye!\n");
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    } while(menu != 3);
}


