# Copyright (c) 2001-2004 Twisted Matrix Laboratories.
# See LICENSE for details.

#

from lib.twisted.words.protocols.irc import IRC
from lib.twisted.python import log
from lib.twisted.internet.protocol import Factory

class IRCUserInterface(IRC):
	def connectionLost(self):
		del self.factory.ircui

class IRCUIFactory(Factory):
	ircui = None
	def buildProtocol(self):
		if self.ircui:
			log.msg("already logged in")
			return None
		i = IRCUserInterface()
		i.factory = self
		self.ircui = i
		return i

