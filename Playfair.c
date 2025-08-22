#include <stdio.h>
#include <string.h>

void crearLlave(char matriz[5][5]){

    char llave[25];
    char alfabeto[26] = "ABCDEFGHIKLMNOPQRSTUVWXYZ";

    printf("Ingresa la llave(Solo letras mayus):\n");
    scanf("%s", llave);
    strupr(llave); // Convertir a mayúsculas
    
    for(int j = 0; j < 5; j++){
      for(int k = 0; k < 5; k++){
        matriz[j][k] = 0; // Inicializar la matriz
      }
    }
    
    int pos = 0;
    for(int i = 0; i < strlen(llave); i++){
      char letra = llave[i];
      if(letra == 'J'){
        letra = 'I'; // Reemplazar J por I
      }

      int yaEsta = 0;
      for(int j = 0; j < 5; j++){
        for(int k = 0; k < 5; k++){
          if(matriz[j][k] == letra){
            yaEsta = 1;
            break;
          }
        }
        if(yaEsta) break;
      }
      
      if(!yaEsta && pos < 25){
        matriz[pos/5][pos%5] = letra;
        pos++;
        // Marcar como usada en alfabeto
        for(int l = 0; l < strlen(alfabeto); l++){
          if(alfabeto[l] == letra){
            alfabeto[l] = '0'; 
            break;
          }
        }
      }
    }

    // Llenar el resto con alfabeto
    for(int k = 0; k < strlen(alfabeto) && pos < 25; k++){ 
      if(alfabeto[k] != '0'){
        matriz[pos/5][pos%5] = alfabeto[k];
        pos++;
      }
    }

    printf("Matriz llave generada:\n");
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }
}

void mensajeCifrado(){

    char matriz[5][5];
    crearLlave(matriz);

    printf("Ingresa el mensaje a cifrar:\n");
    char mensaje[100];
    scanf(" %[^\n]", mensaje);
    printf("Mensaje original: %s\n", mensaje);
    
    // Convertir a mayúsculas manualmente
    for(int i = 0; i < strlen(mensaje); i++){
        if(mensaje[i] >= 'a' && mensaje[i] <= 'z'){
            mensaje[i] = mensaje[i] - 'a' + 'A';
        }
    }
    
    char mensajeLimpio[200];
    int indice = 0;
    for(int i = 0; i < strlen(mensaje); i++){
      if(mensaje[i] != ' '){
        if(mensaje[i] == 'J'){
          mensajeLimpio[indice] = 'I';
        } else {
          mensajeLimpio[indice] = mensaje[i];
        }
        indice++;
      }
    }
    mensajeLimpio[indice] = '\0';
    printf("Mensaje limpio: %s\n", mensajeLimpio);
    
    char pares[200];
    int indicePares = 0;
    for(int i = 0; i < strlen(mensajeLimpio); i++){
      pares[indicePares++] = mensajeLimpio[i];
      if(i + 1 < strlen(mensajeLimpio)){
        if(mensajeLimpio[i] == mensajeLimpio[i + 1]){
          pares[indicePares++] = 'X';
        } else {
          pares[indicePares++] = mensajeLimpio[++i];
        }
      }
    }
    if(indicePares % 2 != 0){
        pares[indicePares++] = 'X'; // Añadir X si es impar
    }
    pares[indicePares] = '\0';

    char textoCifrado[200] = "";

    for(int i = 0; i < strlen(pares); i += 2){
        char letra1 = pares[i];
        char letra2 = pares[i + 1];
        
        // Encontrar posiciones en la matriz
        int fila1, col1, fila2, col2;
        for(int f = 0; f < 5; f++){
            for(int c = 0; c < 5; c++){
                if(matriz[f][c] == letra1){
                    fila1 = f;
                    col1 = c;
                }
                if(matriz[f][c] == letra2){
                    fila2 = f;
                    col2 = c;
                }
            }
        }
        
        char cifrada1, cifrada2;
        
        // Misma fila
        if(fila1 == fila2){
            cifrada1 = matriz[fila1][(col1 + 1) % 5];
            cifrada2 = matriz[fila2][(col2 + 1) % 5];
        }
        // Misma columna
        else if(col1 == col2){
            cifrada1 = matriz[(fila1 + 1) % 5][col1];
            cifrada2 = matriz[(fila2 + 1) % 5][col2];
        }
        // Diferentes fila y columna 
        else{
            cifrada1 = matriz[fila2][col1];
            cifrada2 = matriz[fila1][col2];
        }
        
        // Añadir al texto cifrado
        int len = strlen(textoCifrado);
        textoCifrado[len] = cifrada1;
        textoCifrado[len + 1] = cifrada2;
        textoCifrado[len + 2] = '\0';
    }
    
    printf("Texto cifrado: %s\n", textoCifrado);
}

void mensajeDescifrado(){
  
    char matriz[5][5];
    crearLlave(matriz);

    printf("Ingresa el mensaje a descifrar:\n");
    char mensaje[100];
    scanf(" %[^\n]", mensaje);
    printf("Mensaje original: %s\n", mensaje);
    
    // Convertir a mayúsculas manualmente
    for(int i = 0; i < strlen(mensaje); i++){
        if(mensaje[i] >= 'a' && mensaje[i] <= 'z'){
            mensaje[i] = mensaje[i] - 'a' + 'A';
        }
    }
    
    char pares[200];
    int indicePares = 0;
    for(int i = 0; i < strlen(mensaje); i++){
      if(mensaje[i] != ' '){
        pares[indicePares++] = mensaje[i];
      }
    }
    pares[indicePares] = '\0';

    char textoDescifrado[200] = "";

    for(int i = 0; i < strlen(pares); i += 2){
        char letra1 = pares[i];
        char letra2 = pares[i + 1];
        
        // Encontrar posiciones en la matriz
        int fila1, col1, fila2, col2;
        for(int f = 0; f < 5; f++){
            for(int c = 0; c < 5; c++){
                if(matriz[f][c] == letra1){
                    fila1 = f;
                    col1 = c;
                }
                if(matriz[f][c] == letra2){
                    fila2 = f;
                    col2 = c;
                }
            }
        }
        
        char descifrada1, descifrada2;
        
        // Misma fila
        if(fila1 == fila2){
            descifrada1 = matriz[fila1][(col1 + 4) % 5];
            descifrada2 = matriz[fila2][(col2 + 4) % 5];
        }
        // Misma columna
        else if(col1 == col2){
            descifrada1 = matriz[(fila1 + 4) % 5][col1];
            descifrada2 = matriz[(fila2 + 4) % 5][col2];
        }
        // Diferentes fila y columna 
        else{
            descifrada1 = matriz[fila2][col1];
            descifrada2 = matriz[fila1][col2];
        }

        // Añadir al texto descifrado
        int len = strlen(textoDescifrado);
        textoDescifrado[len] = descifrada1;
        textoDescifrado[len + 1] = descifrada2;
        textoDescifrado[len + 2] = '\0';
    }

    printf("Texto descifrado: %s\n", textoDescifrado);
}

int main()
{
    int opcion;
    
    do {
        printf("\n=== CIFRADO PLAYFAIR ===\n");
        printf("1. Cifrar mensaje\n");
        printf("2. Descifrar mensaje\n");
        printf("3. Salir\n");
        printf("Selecciona una opcion: ");
        scanf("%d", &opcion);
        
        switch(opcion){
            case 1:
                mensajeCifrado();
                break;
            case 2:
                mensajeDescifrado();
                break;
            case 3:
                printf("Hasta luego\n");
                break;
            default:
                printf("Opcion invalida.\n");
        }
    } while(opcion != 3);
    
    return 0;
}