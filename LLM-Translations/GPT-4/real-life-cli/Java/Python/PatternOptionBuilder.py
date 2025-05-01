
from datetime import date
from typing import Union, List
from urllib.parse import urlparse
import os
import numbers

class PatternOptionBuilder:

    STRING_VALUE = str
    OBJECT_VALUE = object
    NUMBER_VALUE = numbers.Number
    DATE_VALUE = date
    CLASS_VALUE = type
    EXISTING_FILE_VALUE = os.path.isfile
    FILE_VALUE = os.path
    FILES_VALUE = List[os.path]
    URL_VALUE = urlparse

    @staticmethod
    def get_value_class(ch):
        return {
            '@': PatternOptionBuilder.OBJECT_VALUE,
            ':': PatternOptionBuilder.STRING_VALUE,
            '%': PatternOptionBuilder.NUMBER_VALUE,
            '+': PatternOptionBuilder.CLASS_VALUE,
            '#': PatternOptionBuilder.DATE_VALUE,
            '<': PatternOptionBuilder.EXISTING_FILE_VALUE,
            '>': PatternOptionBuilder.FILE_VALUE,
            '*': PatternOptionBuilder.FILES_VALUE,
            '/': PatternOptionBuilder.URL_VALUE,
        }.get(ch, None)

    @staticmethod
    def is_value_code(ch):
        return ch in ['@', ':', '%', '+', '#', '<', '>', '*', '/', '!']

    @staticmethod
    def parse_pattern(pattern):
        opt = ' '
        required = False
        type_ = None
        options = {}

        for ch in pattern:
            if not PatternOptionBuilder.is_value_code(ch):
                if opt != ' ':
                    option = {
                        'arg': bool(type_),
                        'required': required,
                        'type': type_
                    }
                    options[opt] = option
                    required = False
                    type_ = None
                    opt = ' '

                opt = ch

            elif ch == '!':
                required = True
            else:
                type_ = PatternOptionBuilder.get_value_class(ch)

        if opt != ' ':
            option = {
                'arg': bool(type_),
                'required': required,
                'type': type_
            }
            options[opt] = option

        return options

#End of Code
