#!/usr/bin/env python

###############################################################################################
# NAME:		R2D2 agent                                                                    #
# DESC:		Host based monitoring agent. Allows monitoring of such resources as:          #
#                                                                                             #
# AUTHOR:	A. Janusz <aleksander.janusz At fis.agh.edu.pl> 	                      #
# DATE:		2012.03.29                                                                    #
# VERSION:	1.0                                                                           #
###############################################################################################

import sys
import random
#import ConfigParser
from optparse import OptionParser

parser = OptionParser()
help = "IP address of local index"
parser.add_option("-i", "--index", dest="index_ip", default="127.0.0.1", help=help)
help = "TCP port of local index"
parser.add_option("-p", "--port", dest="index_port", default="5488", help=help)
help = "Common, human readable name for this monitor, eg. 'monitor-krystyny'"
parser.add_option("-n", "--name", dest="monitor_name", default="", help=help)

(options, args) = parser.parse_args()

#config = ConfigParser.ConfigParser()
#config.read("config.ini")

#----------------------------------------------------------------------------------------------

import socket
import logging
from time import sleep, localtime, strftime
logging.basicConfig(filename="application.log", level=logging.DEBUG, \
                        format="%(asctime)s:%(levelname)s:%(module)sf:%(funcName)s:%(message)s")


def main():
    logging.info("------------[ CUT HERE ]------------")

    a = agent( options.monitor_name, options.index_ip, options.index_port )
    a.start_connection()

    while 1: 
        a.send_data()
        sleep(2.0)

################
# CLASS: agent #
################
class agent:
    def __init__( self, name, index_ip, index_port ):
        '''Constructor - initializes object'''
        logging.info( "Creating monitor '%s' ..." % name )

        self.sock = None
        self.set_index_ip( index_ip )
        self.set_index_port( index_port )
        self.max_connection_retries = 5
        self.name = name

    def start_connection( self ):
        '''Starts outgoing TCP connection to local index. If unable to connect, retries few times.'''
        logging.info( "Connecting to %s:%d ..." % ( self.index_ip, self.index_port ) )

        #self.finish_connection()
        self.sock = None
        retries_count = self.max_connection_retries

        while self.sock is None and retries_count > 0:
            try:
                self.sock = socket.socket( socket.AF_INET, socket.SOCK_STREAM )
                self.sock.connect( ( self.index_ip, self.index_port ) )
                return True
            except Exception, e:
                logging.error( "Connection failed: %s, retries: %s" % (e, retries_count) )
                self.sock = None
                retries_count = retries_count - 1
                sleep(5.0)
        logging.error( "Connection failed: max retries exceeded." )
        raise Exception("Connection failed: could not connect to %s:%d" % (self.index_ip, self.index_port) )
            

    def finish_connection( self ):
        '''Close outgoing TCP connection to local index.'''
        logging.info( "Closing connection." )
        if self.sock is not None: 
            try: self.sock.close()
            except Exception,e: pass

    def set_index_ip( self, ip ):
        self.index_ip = ip

    def set_index_port( self, port ):
        self.index_port = int(port)

    def send_data( self ):
        '''Sends data to local index. If sending fails - try to reconnect.'''
        if self.sock is not None:
            logging.debug( "Sending data:" )
            try:
#                self._send( "The time is: %s\n" % strftime("%Y-%m-%d (%H:%M:%S)") )
                randItem = random.randrange(1,3)
                self._send("\
                <Monitor name='local_mchine_192.168.241.56'>\
                <Atrybute type='Static' name='MEM-Count' value='"+str(randItem)+"GB'/>\
                <Atrybute type='Static' name='CPU-Frequency' value='2.0GHz'/>\
                <Atrybute type='Static' name='OS-Name' value='Debian 6 (Squeeze)'/>\
                </Monitor>")
            except Exception, e:
                logging.error( "Unable to send data: %s" % e )
                self.start_connection()
                
        else:
            logging.warning( "Not sending data: connection closed." )

    def _send( self, data ): 
        self.sock.send( data )
        

# --------------------------------
if __name__ == "__main__": main()
