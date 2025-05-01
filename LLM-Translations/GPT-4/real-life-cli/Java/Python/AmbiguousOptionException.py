class AmbiguousOptionException(Exception):
    def __init__(self, option, matchingOptions):
        message = self.createMessage(option, matchingOptions)
        super(AmbiguousOptionException, self).__init__(message)
        self.matchingOptions = matchingOptions

    @staticmethod
    def createMessage(option, matchingOptions):
        buf = "Ambiguous option: '" + option + "'  (could be: "
        for i, match in enumerate(matchingOptions):
            buf += "'" + match + "'"
            if i != len(matchingOptions) - 1:
                buf += ", "
        buf += ")"
        return buf

    def getMatchingOptions(self):
        return self.matchingOptions


