#include "tdas/list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//El código correrá y compilará con el botón "Run"

//estructura del dato "paciente"
typedef struct {
  char nombre[31];
  int edad;
  char sintoma[31];
  char hora[6];
  int prioridad;
} tipo_paciente;


//la función se usa para comparar elementos de los datos en List sorted insert, si devuelve falso es porque me estaría "pasando" si avanzo a la siguiente posición para insertar el elemento
int lower_than(void *m_pac, void *c_pac)
{
  tipo_paciente *m_paciente = (tipo_paciente *)m_pac;
  tipo_paciente *c_paciente = (tipo_paciente *)c_pac;
  if(m_paciente->prioridad < c_paciente->prioridad)
  {
    return 1;
  }
  else if (m_paciente->prioridad == c_paciente->prioridad)
  {
    if(strcmp(m_paciente->hora, c_paciente->hora) < 0)
    {
      return 1;
    }
  }
  return 0;
}

//imprimir un paciente de la lista. No solo se imprimen pacientes si es que se está mostrando lista, si no que al mostrar por prioridad también, por lo que me permite reutilizar código.
void imprimir_paciente(List *lista, tipo_paciente *dato, int contador)
{
  printf("\nPaciente numero %d en lista: \n\n", contador);
  printf("Nombre del paciente: %s\n", dato->nombre);
  printf("Edad: %d\n", dato->edad);
  printf("Sintoma: %s\n", dato->sintoma);
  printf("Hora de llegada: %s\n", dato->hora);
  printf("Prioridad : ");
  if (dato->prioridad == 1)
  {
    printf("ALTA\n");
  }
  else if (dato->prioridad == 2)
  {
    printf("MEDIA\n");
  }
  else
  {
    printf("BAJA\n");
  }
}

//Verifica que un paciente esté en la lista en base a su nombre.
int esta_en_lista(List *L, char *nombre)
{
  tipo_paciente *dato = list_first(L);
  if (dato == NULL)
  {
    return 0;
  }
  while(dato != NULL)
  {
    if (strcmp(dato->nombre, nombre) == 0)
    {
      return 1;
    }
    dato = list_next(L);
  }
  return -1;
}

//Reasignar prioridad toma el nombre de un paciente, si 
void reasignar_prioridad(List *lista, char *nombre, int prioridad)
{
  tipo_paciente *dato = list_first(lista);
  //buscamos al paciente en la lista, si la prioridad sigue siendo igual no lo vamos a mover.

  //recorrido
    while(dato != NULL)
    {
      if (strcmp(dato->nombre, nombre) == 0)
      {
        if  (dato->prioridad == prioridad)
        {
          printf("La prioridad no ha cambiado\n");
          return;
        }
        else
        {
          //necesito sacarlo, si no cuando lo reinserte habrán dos "Marcelos"??
          list_popCurrent(lista);
          break;
        }
      }
      dato = list_next(lista);
    }
  //termino el recorrido.
  //ahora tengo que cambiar la prioridad.
  dato->prioridad = prioridad;
  //ahora debo insertar de nuevo :)
  list_sortedInsert(lista, dato, lower_than);
  printf("El paciente %s ha sido reasignado a la prioridad %d\n", dato->nombre, dato->prioridad);
}

//Función que maneja la función "reasignar_prioridad". Maneja los casos de error (no hay existencia y lista vacía). Crea un menú para ingresar prioridad y generar menos error del usuario.
void asignar_prioridad(List *lista, char *nombre)
{
  char nueva_prior;
  int esta = esta_en_lista(lista, nombre);
  if (esta == 0)
  {
    printf("No hay pacientes en la lista\n");
  }
  else if (esta == -1)
  {
    printf("El paciente no se encuentra en la lista de espera\n");
  }
  else
  {
    printf("Seleccione la nueva prioridad: \n");
      puts("1) ALTA\n");
      puts("2) MEDIA\n");
      puts("3) BAJA\n");
      scanf(" %c", &nueva_prior); 

      switch (nueva_prior) {
      case '1':
        reasignar_prioridad(lista, nombre, 1);
        break;
      case '2':
        reasignar_prioridad(lista, nombre, 2);
        break;
      case '3':
        reasignar_prioridad(lista, nombre, 3);
        break;
      default:
        puts("Opción inválida. Vuelva a seleccionar una prioridad.\n");
      }
    //termino la reasignacion
  }
}

//Aquí se leen los datos de la funcionalidad del programa "Registrar paciente". Se lee su nombre, edad, síntoma y hora de ingreso. La hora está restringida a ser un string de 5 carácteres que debe ser la hora con : en formato 24hr hh:mm, ya que en la función comparar habrían problemas comparando 9:15 con 16:15, no así con 09:15.
void lectura_lista(tipo_paciente *paciente)
{
  printf("Ingrese el nombre del paciente: \n");
  scanf(" %30[^\n]", paciente->nombre);
  printf("Ingrese la edad del paciente : \n");
  scanf("%d", &paciente->edad);
  printf("Ingrese el síntoma del paciente: \n");
  scanf(" %30[^\n]", paciente->sintoma);
  printf("Ingrese la hora de llegada del paciente: (formato hh:mm 24hr) \n");
  scanf(" %5[^\n]", paciente->hora);
  paciente->prioridad = 3; // La prioridad por defecto es 3 "baja".
}

// Función para limpiar la pantalla
void limpiarPantalla() { system("clear"); }

void presioneTeclaParaContinuar() {
  puts("Presione una tecla para continuar...");
  getchar(); // Consume el '\n' del buffer de entrada
  getchar(); // Espera a que el usuario presione una tecla
}

// Menú principal, se listan las opciones que puede hacer el usuario.
void mostrarMenuPrincipal() {
  limpiarPantalla();
  puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
  puts("     Sistema de Gestión Hospitalaria");
  puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
  printf("\nSeleccione una opción del menú:\n");

  puts("1) Registrar paciente");
  puts("2) Asignar prioridad a paciente");
  puts("3) Mostrar lista de espera");
  puts("4) Atender al siguiente paciente");
  puts("5) Mostrar pacientes por prioridad");
  puts("6) Salir");
}

//Se reserva memoria para registrar los datos del nuevo paciente, para posteriormente leerlos e insertarlo en la lista. Si está vacía, se inserta al final, de cualquier otra forma se inserta en orden.
void registrar_paciente(List *lista_pacientes) 
{
  //Creo dato y se reserva memoria
  tipo_paciente *paciente = (tipo_paciente *) malloc(sizeof(tipo_paciente));

  printf("Registrar nuevo paciente\n");
  //Función de leer datos
  lectura_lista(paciente);

  //Agrego el paciente a la lista
  tipo_paciente *dato = list_first(lista_pacientes);
  if (dato == NULL)
  {
    list_pushBack(lista_pacientes, paciente);
  }
  else
  {
    list_sortedInsert(lista_pacientes, paciente, lower_than);
  }
//Se decide la forma de agregar.
}

//Se muestra toda la lista de pacientes que no se han atendido aún. Si es que no hay pacientes, se emite un aviso.
void mostrar_lista_pacientes(List *lista_pacientes) 
{
  printf("Pacientes en espera: \n");
  tipo_paciente *dato = list_first(lista_pacientes);
  if (dato == NULL)
  {
    printf("AVISO: No hay pacientes en espera\n");
  }
  else
  {
    int contador = 1;
    while(dato != NULL)
      {
//reutilizando 
imprimir_paciente(lista_pacientes, dato, contador);
        contador+=1;
        dato = list_next(lista_pacientes);
      }
  }
}

//Si es que no hay elementos en la lista, se emite un aviso. Se muestra la lista para facilitar el saber a quién se atendería en el caso que el usuario así lo desee. Si es que no quiere, se le comunica que no se atendió a nadie. Si es que sí quería, se elimina al primer paciente de la lista y se muestra su nombre.
void atender_paciente(List *lista)
{
  char opcion;
  tipo_paciente *dato;
  tipo_paciente *first = list_first(lista);
  if (first == NULL)
  {
    printf("AVISO: No hay pacientes en lista de espera\n");
    return;
  }
  mostrar_lista_pacientes(lista);
  printf("\n¿Esta seguro/a de que quiere atender al siguiente paciente en lista de espera? (s/n)\n");
  scanf(" %c", &opcion);
  switch(opcion)
  {  
    case 'n':
      printf("No se atenderá al siguiente paciente\n");
      break;
    
    case 's':
      dato = list_popFront(lista);
      printf("El paciente %s ha sido atendido\n", dato->nombre);
      free(dato);
      break;
    default:
      printf("Opción inválida. Vuelva a seleccionar una opción.\n");
  }
}

//Se muestra la lista de pacientes en la prioridad que seleccione el usuario. Si está vacía la lista, se emite el aviso. Luego se muestra la prioridad, y se muestran los pacientes que corresponden a ella. Si es que habían pacientes en lista pero ninguno cumplía, se muestra que no habían de esa prioridad.
void mostrar_prioridad(List *lista, int prioridad)
{
  tipo_paciente *dato = list_first(lista);
  char prior[6];
  
  if (prioridad == 1)
  {
    strcpy(prior, "ALTA");
  }
  else if (prioridad == 2)
  {
    strcpy(prior, "MEDIA");
  }
  else
  {
    strcpy(prior, "BAJA");
  }

  int contador = 1;
  printf("Mostrando los pacientes de prioridad ""%s""\n", prior);
  while (dato != NULL)
  {  
    if (dato->prioridad == prioridad)
    {
      imprimir_paciente(lista, dato, contador);
      contador+=1;
    }
    dato = list_next(lista);
  }
  if (contador == 1)
  {
    printf("No hay pacientes con prioridad %s\n", prior);
  }
  return;
}

//Función que controla la función mostrar_prioridad. Se le pide al usuario que seleccione la prioridad que quiera ver de los pacientes en espera. Según la respuesta, llama a la otra función. 
void mostrar_lista_prioridad(List *lista)
{
  tipo_paciente *dato = list_first(lista);
  if (dato == NULL)
  {
    printf("AVISO: No hay pacientes en espera\n");
    return;
  }

  char opcion;
  printf("Seleccione la prioridad que desee visualizar: \n");
  puts("1) ALTA\n");
  puts("2) MEDIA\n");
  puts("3) BAJA\n");
  scanf( " %c", &opcion);

  switch (opcion)
  {
    case '1':
      mostrar_prioridad(lista, 1);
      break;

    case '2':
      mostrar_prioridad(lista, 2);
      break;

    case '3':
      mostrar_prioridad(lista, 3);
      break;

    default:
      printf("Opción inválida. Por favor, vuelve a seleccionar una prioridad.\n");
  }
}

//===================MAIN===================
int main() {
  char opcion;
  List *lista_pacientes = list_create(); 
  char nombre[31];

  do {
    mostrarMenuPrincipal();
    printf("Ingrese su opción: ");
    scanf(" %c", &opcion); 

    switch (opcion) {
    case '1':
      registrar_paciente(lista_pacientes);
      break;
    case '2':
      printf("Ingrese el nombre del paciente al que desea cambiar su prioridad  : \n");
      scanf(" %30[^\n]", nombre);
      asignar_prioridad(lista_pacientes, nombre);
      break;

    case '3':
      mostrar_lista_pacientes(lista_pacientes);
      break;

    case '4':
      atender_paciente(lista_pacientes);
      break;

    case '5':
      mostrar_lista_prioridad(lista_pacientes); 
      break;

    case '6':
      puts("Saliendo del sistema de gestión hospitalaria...");
      break;

    default:
      puts("Opción no válida. Por favor, intente de nuevo.");
    }
    presioneTeclaParaContinuar();

  } while (opcion != '6');

  // Liberar recursos, si es necesario
  list_clean(lista_pacientes);
  return 0;
}