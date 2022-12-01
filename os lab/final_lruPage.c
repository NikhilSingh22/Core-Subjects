#include <stdio.h>

int main()
{
    int n, np;
    printf("Enter the size of reference string : ");
    scanf("%d", &n);
    int s[n];
    printf("Enter the reference string : ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &s[i]);
    }

    printf("Enter the number of frames : ");
    scanf("%d", &np);
    int p[np];
    int hist[np];
    for(int i = 0; i < np; i++)
    {
        p[i] = -1;
        hist[i] = 0-i; // for making initial priority in filling the pages
    }
    int pagefaults = 0;
    int pagehits = 0;


    printf("\tPage");
    for(int i = 1; i <= np; i++)
    {
        printf("\tframe%d", i);
    }


    for(int i = 0; i < n; i++)
    {
        int currpage = s[i];
        int fl = 0;
        for(int j = 0; j < np; j++)
        {
            if(p[j] == currpage) // page hit
            {
                pagehits++;
                //reduce everyone's count except for p[j];
                hist[j] = 0;
                for(int k = 0; k < np; k++)
                {
                    if(k == j) continue;
                    hist[k]--;
                }
                fl = 1;
                break;
            }
        }
        if(fl == 0)//page fault
        {
            pagefaults++;
            //find the one that was least recently used;
            int mn = 0;
            for(int j = 0; j < np; j++)
                if(hist[j] < hist[mn]) mn = j;

            p[mn] = currpage;
            hist[mn] = 0;
            for(int k = 0; k < np; k++)
            {
                if(k == mn)continue;
                hist[k]--;
            }
        }

        printf("\n\t%d", currpage);
        for(int i = np-1; i >= 0; i--)
        {
            if(p[i] == -1)
                printf("\t-");
            else
                printf("\t%d", p[i]);
        }
    }

    printf("\nTotal Page faults : %d", pagefaults);
    printf("\nTotal Page hits : %d", pagehits);

    return 0;
}
