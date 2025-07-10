# Sistema de Gestión en Consola - C++

Este proyecto es una aplicación de consola desarrollada en **C++** que permite la **gestión de clientes**, **administradores** y **productos** con múltiples funcionalidades como registro, modificación, eliminación y visualización de datos, además de un sistema básico de **login**.

---

## Características

-  Gestión de **Clientes**
  - Registro con cédula, nombre, apellidos, edad, fecha de nacimiento, estado de salud y estado general.
  - Modificación, eliminación y búsqueda de clientes.
  
- Gestión de **Administradores**
  - Registro con código, cédula, nombre, apellido, teléfono y correo electrónico.
  - Modificación, eliminación y búsqueda por cédula.
  
-  **Gestión de Productos**
  - Simulación de ventas de productos predefinidos.
  - Cálculo del total por cliente y corte final.

- **Login de usuario** con validación de credenciales.

---

## Estructura del código

- `main()` – Punto de entrada principal del programa.
- `Menu()` – Menú principal del sistema.
- `SubMenu()` – Gestión de clientes.
- `SubMenuAD()` – Gestión de administradores.
- `Productos()` – Módulo de ventas.
- `login()` – Sistema de autenticación.
- Uso de **estructuras dinámicas** con `new` para almacenar clientes y administradores.

---

## Requisitos

- Compilador de C++ compatible con C++11 o superior.
- Sistema operativo Windows (usa `windows.h` para `gotoxy()`).
- IDE como Code::Blocks, Dev-C++ o Visual Studio.

---

## Librerías utilizadas

```cpp
#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include <vector>
#include <ctime>
#include <algorithm>
