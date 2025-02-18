#Se importan las librerías
import numpy as np

#La N representa el N-ésimo polinomio de Legendre
def gaussxw(N):
    #Creamos un aproximado inicial
    init_a = np.linspace(3, 4 * (N - 1), N) / ((4 * N) + 2)
    #Se define un código vectorial
    x = np.cos(np.pi * init_a + 1 / (8 * N * N * np.tan(init_a)))

    #Ahora se calculan las raíces de los polinomios utilizando a Newton de la forma:
    epsilon = 1e-15 #Genera un límite para cuando el error sea menor a este epsilon
    delta = 1.0 #Este delta tendrá que irse haciendo más pequeño hasta que la aproximación sea buena
    while delta > epsilon:
        p0 = np.ones(N, dtype = float) #Inicializa el polinomio de Legendre de orden 0 como un array lleno de unos.
        p1 = np.copy(x) #Copia profunda del array x, que representa las raíces iniciales aproximadas del polinomio.
        for k in range(1, N):
            p0, p1 = p1, ((2 * k + 1) * x * p1 - k * p0) / (k + 1) #Este bucle calcula los polinomios de Legendre usando una relación de recurrencia.
        dp = (N + 1) * (p0 - x * p1) / (1 - x * x) #Calcula la derivada de los polinomios de Legendre evaluados en x.
        dx = p1 / dp #Determina el cambio que debe aplicarse a x usando el método de Newton 
        x -= dx #Actualiza las raíces aproximadas en x restando la corrección dx.
        delta = np.max(np.abs(dx)) #Calcula el máximo cambio absoluto entre las aproximaciones sucesivas.

    # Ahora calculamos los pesos
    w = 2 * (N + 1) * (N + 1)/(N * N * (1 - x * x) * dp * dp) 

    return x,w #Devuelve los pesos y puntos de colocación

#Se define un integrando tal que:
def integrando(x):
    return (x**6) - (x**2) * np.sin(2*x)

#Resultado que debería dar: 331.45884423 (Calculadora en grados)

def gaussxwab(x_inf_ver, x_sup_ver, x, w): #'Estira' el espacio de los polinomios con una escala basada en una función constante
    return 0.5 * (x_sup_ver - x_inf_ver) * x + 0.5 * (x_sup_ver + x_inf_ver), 0.5 * (x_sup_ver - x_inf_ver) * w

#Ahora se crea un bucle para obtener información hasta que el error sea mínimo tal que:
# Inicializar variables
error = 1.0
N = 2
Int_prev = 0.0

while error >= 1e-2:
    # Obtener los puntos y pesos de Gauss-Legendre
    x_no_esc, w_no_esc = gaussxw(N)
    
    # Escalar los puntos y pesos al intervalo [a, b]
    a, b = 1, 3  # Intervalo de integración
    x_Escalado, w_Escalado = gaussxwab(a, b, x_no_esc, w_no_esc)
    
    # Calcular la integral
    Int_current = np.sum(w_Escalado * integrando(x_Escalado))
    
    # Calcular el error relativo
    if N > 2:
        error = np.abs(Int_current - Int_prev) / Int_prev
    
    # Actualizar el valor previo de la integral
    Int_prev = Int_current
    
    # Imprimir resultados para cada N
    print(f"N = {N}, Integral = {Int_current}, Error = {error}")
    
    # Incrementar N
    N += 1

# Resultado final
print(f"La integral converge a {Int_current} con un error < 1e-6 para N = {N-1}")

#Esto podría haberse hecho para que el error fuera menor a esta escala, pero luego de 10e-3 ya llega a niveles de N=100