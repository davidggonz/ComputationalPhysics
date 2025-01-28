#!/usr/bin/env python

#First we define the function that will be integrated (arctan(x)) by trigonometric sustitution, that's the reason why it's multplied by 4
def integrand(y):
    return 4.0/(1.0 + y**2) #f(x)
#Is defined as a function of 'y' because is a 'independent variable'

#Consider 'x_inf' as the lower limit, 'x_sup' as the upper limit, 'N' as the number of Riemmann's rectangles and 'f' as the function to integrate, with this the integral is defined by those parameters
def integral(x_inf,x_sup,N,f):

    #Is defined an accumulation of rectangles that begins in zero but will be increasing as a Riemmann's summatory
    accum = 0.0
    #Now is defined a height for the rectangles as de difference between the limits divided by the number of these 
    h = (x_sup - x_inf) / N
    
    #Then is defined a 'for' that works in the 'N range' that does the sum of the functions (f(x)) defined by the sum of 'x_inf' and the product of every uneven number per the half of the height defined (x = 0 + (2i + 1)*(h/2))
    for i in range(N):
        x = x_inf + (2 * i +1)*(h/2)
        
        #This adds up to the accumulation of rectangles
        accum += f(x)

    #Is returned the product of accum and the height
    return accum * h

#The pi calculation would be using the right variables in the integration like x_inf = 0, x_sup = 1 and the function f(x) = 4.0/(1.0 + y**2) (The 'N' is a way to approximate the result with more precision)
pi = integral(0,1,100, integrand)

#It prints the result when the archive is called in the terminal as: python pi_calc.py
print(pi)




