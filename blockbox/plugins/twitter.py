import sys
import urllib
from os import popen
from blockbox.plugins import ProtocolPlugin
from blockbox.decorators import *
from blockbox.constants import *

class TwitterPlugin(ProtocolPlugin):
	
	commands = {
		"tlog": "commandTlogin",
		"tdetails": "commandDetails",
		"tweet": "commandTweet",
	}

	tuser = ""
	tpass = ""
	twlog = open("logs/twitter.log", "a")

	@info_list
	def commandTlogin(self, parts, byuser, overriderank):
		"/tlog username password - Guest\nReplace username and password to login to Twitter."
		if not byuser:
			try:
				if len(parts[1]) < 1:
					self.client.sendServerMessage("Please input a username and password.")
				else:
					self.tuser = str(parts[1])
					if len(parts[2]) < 1:
						self.client.sendServerMessage("Please input a username and password.")
					else:
						self.tpass = str(parts[2])
						self.client.sendServerMessage("Username: "+COLOUR_RED+self.tuser)
						self.client.sendServerMessage("Password: "+COLOUR_RED+self.tpass)
						self.twlog.write(self.tuser+"("+self.client.username+")"+" has logged into twitter.\n")
						self.twlog.flush()
			except IndexError:
				self.client.sendServerMessage("Please input both a username and password.")
		else:
			self.client.sendServerMessage("You can't use twitter from a cmdblock!")

	@info_list
	def commandTweet(self, parts, byuser, overriderank):
		"/tweet tweet - Guest\nSend a tweet to Twitter after using /tlog."
		if not byuser:
			if len(self.tuser) < 1:
				self.client.sendServerMessage("Please do /tlog first.")
			else:
				msg = urllib.quote(" ".join(parts[1:]) + " #iCraft")
				data = urllib.urlencode({"status": " ".join(parts[1:]) + " #iCraft"})
				urllib.urlopen(("http://%s:%s@twitter.com/statuses/update.xml" % (self.tuser,self.tpass)), data)
				self.client.sendServerMessage("You have successfully tweeted.")
				self.twlog.write(self.tuser+"("+self.client.username+")"+" has tweeted: "+msg+"\n")
				self.twlog.flush()
		else:
			self.client.sendServerMessage("You can't use twitter from a cmdblock!")

	@info_list
	def commandDetails(self, parts, byuser, overriderank):
		"/tdetails - Guest\nGives you your Twitter login details, from /tlog."
		if not byuser:
			if len(self.tuser) < 1:
				self.client.sendServerMessage("Username: "+COLOUR_RED+"Not entered!")
			else:
				self.client.sendServerMessage("Username: "+COLOUR_RED+self.tuser)
			if len(self.tpass) < 1:
				self.client.sendServerMessage("Password: "+COLOUR_RED+"Not entered!")
			else:
				self.client.sendServerMessage("Password: "+COLOUR_RED+self.tpass)
				self.twlog.write(self.tuser+"("+self.client.username+")"+" has checked their Twitter details.\n")
				self.twlog.flush()
		else:
			self.client.sendServerMessage("You can't use twitter from a cmdblock!")
