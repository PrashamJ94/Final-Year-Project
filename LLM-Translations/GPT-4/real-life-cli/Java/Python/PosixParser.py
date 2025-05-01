
from typing import List

class PosixParser(Parser):
    def __init__(self):
        self.tokens = []
        self.eat_the_rest = False
        self.current_option = None
        self.options = None

    def burst_token(self, token, stop_at_non_option):
        for i in range(1, len(token)):
            ch = str(token[i])

            if not self.options.has_option(ch):
                if stop_at_non_option:
                    self.process_non_option_token(token[i:], True)
                else:
                    self.tokens.append(token)
                break
            self.tokens.append("-" + ch)
            self.current_option = self.options.get_option(ch)

            if self.current_option.has_arg() and len(token) != i + 1:
                self.tokens.append(token[i + 1:])
                break

    def flatten(self, options, arguments, stop_at_non_option):
        self.init()
        self.options = options

        for token in arguments:
            if token == "-" or token == "--":
                self.tokens.append(token)
            elif token.startswith("--"):
                pos = token.find('=')
                opt = token if pos == -1 else token[:pos] 

                matching_opts = options.get_matching_options(opt)

                if not matching_opts:
                    self.process_non_option_token(token, stop_at_non_option)
                elif len(matching_opts) > 1:
                    raise AmbiguousOptionException(opt, matching_opts)
                else:
                    self.current_option = options.get_option(matching_opts[0])
                    self.tokens.append("--" + self.current_option.get_long_opt())
                    if pos != -1:
                        self.tokens.append(token[pos + 1:])
            elif token.startswith("-"):
                if len(token) == 2 or options.has_option(token):
                    self.process_option_token(token, stop_at_non_option)
                elif options.get_matching_options(token):
                    matching_opts = options.get_matching_options(token)
                    if len(matching_opts) > 1:
                        raise AmbiguousOptionException(token, matching_opts)
                    opt = options.get_option(matching_opts[0])
                    self.process_option_token("-" + opt.get_long_opt(), stop_at_non_option)
                else:
                    self.burst_token(token, stop_at_non_option)
            else:
                self.process_non_option_token(token, stop_at_non_option)

            self.gobble(arguments)

        return self.tokens

    def gobble(self, arguments):
        if self.eat_the_rest:
            for arg in arguments:
                self.tokens.append(arg)

    def init(self):
        self.eat_the_rest = False
        self.tokens.clear()

    def process_non_option_token(self, value, stop_at_non_option):
        if stop_at_non_option and (self.current_option is None or not self.current_option.has_arg()):
            self.eat_the_rest = True
            self.tokens.append("--")

        self.tokens.append(value)

    def process_option_token(self, token, stop_at_non_option):
        if stop_at_non_option and not self.options.has_option(token):
            self.eat_the_rest = True

        if self.options.has_option(token):
            self.current_option = self.options.get_option(token)

        self.tokens.append(token)


