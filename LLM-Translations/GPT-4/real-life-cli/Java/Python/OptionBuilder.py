class OptionBuilder:

    long_option = None
    description = None
    arg_name = None
    required = False
    arg_count = Option.UNINITIALIZED
    type = None
    optional_arg = False
    value_separator = 0

    @staticmethod
    def reset():
        OptionBuilder.description = None
        OptionBuilder.arg_name = None
        OptionBuilder.long_option = None
        OptionBuilder.type = str
        OptionBuilder.required = False
        OptionBuilder.arg_count = Option.UNINITIALIZED
        OptionBuilder.optional_arg = False
        OptionBuilder.value_separator = 0

    @staticmethod
    def create():
        if OptionBuilder.long_option is None:
            OptionBuilder.reset()
            raise ValueError("must specify longopt")

        return OptionBuilder.create(None)

    @staticmethod
    def create(opt):
        option = None
        try:
            option = Option(opt, OptionBuilder.description)
            option.long_option = OptionBuilder.long_option
            option.required = OptionBuilder.required
            option.optional_arg = OptionBuilder.optional_arg
            option.args = OptionBuilder.arg_count
            option.type = OptionBuilder.type
            option.value_separator = OptionBuilder.value_separator
            option.arg_name = OptionBuilder.arg_name
        finally:
            OptionBuilder.reset()

        return option

    @staticmethod
    def has_arg():
        OptionBuilder.arg_count = 1
        return OptionBuilder

    @staticmethod
    def has_arg(has_arg):
        OptionBuilder.arg_count = 1 if has_arg else Option.UNINITIALIZED
        return OptionBuilder

    @staticmethod
    def has_args():
        OptionBuilder.arg_count = Option.UNLIMITED_VALUES
        return OptionBuilder

    @staticmethod
    def has_args(num):
        OptionBuilder.arg_count = num
        return OptionBuilder

    @staticmethod
    def has_optional_arg():
        OptionBuilder.arg_count = 1
        OptionBuilder.optional_arg = True
        return OptionBuilder

    @staticmethod
    def has_optional_args():
        OptionBuilder.arg_count = Option.UNLIMITED_VALUES
        OptionBuilder.optional_arg = True
        return OptionBuilder

    @staticmethod
    def has_optional_args(num_args):
        OptionBuilder.arg_count = num_args
        OptionBuilder.optional_arg = True
        return OptionBuilder

    @staticmethod
    def is_required():
        OptionBuilder.required = True
        return OptionBuilder

    @staticmethod
    def is_required(new_required):
        OptionBuilder.required = new_required
        return OptionBuilder

    @staticmethod
    def with_arg_name(name):
        OptionBuilder.arg_name = name
        return OptionBuilder

    @staticmethod
    def with_description(new_description):
        OptionBuilder.description = new_description
        return OptionBuilder

    @staticmethod
    def with_long_opt(new_longopt):
        OptionBuilder.long_option = new_longopt
        return OptionBuilder

    @staticmethod
    def with_type(new_type):
        OptionBuilder.type = new_type
        return OptionBuilder

    @staticmethod
    def with_value_separator():
        OptionBuilder.value_separator = '='
        return OptionBuilder

    @staticmethod
    def with_value_separator(sep):
        OptionBuilder.value_separator = sep
        return OptionBuilder


