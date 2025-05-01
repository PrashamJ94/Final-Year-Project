
from typing import List

class GnuParser(Parser):

    def flatten(self, options, arguments, stopAtNonOption):
        tokens = []

        eatTheRest = False

        for i in range(len(arguments)):
            arg = arguments[i]

            if arg == "--":
                eatTheRest = True
                tokens.append("--")
            elif arg == "-":
                tokens.append("-")
            elif arg.startswith("-"):
                opt = Util.stripLeadingHyphens(arg)

                if options.hasOption(opt):
                    tokens.append(arg)
                elif '=' in opt and options.hasOption(opt[0:opt.index('=')]):

                    tokens.append(arg[0:arg.index('=')])
                    tokens.append(arg[arg.index('=') + 1:])
                elif options.hasOption(arg[0:2]):

                    tokens.append(arg[0:2])
                    tokens.append(arg[2:])
                else:
                    eatTheRest = stopAtNonOption
                    tokens.append(arg)
            else:
                tokens.append(arg)

            if eatTheRest:
                for i in range(i+1, len(arguments)):
                    tokens.append(arguments[i])

        return tokens

#End of Code

