#! /usr/bin/env python
#-*- coding: utf-8 -*-

import random

def g( total, seed ):
	o = []
	for i in xrange( total ):
		tmp = long( 0.5 + random.random() * 2.5 * seed );
		while tmp == 0L:
			tmp = long( 0.5 + random.random() * 2.5 * seed );
		o.append( tmp )
	return o

def h():
	total = random.randint( 14, 18 )
	seed = long( random.random() * 100 )
	while seed == 0L:
		seed = long( random.random() * 100 )
	o = g( total, seed )
	limit = total * seed
	return limit, o

print 16
for i in xrange( 16 ):
	limit, o = h()
	print '{0} {1}'.format( limit, len( o ) )
	print ' '.join( map( lambda x: str( x ), o ) )
