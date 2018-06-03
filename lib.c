    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "lib.h"
    #include "altaMovie.h"

    int binarioVacio(){
        int registros;
        FILE *archivo;
        archivo=fopen("peliculas.dat", "rb"); //abro modo lectura
        if(archivo==NULL){
            printf("\n\tERROR - No archivo peliculas.dat no existe\n");
            system("pause");
      //      archivo= fopen("peliculas.dat", "wb"); // creo un archivo nuevo
        }
        fread(&registros, sizeof(int), 1, archivo);
        printf("\n\tERROR - %d\n",registros);
        system("pause");
        fclose(archivo);
        return registros;
    }

    void cargarBinario(eMovie* movie, int tammovie){
        int registros;
        inicializarEmovie(movie, tammovie);
        registros=contareBinario(movie, tammovie);
        FILE* archivo;
        archivo=fopen("peliculas.dat", "rb");
        if(archivo==NULL){
            HardCodeMovie(movie, tammovie);
            archivo=fopen("peliculas.dat", "rb");
            if(archivo==NULL){
                printf("\n\tERROR - Archivo peliculas.dat no se puede cargar\n");
            }
        }
        fread(movie, sizeof(eMovie), registros, archivo);
        fclose(archivo);
    }

    int contareBinario(eMovie* movies, int tammovie){
        eMovie letra;
        int leidos=0;
        FILE* archivo;
        archivo = fopen("peliculas.dat","rb");
        if(archivo==NULL){
            printf("error, no se puede abrir fichero");
        }else{
             while(!feof(archivo)&&letra.estado!=0){
                fread(&letra, sizeof(letra), 1, archivo);
                if(feof(archivo)){break;};
                leidos+=1;
            }
        }
        return leidos;
     }

    int contareMovie(eMovie* movies, int tammovie){
        int i;
        int cantMovie;
        for(i=0; i<tammovie; i++){
            cantMovie+=1;
        }
        return cantMovie;
     }

    int eMovieVacio(eMovie* movie, int tammovies){
        int vacio = 0;
        int i;
        if(movie != NULL){
            for(i=0 ; i<tammovies ; i++){
            if((movie+i)->estado == 1){
                vacio = 1;
                break;
            }
        }
    }
    return vacio;
}

    void inicializarEmovie(eMovie* movie, int tammovies){
        for(int i = 0; i<tammovies ; i++){
            (movie+i)->idMovie = 0;
            (movie+i)->estado = 0;
        }
   }
    void HardCodeMovie(eMovie* movie, int tammovies){
        int id[6] = {1,4,6,2,5,3};
        char titulo[6][25] = {"Back to the future","The Secret Life of Pets","Assassins Creed","maria cuire","Mind and Machine","The Land of Stealth"};
        char genero[6][16] = {"Aventura","Animacion","Accion","Biografica","Ciencia ficcion","Romance"};
        int duracion[6] = {116,89,120,100,130,116};
        int puntaje[6] = {86,87,92,88,75,68};
        char LinkDeImagen[6][160] = {"http://image.tmdb.org/t/p/w185/xS3k4YTyt5DdaLmbDGxdioi2v3w.jpg","http://image.tmdb.org/t/p/w185/q2icKmDXoj8FSc2IZU3sOIB2EAG.jpg","thumbnails//AssassinsCreed.jpg","http://image.tmdb.org/t/p/w185/7WsyChQLEftFiDOVTGkv3hFpyyt.jpg","thumbnails//Mind-and-Machine.jpg","thumbnails//TheLandofStealth.jpg"};
        char sinopsis[6][700] = {{"Marty McFly es un adolescente amigo de Doc, un científico a los que todos menos él toman por chiflado. Cuando Doc crea una máquina para viajar en el tiempo en forma de un automóvil deportivo, Marty viaja accidentalmente al año 1955. Allí se encontrará con sus padres cuando eran jóvenes, pero impide su primer encuentro. A partir de entonces, y con el tiempo en su contra, McFly deberá conseguir que se enamoren para que se casen y él no deje de existir."},
                                  {"En un apartamento de Manhattan,las mascotas se reúnen tras la marcha de sus dueños para contar humillantes historias sobre ellos. Su líder un Fox Terrier que ve amenazada su posición de privilegio por la llegada de un perro mestizo.Su rivalidad les llevará a acabar en las duras calles de Nueva York,donde se encontrarán con un aparentemente adorable conejo que en realidad es el líder de un ejército de mascotas abandonadas que ha jurado venganza."},
                                  {"Gracias a una tecnología revolucionaria que permite el acceso a los recuerdos genéticos, Callum Lynch (Michael Fassbender) revive las aventuras de Aguilar, un antepasado suyo que vivió en la España del siglo XV. Así descubre que es descendiente de una misteriosa organización secreta, los Asesinos, y que posee las habilidades y los conocimientos necesarios para enfrentarse a la poderosa y temible organización de los Templarios en la época actual."},
                                  {"Al poco tiempo de que la pareja Curie fuera recompensada con el premio Nobel de Física, Pierre muere en un trágico accidente. Sola con dos niños, la treintañera Marie se aferra a sus estudios científicos en un mundo dominado por los hombres y se convierte en la primera mujer en recibir una cátedra en la Sorbona de París. Cuando se enamora de un científico casado e inicia una aventura con él, la mujer de éste, celosa, hace pública su relación al mismo tiempo que se anuncia su premio Nobel de Química. En lugar de disfrutar de la fama que se ha ganado por su portentoso trabajo de investigación, Marie se ve difamada por cometer adulterio."},
                                  {"Situada en el futuro cercano donde los robots humanoides son comunes en la sociedad, la mafia reprograma a una mujer androide para pensar y sentir con el fin de usarla como asesino a sueldo. Esto tiene consecuencias peligrosas a medida que desarrolla una relación con su creador a la vez que se convierte lentamente en una psicópata asesina."},
                                  {"Shinobi no Kuni nos presenta a Mumon (Satoshi Ono) un personaje que a pesar de ser muy perezoso es también el mejor shinobi de la provincia de Iga. Un día, él mata a un shinobi de una familia diferente para una recompensa. Mumon no sabe que sus acciones conducirán a una batalla mortal entre el cuerpo del shinobi de la provincia de Iga y el cuerpo de Nobukatsu Oda en Ise."}
                                  };
        inicializarEmovie(movie, tammovies);
 //       for(int i = 0; i<tammovies ; i++){
 //           (movie+i)->idMovie = 0;
 //           (movie+i)->estado = 0;
 //       }
        for(int i = 0; i<6 ; i++){
            (movie+i)->idMovie = id[i];
            strcpy((char*)&((movie+i)->titulo),titulo[i]);
            strcpy((char*)&((movie+i)->genero),genero[i]);
            (movie+i)->duracion = duracion[i];
            (movie+i)->puntaje = puntaje[i];
            strcpy((char*)&((movie+i)->LinkDeImagen),LinkDeImagen[i]);
            strcpy((char*)&((movie+i)->sinopsis),sinopsis[i]);
            (movie+i)->estado = 1;
        }

        grabarBinario(movie, tammovies);
        FILE* miArchivo;
        miArchivo = fopen("peliculas.dat","rb");
        fread(movie, sizeof(eMovie), 6, miArchivo);
        for(int i=0; i<6; i++){
            printf("hardcordeo - - - %d--%s\n", movie[i].idMovie, movie[i].titulo);
        }
        system("pause");
    }

    void grabarBinario(eMovie* movie, int tammovies){
        int i;
 //       int registros = 0;
        ordenarMovieId(movie, tammovies);
        FILE* archivo;
        archivo = fopen("peliculas.dat", "wb");
        if(archivo == NULL){
            printf("\n\tERROR - No archivo peliculas.dat no existe\n");
            system("pause");
        }else{
//            for(i=0 ; i<tammovie ; i++){
//                if((movie+i)->estado == 1){
//                    registros++;
//                }
//            }
            for(i=0; i<tammovies ; i++){
                if((movie+i)->estado == 1){
                    fwrite((movie+i), sizeof(eMovie), 1, archivo);
                }
            }
            fclose(archivo);
        }
    }

    int guardarArchivo(eMovie* movie){
        FILE *archivo;
        archivo=fopen("peliculas.dat","wb");
        if(archivo == NULL){
            printf("\n\tERROR - No archivo eMovie.bin no existe\n");
            system("pause");
        }
        fwrite(movie,sizeof(movie),1,archivo);
        fclose(archivo);
        return 0;
    }

    void *ingresoDatoChar(char *txt, char *nombre){
        printf("\n\n\n\n\n\t\t%s ",txt);
        fflush(stdin);
        gets(nombre);
        return nombre;
    }

     int ingresoDatoInt(char txt[]){
        int dato;
        printf("\n\n\n\n\n\t\t%s ",txt);
        scanf("%d", &dato);
        return dato;
    }
    int ingresoNumero(char txt[], int min, int max){
        char sNum[20];
        int dato;
        printf("\n\n\t\t%s ",txt);
        scanf("%s",sNum);
        dato=atoi(sNum); /* atoi convierte el numero ingresado como cadena en entero
        en caso de ser posible, de lo contrario retorna 0*/
        if(dato!=0 ){
            printf("El numero es: %d\n",dato);
            if (dato==2 || dato>max){
                printf("\n\n\t\t\tError - Debe ingresar entre %d y %d\n",min,max);
                system("\n\n\t\tpause");
                dato=-1;
            }
        }else{
            printf("ERROR -Debe ingresar un numero\n");
            system("pause");
            dato=-1;
        }
        return dato;
   }

    void mostrarListaMovie(eMovie* movie, int tammovie) {
        int i;
        printf("\t\tid        titulo                genero\n");
        for(i=0; i<tammovie; i++){
            if((movie+i)->estado == 1){
                    printf("\n\t\t%-5d %-25s %-15s  ", (movie+i)->idMovie, (movie+i)->titulo, (movie+i)->genero);
            }
        }
    }

     int movieExiste(eMovie movie[], int tammovie, int id){
        int existe = -1;
        int i;
        for(i=0; i<tammovie; i++){
            printf("\n\tERROR %d\n",i);
            system("pause");
             if (movie[i].idMovie == id){
                existe = i;
                break;
            }
        }
        return existe;
    }

    int moviePosicionLibre(eMovie* movie, int tammovie){
        int posicion = -1;
        int i;
        for(i=0; i<tammovie; i++){
 //           printf("xxxx1--%d--%s\n", movie[i].idMovie, (movie+i)->titulo);
 //           system("pause");
            if ((movie+i)->estado == 0){
                 posicion = i;
            break;
            }
        }
        return posicion;
    }
    int movieIdLibre(eMovie* movie, int tammovie){
        int id;
        int i;
        for(i=0; i<tammovie; i++){
 //           printf("xxxx1--%d--%s\n", movie[i].idMovie, (movie+i)->titulo);
 //           system("pause");
            if ((movie+i)->estado == 1){
                 id= movie[i].idMovie+1;
            }
        }
        return id;
    }

    int leerPeliculas(eMovie *movie,int tammovie){
        int i;
        int leidos=0;
        eMovie letra;
        FILE* archivo;
        archivo = fopen("peliculas.dat","rb");
        if(archivo==NULL){
            printf("error, no se puede abrir fichero");
        }else{
            fread(&letra, sizeof(letra), 1, archivo);
//            while(!feof(archivo)&&letra.estado!=0){
                for (i=0;i<tammovie;i++){
                leidos+=1;
                printf("%d----%d---%d---%s--\n",leidos,letra.idMovie, letra.estado, letra.titulo);
                fread(&letra, sizeof(letra), 1, archivo);
 //           }
        }
        printf("%d---",leidos);
        system ("pause");
        fread(movie, sizeof(eMovie), 1, archivo);
        fclose(archivo);
      }
	return leidos;
}

    void ordenarMovieId(eMovie* movie, int tammovies){
    int i;
    int j;
    eMovie aux;
    for(i=0 ; i<tammovies-1 ; i++){
        for(j=i+1 ; j<tammovies ; j++){
            if((movie+i)->idMovie > (movie+j)->idMovie){
                aux = *(movie+i);
                *(movie+i) = *(movie+j);
                *(movie+j) = aux;
            }
        }
    }
}

    int opcionesMenu(char txt[]){
        int dato;
        printf("\n\n\n\t\t%s ",txt);
        scanf("%d", &dato);
        return dato;
    }


