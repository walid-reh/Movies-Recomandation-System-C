# structure.o: structure.c
# 	gcc -c structure.c

# parser.o : parser.c structure.c
# 	gcc -c parser.c structure.c 

# preference.o : preference.c structure.c parser.c 
# 	gcc -c preference.c structure.c parser.c

# main : parser.o structure.o
# 	gcc main main.c -o parser.o structure.o





Netflix: tas.o dynamique5.o  UserReg.o structure.o parser.o preference.h main.o 
	gcc -g -c tas.c dynamique5.c structure.c parser.c UserReg.c preference.c main.c && gcc tas.o dynamique5.o structure.o parser.o UserReg.o preference.o main.o -o Netflix

# dynamique3.o: dynamique3.c
# 	gcc -c dynamique3.c

# UserReg.o: UserReg.c dynamique3.h UserReg.h
# 	gcc -c UserReg.c
# main.o: main.c UserReg.h
# 	gcc -c main.c

