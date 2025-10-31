#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // Que: Как обеспечить каждый раз разную генерацию?

    int amount_of_beads,
        amount_of_bins, i, j, final_bin_index, max_height_of_bins_for_image = 0;

    printf("Enter the number of beads: ");
    scanf("%d", &amount_of_beads);
    printf("Enter the number of bins: ");
    scanf("%d", &amount_of_bins);

    int bins[amount_of_bins];

    for (i = 0; i < amount_of_bins; i++)
    {
        bins[i] = 0;
    }

    for (i = 0; i < amount_of_beads; i++)
    {
        final_bin_index = 0;
        for (j = 0; j < amount_of_bins - 1; j++)
        {
            if (rand() % 2)
            {
                final_bin_index++;
            }
        }
        bins[final_bin_index]++;
    }

    for (i = 0; i < amount_of_bins; i++)
    {
        if (max_height_of_bins_for_image < bins[i])
        {
            max_height_of_bins_for_image = bins[i];
        }
    }

    char ascii_image[max_height_of_bins_for_image][amount_of_bins];

    for (i = 0; i < max_height_of_bins_for_image; i++)
    {
        for (j = 0; j < amount_of_bins; j++)
        {
            ascii_image[i][j] = ' ';
        }
    }

    // bins = [1,3,5,10,5,3,1]

    for (i = 0; i < max_height_of_bins_for_image; i++)
    {
        for (j = 0; j < amount_of_bins; j++)
        {
            if (bins[j] >= max_height_of_bins_for_image - i)
            {
                ascii_image[i][j] = 'X';
            }
        }
    }

    for (i = 0; i < max_height_of_bins_for_image; i++)
    {
        for (j = 0; j < amount_of_bins; j++)
        {
            printf("%c ", ascii_image[i][j]);
        }
        printf("%c", '\n');
    }
}