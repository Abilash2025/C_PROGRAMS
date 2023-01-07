#include <stdio.h>
#include <stdlib.h>

void tower_of_hanoi(int no_of_disks , char from_rod , char to_rod , char auxillary_rod);

int main()
{
    int no_of_disks;

    printf("Enter the number of disks : ");

    scanf("%d" , &no_of_disks);

    char from_rod = 'A';
    char to_rod = 'B';
    char auxillary_rod = 'C';

    tower_of_hanoi(no_of_disks , from_rod , to_rod , auxillary_rod);

    return 0;
}

void tower_of_hanoi(int no_of_disks , char from_rod , char to_rod , char auxillary_rod)
{
    if (no_of_disks == 1)
    {
        printf("Move disk %d from rod %c to rod %c \n" , no_of_disks , from_rod , to_rod);
    }
    else
    {
        tower_of_hanoi(no_of_disks - 1 , from_rod , auxillary_rod , to_rod);

        printf("Move disk %d from rod %c to rod %c \n" , no_of_disks , from_rod , to_rod);

        tower_of_hanoi(no_of_disks - 1 , auxillary_rod , to_rod , from_rod);
    }
}
