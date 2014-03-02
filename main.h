#ifndef MAIN_H
#define MAIN_H

/* definition of an individual */
struct Individual {
    char *INDI;
    char *FAMC;
    char *FAMS;
    char *name;
};

/* definition of a family */
struct Family {
    char *FAM;
    char *HUSB;
    char *WIFE;
    char **CHILs;
    int chil_count;
};

#endif
