# Proyecto Push Swap

## Descripción
Push Swap es un proyecto del programa 42 que consiste en ordenar una pila de números utilizando dos pilas (`A` y `B`) y un conjunto limitado de operaciones. El objetivo es lograr la ordenación con la menor cantidad de movimientos posible.

## Reglas y Operaciones Permitidas
El programa debe recibir una lista de números enteros como argumento y ordenarlos utilizando las siguientes operaciones:

### **Operaciones de intercambio**
- `sa` - Intercambia los dos primeros elementos de `A`.
- `sb` - Intercambia los dos primeros elementos de `B`.
- `ss` - Ejecuta `sa` y `sb` simultáneamente.

### **Operaciones de desplazamiento**
- `pa` - Mueve el primer elemento de `B` a `A`.
- `pb` - Mueve el primer elemento de `A` a `B`.

### **Operaciones de rotación**
- `ra` - Rota `A` (el primer elemento pasa al final).
- `rb` - Rota `B` (el primer elemento pasa al final).
- `rr` - Ejecuta `ra` y `rb` simultáneamente.

### **Operaciones de rotación inversa**
- `rra` - Rota `A` en sentido inverso (el último elemento pasa al inicio).
- `rrb` - Rota `B` en sentido inverso.
- `rrr` - Ejecuta `rra` y `rrb` simultáneamente.

## Estrategia de Ordenación recomendadas
Dependiendo del tamaño de la lista, se pueden aplicar distintas estrategias:

1. **Casos pequeños (3 a 5 elementos)**
   - Ordenamiento manual con combinaciones de `sa`, `ra`, `rra`, `pb` y `pa`.

2. **Casos medianos (hasta 100 elementos)**
   - Dividir la pila en "chunks" (bloques) y moverlos de manera ordenada.
   - Utilizar variaciones de **Insertion Sort** o **Selection Sort**.

3. **Casos grandes (>100 elementos)**
   - Implementar **Radix Sort** en base binaria.
   - Aplicar QuickSort adaptado para el uso de dos pilas.
  
## Estrategias de Ordenación usadas

### ✅ Radix Sort
Es un algoritmo no comparativo basado en los bits de cada número. Funcionamiento:
1. Se indexan los elementos (asignando su posición en orden ascendente).
2. Se recorren bit a bit (de menos significativo a más significativo).
3. En cada pasada, se mueve con `pb` los que tengan el bit actual en 0 y con `ra` los que tengan el bit en 1.
4. Después de cada pasada, se devuelve todo a `A` con `pa`.

> 🔁 Este proceso se repite hasta haber recorrido todos los bits del número más grande.
> Los stacks usados tienen que ser proporcionalmente iguales a la base de los numeros. Base 10 se haria con 10 stacks.

---

### ✅ Algoritmo Turco (Chunking)
Inspirado en una estrategia por bloques, muy efectiva para listas medianas y grandes. Funcionamiento:

1. Se divide la pila en **"chunks"** (bloques) de índices consecutivos.
2. Se identifica qué elementos del chunk están más cerca del principio o del final de la pila `A`.
3. Se rota (`ra` o `rra`) hasta que el elemento más accesible esté arriba.
4. Se mueve a `B` con `pb`.
5. Una vez `A` esté vacía, se recupera el orden en `B` usando combinaciones de `pa`, `rb`, `rrb`.

> 🧠 Este método optimiza el número de movimientos usando heurísticas de accesibilidad en la pila.

---
   
## Compilación y Uso

### **Compilación**
Ejecuta el siguiente comando en la terminal:
```sh
make
```
Esto generará un ejecutable llamado `push_swap`.

### **Uso**
Ejecuta el programa pasando una lista de números:
```sh
./push_swap 5 2 8 3 1
```
Esto imprimirá en pantalla la secuencia de operaciones necesarias para ordenar los números.

Para verificar la corrección de la salida, puedes usar el `checker` proporcionado por el proyecto.

```sh
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```
---

## Evaluación
El proyecto se evalúa según la eficiencia del algoritmo:

| Cantidad de números | Movimientos requeridos |
|----------------------|-----------------------|
| 3 elementos         | Máximo 3 movimientos |
| 5 elementos         | Máximo 12 movimientos |
| 100 elementos       | Menos de 700 movimientos |
| 500 elementos       | Menos de 5500 movimientos |

### 🔹 Nivel Intermedio (100 valores aleatorios)
- 5 puntos: menos de 700 instrucciones
- 4 puntos: de 701 a 900 instrucciones
- 3 puntos: de 901 a 1100 instrucciones
- 2 puntos: de 1101 a 1300 instrucciones
- 1 punto: de 1301 a 1500 instrucciones  
  *(Debe verificarse que el programa no esté adaptado específicamente para esta prueba.)*

### 🔹 Versión Avanzada (500 valores aleatorios)
- 5 puntos: ≤ 5500 instrucciones
- 4 puntos: 5501 a 7000 instrucciones
- 3 puntos: 7001 a 8500 instrucciones
- 2 puntos: 8501 a 10000 instrucciones
- 1 punto: 10001 a 11500 instrucciones  
  *(También debe comprobarse que el programa no esté optimizado solo para esta prueba.)*
  

## Recursos y Referencias
- [Documentación oficial de 42](https://github.com/qst0/42cursus)
- Algoritmos de ordenación: Radix Sort, QuickSort, Chunk Sorting.

---

Desarrollado para el programa 42.


