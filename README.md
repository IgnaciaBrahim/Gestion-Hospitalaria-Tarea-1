# Sistema de gestión hospitalaria: lista de espera de pacientes

## Descripción:
Este sistema permite a los usuarios gestionar la atención de pacientes en un hospital. Los usuarios pueden registrar nuevos pacientes, asignar prioridades, ver la lista de espera, y más. Esta herramienta está diseñada para mejorar la eficiencia en la atención de los pacientes, asegurando que aquellos en situaciones críticas reciban atención lo más pronto posible.

## Instalación, compilación y ejecución:
### Por GitHub:
Dado que el sistema está diseñado para ser accesible y fácil de probar, recomendamos usar Repl.it para una rápida configuración y ejecución. Sigue estos pasos para comenzar:
1. Ingresa a [replit](https://repl.it/)
2. Inicia sesión, o crea una cuenta si es que no tienes.
3. Una vez en tu página principal, selecciona "New Repl" y elige "Import from GitHub".
4. Pega la URL del repositorio: [https://github.com/username/sistema-gestion-pacientes.git.](https://github.com/IgnaciaBrahim/Gestion-Hospitalaria-Tarea-1.git)
5. Replit clonará el repositorio y preparará un entorno de ejecución.
6. Presiona el botón "Run" para compilar y ejecutar el código. 

### Por Replit:
Si no deseas clonar el repositorio;
1. Inicia sesión a tu cuenta de Replit, o crea una cuenta si no la tienes.
2. Luego ingresa a [https://replit.com/@IgnaciaLBrahim/tarea-1-gestion-hospitalaria](https://replit.com/@IgnaciaLBrahim/tarea-1-gestion-hospitalaria).
3. Selecciona la opción "Fork".
4. Esto creará una copia del proyecto en tu cuenta, por lo que podrás correrla y editarla si deseas, sin modificar el proyecto original.
5. Puedes compilar y correr el proyecto con "Run".

## Funcionalidades

### Funcionando correctamente:
En el programa podrás encontrar un menú con las siguientes funcionalidades:  

`1) Registrar paciente: ` Registra un paciente y lo agrega a la lista de espera. Debes incluir su nombre, edad, síntoma y hora de llegada en formato 24hr hh:mm. La prioridad de los pacientes cuando se agregan es "BAJA" por defecto, por lo que no deberás indicarla.

`2) Asignar prioridad: `  A través del nombre del paciente, lo busca en la lista de espera y cambia su prioridad. Si no hay pacientes en la lista de espera, se emite un aviso, y si es que la prioridad que ingresaste era la misma que el paciente tenía, se comunica que la prioridad no cambió. De cualquier otra forma, se muestra el paciente y la prioridad a la que fue cambiado/a.

`3) Mostrar la lista de espera: ` Muestra la lista de espera del hospital en orden, teniendo en cuenta que los primeros pacientes son los que tienen prioridad más alta, y luego se encuentran ordenados por hora.

`4) Atender al siguiente paciente: ` Muestra la lista de espera para que observes al primer paciente. Si es que quieres atenderlo, deberás especificar en la consola que deseas hacerlo y escribir "s", o escribir "n" en caso contrario. Si es que decides atenderlo, se muestran los datos del paciente atendido. Si es que no hay pacientes en la lista, se emitirá un aviso.

`5) Mostrar pacientes por prioridad: ` Se pide el ingreso de la prioridad que se quiere visualizar de la lista de espera a través de un menú, y luego se muestran los pacientes que corresponden a esa prioridad. Si no hay pacientes en espera, se muestra un aviso, y se muestra también si no habían pacientes de la prioridad ingresada.

`6) Salir: ` Se da la opción de salir del sistema de gestión de lista de espera del hospital. Si se sale, no se podrá volver a acceder a la lista que se haya creado anteriormente.

### Problemas conocidos:
El único problema conocido, es que si no se ingresa la hora en el formato especificado, no se asegura que se ordenen por prioridad y luego por hora los pacientes (ordenamiento esperado en una lista de espera). Esto se debe que al ordenar, en cuanto a la hora se utiliza la función strcmp de la librería string.h de C. Si es que se ingresa por ejemplo la hora 9:15, esta hora será mayor a la hora 16:15, ya que primero compara el 9 con el 1, y retornará que el 9 es mayor. El problema se resuelve al anteponer el 0 a las horas antes de las 10 AM, ya que se comparará 0 con 1, y el 1 será mayor.

`Ejemplo: `


### A mejorar:

## Ejemplo de uso e interacción:
?? fotos



