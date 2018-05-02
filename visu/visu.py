#!/sgoinfre/goinfre/Perso/abouvero/anaconda3/bin/pythonw

import math
import pygame
from pygame.locals import *
from roomClass import *
from pipeClass import *
from antClass import *
from parser import *


windowHeight = 768
windowWidth = 1366

fontSize = 20
radius = 50

##########################################################################################################

roomList = []
pipeList = []
AntList = []
toMove = []

def drawLegend(window):
	window.blit(pygame.font.SysFont(None, fontSize + 5, 1).render("Entree              | Sortie              | Return => coup suivant | Delete => restart", False, (255, 255, 255)), (windowWidth - 750, 25))
	pygame.draw.circle(window, (106, 90, 205), (windowWidth - 650, 31), 24)
	pygame.draw.circle(window, (30, 144, 255), (windowWidth - 500, 31), 24)

def parse(roomList, pipeList, AntList, toMove):
	i = 1
	lines = getLines()
	if lines[0] == "ERROR":
		print("ERROR")
		exit()
	AntList = initAnts(int(lines[0]), AntList)
	while i < len(lines):
		if lines[i] == "##start":
			roomList = addRoom(lines[i + 1].split(), "sta", roomList, AntList)
			i += 1
		elif lines[i] == "##end":
			roomList = addRoom(lines[i + 1].split(), "end", roomList, AntList)
			i += 1
		elif lines[i].find("-") == -1 and lines[i] != "" and lines[i][0] != "#":
			roomList = addRoom(lines[i].split(), "def", roomList, AntList)
		elif lines[i].find("-") != -1:
			pipeList = addPipe(lines[i].split("-"), pipeList, roomList)
		elif lines[i] == "":
			toMove = parseToMove(lines, i + 1, toMove)
			return
		i += 1

parse(roomList, pipeList, AntList, toMove)

##########################################################################################################

window = pygame.display.set_mode((windowWidth, windowHeight))
pygame.display.set_caption('lem_in')
AntImg = pygame.image.load("visu/img/ant.png").convert_alpha()

pygame.init()

done = False
i = 0
count = -1

while not done:
	window.fill((0, 0, 0))
	for event in pygame.event.get():
		if event.type == QUIT:
			done = True
		if event.type == KEYDOWN:
			if event.key == K_ESCAPE:
				done = True
			elif event.key == K_DELETE:
				i = 0
				for room in roomList:
					if room.type == "sta":
						start = room.name
				for ant in AntList:
					ant.restart(start, roomList)
				count = -1
			elif event.key == K_RETURN and count == -1:
				if i >= len(toMove):
					i = len(toMove) - 1
				whos = toMove[i]
				for ant in AntList:
					for who in whos:
						if ant.num == who[0]:
							ant.moveTo(who[1], roomList)
				count = 0
				i += 1
	for pipe in pipeList:
		pipe.display(window)
	for room in roomList:
		room.display(window)
		window.blit(pygame.font.SysFont(None, fontSize, 1).render(room.name, False, (255, 255, 255)), (room.coo[0] - ((len(room.name) * fontSize) / 4.5), room.coo[1] + radius + 2))
	for ant in AntList:
		ant.display(window, AntImg, radius)
	drawLegend(window)
	pygame.display.flip()
	if count > -1:
		count += 1
	if count == 63:
		count = -1

pygame.quit()
