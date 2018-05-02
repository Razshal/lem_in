from antClass import *
from roomClass import *
from pipeClass import *
import fileinput
import math
import sys

windowHeight = 768
windowWidth = 1366
radius = 50

def parseToMove(lines, i, toMove):
	while i < len(lines):
		instL = []
		insts = lines[i].split()
		for inst in insts:
			instL.append((int(inst[1]), inst[3:]))
		toMove.append(instL)
		i += 1
	return toMove

def getLines():
	lines = []
	stdin = sys.stdin.readlines()
	for l in stdin:
		lines.append(l.replace('\n', ''))
	return lines
			
def addRoom(args, types, roomList, AntList):
	roomList.append(Room((math.floor((int(args[1]) * windowWidth) / 24), math.floor((int(args[2]) * windowHeight) / 10)), args[0], types, AntList, radius))
	return roomList

def addPipe(args, pipeList, roomList):
	pipeList.append(Pipe((args[0], args[1]), roomList))
	return pipeList

def initAnts(nbr, AntList):
	i = 1
	while i <= nbr:
		AntList.append(Ant(i, (0, 0)))
		i += 1
	return AntList