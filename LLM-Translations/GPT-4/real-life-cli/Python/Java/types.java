
import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.time.format.DateTimeFormatter;
import java.util.List;
import java.util.UUID;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public abstract class ParamType {
    public static final String TEXT = "text";
    public static final String PATH = "path";

    public String name;

    public abstract Object convert(Object value, Parameter param, Context ctx);

    public String fail(String message, Parameter param, Context ctx) throws Exception {
        throw new BadParameter(message, ctx, param);
    }
}

class UnprocessedParamType extends ParamType {
    public UnprocessedParamType() {
        this.name = TEXT;
    }

    @Override
    public Object convert(Object value, Parameter param, Context ctx) {
        return value;
    }
}

class StringParamType extends ParamType {
    public StringParamType() {
        this.name = TEXT;
    }

    @Override
    public Object convert(Object value, Parameter param, Context ctx) {
        return String.valueOf(value);
    }
}

class Choice extends ParamType {
    private List<String> choices;

    public Choice(List<String> choices) {
        this.name = "choice";
        this.choices = choices;
    }

    @Override
    public Object convert(Object value, Parameter param, Context ctx) throws Exception {
        String strValue = String.valueOf(value);
        if (choices.contains(strValue)) {
            return strValue;
        } else {
            fail(strValue + " is not a valid choice. Choose from " + choices, param, ctx);
            return null;
        }
    }
}

class FilePath extends ParamType {
    public FilePath() {
        this.name = PATH;
    }

    @Override
    public Object convert(Object value, Parameter param, Context ctx) throws Exception {
        Path path = Paths.get(String.valueOf(value));
        if (Files.exists(path)) {
            return path;
        } else {
            fail("File " + path + " does not exist.", param, ctx);
            return null;
        }
    }
}

class UUIDParameterType extends ParamType {
    public UUIDParameterType() {
        this.name = "uuid";
    }

    @Override
    public Object convert(Object value, Parameter param, Context ctx) throws Exception {
        try {
            return UUID.fromString(String.valueOf(value));
        } catch (IllegalArgumentException e) {
            fail(value + " is not a valid UUID.", param, ctx);
            return null;
        }
    }
}

class DateTime extends ParamType {
    private DateTimeFormatter dateTimeFormatter;

    public DateTime(DateTimeFormatter dateTimeFormatter) {
        this.name = "datetime";
        this.dateTimeFormatter = dateTimeFormatter;
    }

    @Override
    public Object convert(Object value, Parameter param, Context ctx) throws Exception {
        try {
            return dateTimeFormatter.parse(String.valueOf(value));
        } catch (Exception e) {
            fail(value + " is not a valid datetime.", param, ctx);
            return null;
        }
    }
}

// End of Code
