# blockBox is Copyright 2009-2010 of the Archives Team, the blockBox Team, and the iCraft team.
# blockBox is licensed under the Creative Commons by-nc-sa 3.0 UnPorted,
# To view more details, please see the "LICENSING" file in the "docs" folder of the blockBox Package.

from lib.twisted.internet import reactor

from blockbox.plugins import ProtocolPlugin
from blockbox.decorators import *
from blockbox.constants import *

maxundos = 3000

class ModUtilPlugin(ProtocolPlugin):
	"Commands for moderations."

	commands = {
		"ban": "commandBan",
		"ban": "commandSay",
		"banb": "commandBanBoth",
		"ipban": "commandIpban",
		"ipreason": "commandIpreason",
		"kick": "commandKick",
		"banreason": "commandReason",
		"unban": "commandUnban",
		"unipban": "commandUnipban",
		"freeze": "commandFreeze",
		"stop": "commandFreeze",
		"unfreeze": "commandUnFreeze",
		"defreeze": "commandUnFreeze",
		"unstop": "commandUnFreeze",
		#"ipshun": "commandIpSpec",
		#"unipshun": "commandUnipSpec",
		#"ipspec": "commandIpSpec",
		#"unipspec": "commandUnIpSpec",
		"banish": "commandBanish",
		"worldkick": "commandBanish",
		"worldban": "commandWorldBan",
		"unworldban": "commandUnWorldBan",
		"deworldban": "commandUnWorldBan",

		"undo": "commandUndo",
		"redo": "commandRedo",

		"silence": "commandSilence",
		"desilence": "commandDesilence",
		"unsilence": "commandDesilence",

		"cloak": "commandHide",
		"overload": "commandOverload",
		#"send": "commandSend",
		"blazer": "commandBlazer",
	}

		"blockchange": "blockChanged",
		"newworld": "newWorld",
		self.client.var_undolist = []
		self.client.var_redolist = []
	def blockChanged(self, x, y, z, block, selected_block, fromloc):
		"Hook trigger for block changes."
		world = self.client.world
		originalblock = world.blockstore.raw_blocks[world.blockstore.get_offset(x, y, z)]
		block = chr(block)
		if len(self.client.var_undolist) < maxundos:
			self.client.var_undolist.insert(0,((x,y,z),block,originalblock))
		else:
			del self.client.var_undolist[-1]
			self.client.var_undolist.insert(0,((x,y,z),block,originalblock))

	def newWorld(self, world):
		"Hook to reset undolist in new worlds."
		self.client.var_undolist = []

	def posChanged(self, x, y, z, h, p):
		"Hook trigger for when the player moves"
		spectators = set()
		for uid in self.client.factory.clients:
			user = self.client.factory.clients[uid]
			try:
				if user.spectating == self.client.id:
					if user.x != x and user.y != y and user.z != z:
						user.teleportTo(x >> 5, y >> 5, z >> 5, h, p)
			except AttributeError:
				pass
	def playerMoved(self, x, y, z, h, p):
		"Stops transmission of player positions if hide is on."
		if self.hidden:
			return False

	@player_list
	@mod_only
	@username_command
	def commandKick(self, user, fromloc, overriderank, params=[]):
		"/kick username [reason] - Mod\nKicks the Player off the server."
		if params:
			user.sendError("Kicked: %s" % " ".join(params))
			self.client.sendServerMessage("They were just kicked.")
		else:
			user.sendError("You got Kicked.")
			self.client.sendServerMessage("They were just kicked.")

	@player_list
	@admin_only
	@only_username_command
	def commandBanBoth(self, username, fromloc, overriderank, params=[]):
		"/banb username reason - Admin\nName and IP ban a Player from this server."
		if not params:
			self.client.sendServerMessage("Please give a reason.")
		else:
			if username in self.client.factory.usernames:
				self.commandIpban(["/banb",username] + params, fromloc, overriderank)
			self.commandBan(["/banb",username] + params, fromloc, overriderank)

	@player_list
	@admin_only
	@only_username_command
	def commandBan(self, username, fromloc, overriderank, params=[]):
		"/ban username reason - Admin\nBans the Player from this server."
		if self.client.factory.isBanned(username):
			self.client.sendServerMessage("%s is already Banned." % username)
		else:
			if not params:
				self.client.sendServerMessage("Please give a reason.")
			else:
				self.client.factory.addBan(username, " ".join(params))
				if username in self.client.factory.usernames:
					self.client.factory.usernames[username].sendError("You got Banned!")
				self.client.sendServerMessage("%s has been Banned." % username)

	@player_list
	@director_only
	@only_username_command
	def commandIpban(self, username, fromloc, overriderank, params=[]):
		"/ipban username reason - Director\nBan a Player's IP from this server."
		ip = self.client.factory.usernames[username].transport.getPeer().host
		if self.client.factory.isIpBanned(ip):
			self.client.sendServerMessage("%s is already IPBanned." % ip)
		else:
			if not params:
				self.client.sendServerMessage("Please give a reason.")
			else:
				self.client.factory.addIpBan(ip, " ".join(params))
				if username in self.client.factory.usernames:
					self.client.factory.usernames[username].sendError("You got Banned!")
				self.client.sendServerMessage("%s has been IPBanned." % ip)

	@player_list
	@admin_only
	@only_username_command
	def commandUnban(self, username, fromloc, overriderank):
		"/unban username - Admin\nRemoves the Ban on the Player."
		if not self.client.factory.isBanned(username):
			self.client.sendServerMessage("%s is not Banned." % username)
		else:
			self.client.factory.removeBan(username)
			self.client.sendServerMessage("%s was UnBanned." % username)

	@player_list
	@director_only
	@only_string_command("IP")
	def commandUnipban(self, ip, fromloc, overriderank):
		"/unipban ip - Director\nRemoves the Ban on the IP."
		if not self.client.factory.isIpBanned(ip):
			self.client.sendServerMessage("%s is not Banned." % ip)
		else:
			self.client.factory.removeIpBan(ip)
			self.client.sendServerMessage("%s UnBanned." % ip)

	@player_list
	@admin_only
	@only_username_command
	def commandReason(self, username, fromloc, overriderank):
		"/banreason username - Admin\nGives the reason a Player was Banned."
		if not self.client.factory.isBanned(username):
			self.client.sendServerMessage("%s is not Banned." % username)
		else:
			self.client.sendServerMessage("Reason: %s" % self.client.factory.banReason(username))

	@player_list
	@director_only
	@only_string_command("IP")
	def commandIpreason(self, ip, fromloc, overriderank):
		"/ipreason username - Director\nGives the reason an IP was Banned."
		if not self.client.factory.isIpBanned(ip):
			self.client.sendServerMessage("%s is not Banned." % ip)
		else:
			self.client.sendServerMessage("Reason: %s" % self.client.factory.ipBanReason(ip))

	@player_list
	@mod_only
	def commandUnFreeze(self, parts, fromloc, overriderank):
		"/unfreeze playername - Mod\nAliases: defreeze, unstop\nUnfreezes the player, allowing them to move again."
		try:
			username = parts[1]
		except:
			self.client.sendServerMessage("No player name given.")
			return
		try:
			user = self.client.factory.usernames[username]
		except:
			self.client.sendServerMessage("Player is not online.")
			return
		user.frozen = False
		user.sendNormalMessage("&4You have been unfrozen by %s!" % self.client.username)

	@player_list
	@mod_only
	def commandFreeze(self, parts, fromloc, overriderank):
		"/freeze playername - Mod\nAliases: stop\nFreezes the player, preventing them from moving."
		try:
			username = parts[1]
		except:
			self.client.sendServerMessage("No player name given.")
			return
		try:
			user = self.client.factory.usernames[username]
		except:
			self.client.sendServerMessage("Player is not online.")
			return
		user.frozen = True
		user.sendNormalMessage("&4You have been frozen by %s!" % self.client.username)

	#@player_list
	#@mod_only
	#@only_username_command
	#def commandIpSpec(self, username, fromloc, overriderank):
	#	"/ipspec playername - Mod\nAliases: ipshun\nIPSpec a Player's IP in this server."
	#	ip = self.client.factory.usernames[username].transport.getPeer().host
	#	if self.client.factory.isIpShunned(ip):
	#		self.client.sendServerMessage("%s is already IPSpecced." % ip)
	#	else:
	#		self.client.factory.addIpShun(ip)
	#		if username in self.client.factory.usernames:
	#			self.client.factory.usernames[username].sendServerMessage("You got IPSpecced!")
	#		self.client.sendServerMessage("%s has been IPSpecced." % ip)
	#		logging.log(logging.INFO,self.client.username + ' IPSpecced ' + username + ip)

	#@player_list
	#@mod_only
	#@only_string_command("IP")
	#def commandUnIpSpec(self, ip, fromloc, overriderank):
	#	"/unipspec ip - Mod\nAliases: unipshun\nRemoves the IPSpec on the IP."
	#	if not self.client.factory.isIpShunned(ip):
	#		self.client.sendServerMessage("%s is not IPSpecced." % ip)
	#	else:
	#		self.client.factory.removeIpShun(ip)
	#		self.client.sendServerMessage("%s UnIPSpecced." % ip)
	#		logging.log(logging.INFO,self.client.username + ' UnIPSpecced ' + ip)


	def chatmsg(self, message):
		if self.client.var_fetchrequest:
			self.client.var_fetchrequest = False
			if message in ["y"]:
				sender,world,rx,ry,rz = self.client.var_fetchdata
				if self.client.world == world:
					self.client.teleportTo(rx, ry, rz)
				else:
					self.client.changeToWorld(world.id, position=(rx, ry, rz))
				sender.sendServerMessage("%s has accepted your fetch request." % self.client.username)
			else:
				sender = self.client.var_fetchdata[0]
				sender.sendServerMessage("%s did not accept your request." % self.client.username)
			self.client.var_fetchdata
			return True

	@op_only
	@username_command
	def commandBanish(self, user, fromloc, overriderank):
		"/worldkick username - Op\nAliases: banish\nBanishes the Player to the default world."
		if user.world == self.client.world:
			user.sendServerMessage("You were WorldKicked from '%s'." % self.client.world.id)
			user.changeToWorld("main")
			self.client.sendServerMessage("Player %s got WorldKicked." % user.username)
		else:
			self.client.sendServerMessage("Your Player is in another world!")

	@player_list
	@op_only
	@only_username_command
	def commandWorldBan(self, username, fromloc, overriderank):
		"/worldban username - Op\nWorldBan a Player from this Map."
		if self.client.world.isWorldBanned(username):
			self.client.sendServerMessage("%s is already WorldBanned." % username)
		else:
			self.client.world.add_worldban(username)
			if username in self.client.factory.usernames:
				if self.client.factory.usernames[username].world == self.client.world:
					self.client.factory.usernames[username].changeToWorld("main")
					self.client.factory.usernames[username].sendServerMessage("You got WorldBanned!")
			self.client.sendServerMessage("%s has been WorldBanned." % username)

	@player_list
	@op_only
	@only_username_command
	def commandUnWorldBan(self, username, fromloc, overriderank):
		"/unworldban username - Op\nAliases: deworldban\nRemoves the WorldBan on the Player."
		if not self.client.world.isWorldBanned(username):
			self.client.sendServerMessage("%s is not WorldBanned." % username)
		else:
			self.client.world.delete_worldban(username)
			self.client.sendServerMessage("%s was UnWorldBanned." % username)

	def commandUndo(self, parts, fromloc, overriderank):
		"/undo numchanges [username] - Guest\nUndoes yours or other people's changes (If Mod+)"
		world = self.client.world
		if len(parts) == 3:
			if not self.client.isMod():
				self.client.sendServerMessage("You are not a Mod+")
				return
			try:
				username = parts[2].lower()
				user = self.client.factory.usernames[username]
			except:
				self.client.sendServerMessage("%s is not online." % parts[2])
				return
			var_sublist = user.var_undolist[:]
			undolistlength = len(user.var_undolist)
			if parts[1] == "all":
				def generate_changes():
					try:
						user = self.client.factory.usernames[username]
						for index in range(undolistlength):
							originalblock = user.var_undolist[index][2]
							block = user.var_undolist[index][1]
							i,j,k = user.var_undolist[index][0]
							if not self.client.AllowedToBuild(i,j,k) and overriderank==False:
								self.client.sendServerMessage("You do not have permission to build here.")
								return
							del var_sublist[var_sublist.index(((i,j,k),block,originalblock))]
							user.var_redolist.insert(0,((i,j,k),originalblock,block))
							try:
								world[i, j, k] = originalblock
							except AssertionError:
								self.client.sendServerMessage("Out of bounds undo error.")
								return
							user.queueTask(TASK_BLOCKSET, (i, j, k, originalblock), world=world)
							user.sendBlock(i, j, k, originalblock)
							yield
						user.var_undolist = var_sublist
					except:
						self.client.sendSplitServerMessage("The user seems to have logged off before the undo could finish.")
						return
			else:
				try:
					num = int(parts[1])
				except:
					self.client.sendServerMessage("The numchanges must be a number or 'all'.")
					return
				if num > undolistlength:
					self.client.sendServerMessage("They have not made that many changes.")
					return
				def generate_changes():
					try:
						for index in range(num):
							originalblock = user.var_undolist[index][2]
							block = user.var_undolist[index][1]
							i,j,k = user.var_undolist[index][0]
							if not self.client.AllowedToBuild(i,j,k) and overriderank==False:
								self.client.sendServerMessage("You do not have permission to build here.")
								return
							del var_sublist[var_sublist.index(((i,j,k),block,originalblock))]
							user.var_redolist.insert(0,((i,j,k),originalblock,block))
							try:
								world[i, j, k] = originalblock
							except AssertionError:
								self.client.sendServerMessage("Out of bounds undo error.")
								return
							user.queueTask(TASK_BLOCKSET, (i, j, k, originalblock), world=world)
							user.sendBlock(i, j, k, originalblock)
							yield
						user.var_undolist = var_sublist
					except:
						self.client.sendSplitServerMessage("The user seems to have logged off before the undo could finish.")
						return
		else:
			self.client.sublist = self.client.var_undolist[:]
			undolistlength = len(self.client.var_undolist)
			if len(parts) == 1:
				self.client.sendSplitServerMessage("Please specify a number of changes to undo or 'all' (and if you are Mod+ you can specify a username)")
				return
			else:
				if parts[1] == "all":
					def generate_changes():
						for index in range(undolistlength):
							originalblock = self.client.var_undolist[index][2]
							block = self.client.var_undolist[index][1]
							i,j,k = self.client.var_undolist[index][0]
							if not self.client.AllowedToBuild(i,j,k) and overriderank==False:
								self.client.sendServerMessage("You no longer have permission to build here.")
								return
							del self.client.sublist[self.client.sublist.index(((i,j,k),block,originalblock))]
							self.client.var_redolist.insert(0,((i,j,k),originalblock,block))
							try:
								world[i, j, k] = originalblock
							except AssertionError:
								self.client.sendServerMessage("Out of bounds undo error.")
								return
							self.client.queueTask(TASK_BLOCKSET, (i, j, k, originalblock), world=world)
							self.client.sendBlock(i, j, k, originalblock)
							yield
						self.client.var_undolist = self.client.sublist
				else:
					try:
						num = int(parts[1])
					except:
						self.client.sendServerMessage("The numchanges must be a number or 'all'.")
						return
					if num > undolistlength:
						self.client.sendServerMessage("You have not made that many changes.")
						return
					def generate_changes():
						for index in range(num):
							originalblock = self.client.var_undolist[index][2]
							block = self.client.var_undolist[index][1]
							i,j,k = self.client.var_undolist[index][0]
							if not self.client.AllowedToBuild(i,j,k) and overriderank==False:
								self.client.sendServerMessage("You no longer have permission to build here.")
								return
							del self.client.sublist[self.client.sublist.index(((i,j,k),block,originalblock))]
							self.client.var_redolist.insert(0,((i,j,k),originalblock,block))
							try:
								world[i, j, k] = originalblock
							except AssertionError:
								self.client.sendServerMessage("Out of bounds undo error.")
								return
							self.client.queueTask(TASK_BLOCKSET, (i, j, k, originalblock), world=world)
							self.client.sendBlock(i, j, k, originalblock)
							self.client.total += 1
							yield
						self.client.var_undolist = self.client.sublist
		# Now, set up a loop delayed by the reactor
		block_iter = iter(generate_changes())
		def do_step():
			# Do 10 blocks
			try:
				for x in range(10):#10 blocks at a time, 10 blocks per tenths of a second, 100 blocks a second
					block_iter.next()
				reactor.callLater(0.01, do_step)  #This is how long(in seconds) it waits to run another 10 blocks
			except StopIteration:
				if fromloc == 'user':
					self.client.finalizeMassCMD('undo', self.client.total)
					self.client.total = 0
				pass
		do_step()

	@build_list
	def commandRedo(self, parts, fromloc, overriderank):
		"/redo numchanges [username] - Guest\nRedoes yours or other people's changes (If Mod+)"
		world = self.client.world
		if len(parts) == 3:
			if not self.client.isMod():
				self.client.sendServerMessage("You are not a Mod+")
				return
			try:
				username = parts[2].lower()
				user = self.client.factory.usernames[username]
			except:
				self.client.sendServerMessage("%s is not online." % parts[2])
				return
			var_sublist = user.var_redolist[:]
			redolistlength = len(user.var_redolist)
			if parts[1] == "all":
				def generate_changes():
					try:
						user = self.client.factory.usernames[username]
						for index in range(redolistlength):
							originalblock = user.var_redolist[index][2]
							block = user.var_redolist[index][1]
							i,j,k = user.var_redolist[index][0]
							if not self.client.AllowedToBuild(i,j,k) and overriderank==False:
								self.client.sendServerMessage("You do not have permission to build here.")
								return
							del var_sublist[var_sublist.index(((i,j,k),block,originalblock))]
							user.var_undolist.insert(0,((i,j,k),originalblock,block))
							try:
								world[i, j, k] = originalblock
							except AssertionError:
								self.client.sendServerMessage("Out of bounds redo error.")
								return
							user.queueTask(TASK_BLOCKSET, (i, j, k, originalblock), world=world)
							user.sendBlock(i, j, k, originalblock)
							self.client.total += 1 # This is how you increase a number in python.... - Stacy
							yield
						user.var_redolist = var_sublist
					except:
						self.client.sendSplitServerMessage("The user seems to have logged off before the redo could finish.")
						return
			else:
				try:
					num = int(parts[1])
				except:
					self.client.sendServerMessage("The numchanges must be a number or 'all'.")
					return
				if num > redolistlength:
					self.client.sendServerMessage("They have not made that many undos.")
					return
				def generate_changes():
					try:
						for index in range(num):
							originalblock = user.var_redolist[index][2]
							block = user.var_redolist[index][1]
							i,j,k = user.var_redolist[index][0]
							if not self.client.AllowedToBuild(i,j,k) and overriderank==False:
								self.client.sendServerMessage("You do not have permission to build here.")
								return
							del var_sublist[var_sublist.index(((i,j,k),block,originalblock))]
							user.var_undolist.insert(0,((i,j,k),originalblock,block))
							try:
								world[i, j, k] = originalblock
							except AssertionError:
								self.client.sendServerMessage("Out of bounds redo error.")
								return
							user.queueTask(TASK_BLOCKSET, (i, j, k, originalblock), world=world)
							user.sendBlock(i, j, k, originalblock)
							self.client.total += 1 # This is how you increase a number in python.... - Stacy
							yield
						user.var_redolist = var_sublist
					except:
						self.client.sendSplitServerMessage("The user seems to have logged off before the redo could finish.")
						return
		else:
			self.client.sublist = self.client.var_redolist[:]
			redolistlength = len(self.client.var_redolist)
			if len(parts) == 1:
				self.client.sendSplitServerMessage("Please specify a number of changes to redo or 'all' (and if you are Mod+ you can specify a username)")
				return
			else:
				if parts[1] == "all":
					def generate_changes():
						for index in range(redolistlength):
							originalblock = self.client.var_redolist[index][2]
							block = self.client.var_redolist[index][1]
							i,j,k = self.client.var_redolist[index][0]
							if not self.client.AllowedToBuild(i,j,k) and overriderank==False:
								self.client.sendServerMessage("You no longer have permission to build here.")
								return
							del self.client.sublist[self.client.sublist.index(((i,j,k),block,originalblock))]
							self.client.var_undolist.insert(0,((i,j,k),originalblock,block))
							try:
								world[i, j, k] = originalblock
							except AssertionError:
								self.client.sendServerMessage("Out of bounds redo error.")
								return
							self.client.queueTask(TASK_BLOCKSET, (i, j, k, originalblock), world=world)
							self.client.sendBlock(i, j, k, originalblock)
							self.client.total += 1 # This is how you increase a number in python.... - Stacy
							yield
						self.client.var_redolist = self.client.sublist
				else:
					try:
						num = int(parts[1])
					except:
						self.client.sendServerMessage("The numchanges must be a number or 'all'.")
						return
					if num > redolistlength:
						self.client.sendServerMessage("You have not made that many undos.")
						return
					def generate_changes():
						for index in range(num):
							originalblock = self.client.var_redolist[index][2]
							block = self.client.var_redolist[index][1]
							i,j,k = self.client.var_redolist[index][0]
							if not self.client.AllowedToBuild(i,j,k) and overriderank==False:
								self.client.sendServerMessage("You no longer have permission to build here.")
								return
							del self.client.sublist[self.client.sublist.index(((i,j,k),block,originalblock))]
							self.client.var_undolist.insert(0,((i,j,k),originalblock,block))
							try:
								world[i, j, k] = originalblock
							except AssertionError:
								self.client.sendServerMessage("Out of bounds redo error.")
								return
							self.client.queueTask(TASK_BLOCKSET, (i, j, k, originalblock), world=world)
							self.client.sendBlock(i, j, k, originalblock)
							self.client.total += 1 # This is how you increase a number in python.... - Stacy
							yield
						self.client.var_redolist = self.client.sublist
		# Now, set up a loop delayed by the reactor
		block_iter = iter(generate_changes())
		def do_step():
			# Do 10 blocks
			try:
				for x in range(10):#10 blocks at a time, 10 blocks per tenths of a second, 100 blocks a second
					block_iter.next()
				reactor.callLater(0.01, do_step)  #This is how long(in seconds) it waits to run another 10 blocks
			except StopIteration:
				if fromloc == 'user':
					self.client.finalizeMassCMD('redo', self.client.total)
					self.client.total = 0
				pass
		do_step()

	@op_only
	@username_command
	def commandSpectate(self, user, fromloc, overriderank):
		"/spectate username - Guest\nAliases: follow, watch\nFollows specified player around"
		nospec_check = True
		try:
			self.client.spectating
		except AttributeError:
			nospec_check = False
		if not nospec_check or self.client.spectating != user.id:
			self.client.sendServerMessage("You are now spectating %s" % user.username)
			self.client.spectating = user.id
		else:
			self.client.sendServerMessage("You are no longer spectating %s" % user.username)
			self.client.spectating = False

	@mod_only
	@only_username_command
	def commandSilence(self, username, fromloc, overriderank):
		"/silence username - Mod\nDisallows the Player to talk."
		if self.client.factory.usernames[username].isMod():
			self.client.sendServerMessage("You cannot silence staff!")
			return
		self.client.factory.silenced.add(username)
		self.client.sendServerMessage("%s is now Silenced." % username)

	@player_list
	@mod_only
	@only_username_command
	def commandDesilence(self, username, fromloc, overriderank):
		"/desilence username - Mod\nAliases: unsilence\nAllows the Player to talk."
		if self.client.factory.isSilenced(username):
			self.client.factory.silenced.remove(username)
			self.client.sendServerMessage("%s is no longer Silenced." % username.lower())
		else:
			self.client.sendServerMessage("User specified is not silenced.")

	@player_list
	@op_only
	def commandHide(self, params, fromloc, overriderank):
		"/hide - Op\nAliases: cloak\nHides you so no other players can see you. Toggle."
		if not self.hidden:
			self.client.sendServerMessage("You have vanished.")
			self.hidden = True
			# Send the "player has disconnected" command to people
			self.client.queueTask(TASK_PLAYERLEAVE, [self.client.id])
		else:
			self.client.sendServerMessage("That was Magic!")
			self.hidden = False
			#Imagine that! They've mysteriously appeared.
			self.client.queueTask(TASK_NEWPLAYER, [self.client.id, self.client.username, self.client.x, self.client.y, self.client.z, self.client.h, self.client.p])
			#self.client.queueTask(TASK_PLAYERCONNECT, [self.client.id, self.client.username, self.client.x, self.client.y, self.client.z, self.client.h, self.client.p])

	@mod_only
	def commandBlazer(self, parts, fromloc, overriderank):
		"/blazer - Mod\nBlazer!"
		for i in range(10):
			self.client.sendServerMessage("SPAM!")

	@player_list
	@admin_only
	@username_command
	def commandOverload(self, client, fromloc, overriderank):
		"/overload username - Admin\nSends the players client a massive fake map."
		client.sendOverload()
		self.client.sendServerMessage("Overload sent to %s" % client.username)

	#@player_list
	#@mod_only
	#@username_command
	#def commandSend(self, client, fromloc, overriderank):
		#"/send username [world] - Mod\nSends the players client another world."
		#if user.isMod():
			#self.client.sendServerMessage("You cannot send Staff!")
		#if len(parts) == 2:
			#self.client.sendServerMessage("Please specify a world ID.")
		#else:
			#world_id = parts[2]
			#user.changeToWorld("%s" % world_id)
			#else:
				#user.sendServerMessage("You were sent to '%s'." % self.client.world.id)
				#user.changeToWorld("default")
				#self.client.sendServerMessage("Player %s was sent." % user.username)
		#else:
			#self.client.sendServerMessage("Your Player is in another world!")