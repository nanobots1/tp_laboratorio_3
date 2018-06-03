    #include <stdio.h>
    #include <stdlib.h>
    #include "lib.h"
    #include "bajaMovie.h"

    void bajaMovie(eMovie movie[],int tammovies) {
        int i;
        int id;
        int salir;
        do{
            salir=0;
            system("cls");
            printf("\t ------------------------------------------------------------\n");
            printf("\t|                         Baja de movie                      |\n");
            printf("\t ------------------------------------------------------------\n");
 //           ordenarMovieId(movie, tammovies);
            mostrarListaMovie(movie, tammovies);
            printf("\n\n\n\t\t Selecione un movie a dar de baja - 0 salir : ");
            scanf("%d", &id);
            if(id!=0){
                for(i=0; i<tammovies; i++){
                    if(movie[i].idMovie == id && movie[i].estado==1){
                        confirmaBaja(movie, i, tammovies);
                        salir=2;
                        break;
                    }else{
                        salir=3;
                    }
                }
                if (salir==3){
                    printf("\n\tMovie %d no exsiste - ",id);
                    system("pause");
                }
            }
         }while(salir!=0);
       }

       void confirmaBaja(eMovie movie[], int id, int tammovies ){
        int salir=0;
        do{
            int opcion=0;
            system("cls");
            printf("\t-------------------------------------------------------\n");
            printf("\t|                 Baja de movie                     |\n");
            printf("\t-------------------------------------------------------\n");
            printf("\n\n\t\t\tMovie Nro.: %d",movie[id].idMovie);
            printf("\n\n\t\t\tNombre    : %s",movie[id].titulo);
            printf("\n\n\t\t\tDomicilio : %s",movie[id].genero);
            printf("\n\n\t\t\tMovie Nro.: %d",movie[id].duracion);
            printf("\n\n\t\t\tMovie Nro.: %d",movie[id].puntaje);
            printf("\n\n\t\t\tLink      : %s",movie[id].LinkDeImagen);
            printf("\n\n\n\n\n\n\t\tElija una opcion  1 Confirma baja - 0 Salir :--> ");
            scanf("%d",&opcion);
            if (opcion<0 || opcion>1){
               printf("\n\n\t\t\tError - Debe ingresar entre %d y %d\n",0,1);
               system("\n\n\t\tpause");
            }
            switch(opcion) {
                case  0 :
                    salir=-1;
                    break;
                case 1 :
                   movie[id].estado=0;
                grabarBinario(movie, tammovies);
                   salir=-1;
                   break;
            }
    }while(salir!=-1);
  }
