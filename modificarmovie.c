    /**
     * Programación I - UTN Fra
     * Trabajo práctico Nº 3 - ABM
     * Alumno : Roberto Desipio 1 C
     */

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <conio.h>
    #include "lib.h"
    #include "modificarMovie.h"

    void modificarMovie(eMovie movie[],int tammovies) {
        int i;
        int id;
        int salir=0;
        int flagMovie=0;
        do{
            system("cls");
            printf("\t -------------------------------------------------------\n");
            printf("\t|             Modificacion  de movie                    |\n");
            printf("\t -------------------------------------------------------\n");
            id=eMovieVacio(movie, tammovies);
            if(id==0){
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\tNo hay movie para mostrar - archivo vacio ");
                system("pause");
            }else{
                mostrarListaMovie(movie, tammovies);
                printf("\n\n\n\t\t Selecione un pelicula a modificar - 0 salir : ");
                scanf("%d", &id);
                if(id!=0){
                    for(i=0; i<tammovies; i++){
                        if(movie[i].idMovie == id){
                            movie[i].estado=0;
                            cambiosMovie(movie, i, tammovies);
                            flagMovie=1;
                            salir=-1;
                            break;
                        }
                    }
                    if (flagMovie!=1){
                            printf("\n\tEl movie %d no exsiste  -  ",id);
                            system("pause");
                            break;
                    }

                }else{
                        salir=-1;
                    }
            }
        }while(salir!=-1);
    }

    void cambiosMovie(eMovie movie[],int id, int tammovies) {
        eMovie auxMovie;
        auxMovie=movie[id];
        int salir=0;
        int min;
        int max;

        do{
            fflush(stdin);
            system("cls");
            printf("\t -------------------------------------------------------\n");
            printf("\t|               Modificacion  de movie                |\n");
            printf("\t -------------------------------------------------------");
            int opcion=0;
            printf("\n\n\n\t\tMovie Nro.  : %d",auxMovie.idMovie);
            printf("\n\n\t\t1- titulo     : %s",auxMovie.titulo);
            printf("\n\n\t\t2- genero     : %s",auxMovie.genero);
            printf("\n\n\t\t3- duracion   : %d",auxMovie.duracion);
            printf("\n\n\t\t4- puntaje    : %d",auxMovie.puntaje);
            printf("\n\n\t\t5- link       : %s",auxMovie.LinkDeImagen);
            printf("\n\n\n\n\t\tIngrese campo a modificar - 0 Guardar :--> ");
            scanf("%d",&opcion);

            if (opcion< 0 || opcion>5){
               printf("\n\n\t\t\tError - Debe ingresar entre %d y %d\n",0,5);
               system("\n\n\t\tpause");
            }
            switch(opcion){
                case 0:
                    guardarcambios(movie, id, auxMovie, tammovies);
                    salir=-1;
                    break;
                 case 1:
                    printf("\n\t\tIngresar titulo: ");
                    fflush(stdin);
                    gets(auxMovie.titulo);
                    break;
               case 2:
                    printf("\t\tIngresar genero     : ");
                    fflush(stdin);
                    gets(auxMovie.genero);
                    break;
               case 3:
                    min=100;
                    max=300;
                    auxMovie.duracion=ingresoNumero("Ingrese duracion : ",min ,max);
                    break;
               case 4:
                    min=1;
                    max=100;
                    auxMovie.puntaje=ingresoNumero("Ingrese puntaje : ",min,max);
                    break;
               case 5:
                    printf("\t\tIngresar link     : ");
                    fflush(stdin);
                    gets(auxMovie.LinkDeImagen);
                    break;
            }

    }while(salir!=-1);
  }

    void guardarcambios(eMovie movie[],int idMovie, eMovie auxMovie, int tammovies){
        int salir=0;
        do{
           fflush(stdin);
            system("cls");
            printf("\t -------------------------------------------------------\n");
            printf("\t|               Modificacion  de movie                |\n");
            printf("\t -------------------------------------------------------");
            int opcion=0;
            printf("\n\n\n\t\tMovie Nro.  : %d",auxMovie.idMovie);
            printf("\n\n\t\t1- titulo     : %s",auxMovie.titulo);
            printf("\n\n\t\t2- genero     : %s",auxMovie.genero);
            printf("\n\n\t\t3- duracion   : %d",auxMovie.duracion);
            printf("\n\n\t\t4- puntaje    : %d",auxMovie.puntaje);
            printf("\n\n\t\t5- link       : %s",auxMovie.LinkDeImagen);

            printf("\n\n\n\n\t\tElija una opcion  1 Guardar cambios - 0 Salir :--> ");
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
                        strcpy((char*)&((movie+idMovie)->titulo),auxMovie.titulo);
                        strcpy((char*)&((movie+idMovie)->genero),auxMovie.genero);
                        (movie+idMovie)->duracion = auxMovie.duracion;
                        (movie+idMovie)->puntaje = auxMovie.puntaje;
                        strcpy((char*)&((movie+idMovie)->LinkDeImagen),auxMovie.LinkDeImagen);
                        (movie+idMovie)->estado = 1;
                        grabarBinario(movie, tammovies);
                    movie[idMovie].estado=1;
                    salir=-1;
                    break;
            }

    }while(salir!=-1);
  }



