class MissingOptionException(Exception):
    
    def __init__(self, missingOptions):
        super().__init__(self.create_message(missingOptions))
        self.missingOptions = missingOptions

    @staticmethod
    def create_message(missingOptions):
        buf = "Missing required option"
        buf += "" if len(missingOptions) == 1 else "s"
        buf += ": "

        for i, option in enumerate(missingOptions):
            buf += str(option)
            if i < len(missingOptions) - 1:
                buf += ", "
        
        return buf

    def get_missing_options(self):
        return self.missingOptions


