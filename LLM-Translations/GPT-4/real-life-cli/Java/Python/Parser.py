
import copy
from collections import ABC

class Parser:

    cmd = None
    options = None
    required_options = None

    def check_required_options(self):
        if self.required_options:
            raise MissingOptionException(self.required_options)

    def flatten(self, opts, arguments, stop_at_non_option):
        raise NotImplementedError

    def get_options(self):
        return self.options

    def get_required_options(self):
        return self.required_options

    def parse(self, options, arguments, properties=None, stop_at_non_option=False):
        for opt in options.help_options():
            opt.clear_values()
        for group in options.get_option_groups():
            group.set_selected(None)
        self.options = options
        self.cmd = CommandLine()
        eat_the_rest = False
        arguments = arguments or []
        token_list = list(self.flatten(self.get_options(), arguments, stop_at_non_option))
        iterator = iter(token_list)
        for t in iterator:
            if t == '--':
                eat_the_rest = True
            elif t == '-':
                if stop_at_non_option:
                    eat_the_rest = True
                else:
                    self.cmd.add_arg(t)
            elif t.startswith('-'):
                if stop_at_non_option and not self.get_options().has_option(t):
                    eat_the_rest = True
                    self.cmd.add_arg(t)
                else:
                    self.process_option(t, iterator)
            else:
                self.cmd.add_arg(t)
                if stop_at_non_option:
                    eat_the_rest = True
            if eat_the_rest:
                for str_ in iterator:
                    if str_ != '--':
                        self.cmd.add_arg(str_)
        self.process_properties(properties)
        self.check_required_options()
        return self.cmd

    def process_args(self, opt, iter_):
        for str_ in iter_:
            if self.get_options().has_option(str_) and str_.startswith('-'):
                break
            try:
                opt.add_value_for_processing(Util.strip_leading_and_trailing_quotes(str_))
            except RuntimeError:
                break
        if opt.get_values() is None and not opt.has_optional_arg():
            raise MissingArgumentException(opt)

    def process_option(self, arg, iter_):
        if not self.get_options().has_option(arg):
            raise UnrecognizedOptionException(f"Unrecognized option: {arg}", arg)
        opt = copy.deepcopy(self.get_options().get_option(arg))
        self.update_required_options(opt)
        if opt.has_arg():
            self.process_args(opt, iter_)
        self.cmd.add_option(opt)

    def process_properties(self, properties):
        if properties is None:
            return
        for option in properties.property_names():
            opt = self.options.get_option(option)
            if opt is None:
                raise UnrecognizedOptionException("Default option wasn't defined", option)
            group = self.options.get_option_group(opt)
            selected = group is not None and group.get_selected() is not None
            if not self.cmd.has_option(option) and not selected:
                value = properties.get_property(option)
                if opt.has_arg():
                    if opt.get_values() is None or len(opt.get_values()) == 0:
                        try:
                            opt.add_value_for_processing(value)
                        except RuntimeError:
                            pass
                elif not (value.lower() in ("yes", "true", "1")):
                    continue
                self.cmd.add_option(opt)
                self.update_required_options(opt)

    def set_options(self, options):
        self.options = options
        self.required_options = list(options.get_required_options())

    def update_required_options(self, opt):
        if opt.is_required():
            self.required_options.remove(opt.get_key())
        if self.get_options().get_option_group(opt) is not None:
            group = self.get_options().get_option_group(opt)
            if group.is_required():
                self.required_options.remove(group)
            group.set_selected(opt)


