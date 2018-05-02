class Ant:
	def __init__(self, nbr, coo):
		self.num = nbr
		self.coo = coo
		self.div = 60
		self.i = -1
		self.dirx = 0
		self.diry = 0

	def display(self, window, AntImg, radius):
		if self.dirx != 0 or self.diry != 0:
			if self.i == self.div:
				self.dirx = 0
				self.diry = 0
				self.i = -1
			else:
				self.i += 1
		self.move()
		window.blit(AntImg, (self.coo[0] - 1.4 * radius, self.coo[1] - radius / 1.8))

	def moveTo(self, where, roomList):
		self.i += 1
		for room in roomList:
			if room.name == where:
				self.dirx = room.coo[0] - self.coo[0]
				self.diry = room.coo[1] - self.coo[1]

	def restart(self, where, roomList):
		self.dirx = 0
		self.diry = 0
		self.i = -1
		for room in roomList:
			if room.name == where:
				self.coo = room.coo

	def move(self):
		self.coo = (self.coo[0] + self.dirx / self.div, self.coo[1] + self.diry / self.div)