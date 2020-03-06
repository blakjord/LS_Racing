//
// Created by Alejandro on 03/03/2020.
//
#include "lectura.h"

General lecturaFicheros(char * argv[]){
    General general;
    general = lecturaPiezas(argv[1], general);
    general = lecturaGPs(argv[2], general);
    general = lecturaCorredores(argv[3], general);
    general = lecturaBase(argv[4], general);
    return general;
}

General lecturaPiezas(char * argv, General general) {
    char cadena[50], aux = ' ';
    FILE * fp = fopen(argv, "r");
    if (fp == NULL) {
        printf("Error: Fichero inexistente.\n\n");
        exit(0);
    }
    fscanf(fp,"%d",&general.numCategorias);
    //printf("%d",general.numCategorias);
    general.categoria = malloc(sizeof(Categoria));
    for (int i = 0; i < general.numCategorias; ++i) {
        //printf("i: %d\n",i);
        general.categoria = (Categoria*)realloc(general.categoria, sizeof(Categoria)*(i+1));
        fscanf(fp,"%s",general.categoria[i].nombreCategoria);
        fscanf(fp,"%c", &aux);
        while (aux != '\n'){
            fscanf(fp,"%s",cadena);
            fscanf(fp,"%c", &aux);
            strcat(general.categoria[i].nombreCategoria,cadena);
        }
        //printf("Nombre Categoria: %s\n", general.categoria[i].nombreCategoria);
        fscanf(fp,"%d", &general.categoria[i].numPiezas);
        //printf("Numero Piezas %d\n", general.categoria[i].numPiezas);
        general.categoria[i].pieza = (Pieza*)malloc(sizeof(Pieza));
        for (int j = 0; j < general.categoria[i].numPiezas; ++j) {
            //printf("j: %d\n",j);
            general.categoria[i].pieza = (Pieza*)realloc(general.categoria[i].pieza, sizeof(Pieza)*(j+1));
            fscanf(fp,"%s",general.categoria[i].pieza[j].nombrePieza);
            fscanf(fp,"%c", &aux);
            while (aux != '\n'){
                fscanf(fp,"%s",cadena);
                fscanf(fp,"%c", &aux);
                strcat(general.categoria[i].pieza[j].nombrePieza,cadena);
            }
            //printf("Nombre Piezas: %s\n", general.categoria[i].pieza[j].nombrePieza);
            fscanf(fp, "%d", &general.categoria[i].pieza[j].velocidad);
            fscanf(fp, "%d", &general.categoria[i].pieza[j].aceleracion);
            fscanf(fp, "%d", &general.categoria[i].pieza[j].consumo);
            fscanf(fp, "%d", &general.categoria[i].pieza[j].fiabilidad);
        }
    }
    printf("WHAT THE FUCK 1\n");
    fclose(fp);
    return general;
}

/*void swap(GP * gp1, GP * gp2){
    GP * aux = NULL;
    *aux = *gp1;
    *gp1 = *gp2;
    *gp2 = *aux;
}

void bubbleSort(GP * gp, int n){
    int i, j,r;
    for (i = 0; i < n-1; i++){
        for (j = 0; j < n-i-1; j++){
            r = strcmp(,);
            if (r > 0){
                swap(&gp[j], &gp[j+1]);
            }
        }
    }
}*/

General lecturaGPs(char * argv, General general){
    char cadena[50], aux = ' ';
    GP * gp;
    general = GPLIST_create(general);
    FILE * fp = fopen(argv, "r");
    if (fp == NULL) {
        printf("Error: Fichero inexistente.\n\n");
        exit(0);
    }
    fscanf(fp, "%d", &general.listaGp.numGPs);
    gp = (GP*)malloc(sizeof(GP));
    for (int i = 0; i < general.listaGp.numGPs; ++i) {
        //printf("i: %d",i);
        gp = (GP*)realloc(gp, sizeof(GP)*(i+1));
        fscanf(fp, "%d", &gp[i].posCalndario);
        fscanf(fp, "%s", gp[i].nombreGP);
        fscanf(fp,"%c", &aux);
        while (aux != '\n'){
            fscanf(fp,"%s",cadena);
            fscanf(fp,"%c", &aux);
            strcat(gp[i].nombreGP,cadena);
        }
        //printf("%s",general.gp[i].nombreGP);
        fscanf(fp, "%d", &gp[i].velocidadAdec);
        fscanf(fp, "%d", &gp[i].aceleracionAdec);
        fscanf(fp, "%d", &gp[i].consumoAdec);
        fscanf(fp, "%d", &gp[i].fiabilidadAdec);
        fscanf(fp, "%f", &gp[i].tiempoBase);
        fscanf(fp, "%d", &gp[i].tiempoPinStop);
        fscanf(fp, "%d", &gp[i].numeroPinStop);
        GPLIST_insert(&general.listaGp , gp[i]);
    }
    fclose(fp);
    printf("WHAT THE FUCK 2\n");
    return general;
}

General lecturaCorredores(char * argv, General general){
    FILE * fp = fopen(argv, "r");
    if (fp == NULL) {
        printf("Error: Fichero inexistente.\n\n");
        exit(0);
    }
    general.corredor = (Corredor*)malloc(sizeof(Corredor)*7);
    for (int i = 0; i < 7; ++i) {
        fread(&general.corredor[i], sizeof(Corredor), 1, fp);
        /*printf("i: %d, nombre: %s\n", i, general.corredor[i].nombreCorredor);
        printf("%s\n",general.corredor[i].escuderia);
        printf("%d\n", general.corredor[i].consumo);
        printf("%d\n", general.corredor[i].aceleracion);
        printf("%d\n", general.corredor[i].velocidad);
        printf("%d\n", general.corredor[i].condicionFisica);
        printf("%d\n", general.corredor[i].dorsal);
        printf("%d\n", general.corredor[i].fiabilidad);
        printf("%d\n", general.corredor[i].reflejos);*/
    }
    printf("WHAT THE FUCK 3\n");
    fclose(fp);
    return general;
}

General lecturaBase(char * argv, General general){
    FILE * fp = fopen(argv, "r");
    if (fp == NULL) {
        printf("Error: Fichero inexistente.\n\n");
        exit(0);
    }
    fread(&general.base, sizeof(Base), 1, fp);
    //printf("Estadisticas: %d , %d , %d , %d .", general.base.fiabilidad, general.base.velocidad, general.base.aceleracion, general.base.consumo);
    printf("WHAT THE FUCK 4\n");
    fclose(fp);
    return general;
}