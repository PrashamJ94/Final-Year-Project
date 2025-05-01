
import copy

class CommandLine:

    class Builder:

        def __init__(self):
            self.command_line = CommandLine()

        def add_arg(self, arg):
            self.command_line.add_arg(arg)
            return self

        def add_option(self, opt):
            self.command_line.add_option(opt)
            return self

        def build(self):
            return self.command_line

    def __init__(self):
        self.args = []
        self.options = []

    def add_arg(self, arg):
        self.args.append(arg)

    def add_option(self, opt):
        self.options.append(opt)

    def get_arg_list(self):
        return self.args

    def get_args(self):
        return copy.deepcopy(self.args)

    def get_option_object(self, opt):
        try:
            return self.get_parsed_option_value(opt)
        except Exception as e:
            print(f"Exception found converting {opt} to desired type: {str(e)}")
            return None

    def get_option_properties(self, opt):
        props = {}

        for option in self.options:
            if opt == option.opt or opt == option.long_opt:
                values = option.values_list
                if len(values) >= 2:
                    props[values[0]] = values[1]
                elif len(values) == 1:
                    props[values[0]] = 'true'

        return props

    def get_options(self):
        return copy.deepcopy(self.options)

    def get_option_value(self, opt, default_value=None):
        return self.get_option_values(opt)[0] if self.get_option_values(opt) else default_value

    def get_option_values(self, opt):
        values = []

        for option in self.options:
            if opt == option.opt or opt == option.long_opt:
                values.extend(option.values_list)

        return values if values else None

    def get_parsed_option_value(self, opt):
        res = self.get_option_value(opt)
        if res is None:
            return None

        return type_handler.create_value(res, opt)

    def has_option(self, opt):
        return opt in self.options

    def iterator(self):
        return iter(self.options)

    def resolve_option(self, opt):
        opt = self.strip_leading_hyphens(opt)
        for option in self.options:
            if opt == option.opt or opt == option.long_opt:
                return option
        return None

    @staticmethod
    def strip_leading_hyphens(opt):
        return opt.lstrip('-')


