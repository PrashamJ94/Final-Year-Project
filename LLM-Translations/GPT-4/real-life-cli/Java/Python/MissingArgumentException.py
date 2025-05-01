class MissingArgumentException(Exception):
    def __init__(self, option=None, message=None):
        if option is not None:
            super().__init__("Missing argument for option: " + option.getKey())
            self.option = option
        elif message is not None:
            super().__init__(message)
    
    def getOption(self):
        return self.option


