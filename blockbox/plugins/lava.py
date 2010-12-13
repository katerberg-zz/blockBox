# blockBox is Copyright 2009-2010 of the Archives Team, the blockBox Team, and the iCraft team.
# blockBox is licensed under the Creative Commons by-nc-sa 3.0 UnPorted,
# To view more details, please see the "LICENSING" file in the "docs" folder of the blockBox Package.

from twisted.internet import reactor

from blockbox.plugins import ProtocolPlugin
from blockbox.decorators import *
from blockbox.constants import *

class LavaPlugin(ProtocolPlugin):
	"Class for player handling when touched lava."
	hooks = {
		"poschange": "posChanged",
	}

	def gotClient(self):
		self.died = False

	def posChanged(self, x, y, z, h, p):
		"Hook trigger for when the player moves"
		rx = x >> 5
		ry = y >> 5
		rz = z >> 5
		if hasattr(self.client.world.blockstore, "raw_blocks"):
			try: 
				check_offset = self.client.world.blockstore.get_offset(rx, ry, rz)
				try:
					block = self.client.world.blockstore.raw_blocks[check_offset]
				except (IndexError):
					return
				check_offset = self.client.world.blockstore.get_offset(rx, ry-1, rz)
				blockbelow = self.client.world.blockstore.raw_blocks[check_offset]
			except (KeyError, AssertionError):
				pass
			else:
				if block == chr(BLOCK_LAVA) or blockbelow == chr(BLOCK_LAVA):
				#or block == chr(BLOCK_STILLLAVA) or blockbelow == chr(BLOCK_STILLLAVA):
				#Ok, so they touched lava, THEY MUST DIE. Warp them to the spawn, timer to stop spam.
					if self.died is False:
						self.died = True
						self.client.teleportTo(self.client.world.spawn[0], self.client.world.spawn[1], self.client.world.spawn[2], self.client.world.spawn[3])
						self.client.factory.queue.put ((self.client.world,TASK_WORLDMESSAGE, (255, self.client.world, COLOUR_DARKRED+self.client.username+" has died from lava.")))
						reactor.callLater(1, self.unDie)

	def unDie(self):
		self.died = False
