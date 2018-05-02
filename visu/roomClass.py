import pygame

class Room:
	def __init__(self, coo, name, type, AntList, radius):
		self.coo = coo
		self.type = type
		if (self.type == "sta"):
			for ant in AntList:
				ant.coo = self.coo
		self.name = name
		self.radius = radius

	def display(self, window):
		if (self.type == "def"):
			color = (255, 127, 80)
		elif (self.type == "end"):
			color = (30, 144, 255)
		else:
			color = (106, 90, 205)
		pygame.draw.circle(window, color, self.coo, self.radius)
