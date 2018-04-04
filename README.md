# CAD Software 
This repository hosts the Mathematical Model, Functional Model, Design Documentation 
This tool is made as a part of COP290 course under Prof. Subhashish Bannerjee. </br>
Source Code, Mathematical Model, Functional Specification and Documentation is in this repository.

## Functionalities
1. Read ```2D/3D model``` from files.
2. Save ```2D/3D model``` in file.
3. Implicit conversion from 2D file[Projections] to 3D.

## UI Interface
![Alt text](screens/Interface.png "Screenshot")

## Directory Structure
                                       
.                                       
├── docs                                       
│   ├── html                                       
│   │   └── search                                       
│   ├── latex                                       
│   └── xml                                       
├── Make                                       
├── mathClassesAndDocs                                       
│   └── doc                                       
│       └── latex                                       
├── mathClasses & Doc                                       
│   ├── doc                                       
│   │   ├── html                                       
│   │   │   └── search                                       
│   │   ├── latex                                       
│   │   ├── man                                       
│   │   │   └── man3                                       
│   │   ├── rtf                                       
│   │   └── xml                                       
│   ├── include                                       
│   └── src                                       
├── models                                       
├── screens                                       
├── src                                       
└── templates                                       
                                      

src contains the main project source files wich have to be built for different platforms.

## Project Description  
Main Classes and UI are in src/ folder [Documented in docs]                </br> 
Math Classes are the conceptual classes. [Documented in the subfolder]     </br> 

## Platform compatibility
Built and tested on Ubuntu-16.04 .

## Technologies Used
1. **QT**
2. **Open-GL**
3. **C++ std-11**

## Compilation and Execution Instructions
1. Run by
```
cd Make && ./CadSoftware
```
2. Compiling with Makefile, but this makefile is configured for my desktop environment.
```
cd Make && make
```
3. To execute, run
```
./CadSoftware
```
4. In case, ```Make``` throws errors becase of difference in build environments, compile from source with qmake :
```
qmake CadSoftware.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug
```

##Authors: </br>
Udit Jain       - 2016CS10327 [@udit01](https://github.com/udit01/)         </br>
Shashank Goel   - 2016CS10332 [@ShashuBoy](https://github.com/ShashuBoy)    </br>

Indian Institute of Technology Delhi
