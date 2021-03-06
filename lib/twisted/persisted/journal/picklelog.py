# Copyright (c) 2001-2004 Twisted Matrix Laboratories.
# See LICENSE for details.

# 
# -*- test-case-name: lib.twisted.test.test_journal -*-

"""Logging that uses pickles.

TODO: add log that logs to a file.
"""

# twisted imports
from lib.twisted.persisted import dirdbm
from lib.twisted.internet import defer
from lib.zope.interface import implements

# sibling imports
import base


class DirDBMLog:
	"""Log pickles to DirDBM directory."""

	implements(base.ICommandLog)

	def __init__(self, logPath):
		self.db = dirdbm.Shelf(logPath)
		indexs = map(int, self.db.keys())
		if indexs:
			self.currentIndex = max(indexs)
		else:
			self.currentIndex = 0
			
	def logCommand(self, command, time):
		"""Log a command."""
		self.currentIndex += 1
		self.db[str(self.currentIndex)] = (time, command)
		return defer.succeed(1)
	
	def getCurrentIndex(self):
		"""Return index of last command logged."""
		return self.currentIndex
	
	def getCommandsSince(self, index):
		result = []
		for i in range(index, self.currentIndex + 1):
			result.append(self.db[str(i)])
		return result
