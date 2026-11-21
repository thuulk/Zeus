# FRC 6676 — Código del robot (temporada 2024)

Proyecto WPILib en C++ (GradleRIO 2024.3.2) del equipo 6676.

## Estructura

```
src/main/cpp/Robot.cpp       # Lógica del robot (incluye main())
src/main/include/Robot.h
src/main/deploy/             # Archivos que se copian al roboRIO
vendordeps/                  # Librerías de terceros (REVLib, Phoenix 5/6, Commands)
build.gradle, gradlew        # Build con GradleRIO
.wpilib/wpilib_preferences.json  # Año 2024, equipo 6676
```

## Software necesario

- **WPILib 2024.3.2** (incluye VS Code, JDK y toolchain del roboRIO)
  - Para qué: escribir, compilar y desplegar el código
  - Plataforma: Windows, macOS, Linux
- **FRC Game Tools 2024** (Driver Station, roboRIO Imaging Tool)
  - Para qué: manejar el robot y flashear el roboRIO
  - Plataforma: solo Windows
- **REV Hardware Client**
  - Para qué: configurar los SPARK MAX (CANSparkMax)
  - Plataforma: Windows (ver docs de REV)
- **Phoenix Tuner X**
  - Para qué: configurar los controladores CTRE (VictorSPX)
  - Plataforma: Windows, Android, iOS

> Importante: usen **WPILib 2024**, no la versión más nueva. El código usa APIs de REVLib/Phoenix de 2024 (por ejemplo `CANSparkMax`) que cambiaron en temporadas posteriores.

Los programas para configurar los controladores dependen de qué controladores use el robot. Si cambian de hardware, busquen el software del fabricante correspondiente.

### Instalar WPILib 2024.3.2

Descarguen el instalador de la release
[v2024.3.2 de allwpilib](https://github.com/wpilibsuite/allwpilib/releases/tag/v2024.3.2).
Guía oficial (2024): https://docs.wpilib.org/es/2024/docs/zero-to-robot/step-2/wpilib-setup.html

**Windows:** descarguen `WPILib_Windows-2024.3.2.iso`, móntenlo y ejecuten `WPILibInstaller.exe`.

**Linux (x86_64):**

```bash
tar -xzf WPILib_Linux-2024.3.2.tar.gz
cd WPILib_Linux-2024.3.2
./WPILibInstaller
```

Se instala en `~/wpilib/2024/`. Para abrir el VS Code **de WPILib** (no el VS Code normal del sistema):

```bash
~/wpilib/2024/vscode/VSCode-linux-x64/code
```

Si usan el comando `code` normal, no aparecerán los comandos de WPILib.

### Otras herramientas

- FRC Game Tools 2024: https://www.ni.com/es/support/downloads/drivers/download.frc-game-tools.html
- REV Hardware Client: https://docs.revrobotics.com/rev-hardware-client/
- Phoenix Tuner X: https://v6.docs.ctr-electronics.com/en/stable/docs/tuner/index.html

## Clonar y compilar

```bash
git clone https://github.com/thuulk/FRC_6676.git
cd FRC_6676
git checkout FRC-2024
./gradlew build          # En Windows: gradlew.bat build
```

La primera compilación necesita internet porque descarga Gradle, el toolchain del roboRIO y las librerías de `vendordeps/`.

También pueden abrir la carpeta en el VS Code de WPILib y usar **WPILib: Build Robot Code**.

## Desplegar al robot

Conectados al robot (USB, Ethernet o WiFi):

```bash
./gradlew deploy
```

O en VS Code: **WPILib: Deploy Robot Code**.

## Notas

- `build/` y `.gradle/` se generan al compilar y están en `.gitignore`. No los suban.
- Si VS Code marca errores de `#include` ("cannot open source file") pero `./gradlew build` pasa, es un problema de IntelliSense, no del código. Compilen una vez y luego usen **WPILib: Refresh C++ Intellisense** o **Developer: Reload Window**.
