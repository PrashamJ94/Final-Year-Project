class UnrecognizedOptionException(Exception):

    def __init__(self, message, option=None):
        super().__init__(message)
        self.option = option

    def getOption(self):
        return self.option


