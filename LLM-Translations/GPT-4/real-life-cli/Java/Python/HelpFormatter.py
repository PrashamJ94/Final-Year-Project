
from abc import ABC, abstractmethod
import sys
import textwrap

DEFAULT_WIDTH = 74
DEFAULT_LEFT_PAD = 1
DEFAULT_DESC_PAD = 3
DEFAULT_SYNTAX_PREFIX = "usage: "
DEFAULT_OPT_PREFIX = "-"
DEFAULT_LONG_OPT_PREFIX = "--"
DEFAULT_LONG_OPT_SEPARATOR = " "
DEFAULT_ARG_NAME = "arg"

class OptionComparator:
    def compare(self, opt1, opt2):
        return opt1.get_key().casefold() < opt2.get_key().casefold()


class HelpFormatter(ABC):
    option_comparator = OptionComparator()
    long_opt_separator = DEFAULT_LONG_OPT_SEPARATOR

    @abstractmethod
    def append_option(self, buff, option, required):
        pass

    @abstractmethod
    def append_option_group(self, buff, group):
        pass

    @abstractmethod
    def create_padding(self, len):
        pass

    @abstractmethod
    def find_wrap_pos(self, text, width, start_pos):
        pass

    def get_arg_name(self):
        return DEFAULT_ARG_NAME

    def get_desc_padding(self):
        return DEFAULT_DESC_PAD

    def get_left_padding(self):
        return DEFAULT_LEFT_PAD

    def get_long_opt_prefix(self):
        return DEFAULT_LONG_OPT_PREFIX

    def get_long_opt_separator(self):
        return self.long_opt_separator

    def get_new_line(self):
        return '\n'

    def get_option_comparator(self):
        return self.option_comparator

    def get_opt_prefix(self):
        return DEFAULT_OPT_PREFIX

    def get_syntax_prefix(self):
        return DEFAULT_SYNTAX_PREFIX

    def get_width(self):
        return DEFAULT_WIDTH

    def print_usage(self, pw, width, cmd_line_syntax):
        arg_pos = cmd_line_syntax.find(' ') + 1
        self.print_wrapped(pw, width, self.get_syntax_prefix().length() + arg_pos, self.get_syntax_prefix() + cmd_line_syntax)

    def print_wrapped(self, pw, width, text):
        self.print_wrapped(pw, width, 0, text)

    def rtrim(self, s):
        return s.rstrip()

    def set_arg_name(self, name):
        global DEFAULT_ARG_NAME
        DEFAULT_ARG_NAME = name

    def set_desc_padding(self, padding):
        global DEFAULT_DESC_PAD
        DEFAULT_DESC_PAD = padding

    def set_left_padding(self, padding):
        global DEFAULT_LEFT_PAD
        DEFAULT_LEFT_PAD = padding

    def set_long_opt_prefix(self, prefix):
        global DEFAULT_LONG_OPT_PREFIX
        DEFAULT_LONG_OPT_PREFIX = prefix

    def set_long_opt_separator(self, long_opt_separator):
        self.long_opt_separator = long_opt_separator

    def set_new_line(self, newline):
        global NEWLINE
        NEWLINE = newline

    def set_option_comparator(self, comparator):
        self.option_comparator = comparator

    def set_opt_prefix(self, prefix):
        global DEFAULT_OPT_PREFIX
        DEFAULT_OPT_PREFIX = prefix

    def set_syntax_prefix(self, prefix):
        global DEFAULT_SYNTAX_PREFIX
        DEFAULT_SYNTAX_PREFIX = prefix

    def set_width(self, width):
        global DEFAULT_WIDTH
        DEFAULT_WIDTH = width


