# Justificación de órdenes — Obligatorio 2

## Ejercicio 6
- **placa — Orden temporal:** O(N) pc, siendo N la cantidad de placas.

  **Justificación:** se utilizó una estrategia greedy, en la cual se creó un array de enteros. En ese array se agregan los elementos de a pares en sus “antípodas”, ordenados de mayor a menor (ej1: hay una pareja de 15 y es el más grande en parejas, va a ir en la posición 0 y N-1). En el caso de que exista un número libre, se coloca al mayor en el centro, ya que no tiene otro par con el cual emparejarse.

  Todo esto parte de un array de Carteles, que contiene el número de placa y su cantidad. Como el rango de placas es acotado (de 0 a 1000), se crea un array de largo 1000 para almacenar los valores distintos (no altera el orden temporal porque es constante). Para tenerlos ordenados de mayor a menor, se recorre desde el final hacia el principio y se agregan los valores cuya cantidad sea mayor a cero. Así, se obtiene por un lado el tamaño del array de distintos valores y, por otro la longitud final que tendrá el array de salida, incluyendo el elemento libre si existe.

  De esta forma, el ordenamiento queda en O(N) en el peor caso, ya que la primera iteración recorre una sola vez el conjunto de placas y realiza operaciones constantes. En el peor caso se recorre hasta N/2 si la mayoría de los elementos forman pares. Además, existe la posibilidad de que todos los elementos sean distintos y no haya pares para ubicar; en ese caso, se recorre hasta N.

  Después, se revisa si hay algún libre, recorriendo el array de nuevo hasta encontrar el valor que debe ubicarse en el centro. El peor caso implica otra recorrida hasta el final, que sería no encontrar libre o encontrarlo en la última posición. Finalmente, se imprime el array final con los N elementos, que en el peor caso son todos los elementos originales.
  La suma total quedaría O(2N) ~ O(N). 
  
- **placa — Orden espacial:** O(N)

  En este ejercicio simplemente se crea un array de largo N, y se van colocando los elementos con sus pares en las "antípodas", como ya se detalló anteriormente.

## Ejercicio 7
- **cantRemontadas — Orden temporal:** O(NlogN) pc, siendo N la cantidad de corredores.

  **Justificación:** se utiliza divide and conquer para resolver el problema, en la cual se divide el array de puestos y, al combinar las dos mitades, se cuentan las remontadas antes de dejarlas ordenadas. Para esto se recorre la mitad izquierda y luego sobre la mitad derecha, donde se buscan todos los puestos que cumplan la condición de remontada. Como ambas mitades están ordenadas, el array de la derecha avanza una sola vez por combinación y no vuelve para atrás, por lo que si no se cumple la remontada en una posición de la derecha, se deja de recorrer y se pasa la siguiente posición a revisar.

  El array parte con los puestos originales y se divide hasta llegar a subarrays de un elemento, haciendo que quede O(log N). En cada nivel se realiza una recorrida de O(N) para contar las parejas y otra para combinar y ordenar los elementos, que hace que quede O(2N) ~ O(N). Como resultado final esto da O(NlogN) en el peor caso.

REVISAR

- **cantRemontadas — Orden espacial:** O(N)

  En este ejercicio se crea un array auxiliar de largo N para ir combinando las mitades y ordenando los puestos, por lo que el orden espacial queda O(N). 

## Ejercicio 8
- Sin restricciones de órdenes. / Justificación: ...

## Ejercicio 9
- Sin restricciones de órdenes. / Justificación: ...

## Ejercicio 10
- Sin restricciones de órdenes. / Justificación: ...