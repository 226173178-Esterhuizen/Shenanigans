#ifndef ASSETS_H
#define ASSETS_H

struct Asset {
    int id;
    char name[50];
    char type[30];
    float value;
    char department[50];
    char condition[30];
};

void manageAssets();

#endif