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

![Captura de pantalla 2024-04-21 174859](https://github.com/IgnaciaBrahim/Gestion-Hospitalaria-Tarea-1/assets/137849174/43f5be45-a9d1-48ec-abae-ff3af32cba3a)

Se puede observar que la hora 9 está abajo de la hora 21, incluso en prioridad igual.

### A mejorar:

1) No es un problema, pero el programa fallará si se ingresan nombres y síntomas mayores a 30 caracteres, y horas con más de 5 caracteres. También, podría compararse horas y minutos aparte para evitar el problema de anteponer 0, ya que 9 < 16.
2) Implementar una interfaz de usuario más amigable en general.
3) Permitir insertar los datos a partir de un archivo csv, ya que para grandes cantidades de pacientes es costoso registrarlos a todos.
4) Permitir la edición de los datos de los pacientes, ya que pueden haber errores en el ingreso y su eliminación es difícil.
5) Permitir eliminar pacientes de la lista sin razón.
   
## Ejemplo de uso e interacción:
Para poder interactuar con el programa, deberás apretar el botón "Run" y luego ir al apartado "Console" para poder ingresar datos:

![Captura de pantalla 2024-04-21 180426](https://github.com/IgnaciaBrahim/Gestion-Hospitalaria-Tarea-1/assets/137849174/6624cf3e-8f0e-49f3-b82a-76ad20cb9482)

`1) Registrar paciente: `

![Captura de pantalla 2024-04-21 180053](https://github.com/IgnaciaBrahim/Gestion-Hospitalaria-Tarea-1/assets/137849174/88ddd2fd-a17f-4957-bb01-78ebdfe9e843)

Se ingresa a la paciente "Ana", paciente que acaba de ingresar al hospital. Su prioridad se asigna automáticamente a baja.

`2) Asignar prioridad: `

![Captura de pantalla 2024-04-21 180120](https://github.com/IgnaciaBrahim/Gestion-Hospitalaria-Tarea-1/assets/137849174/23caaf7e-5de8-4288-844b-197f4c445d00)

A la misma paciente, Ana, se le reasigna a la prioridad "ALTO", ya que su caso era grave. Así, se asegura que la atenderán pronto.

`3) Mostrar la lista de espera: `

![Captura de pantalla 2024-04-21 180151](https://github.com/IgnaciaBrahim/Gestion-Hospitalaria-Tarea-1/assets/137849174/4a12db5c-8c93-4e1d-8c92-3440bcdd379c)

Se muestra la lista de espera, en la que por el momento solo se encuentra la paciente Ana.

`5) Mostrar pacientes por prioridad: `

Si seleccionamos la prioridad "ALTO", podremos ver que Ana se encuentra en esa prioridad.

![Captura de pantalla 2024-04-21 180246](https://github.com/IgnaciaBrahim/Gestion-Hospitalaria-Tarea-1/assets/137849174/4a5f0d2d-3256-48c8-9c0a-b688f7f0743a)

`4) Atender al siguiente paciente: `

Se visualiza la lista de espera del hospital, en donde Ana es la única paciente y está primero en la lista. Al atenderla, se elimina de la lista de pacientes.

![Captura de pantalla 2024-04-21 180307](https://github.com/IgnaciaBrahim/Gestion-Hospitalaria-Tarea-1/assets/137849174/5798b5b6-5775-4c3d-b8b5-c4a009019ab9)

`6) Salir: `

![Captura de pantalla 2024-04-21 180321](https://github.com/IgnaciaBrahim/Gestion-Hospitalaria-Tarea-1/assets/137849174/8417d4c4-a1fe-42e2-b49a-c1efa6d4bf8d)

Para salir del sistema, se selecciona la opción 6. No se podrá volver a acceder a los datos que se habían ingresado antes.





