import datetime
import traceback
from lib.twisted.words.protocols import MSN
from lib.twisted.internet import protocol
import logging
from constants import *
from globals import *
from blockbox.plugins import protocol_plugins
from blockbox.decorators import *

"""
THIS IS A NEWLY PLANNED IDEA. NOTHING HAS BEEN DONE YET!

A brand new idea. MSN client.

Users get an new account for the bot on Windows Live, when server starts up the MSN bot will connect.
Specify the owner's MSN account, and the bot will try to add him. If owner sent a request to add the bot, the bot will accept (at this point it ignores others)
The owner can send a Shake (idk what's the name) which is equal to a /cmdlist.
The owner can send commands. He can also make the MSN client return chatlogs or even console logs.
The owner can save maps to the server and boot it, thanks to the file transfer feature in MSN.

So... these are the currently planned features. 
-tyteen
"""