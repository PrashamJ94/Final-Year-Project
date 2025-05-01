class AlreadySelectedException(Exception):
    def __init__(self, group=None, option=None, message=None):
        if not message:
            message = f"The option '{option.key}' was specified but an option from this group has already been selected: '{group.selected}'"
        super().__init__(message)
        self.group = group
        self.option = option

    @property
    def option(self):
        return self._option

    @property
    def group(self):
        return self._group


