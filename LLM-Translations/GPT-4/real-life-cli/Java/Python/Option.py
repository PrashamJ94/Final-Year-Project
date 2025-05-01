Below is the Python translation of the provided Java code:


from typing import Any, List, Optional


class Option:

    UNINITIALIZED = -1
    UNLIMITED_VALUES = -2

    def __init__(self, option: str, long_option: str, has_arg: bool, description: str):
        self.option = option
        self.long_option = long_option
        self.has_arg = has_arg
        self.description = description
        self.values = []
        self.arg_count = 1 if has_arg else Option.UNINITIALIZED

    def accepts_arg(self):
        return (self.has_arg() or self.has_args() or self.has_optional_arg()) and (self.arg_count <= 0 or len(self.values) < self.arg_count)

    def add(self, value: str):
        if not self.accepts_arg():
            raise Exception("Cannot add value, list full.")
        self.values.append(value)

    def clear_values(self):
        self.values.clear()

    def clone(self):
        cloned_option = Option(self.option, self.long_option, self.has_arg, self.description)
        cloned_option.values = self.values.copy()
        return cloned_option

    def equals(self, obj: Any) -> bool:
        if isinstance(obj, Option):
            return self.long_option == obj.long_option and self.option == obj.option
        return False

    def get_arg_name(self) -> str:
        return self.arg_name

    def get_args(self) -> int:
        return self.arg_count

    def get_description(self) -> str:
        return self.description

    def get_id(self) -> int:
        return ord(self.get_key()[0])

    def get_key(self) -> str:
        return self.long_option if self.option is None else self.option

    def get_long_opt(self) -> str:
        return self.long_option

    def get_opt(self) -> str:
        return self.option

    def get_type(self) -> Any:
        return self.type

    def get_value(self) -> Optional[str]:
        return None if self.has_no_values() else self.values[0]

    def get_values(self) -> Optional[List[str]]:
        return None if self.has_no_values() else self.values

    def get_value_separator(self) -> str:
        return self.valuesep

    def has_arg(self) -> bool:
        return self.arg_count > 0 or self.arg_count == Option.UNLIMITED_VALUES

    def has_arg_name(self) -> bool:
        return self.arg_name is not None and self.arg_name != ''

    def has_args(self) -> bool:
        return self.arg_count > 1 or self.arg_count == Option.UNLIMITED_VALUES

    def has_long_opt(self) -> bool:
        return self.long_option is not None

    def has_no_values(self) -> bool:
        return len(self.values) == 0

    def has_optional_arg(self) -> bool:
        return self.optional_arg

    def has_value_separator(self) -> bool:
        return self.valuesep > 0

    def is_required(self) -> bool:
        return self.required

    def process_value(self, value: str):
        if self.has_value_separator():
            sep = self.get_value_separator()
            while value.find(sep) != -1:
                if len(self.values) == self.arg_count - 1:
                    break
                self.add(value[0: value.find(sep)])
                value = value[value.find(sep) + 1:]
        self.add(value)

    def requires_arg(self) -> bool:
        return not self.optional_arg and (len(self.values) == 0 if self.arg_count == Option.UNLIMITED_VALUES else self.accepts_arg())

    def set_arg_name(self, arg_name: str):
        self.arg_name = arg_name

    def set_args(self, num: int):
        self.arg_count = num

    def set_description(self, description: str):
        self.description = description

    def set_long_opt(self, long_opt: str):
        self.long_option = long_opt

    def set_optional_arg(self, optional_arg: bool):
        self.optional_arg = optional_arg

    def set_required(self, required: bool):
        self.required = required

    def set_type(self, type: Any):
        self.type = type

    def set_value_separator(self, sep: str):
        self.valuesep = sep

    def __str__(self):
        buf = f"[ option: {self.option} {self.long_option if self.long_option is not None else ''} "
        if self.has_args():
            buf += "[ARG...]"
        elif self.has_arg():
            buf += "[ARG]"
        buf += f" :: {self.description}"
        if self.type is not None:
            buf += f" :: {str(self.type)}"
        buf += " ]"
        return buf

End of Code.
