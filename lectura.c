//
// Alejandro Viana Labà - Blai Jordan Borobia | Logins: alejandro.viana - blai.jordan
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
    general.categoria = malloc(sizeof(Categoria));
    for (int i = 0; i < general.numCategorias; ++i) {
        general.categoria = (Categoria*)realloc(general.categoria, sizeof(Categoria)*(i+1));
        fscanf(fp,"%s",general.categoria[i].nombreCategoria);
        fscanf(fp,"%c", &aux);
        while (aux != '\n'){
            fscanf(fp,"%s",cadena);
            fscanf(fp,"%c", &aux);
            strcat(general.categoria[i].nombreCategoria," ");
            strcat(general.categoria[i].nombreCategoria,cadena);
        }
        fscanf(fp,"%d", &general.categoria[i].numPiezas);
        general.categoria[i].pieza = (Pieza*)malloc(sizeof(Pieza));
        for (int j = 0; j < general.categoria[i].numPiezas; ++j) {
            general.categoria[i].pieza = (Pieza*)realloc(general.categoria[i].pieza, sizeof(Pieza)*(j+1));
            fscanf(fp,"%s",general.categoria[i].pieza[j].nombrePieza);
            fscanf(fp,"%c", &aux);
            while (aux != '\n'){
                fscanf(fp,"%s",cadena);
                fscanf(fp,"%c", &aux);
                strcat(general.categoria[i].pieza[j].nombrePieza," ");
                strcat(general.categoria[i].pieza[j].nombrePieza,cadena);
            }
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

General lecturaGPs(char * argv, General general){
    char cadena[50], aux = ' ';
    GP gpaux;
    general.listaGP = NULL;
    struct _node * new_node;
    FILE * fp = fopen(argv, "r");
    if (fp == NULL) {
        printf("Error: Fichero inexistente.\n\n");
        exit(0);
    }
    fscanf(fp, "%d", &general.numGPs);
    for (int i = 0; i < general.numGPs; ++i) {
        fscanf(fp, "%d", &gpaux.posCalndario);
        fscanf(fp, "%s", gpaux.nombreGP);
        fscanf(fp,"%c", &aux);
        while (aux != '\n'){
            fscanf(fp,"%s",cadena);
            fscanf(fp,"%c", &aux);
            strcat(gpaux.nombreGP," ");
            strcat(gpaux.nombreGP,cadena);
        }
        fscanf(fp, "%d", &gpaux.velocidadAdec);
        fscanf(fp, "%d", &gpaux.aceleracionAdec);
        fscanf(fp, "%d", &gpaux.consumoAdec);
        fscanf(fp, "%d", &gpaux.fiabilidadAdec);
        fscanf(fp, "%f", &gpaux.tiempoBase);
        fscanf(fp, "%d", &gpaux.tiempoPinStop);
        fscanf(fp, "%d", &gpaux.numeroPinStop);
        new_node = newNode(gpaux);
        sortedInsert(&general.listaGP,new_node);
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
    printf("WHAT THE FUCK 4\n");
    fclose(fp);
    return general;
}