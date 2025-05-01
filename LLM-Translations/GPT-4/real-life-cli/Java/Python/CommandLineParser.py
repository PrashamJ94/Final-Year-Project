class CommandLineParser:
    def parse(self, options, arguments):
        raise NotImplementedError('Subclasses must override parse method to provide functionality')

    def parse(self, options, arguments, stopAtNonOption):
        raise NotImplementedError('Subclasses must override parse method to provide functionality')


