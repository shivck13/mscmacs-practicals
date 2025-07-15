"Collection of all the practicals for MMT-007 - Differential Equations & Numerical Solutions" 

### Index
#### Session 1
[1.](p1.c)  Write a program using Euler's method to solve the initial value problem $y' = f(x, y), y(x_0) = y_0$ . INput the step length $h$ and the number of steps of integration. 

Test your program on E1:

E1: Calculate $y(1.2)$ for $y' = -y^2, y(1) = 1$ with $h = 0.1$

[2.](p2.c) Write a program using Taylor series method of second order to solve the initial value problem $y'= f(x, y), y(x_0) = y_0$ . User shall give the expression for $y''$ . Input the step length $h$ and the number of steps of integration.  

Test your program on exercises (E2) and (E3).
    
E2: Solve $y' = 2x + 3y, y(0) = 1$ in the interval $[0, 0.4]$ with $h = 0.2$

E3: Solve $y' = x + \sin(y), y(1) = 1$ in the ingterval $[1, 1.2]$ with $h = 0.1$

[3.](p3.c) Write a program using Runge-Kutta second order method to solve the initial value problem $y' = f(x, y), y(x_0) = y_0$. Input the step length $h$ and the number of
steps of mtegration. 

Test your program on exercises (E6) and (E7)

E6: Solve $y' = x + y^2, y(0) = 1$ on the interval $[0, 0.4]$ with $h = 0.2$

E7: Find $y(1.2)$ for $y' = \frac{y - x}{y + x}, y(1) = 2$ with $h= 0.1$

[4.](p4.c) Write a program using fourth order classical Runge-Kutta method to solve the initial value problem $y' = f(x, y), y(x_0) = y_0. Input the step length $h$ and the number of steps of integration. 

Test your program on exercises (E8)and (E9)

E8: Find $y(2.4)$ for $y' = x(y-x), y(2) = 3$ with $h=0.2$

E9:  Solve $y' = x + \cos(y), y(1) = 1$ on the interval $[1, 1.2]$ with $h = 0.1$

#### Session 2
[5.](p5.c) Write a program to solve the initial value problem $y' = f(x, y), y(x_0)= y_0$, using Euler method as predictor and Backward Euler method as corrector. Use the corrector three times. Input the step length $h$ and the number of steps of itegration.

[6.](p6.c) Write a program to solve the initial value problem $y' = f(x, y), y(x_0)= y_0$, using Euler method as predictor and Trapezoidal method as corrector. Use the corrector three times. Input the step length $h$ and the number of steps of integration.

[7.](p7.c) Write a program to solve the initial value problem $y' = f(x, y), y(x_0) = y_0$ , using Milne's predictor-corrector method. Required starting values are to be computed using the Euler method.

[8.](p8.c) Write a program to solve the initial value problem $y' = f(x, y), y(x_0)= y_0$ , using Milne's predictor-corrector method. Required starting values are to be computed using the Taylor series method of second order.
    
Test your program on Example 9.

Exa9: Solve $y' = x^2 + y^3, y(1) = 0$ on the interval $[1, 1.6]$ with $h = 0.2$

#### Session 3
[9.](p9.c) Write a program to solve the boundary value problem $y'' + p(x) y = r(x), y(a) = \alpha, y(b) = \beta, a \leq x \leq b$, using a second order finite difference method. Input $h$.

[10.](p10.c) Write a program to solve the boundary value problem $a(x)y'' + b(x)y' +c(x)y = r(x), y(a) = \alpha , y(b) = \beta, a \leq x \leq b$, using second order central difference approximations to both $y''$ and $y'$ . Input $h$. 
    
Test your program on exercises (E4) and (E5).

E4: Solve BVP $y'' = 2yy', y(0) = \frac{1}{2}, y(1) = 1$ with $h = \frac{1}{2}$ and $h = \frac{1}{3}$

E5: Solve BVP $y'' = \frac{3}{2}y^2, y(0) = 4, y(1) = 1$ with $h = \frac{1}{2}$ and $h = \frac{1}{3}$


[11.](p11.c) Write a program to solve the boundary value problem $a(x)y'' + b(x)y' +c(x)y = r(x), y(a) = \alpha , y(b) = \beta, a \leq x \leq b$, using shooting method. Use Taylor series method of second order to solve the corresponding
initial value problems.
    
Test your program on Example 6 and (E6)

Exa6: Solve $y'' = y + 1, y(0) = 0, y(1) = e - 1$ with $h = 0.25$

E6: Solve BVP $x^2y'' - 2y + x = 0, y(2) = 0, y(3) = 0$ with $h = 0.25$

#### Session 4-5
[12.](p12.c) Write a program to solve  
(a) Laplace equation $\nabla^2 u = 0$ on (i) a square of side $a$ (ii) a rectangle of side $a, b$  
(b) Poisson equation $\nabla^2 2 u = G(x, y)$ on (i) a square of side $a$ (ii) a rectangle of side $a, b$ .

Use Dirichlet boundary conditions. Use a method of second order and uniform step length $h$ along $x$ and $y$ directions. Solve the resulting equations by Gauss elimination method. Test your program on exercises (E2) and (E3).

E2: 
Find the solution of
$\nabla^2 u = 0 \quad \text{in } R$
subject to the given region $R$ and boundary conditions using the five-point formula.

**(a)**
Region: square
$0 \leq x \leq 1,\; 0 \leq y \leq 1$
Boundary condition:
$u(x, y) = x - y$ on $\Gamma$
Assume $h = \frac{1}{3}$

**(b)**
Region: rectangle
$0 \leq x \leq 3,\; 0 \leq y \leq 2$
Boundary condition:
$u(x, y) = x^2 - 3y^2$ on $\Gamma$
Assume $h = 1.0$

**(c)**
Region: triangle
$0 \leq x \leq 1,\; 0 \leq y \leq 1,\; 0 \leq x + y \leq 1$
Boundary condition:
$u(x, y) = x^2 - y^2$ on $\Gamma$
Assume $h = \frac{1}{3}$

**(d)**
Region: rectangle
$0 \leq x \leq \frac{5}{6},\; 0 \leq y \leq 1$
Boundary condition:
$u(x, y) = x - y$ on $\Gamma$
Assume $h = \frac{1}{3}$


E3:
Find the solution of
$\nabla^2 u = G(x, y) \quad \text{in } R$
subject to the given $R$, $G$, and boundary conditions, using the five-point formula.

**(a)**
Region: square
$0 \leq x \leq 1,\; 0 \leq y \leq 1$
Source term:
$G(x, y) = 2x + 3y$
Boundary condition:
$u(x, y) = x - y$ on $\Gamma$
Assume $h = \frac{1}{3}$

**(b)**
Region: rectangle
$0 \leq x \leq 3,\; 0 \leq y \leq 2$
Source term:
$G(x, y) = x - y$
Boundary condition:
$u(x, y) = x^2 - 3y^2$ on $\Gamma$
Assume $h = 1.0$

**(c)**
Region: triangle
$0 \leq x \leq 1,\; 0 \leq y \leq 1,\; 0 \leq x + y \leq 1$
Source term:
$G(x, y) = x^2 + y^2$
Boundary condition:
$u(x, y) = x^2 - y^2$ on $\Gamma$
Assume $h = \frac{1}{3}$

**(d)**
Region: rectangle
$0 \leq x \leq \frac{5}{6},\; 0 \leq y \leq 1$
Source term:
$G(x, y) = 2x + 3y$
Boundary condition:
$u(x, y) = x - y$ on $\Gamma$
Assume $h = \frac{1}{3}$

[13.](p13.c) Write a program to solve
$\frac{\partial u}{\partial t} = \frac{\partial^2 u}{\partial^2 x^2}, 0 \leq x \leq a, t \geq 0,$  
$u(x, 0) = f(x), u(0, t) = A, u(a, t) = B $

using  
(i) Schmidt method  
(ii) Laasonen method  
(iii) Crank-Nicolson method  

Input $h, k$ and number of steps $n$ . Solve the tridiagonal systems in (ii) and (iii) above by using Gauss elimination method. 

Test your program on exercises (E12) and (E13).

E12:
Find the solution of the following initial boundary value problem, subject to the given initial and boundary conditions:

$$
\frac{\partial u}{\partial t} = \frac{\partial^2 u}{\partial x^2}, \quad u(x, 0) = 
\begin{cases}
2x, & \text{for } x \in [0, \frac{1}{2}] \\
2(1 - x), & \text{for } x \in [\frac{1}{2}, 1]
\end{cases}
$$

Boundary conditions:
$u(0, t) = 0 = u(1, t)$

Use $h = 0.2$. (Note the symmetry in the problem and the solution about $x = \frac{1}{2}$)

E13:
Find the solution of the following initial boundary value problem, subject to the given initial and boundary conditions:

$$
\frac{\partial u}{\partial t} = \frac{\partial^2 u}{\partial x^2}, \quad 0 \leq x \leq 1
$$

Initial condition:
$u(x, 0) = \sin(2\pi x)$, $0 \leq x \leq 1$

Boundary conditions:
$u(0, t) = 0 = u(1, t)$

Assume $h = 0.25$

[14.](p14.c) Write a program to solve
$\frac{\partial^2 u}{\partial t^2} = \frac{\partial^2 u}{\partial^2 x^2}, 0 \leq x \leq a, t \geq 0,$

$0 \leq x \leq 1, t \geq 0$  
$u(x, 0) = f(x), \frac{\partial u}{\partial t}(x, 0) = g(x), u(0, t) = A, u(1, t) = B$


using  
(i) explicit scheme  
(ii) implicit scheme  

Input $h, k$ and number of steps. Solve the tridiagonal system in (ii) using Gauss elimination method. Use central difference approximation to $(\frac{\partial u}{\partial t}(x, 0))$

Test your program on Example 7 and (E15)

Exa7:
$$
\frac{\partial^2 u}{\partial t^2} = \frac{\partial^2 u}{\partial x^2}, \quad 0 \leq x \leq 1
$$

with initial and boundary conditions:

* $u(x, 0) = \sin(\pi x), \quad 0 \leq x \leq 1$
* $\frac{\partial u}{\partial t}(x, 0) = 0, \quad 0 \leq x \leq 1$
* $u(0, t) = 0, \quad u(1, t) = 0, \quad t > 0$

Use:

1. The explicit scheme (equation 48)
2. The implicit scheme (equation 52)

Use the central difference approximation to the derivative to obtain the initial condition. Assume:

* $h = \frac{1}{4}$
* $r = \frac{1}{2}$

Integrate for **one time step**.

Compare with the exact solution:

$$
u(x, t) = \sin(\pi x) \cos(\pi t)
$$


E15:
* $h = \frac{1}{4}$
* $r = \frac{1}{3}$

Integrate for **one time step**.

Compare with the exact solution:

$$
u(x, t) = \sin(\pi x) \cos(\pi t)
$$