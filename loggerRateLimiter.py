class Logger(object):

    def __init__(self):
        self.message_timestamp = {}

    def shouldPrintMessage(self, timestamp, message):
        """
        :type timestamp: int
        :type message: str
        :rtype: bool
        """
        
        
        if message not  in self.message_timestamp :
            self.message_timestamp[message] = timestamp
            return True


        if timestamp - self.message_timestamp[message] >= 10:
            self.message_timestamp[message] = timestamp
            return True

        return False    
