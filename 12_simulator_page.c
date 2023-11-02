#include <stdio.h>
// #include <conio.h>
int i, j, nof, nor, flag = 0, ref[50], frm[50], pf = 0, victim = -1;
void main()
{
    
    printf("\n \t\t\t FIFI PAGE REPLACEMENT ALGORITHM");
    printf("\n Enter no.of frames ... ");
    scanf("%d", &nof);
    printf("Enter number of Pages.\n");
    scanf("%d", &nor);
    printf("\n Enter the Page No .. ");
    for (i = 0; i < nor; i++)
        scanf("%d", &ref[i]);
    printf("\nThe given Pages are:");
    for (i = 0; i < nor; i++)
        printf("%4d", ref[i]);
    for (i = 1; i <= nof; i++)
        frm[i] = -1;
    printf("\n");
    for (i = 0; i < nor; i++)
    {
        flag = 0;
        printf("\n\t page no %d->\t", ref[i]);
        for (j = 0; j < nof; j++)
        {
            if (frm[j] == ref[i])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            pf++;
            victim++;
            victim = victim % nof;
            frm[victim] = ref[i];
            for (j = 0; j < nof; j++)
                printf("%4d", frm[j]);
        }
    }
    printf("\n\n\t\t No.of pages faults...%d", pf);


}