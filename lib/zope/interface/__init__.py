##############################################################################
#
# Copyright (c) 2001, 2002 Zope Foundation and Contributors.
# All Rights Reserved.
#
# This software is subject to the provisions of the Zope Public License,
# Version 2.1 (ZPL).  A copy of the ZPL should accompany this distribution.
# THIS SOFTWARE IS PROVIDED "AS IS" AND ANY AND ALL EXPRESS OR IMPLIED
# WARRANTIES ARE DISCLAIMED, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
# WARRANTIES OF TITLE, MERCHANTABILITY, AGAINST INFRINGEMENT, AND FITNESS
# FOR A PARTICULAR PURPOSE.
#
##############################################################################
"""Interfaces

This package implements the Python "scarecrow" proposal.

The package exports two objects, `Interface` and `Attribute` directly. It also
exports several helper methods. Interface is used to create an interface with
a class statement, as in:

  class IMyInterface(Interface):
	'''Interface documentation
	'''

	def meth(arg1, arg2):
		'''Documentation for meth
		'''

	# Note that there is no self argument

To find out what you can do with interfaces, see the interface
interface, `IInterface` in the `interfaces` module.

The package has several public modules:

  o `declarations` provides utilities to declare interfaces on objects. It
	also provides a wide range of helpful utilities that aid in managing
	declared interfaces. Most of its public names are however imported here.

  o `document` has a utility for documenting an interface as structured text.

  o `exceptions` has the interface-defined exceptions

  o `interfaces` contains a list of all public interfaces for this package.

  o `verify` has utilities for verifying implementations of interfaces.

See the module doc strings for more information.

$Id: __init__.py 110699 2010-04-09 08:16:17Z regebro $
"""
__docformat__ = 'restructuredtext'

from lib.zope.interface.interface import Interface, _wire

# Need to actually get the interface elements to implement the right interfaces
_wire()
del _wire

from lib.zope.interface.interface import Attribute, invariant, taggedValue

from lib.zope.interface.declarations import providedBy, implementedBy
from lib.zope.interface.declarations import classImplements, classImplementsOnly
from lib.zope.interface.declarations import directlyProvidedBy, directlyProvides
from lib.zope.interface.declarations import alsoProvides, provider
from lib.zope.interface.declarations import implementer, implementer_only
from lib.zope.interface.declarations import implements, implementsOnly
from lib.zope.interface.declarations import classProvides, moduleProvides
from lib.zope.interface.declarations import noLongerProvides, Declaration
from lib.zope.interface.exceptions import Invalid

# The following are to make spec pickles cleaner
from lib.zope.interface.declarations import Provides


from lib.zope.interface.interfaces import IInterfaceDeclaration

moduleProvides(IInterfaceDeclaration)

__all__ = ('Interface', 'Attribute') + tuple(IInterfaceDeclaration)
