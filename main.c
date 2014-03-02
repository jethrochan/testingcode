#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "search.h"
#include "vector.h"
#include "main.h"

/* entry point of the program */
int main(int argc, char *argv[]) {
	struct Individual *individuals = NULL;
    struct Family *families = NULL;

	/* two ints to hold the sizes of the two sets of parallel arrays */
    int indi_count = 0;
    int fam_count = 0;

	/* and a FILE */
    FILE *fp = NULL;

    /* there should only be 2 arguments */
    if(argc != 2) {
        printf("Usage: family.out <ged_filename>\n");
        return 1;
    }

	fp = count_records(argv[1], &indi_count, &fam_count);
    initialize(indi_count, fam_count, &individuals, &families);

	read_file(fp, individuals, families);


	/* sort individuals and families qsort functions */
    qsort(individuals, indi_count, sizeof(struct Individual), individual_cmp);
	qsort(families, fam_count, sizeof(struct Family), family_cmp);

    find_children(indi_count, fam_count, individuals, families);
    deallocate(indi_count, fam_count, individuals, families);

	return 0;
}
