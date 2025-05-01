class Util:

    EMPTY_STRING_ARRAY = []

    @staticmethod
    def strip_leading_and_trailing_quotes(str):
        length = len(str)
        if length > 1 and str.startswith("\"") and str.endswith("\"") and str[1:length-1].find("\"") == -1:
            str = str[1:length-1]
        return str

    @staticmethod
    def strip_leading_hyphens(str):
        if str is None:
            return None
        if str.startswith("--"):
            return str[2:]
        if str.startswith("-"):
            return str[1:]
        return str


