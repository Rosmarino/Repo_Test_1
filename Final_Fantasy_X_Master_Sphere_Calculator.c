#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _stat
{
    char info[15]; // Stat's name
    int number; // Number of spheres of the current stat
    int total; // Total amount of the stat
}StatOfSphere;
typedef StatOfSphere *SphereOfStats;

void PrintSphere (SphereOfStats Sphere[], int free) // Prints the full sphere at each call
{
    printf("The current sphere is:\n\n");
    for (int i = 0; i < 10; i++)
        printf("[%s] = %d. Current number of spheres = %d\n", Sphere[i]->info, Sphere[i]->total, Sphere[i]->number);
    printf("Number of free spaces = %d\n\n", free);
}

int main ()
{
    int i = 0, free = 0; // Free = Free spheres
    SphereOfStats *Sphere = (SphereOfStats*)malloc(10 * sizeof(StatOfSphere*)); // Full sphere
    for (i = 0; i < 10; i++) // Sphere creation
    {
        Sphere[i] = (SphereOfStats)malloc(sizeof(StatOfSphere));
        Sphere[i]->number = 0;
        Sphere[i]->total = 0;
       switch (i)
       {
   	    case 0:
   	    	strcpy(Sphere[0]->info, "HP");
   	    	break;
   	    case 1:
   	    	strcpy(Sphere[1]->info, "STRENGHT");
   	    	break;
   	    case 2:
   	    	strcpy(Sphere[2]->info, "DEFENSE");
   	    	break;
   	    case 3:
   	    	strcpy(Sphere[3]->info, "MAGIC");
   	    	break;
   	    case 4:
   	    	strcpy(Sphere[4]->info, "MAGIC DEFENSE");
   	    	break;
   	    case 5:
   	    	strcpy(Sphere[5]->info, "MP");
   	    	break;
   	    case 6:
   	    	strcpy(Sphere[6]->info, "AGILITY");
   	    	break;
   	    case 7:
   	    	strcpy(Sphere[7]->info, "LUCK");
   	    	break;
   	    case 8:
   	    	strcpy(Sphere[8]->info, "EVASION");
   	    	break;
   	    case 9:
   	    	strcpy(Sphere[9]->info, "ACCURACY");
   	    	break;
	}
    }
    PrintSphere(Sphere, free);
    char yes, print, keep, wish, operation;
    int check = 0, quantity = 0;
    while (yes != 'n') // While you want to modify the sphere
    {
        keep = 'y';
        printf("Do you want to modify the Sphere? y / n\n");
        scanf("\n%c", &yes);
        while (yes != 'y' && yes != 'n')
        {
            printf("Wrong operation.\nDo you want to modify the Sphere? y / n\n");
            scanf("\n%c", &yes);        
        }
        if(yes == 'y')
        {
            printf("Select the stat you want to modify:\n[0] - HP\n[1] - STRENGHT\n[2] - DEFENSE\n[3] - MAGIC\n[4] - MAGIC DEFENSE\n[5] - MP\n[6] - AGILITY\n[7] - LUCK\n[8] - EVASION\n[9] - ACCURACY\n[10] - FREE SPACES\n");
            scanf("%d", &check);
            while(check < 0 || check > 10)
            {
                printf("Wrong choice.\nSelect the stat you want to modify:\n[0] - HP\n[1] - STRENGHT\n[2] - DEFENSE\n[3] - MAGIC\n[4] - MAGIC DEFENSE\n[5] - MP\n[6] - AGILITY\n[7] - LUCK\n[8] - EVASION\n[9] - ACCURACY\n[10] - FREE SPACES\n");
                scanf("%d", &check);
            }
            if (check == 10)
            {
                printf("You selected FREE SPACES:\n");
                while (keep != 'n')
                {
                    printf("Do you wish to add or subtract? + / -\n");
                    scanf("\n%c %d", &operation, &quantity);
                    if(operation == '+')
                        free += quantity;
                    else if (operation == '-')
                        free -= quantity;
                    else
                        printf("Wrong operation.\n");
                    printf("Current FREE SPACES = %d. Do you wish to continue to modify this stat? y / n\n", free);
                    scanf("\n%c", &keep);
                }
            }
            else
            {
                printf("You selected %s:\n", Sphere[check]->info);
                while (keep != 'n')
                {
                    printf("Which paramether do you wish to edit?\n[1] - Number of spheres\n[2] - Stat's amount\n");
                    scanf("%d", &quantity);
                    if (quantity == 1) // Number of spheres
                    {
                        printf("Do you wish to add or subtract? + / -\n");
                        scanf("\n%c %d", &operation, &quantity);
                        if (check == 0) // HP
                        {
                            if (operation == '+')
                            {
                                Sphere[check]->number += quantity;
                                Sphere[check]->total += quantity * 300;
                            }
                            else if (operation == '-')
                            {
                                Sphere[check]->number -= quantity;
                                Sphere[check]->total -= quantity * 300;
                            }
                            else
                                printf("Wrong operation\n");
                        }
                        else if (check == 5) // MP
                        {
                            if (operation == '+')
                            {
                                Sphere[check]->number += quantity;
                                Sphere[check]->total += quantity * 40;
                            }
                            else if (operation == '-')
                            {
                                Sphere[check]->number -= quantity;
                                Sphere[check]->total -= quantity * 40;
                            }
                            else
                                printf("Wrong operation\n");
                        }
                        else
                        {
                            if (operation == '+')
                            {
                                Sphere[check]->number += quantity;
                                Sphere[check]->total += quantity * 4;
                            }
                            else if (operation == '-')
                            {
                                Sphere[check]->number -= quantity;
                                Sphere[check]->total -= quantity * 4;
                            }
                            else
                                printf("Wrong operation\n");
                        }
                    }
                    else if (quantity == 2) // Stat's amount
                    {
                        printf("Do you wish to add or subtract? + / -\n");
                        scanf("\n%c %d", &operation, &quantity);
                        if (operation == '+')
                            Sphere[check]->total += quantity;
                        else if (operation == '-')
                            Sphere[check]->total -= quantity;
                        else
                            printf("Wrong operation\n");
                    }
                    else
                        printf("Wrong selection\n");
                    printf("Current %s: Number of spheres = %d. Stat's amount = %d.\nDo you wish to continue to modify this stat? y / n\n", Sphere[check]->info, Sphere[check]->number, Sphere[check]->total);
                    scanf("\n%c", &keep);
                    if(check == 0)
                        printf("You still need %d spheres to reach the perfect stat\n", (99900 - Sphere[check]->total) / 300);
                    else if(check == 5)
                        printf("You still need %d spheres to reach the perfect stat\n", (1000 - Sphere[check]->total) / 40);
                    else if(check == 7)
                        printf("You still need %d spheres to reach the perfect stat\n", (240 - Sphere[check]->total) / 4);
                    else
                        printf("You still need %d spheres to reach the perfect stat\n", (252 - Sphere[check]->total) / 4);
                }
            }
        }
        printf("Do you want to print the current Sphere? y / n\n");
        scanf("\n%c", &print);
        while (print != 'y' && print != 'n')
        {
            printf("Wrong operation.\nDo you want to print the current Sphere? y / n\n");
            scanf("\n%c", &print);
        }
        if(print == 'y')
            PrintSphere(Sphere, free);
    }
    return 0;
}
