#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "time.h"
#include "TreeRB.h"

int randomRange(int min, int max){
   return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

double testARB(unsigned int n){
    clock_t begin = clock();

    ARB root = NULL;
    for(int i = 0; i < n; i++){
        Ajouter(root, randomRange(-50, 50));
    }

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    return time_spent;
}

void gnuprint(FILE *gp, unsigned int x[], double y[], int N)
{
    fprintf(gp, "plot '-' with lines, '-' with lines\n");

    for (int i=0; i<N; i++)
    {
        printf("%d: %lf\n", x[i], y[i]);
        fprintf(gp, "%d %lf \n", x[i], y[i]);
    }
    fflush(gp);
    fprintf(gp, "e\n");
}

int main()
{
    unsigned int samples[5] = {10, 100, 500, 1000, 1500};
    double result[5] = {0, 0, 0, 0, 0};

    // Faire le test
    for(int i = 0; i < 5; i++){
        result[i] = testARB(samples[i]);
    }

    FILE * gnuplotPipe = popen ("gnuplot -persistent", "w");
    gnuprint(gnuplotPipe, samples, result, 5);

    return EXIT_SUCCESS;
}
