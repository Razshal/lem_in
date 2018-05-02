import pygame

class Pipe:
	def __init__(self, names, roomList):
		for room in roomList:
			if room.name == names[0]:
				self.start = room.coo
			if room.name == names[1]:
				self.end = room.coo

	def display(self, window):
		pygame.draw.line(window, (255, 127, 80), self.start, self.end, 5)