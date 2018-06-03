    #include <stdio.h>
    #include <stdlib.h>
    #include "lib.h"
    #include "listadoMovie.h"
    #include "altaMovie.h"
    #include "bajaMovie.h"
    #include "modificarmovie.h"

    int menu(eMovie* movie, int tammovies) {
        int opcion;
        int id;
        do{
            int min=1;
            int max=5;
            system("cls");
            printf("\t --------------------------------------------------------------\n");
            printf("\t|              Sistema de Peliculas - version 1.0.0            |\n");
            printf("\t --------------------------------------------------------------");
            printf("\n\n\n\t\t\t1- Alta pelicula");
            printf("\n\n\t\t\t2- Baja de pelicula");
            printf("\n\n\t\t\t3- Modificacion de pelicula");
            printf("\n\n\t\t\t4- Generar pagina web");
            printf("\n\n\t\t\t5- Salir");
            opcion=opcionesMenu("Ingrese una opcion ==> ");
            if (opcion< min || opcion>max){
                printf("\n\n\t\t\tError - Debe ingresar entre %d y %d", min, max);
                system("pause");
            }
            switch( opcion ) {
                case  1 :
                    cargarBinario(movie, tammovies);
                    contareBinario(movie, tammovies);
                    id=moviePosicionLibre(movie,tammovies);
                    if(id!=-1){
                        altaMovie(movie, tammovies, id);
                    }else{
                        printf("\n\tERROR - No hay mas espacio para agregar movie\n");
                        system("pause");
                    }
                    break;
                case 2 :
                    cargarBinario(movie, tammovies);
                    bajaMovie(movie, tammovies);
                    opcion=1;
                   break;
                case 3 :
                    cargarBinario(movie, tammovies);
                    modificarMovie(movie, tammovies);
                    opcion=1;
                    break;
                case 4 :
                  eMovieVacio(movie, tammovies);
                  cargarBinario(movie, tammovies);
                  listadoMovie(movie, tammovies);
                   opcion=-1;
                   break;
                case 5 :
                    exit(-1);
                    break;
            }
        } while( opcion!=0 );
        return 0;
    }
