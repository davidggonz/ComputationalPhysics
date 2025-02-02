# Cuadratura Gaussiana

La **Cuadratura Gaussiana** es un método numérico utilizado para aproximar integrales definidas. A diferencia de otros métodos como la regla del trapecio o la regla de Simpson, la Cuadratura Gaussiana selecciona puntos de evaluación óptimos (nodos) y pesos asociados para maximizar la precisión de la aproximación.

## Fórmula General

La integral definida de una función \( f(x) \) en el intervalo \([a, b]\) se aproxima mediante:

\[
\int_{a}^{b} f(x) \, dx \approx \sum_{i=1}^{n+1} w_i f(x_i)
\]

Donde:
- \( x_i \) son los **nodos** (puntos de evaluación), donde se utiliza **N+1** ya que son N subregiones. Además,
 \( w_i \) son los **pesos** asociados a cada nodo.

## Pasos para Implementar la Cuadratura Gaussiana

1. **Seleccionar el número de puntos \( n \):** Cuantos más puntos se utilicen, mayor será la precisión de la aproximación.
2. **Obtener los nodos y pesos:** Los nodos \( x_i \) y los pesos \( w_i \) se obtienen de tablas predefinidas o se calculan utilizando polinomios de Legendre, tal que:
$\displaystyle w_i = \left[\frac{2}{1-x^2}\left(\frac{dP_N}{dx}\right)^{-2}\right]_{x={x_i}}$, con $x_i$ que cumple $P_N(x_i)=0$
3. **Evaluar la función en los nodos:** Calcular \( f(x_i) \) para cada nodo.
4. **Calcular la suma ponderada:** Multiplicar cada \( f(x_i) \) por su peso correspondiente \( w_i \) y sumar los resultados.

## Ejemplo

Aproximar la integral de \( f(x) = e^{-x^2} \) en el intervalo \([-1, 1]\) utilizando 3 puntos de Cuadratura Gaussiana.

Los nodos y pesos para \( n = 3 \) son:

- Nodos: \( x_1 = -\sqrt{\frac{3}{5}} \), \( x_2 = 0 \), \( x_3 = \sqrt{\frac{3}{5}} \)
- Pesos: \( w_1 = \frac{5}{9} \), \( w_2 = \frac{8}{9} \), \( w_3 = \frac{5}{9} \)

La aproximación de la integral es:

$\int_{-1}^{1} e^{-x^2} \, dx \approx \frac{5}{9} e^{-\left(-\sqrt{\frac{3}{5}}\right)^2} + \frac{8}{9} e^{-0^2} + \frac{5}{9} e^{-\left(\sqrt{\frac{3}{5}}\right)^2} = 1.493648266$

## Referencias

- [Wikipedia: Gaussian Quadrature](https://en.wikipedia.org/wiki/Gaussian_quadrature)
- Libro: "Numerical Analysis" por Richard L. Burden y J. Douglas Faires.
