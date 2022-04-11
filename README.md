# RandomLearning
This Repo created for random learning programs for myself. While I am studying I am writing small programs for my learning process. Virtualization and practice is helpful for learning process. Do not forget that these are simple examples.

```
pipes: Learning pipes

Pedantic.c: The program is written to run one specific command: sort.
```
```
ReadWrite: How to write to file.txt and read from file.txt
```
```
signals: Basic signal handler learning
```
```
---cppLearning---

dynamicLib: 
compile ;	
(1) gcc -shared -fPIC -o libsquare.so square.cpp
(2) g++ main.cpp 
(check) nm libsquare.so ->	T __Z6squarei
                 			U dyld_stub_binder
run;
./a.out libsquare.so

example_class:
compile;
(1) g++ -shared -fPIC -o game.so player.cpp
(2) g++ main.cpp  
run;
./a.out game.so
```
