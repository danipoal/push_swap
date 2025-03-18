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

## Estrategia de Ordenación
Dependiendo del tamaño de la lista, se pueden aplicar distintas estrategias:

1. **Casos pequeños (3 a 5 elementos)**
   - Ordenamiento manual con combinaciones de `sa`, `ra`, `rra`, `pb` y `pa`.

2. **Casos medianos (hasta 100 elementos)**
   - Dividir la pila en "chunks" (bloques) y moverlos de manera ordenada.
   - Utilizar variaciones de **Insertion Sort** o **Selection Sort**.

3. **Casos grandes (>100 elementos)**
   - Implementar **Radix Sort** en base binaria.
   - Aplicar QuickSort adaptado para el uso de dos pilas.
   
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

## Evaluación
El proyecto se evalúa según la eficiencia del algoritmo:

| Cantidad de números | Movimientos requeridos |
|----------------------|-----------------------|
| 3 elementos         | Máximo 3 movimientos |
| 5 elementos         | Máximo 12 movimientos |
| 100 elementos       | Menos de 700 movimientos |
| 500 elementos       | Menos de 5500 movimientos |

## Recursos y Referencias
- [Documentación oficial de 42](https://github.com/qst0/42cursus)
- Algoritmos de ordenación: Radix Sort, QuickSort, Chunk Sorting.

---

Desarrollado para el programa 42.


