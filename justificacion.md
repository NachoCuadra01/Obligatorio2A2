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

  **Justificación:** se utiliza divide and conquer para resolver el problema recursivamente, en la cual se divide el array de puestos y, al combinar las dos mitades, se cuentan las remontadas antes de dejarlas ordenadas. Para esto se recorre la mitad izquierda y luego sobre la mitad derecha, donde se buscan todos los puestos que cumplan la condición de remontada. Como ambas mitades están ordenadas, el array de la derecha avanza una sola vez por combinación y no vuelve para atrás, es decir, j avanza solamente mientras puestos[i] > 2 * puestos[j]; como j no retrocede, cada elemento derecho se visita a lo sumo una vez.

  El array parte con los puestos originales y se divide hasta llegar a subarrays de un elemento, haciendo que quede O(log N). En cada nivel se realiza una recorrida de O(N) para contar las parejas y otra para combinar y ordenar los elementos, que hace que quede O(2N) ~ O(N). Como resultado final esto da O(NlogN) en el peor caso.

- **cantRemontadas — Orden espacial:** O(N)

  En este ejercicio se crea un array auxiliar de largo N para ir combinando las mitades y ordenando los puestos, por lo que el orden espacial queda O(N). 

## Ejercicio 8

## Ejercicio 8
- **maxSatisfaccion — Orden temporal:** O(N ⋅ W ⋅ L0 ⋅ L1 ⋅ L2 ⋅ L3) pc, siendo N la cantidad de productos y W el peso máximo.

  **Justificación:** se utiliza programación dinámica con tabulación, en la cual se crea un array que guarda el resultado para cada producto, peso y cantidad de productos de cada categoría. Cada posición dp[i][w][a][b][c][d] representa la máxima satisfacción que se puede lograr usando solo los primeros i productos, con un peso total de a lo sumo w y con a lo sumo a achuras, b cortes principales, c bebidas y d vegetales. Por más que es un único array, se accede como si fuera una tabla de seis dimensiones calculando el índice con el tamaño de cada dimensión.

  La tabla se llena de a capas, específicamente una por producto. Para cada producto se recorren todos los pesos de 0 a W y todas las cantidades de 0 a L0, L1, L2 y L3, es decir (W+1) ⋅ (L0+1) ⋅ (L1+1) ⋅ (L2+1) ⋅ (L3+1) estados. En cada estado solo hay dos opciones: no comprar el producto, copiando el valor de la capa anterior; o comprarlo (si entra en el peso y queda lugar en su categoría), sumando su satisfacción al valor de la capa anterior con el peso y el hueco de su categoría reducidos. Como solo se revisa la categoría del producto actual, cada estado se resuelve en tiempo constante.

  Al repetir esto para los N productos, el orden temporal queda O(N ⋅ W ⋅ L0 ⋅ L1 ⋅ L2 ⋅ L3) en el peor caso. Esto se ve fácilmente en el código con sus 6 for de corrido. La respuesta final se lee en la posición dp[N][W][L0][L1][L2][L3].

- **maxSatisfaccion — Orden espacial:** O(N ⋅ W ⋅ L0 ⋅ L1 ⋅ L2 ⋅ L3)

  En este ejercicio se crea un array de programación dinámica que guarda los resultados de todos los productos, pesos y cantidades posibles de cada categoría. Su tamaño es (N + 1) ⋅ (W + 1) ⋅ (L0 + 1) ⋅ (L1 + 1) ⋅ (L2 + 1) ⋅ (L3 + 1), por lo que el orden espacial queda en O(N ⋅ W ⋅ L0 ⋅ L1 ⋅ L2 ⋅ L3). Además, se crean tres arrays de largo N para guardar el peso, la satisfacción y la categoría de cada producto pero que no cambian el orden final.

## Ejercicio 9

- **maxLikes — Orden temporal:** O(K²) pc, siendo K la cantidad de rondas.

  **Justificación:** se utiliza programación dinámica con memorización, en la cual se resuelve el problema de forma recursiva con maxLikesMemo y se guarda en una tabla el resultado de cada estado ya calculado. Cada posición de memo[ronda][dif][prev] representa la máxima cantidad de likes que se pueden juntar desde la ronda actual hasta la última, siendo dif la ventaja actual del equipo A y prev si "Pato" bailó en el penal anterior o no (puede ser 0 o 1). Cabe destacar que la ventaja determina si se puede bailar sin que A pase a perder, y prev confirma si el baile da los likes completos o la mitad.

  En cada ronda, primero patea A, por lo que la ventaja pasa a ser dif + pateadores[ronda]. Luego hay dos opciones: no bailar, que no suma likes y pasa a la ronda siguiente con la misma ventaja y prev = 0; o bailar, que solo es posible si esa ventaja es al menos 1 (ya que B convierte en ese caso). Se suma likes[ronda], o (likes[ronda] / 2) (redondeado hacia abajo) si "Pato" ya había bailado en el tiro anterior, y pasa a la ronda siguiente con la ventaja reducida en 1 y prev = 1. Finalmente, se toma el máximo de ambas opciones.

  En la tanda de penales existen (K ⋅ (K+1) ⋅ 2) ~ K² estados; basados en el número de rondas, la diferencia y las prev (0/1). La memorización calcula una vez cada estado posible, y como cada cálculo revisa las opciones con operaciones constantes, el orden queda O(K²). Por otra parte, la creación de la tabla "memo" inicializa todos los posibles estados en -1 y también es O(K²), por lo que el orden temporal queda en O(K²) en el peor caso.

- **maxLikes — Orden espacial:** O(K²)

  Se crea una tabla de memorización memo[ronda][dif][prev] de la cual se usan K ⋅ (K + 1) ⋅ 2 posiciones, una por estado, lo que se simplifica en orden espacial O(K²). Además, se crean dos arrays de largo K con los resultados de cada pateador de A y los likes que genera cada tiro, pero ambos son O(K) y no alteran el orden final.

## Ejercicio 10

- A pesar de que este ejercicio no tenía restricciones de órdenes, decidimos realizar una justificación del código por su extensión.

Se implementó el método de optimización de backtracking para resolver este ejercicio. En primer lugar, como ya fue declarado, se utilizó la inteligencia artificial para ver qué parámetros necesitábamos pasarle a la función; por lo que obtuvimos, entre los que ya teníamos y los nuevos recibidos, los siguientes: 
  - string* palabras: un array que contiene a las palabras que se reciben y la palabra final como última posición
  - long long* sumados: un array del largo de la cantidad de palabras, que va a contener al valor numérico más óptimo de cada palabra. Además, su última posición es la sumatoria. 
  - long long mejorRes: el valor numérico final de la suma más óptima 
  - int cant: la cantidad de palabras recibidas más 1
  - bool* visitados: de largo 10 (del 0 al 9), va a servir para marcar como true cuando una letra tenga un valor asignado (ej: si a "B" le asignamos 3 como valor, visitados[3] = true, ninguna otra letra va a ser 3)
  - int* valor: de largo 26 (como el alfabeto), va a tener el valor final de las letras requeridas (ej: valor[1] = 3)
  - bool* noCero: también de largo 26, va a tener true a los que no pueden ser 0 por la letra del ejercicio
  - int columna: representa a la columna de cada sumando (ej: "SEND" tiene 4)
  - int fila: representa a la fila de cada sumando y la palabra final (ej: en "SEND", "MORE" y "MONEY" hay 3)
  - int suma: representa al valor que va teniendo la suma de las diferentes letras 

Como toda llamada recursiva, primero se trabaja con el caso base. Cuando estamos en la última columna, si la suma viene con un valor diferente de 0 significa que ya fue insertado sea por medio del dígito en sí o por el acarreo de las columnas previas, por lo que retorna enseguida. Sino, se crea un array de "numeros" el cual actúa como un "sumados" provisorio para ese caso. Luego se obtiene al valor de la última posición (la sumatoria), y se lo compara con mejorRes: si es mayor a mejorRes, se olvida. Si son iguales, se evalúa letra por letra; el que tenga a la menor letra primero es la mejor solución, y si resultado es estrictamente menor es mejor solución. En el caso de que "resultado" sea mejor solución, se reemplazan los valores de sumados por los de numeros, y mejorRes pasa a ser ese nuevo resultado.

Fuera del caso base, nos ponemos a revisar si estamos ante la palabra final: si no es el caso, buscamos la posición de la letra con la que queremos trabajar. Si la posición es negativa, significa que terminamos con esa palabra, por lo que se llama al backtracking pero con la fila siguiente (la próxima palabra pero en la misma columna). Sino, la letra pasa a ser (palabras[fila][pos] - 'A'); que representa a la letra que vamos a usar basados en las posiciones del abecedario. Si en el array de valor, esta posición es distinta de -1, significa que ya tiene un valor asignado, por lo que se llama a la recursiva, pero a la siguiente palabra (manteniendo la columna) y con la suma agregada al valor de esta letra. Si no es el caso, se hace la esencia del backtracking: hacer un movimiento, llamar a la recursiva para ese caso aplicado, y deshacerlo. En este caso, a la letra se le asigna todos los valores aún no marcados (y 0 si se puede), se llama a la recursiva con la siguiente palabra (también manteniendo la columna) y con suma siendo igual más este nuevo valor, y luego se deshace la acción. 

En el caso de que se trate de la palabra final, realizamos el mismo proceso para encontrar la letra correspondiente; asignamos como dígito a lo que ya venía como suma anterior (mod 10 porque puede tener acarreo), y verificamos si lleva acarreo para la siguiente columna. Luego, si el valor de la letra coincide con el dígito, significa que ya quedó guardado este valor para esa letra, por lo que se llama a la función recursiva con la siguiente columna desde el inicio de las filas y con el acarreo correspondiente. En el caso que sea un valor distinto, significa que una letra tiene 2 valores diferentes, por lo que esa solución no sirve. 
Luego está el caso de que el valor de esa letra sea -1, lo que da a entender que aún no se le asignó un valor a la letra. Entonces, si el dígito no está marcado como usado y es distinto de 0 (o si puede serlo), se vuelve a hacer otro backtracking: se le asigna ese dígito al valor de la letra y se marca al dígito como usado. Luego, se llama a la recursiva para la columna siguiente desde el primer sumando (fila 0) y con el acarreo que deba. Por último, se deshace la acción. 
