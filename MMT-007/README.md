"Collection of all the practicals for MMT-007 - Differential Equations & Numerical Solutions" 

### Index
#### Session 1
1. Write a program using Euler's method to solve the initial value problem $y' = f(x, y), y(x_0) = y_0$ . INput the step length $h$ and the number of steps of integration. 

    Test your program on E1:
    
    E1: Calculate $y(1.2)$ for $y' = -y^2, y(1) = 1$ with $h = 0.1$

2. Write a program using Taylor series method of second order to solve the initial value problem $y'= f(x, y), y(x_0) = y_0$ . User shall give the expression for $y''$ . Input the step length $h$ and the number of steps of integration.  

    Test your program on exercises (E2) and (E3).
      
    E2: Solve $y' = 2x + 3y, y(0) = 1$ in the interval $[0, 0.4]$ with $h = 0.2$
    
    E3: Solve $y' = x + \sin(y), y(1) = 1$ in the ingterval $[1, 1.2]$ with $h = 0.1$

3. Write a program using Runge-Kutta second order method to solve the initial value problem $y' = f(x, y), y(x_0) = y_0$. Input the step length $h$ and the number of
steps of mtegration. 

    Test your program on exercises (E6) and (E7)

    E6: Solve $y' = x + y^2, y(0) = 1$ on the interval $[0, 0.4]$ with $h = 0.2$

    E7: Find $y(1.2)$ for $y' = \frac{y - x}{y + x}, y(1) = 2$ with $h= 0.1$

4. Write a program using fourth order classical Runge-Kutta method to solve the initial value problem $y' = f(x, y), y(x_0) = y_0. Input the step length $h$ and the number of steps of integration. 

    Test your program on exercises (E8)and (E9)

    E8: Find $y(2.4)$ for $y' = x(y-x), y(2) = 3$ with $h=0.2$

    E9:  Solve $y' = x + \cos(y), y(1) = 1$ on the interval $[1, 1.2]$ with $h = 0.1$
#### Session 2
5. Write a program to solve the initial value problem $y' = f(x, y), y(x_0)= y_0$, using Euler method as predictor and Backward Euler method as corrector. Use the corrector three times. Input the step length $h$ and the number of steps of itegration.
6. Write a program to solve the initial value problem $y' = f(x, y), y(x_0)= y_0$, using Euler method as predictor and Trapezoidal method as corrector. Use the corrector three times. Input the step length $h$ and the number of steps of integration.
7. Write a program to solve the initial value problem $y' = f(x, y), y(x_0) = y_0$ , using Milne's predictor-corrector method. Required starting values are to be computed using the Euler method.
8. Write a program to solve the initial value problem $y' = f(x, y), y(x_0)= y_0$ , using Milne's predictor-corrector method. Required starting values are to be computed using the Taylor series method of second order.
    
    Test your program on Example 9.

    Exa9: Solve $y' = x^2 + y^3, y(1) = 0$ on the interval $[1, 1.6]$ with $h = 0.2$

#### Session 3
9. Write a program to solve the boundary value problem $y'' + p(x) y = r(x), y(a) = \alpha, y(b) = \beta, a \leq x \leq b$, using a second order finite difference method. Input $h$.

10. Write a program to solve the boundary value problem $a(x)y'' + b(x)y' +c(x)y = r(x), y(a) = \alpha , y(b) = \beta, a \leq x \leq b$, using second order central difference approximations to both $y''$ and $y'$ . Input $h$. 
    
    Test your program on exercises (E4) and (E5).

    E4: Solve BVP $y'' = 2yy', y(0) = \frac{1}{2}, y(1) = 1$ with $h = \frac{1}{2}$ and $h = \frac{1}{3}$

    E5: Solve BVP $y'' = \frac{3}{2}y^2, y(0) = 4, y(1) = 1$ with $h = \frac{1}{2}$ and $h = \frac{1}{3}$


11. Write a program to solve the boundary value problem $a(x)y'' + b(x)y' +c(x)y = r(x), y(a) = \alpha , y(b) = \beta, a \leq x \leq b$, using shooting method. Use Taylor series method of second order to solve the corresponding
initial value problems.
    
    Test your program on Example 6 and (E6)

    Exa6: Solve $y'' = y + 1, y(0) = 0, y(1) = e - 1$ with $h = 0.25$

    E6: Solve BVP $x^2y'' - 2y + x = 0, y(2) = 0, y(3) = 0$ with $h = 0.25$

#### Session 4-5
12. Write a program to solve  
(a) Laplace equation $\nabla^2 u = 0$ on (i) a square of side $a$ (ii) a rectangle of side $a, b$  
(b) Poisson equation $\nabla^2 2 u = G(x, y)$ on (i) a square of side $a$ (ii) a rectangle of side $a, b$ .

    Use Dirichlet boundary conditions. Use a method of second order and uniform step length $h$ along $x$ and $y$ directions. Solve the resulting equations by Gauss elimination method. Test your program on exercises (E2) and (E3).

    E2:

    E3:

13. Write a program to solve
    $\frac{\partial u}{\partial t} = \frac{\partial^2 u}{\partial^2 x^2}, 0 \leq x \leq a, t \geq 0,$  
    $u(x, 0) = f(x), u(0, t) = A, u(a, t) = B $

    using  
    (i) Schmidt method  
    (ii) Laasonen method  
    (iii) Crank-Nicolson method  

    Input $h, k$ and number of steps $n$ . Solve the tridiagonal systems in (ii) and (iii) above by using Gauss elimination method. 
    
    Test your program on exercises (E12) and (E13).

    E12:

    E13:


14. Write a program to solve
    $\frac{\partial^2 u}{\partial t^2} = \frac{\partial^2 u}{\partial^2 x^2}, 0 \leq x \leq a, t \geq 0,$

    $0 \leq x \leq 1, t \geq 0$  
    $u(x, 0) = f(x), \frac{\partial u}{\partial t}(x, 0) = g(x), u(0, t) = A, u(1, t) = B$


    using  
    (i) explicit scheme  
    (ii) implicit scheme  
    
    Input $h, k$ and number of steps. Solve the tridiagonal system in (ii) using Gauss elimination method. Use central difference approximation to $(\frac{\partial u}{\partial t}(x, 0))$
    
    Test your program on Example 7 and (E15)

    Exa7:

    E15: