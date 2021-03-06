###############################################################
# Program:
#     Project 3, Skeet
#     Brother Comeau, CS165
# Author:
#     Trevor Nestman
# Summary:
#     Enter a brief description of your program here! If you do any
#     extra credit, this would be a good place to describe it.
#
#     Estimated:  0.4 hrs
#     Actual:     2,005.0 hrs
#       Please describe briefly what was the most difficult part
###############################################################

# for the linux VM in vmware, you need to add '-lGL' to LFLAGS
LFLAGS = -lGL -lglut -lGLU

# vars for the backup feature
PACKAGE   = backup
VERSION   = ` date +"%Y%m%d_%H%M%S" `
ARCHIVE   = $(PACKAGE)-$(VERSION)

###############################################################
# Programs:
#    moon:         The moon lander game lol
###############################################################
a.out: game.o uiInteract.o uiDraw.o point.o velocity.o rifle.o movable.o bullet.o bird.o normal.o tough.o sacred.o drop.o
	g++ -o a.out game.o uiInteract.o uiDraw.o point.o velocity.o rifle.o movable.o bullet.o bird.o normal.o tough.o sacred.o drop.o $(LFLAGS)
	tar -j -cf project3.tar makefile *.h *.cpp

###############################################################
# Individual files
#    rifle.o       Displays the rifle
#    game.o        The skeet game
#    uiInteract.o  Handles input events
#    uiDraw.o      Drawing functions
#    point.o       Point class
#    velocity.o    velocity class
#    movable.o     movable class
#    bullet.o      bullet class
#    bird.o        bird class
#    normal.o      normal bird class
#    tough.o       tough bird class
#    sacred.o      sacred bird class
#    drop.o        drop class
###############################################################
game.o: game.cpp uiDraw.h uiInteract.h point.h rifle.h movable.h drop.h bullet.h bird.h normal.h tough.h sacred.h
	g++ -c game.cpp

uiInteract.o: uiInteract.cpp uiInteract.h
	g++ -c uiInteract.cpp

uiDraw.o: uiDraw.cpp uiDraw.h
	g++ -c uiDraw.cpp

velocity.o: velocity.cpp velocity.h point.h
	g++ -c velocity.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

rifle.o: rifle.cpp rifle.h
	g++ -c rifle.cpp

movable.o: movable.cpp movable.h uiDraw.h
	g++ -c movable.cpp

bullet.o: bullet.cpp bullet.h movable.h
	g++ -c bullet.cpp

bird.o: bird.cpp bird.h movable.h
	g++ -c bird.cpp

normal.o: normal.cpp normal.h bird.h
	g++ -c normal.cpp

tough.o: tough.cpp tough.h bird.h
	g++ -c tough.cpp

sacred.o: sacred.cpp sacred.h bird.h
	g++ -c sacred.cpp

drop.o: drop.cpp drop.h movable.h
	g++ -c drop.cpp

###############################################################
# General rules
###############################################################
clean:
	rm a.out project3.tar *.o

cleanbackups:
	rm backup*.tar

backup:
	tar -j -cvf $(ARCHIVE).tar *.cpp *.h makefile

all:
	a.out
