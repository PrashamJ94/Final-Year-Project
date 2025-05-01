
from collections import OrderedDict

class AlreadySelectedException(Exception):
    pass

class OptionGroup:

    def __init__(self):
        self.optionMap = OrderedDict()
        self.selected = None
        self.required = False

    def addOption(self, option):
        self.optionMap[option.getKey()] = option
        return self

    def getNames(self):
        return self.optionMap.keys()

    def getOptions(self):
        return self.optionMap.values()

    def getSelected(self):
        return self.selected

    def isRequired(self):
        return self.required

    def setRequired(self, required):
        self.required = required

    def setSelected(self, option):
        if option is None:
            self.selected = None
            return

        if self.selected is not None and self.selected != option.getKey():
            raise AlreadySelectedException()

        self.selected = option.getKey()

    def __str__(self):
        buff = []

        for option in self.getOptions():
            if option.getOpt() is not None:
                buff.append('-')
                buff.append(str(option.getOpt()))
            else:
                buff.append('--')
                buff.append(str(option.getLongOpt()))

            if option.getDescription() is not None:
                buff.append(' ')
                buff.append(str(option.getDescription()))

            buff.append(', ')

        buff = buff[:-1]  # remove trailing comma
        return '[' + ''.join(buff) + ']'


