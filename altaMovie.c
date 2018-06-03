    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <conio.h>
    #include "lib.h"

     void altaMovie(eMovie* movie, int tammovies, int id) {
        eMovie auxMovie;
        int min;
        int max;
        char titulo[20];
        char genero[20];
        char LinkDeImagen[160];
        int opcion=0;
        int flag=1;
        int flagTitulo=0;
        long int flagGenero=0;
        int flagDuracion=0;
        int flagPuntaje=0;
        int flagLink=0;
        int posicion;
        posicion=moviePosicionLibre(movie,tammovies);
        id=movieIdLibre(movie,tammovies);
        do{
            system("cls");
            printf("\t -------------------------------------------------------\n");
            printf("\t|                 Alta de peliculas                  |\n");
            printf("\t -------------------------------------------------------\n");
            printf("\n\n\n\n\t\tid       : %d",id);
            if (flagTitulo==0){
                printf("\n\n\t\tTitulo   :");
            }else{
                printf("\n\n\t\tTitulo   : %s",auxMovie.titulo);
            }
            if (flagGenero==0){
                printf("\n\n\t\tGenero   :");
            }else{
                printf("\n\n\t\tGenero   : %s",auxMovie.genero);
            }
           if (flagDuracion==0){
                printf("\n\n\t\tDuracion :");
            }else{
                printf("\n\n\t\tDuracion : %d",auxMovie.duracion);
            }
            if (flagPuntaje==0){
                printf("\n\n\t\tPuntaje  :");
            }else{
                printf("\n\n\t\tPuntaje  : %d",auxMovie.puntaje);
            }
            if (flagLink==0){
                printf("\n\n\t\tLink     :");
            }else{
                printf("\n\n\t\tLink     : %s",auxMovie.LinkDeImagen);
            }

            switch(flag){
                case 0:
                    printf("\n\n\t\t\tError - Debe ingresar entre %d y %d\n",0,1);
                    system("\n\n\t\tpause");
 //               case 1:
 //                   auxMovie.idMovie=ingresoDatoInt("Ingrese movie : ");
 //                   existe=movieExiste(movie, tammovies, auxMovie.idMovie);
 //                   if (existe!=-1){
 //                       printf("\n\n\t\t\tError - El movie %d ya existe\n",auxMovie.idMovie);
 //                       system("\n\n\t\tpause");
 //                    }else{
 //                       flagLegajo = 1;
 //                       flag=2;
 //                   }
 //                   break;
                case 1:
 //                   strcpy(&((auxMovie+id)->titulo),ingresoDatoChar("Ingrese nombre : ",titulo));
//                    strcpy(titulo, ingresoDatoChar("Ingrese nombre : ",titulo));
                    strcpy(auxMovie.titulo, ingresoDatoChar("Ingrese titulo : ",titulo));
                    flagTitulo = 1;
                    flag=2;
                    break;
                case 2:
                    strcpy(auxMovie.genero, ingresoDatoChar("Ingrese genero : ",genero));
                    flagGenero=1;
                    flag=3;
                    break;
                case 3:
                    min=100;
                    max=300;
                    auxMovie.duracion=ingresoNumero("Ingrese duracion : ",min ,max);
                    if (auxMovie.duracion==-1){
                        flag=3;
                    }else{
                        flagDuracion=1;
                        flag=4;
                    }
                    break;
                case 4:
                    min=1;
                    max=100;
                    auxMovie.puntaje=ingresoNumero("Ingrese puntaje : ",min,max);
                    if (auxMovie.puntaje==-1){
                        flag=4;
                    }else{
                        flagPuntaje=1;
                        flag=5;
                    }
                    break;
                case 5:
                    strcpy(auxMovie.LinkDeImagen, ingresoDatoChar("Ingrese link : ",LinkDeImagen));
                    flagLink=1;
                    flag=6;
                    break;
               case 6:
                    flag=7;
                    opcion=opcionesMenu("\n\n\t\tConfirma cambios ?    1-grabar 0-Salir :");
                    if(opcion<0 || opcion>1){
                        printf("\n\n\t\t\tError - Debe ingresar entre %d y %d\n",0,1);
                        system("pause");
                        flag=6;
                    }else if (opcion==1){
                        (movie+posicion)->idMovie = id;
                        strcpy((char*)&((movie+posicion)->titulo),auxMovie.titulo);
                        strcpy((char*)&((movie+posicion)->genero),auxMovie.genero);
                        (movie+posicion)->duracion = auxMovie.duracion;
                        (movie+posicion)->puntaje = auxMovie.puntaje;
                        strcpy((char*)&((movie+posicion)->LinkDeImagen),auxMovie.LinkDeImagen);
                        (movie+posicion)->estado = 1;
                        grabarBinario(movie, tammovies);
                        flag=7;
                        break;
                    }else{
                        flag=7;
                        break;
                    }
                }
            }while(flag!=7);
       }
