#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED
#define T 5

    typedef struct File{
        int elt;
        struct File * next;
    }*File;

    int filevide();
    int filepleine();
    void inserer(int y);
    int retirer();
    void afficher();
    void menu();

#endif

