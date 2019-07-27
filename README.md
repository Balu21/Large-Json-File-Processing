# Large-Json-File-Processing
Large-Scale Processing of JSON Objects

The source code is written for a windows environment. Eclipse C++ needs to be set-up to run the program.
Eclipse can be downloaded from here: https://www.eclipse.org/downloads/download.php?file=/oomph/epp/2019-06/R/eclipse-inst-win64.exe

The files in src need to imported into a new C++ Project.

I've used jsoncpp to handle json objects. 
The jsoncpp library can be downloaded from here: https://github.com/open-source-parsers/jsoncpp
Extract the files from the zip folder.

Generate an amalgamated source and header for jsoncpp by using the following command within the directory.

python amalgamate.py

The following files are generated: 

dist/jsoncpp.cpp - source file to be added to the Project.

dist/json/json.h and dist/json/json-forwards.h - to copied into the include directory of jsoncpp.

Inside Eclipse, goto project properties, goto C/C++ Build Settings and add the path to jsoncpp's include directory in the MinGW C++ Linker Libraries.

The output for small.txt and medium.txt are present in output_small.txt and output_medium.txt files respectively.

Task 2:

I have used multithreading to distribute the work to computing each query.

I have also used dynamic memory allocation to handle larger files.

Task 3:

System Configuration:

CPU cores : 4

Physical Memory : 7.7 GB

Type of Disk : Hard Disk Drive

OS : Windows 10 64-bit
 
