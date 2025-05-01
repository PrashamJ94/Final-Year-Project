class OptionValidator:

    @staticmethod
    def is_valid_char(c):
        return c.isidentifier()

    @staticmethod
    def is_valid_opt(c):
        return OptionValidator.is_valid_char(c) or c == '?' or c == '@'

    @staticmethod
    def validate(option):
        if option is None:
            return None

        if len(option) == 1:
            ch = option[0]
            if not OptionValidator.is_valid_opt(ch):
                raise ValueError(f"Illegal option name '{ch}'")

        else:
            for ch in option:
                if not OptionValidator.is_valid_char(ch):
                    raise ValueError(f"The option '{option}' contains an illegal character : '{ch}'")
        return option


