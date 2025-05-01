class Options:

    def __init__(self):
        self.short_opts = {}
        self.long_opts = {}
        self.required_opts = []
        self.option_groups = {}

    def add_option(self, opt):
        key = opt.get_key()
        if opt.has_long_opt():
            self.long_opts[opt.get_long_opt()] = opt
        if opt.is_required():
            if key in self.required_opts:
                self.required_opts.remove(key)
            self.required_opts.append(key)
        self.short_opts[key] = opt
        return self

    def add_option_arg(self, opt, has_arg, description):
        self.add_option(Option(opt, None, has_arg, description))
        return self

    def add_option_desc(self, opt, description):
        self.add_option(Option(opt, None, False, description))
        return self

    def add_option_long(self, opt, long_opt, has_arg, description):
        self.add_option(Option(opt, long_opt, has_arg, description))
        return self

    def add_option_group(self, group):
        if group.is_required():
            self.required_opts.append(group)
        for option in group.get_options():
            option.set_required(False)
            self.add_option(option)
            self.option_groups[option.get_key()] = group
        return self

    def add_required_option(self, opt, long_opt, has_arg, description):
        option = Option(opt, long_opt, has_arg, description)
        option.set_required(True)
        self.add_option(option)
        return self

    def get_matching_options(self, opt):
        opt = opt.lstrip('-')
        matching_opts = [opt for long_opt in self.long_opts if long_opt.startswith(opt)]
        return matching_opts if matching_opts else [opt]

    def get_option(self, opt):
        opt = opt.lstrip('-')
        return self.short_opts.get(opt) or self.long_opts.get(opt)

    def get_option_group(self, opt):
        return self.option_groups.get(opt.get_key())

    def get_option_groups(self):
        return set(self.option_groups.values())

    def get_options(self):
        return list(self.short_opts.values())

    def get_required_options(self):
        return self.required_opts

    def has_long_option(self, opt):
        opt = opt.lstrip('-')
        return opt in self.long_opts

    def has_option(self, opt):
        opt = opt.lstrip('-')
        return opt in self.short_opts or opt in self.long_opts

    def has_short_option(self, opt):
        opt = opt.lstrip('-')
        return opt in self.short_opts

    def __str__(self):
        return f"[ Options: [ short {self.short_opts} ] [ long {self.long_opts} ]]"


