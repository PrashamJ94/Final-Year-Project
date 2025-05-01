
import os
from abc import ABC, abstractmethod
from urllib.parse import urlparse
from dateutil.parser import parse as parse_date

class ParseException(Exception):
    pass

class TypeHandler(ABC):
    @staticmethod
    def create_class(class_name):
        try:
            return __import__(class_name)
        except ImportError:
            raise ParseException(f"Unable to find the class: {class_name}")

    @staticmethod
    def create_date(str):
        try:
            return parse_date(str)
        except ValueError:
            raise ParseException(f"Unable to parse the date: {str}")

    @staticmethod
    def create_file(str):
        return os.path.abspath(str)

    @staticmethod
    def create_files(str):
        raise NotImplementedError("Not yet implemented")

    @staticmethod
    def create_number(str):
        try:
            if '.' in str:
                return float(str)
            return int(str)
        except ValueError:
            raise ParseException(f"Unable to parse the number: {str}")
        
    @staticmethod
    def create_object(class_name):
        try:
            class_ = __import__(class_name)
            return class_()
        except Exception as e:
            raise ParseException(f"{type(e).__name__}; Unable to create an instance of: {class_name}")

    @staticmethod
    def create_url(str):
        try:
            return urlparse(str)
        except ValueError:
            raise ParseException(f"Unable to parse the URL: {str}")

    @abstractmethod
    def create_value(self, str, clazz):
        pass

    @abstractmethod
    def create_value_with_obj(self, str, obj):
        pass

    @staticmethod
    def open_file(str):
        try:
            return open(str, 'r')
        except FileNotFoundError:
            raise ParseException(f"Unable to find file: {str}")


