
import java.io.IOException;
import java.util.Optional;

// Define common exceptions
class ClickException extends Exception {
    int exitCode = 1;

    public ClickException(String message) {
        super(message);
    }

    public void show(Optional<String> file) {
        if (file.isEmpty()) {
            System.out.println("Error: " + this.getMessage());
        }
    }
}

class UsageError extends ClickException {
    int exitCode = 2;
    Optional<Context> ctx;
    Optional<Command> cmd;

    public UsageError(String message, Optional<Context> ctx) {
        super(message);
        this.ctx = ctx;
        this.cmd = ctx.isPresent() ? ctx.get().command : Optional.empty();
    }

    @Override
    public void show(Optional<String> file) {
        if (file.isEmpty()) {
            String color = null;
            String hint = "";

            if (this.ctx.isPresent() 
                && this.ctx.get().command.getHelpOption(this.ctx.get()) != null) {
                hint = "Try '" + this.ctx.get().commandPath 
                    + " " + this.ctx.get().helpOptionNames[0] + "' for help.";
                hint = hint + "\n";
            }

            if (this.ctx.isPresent()) {
                color = this.ctx.get().color;
                System.out.println(this.ctx.get().getUsage() + "\n" + hint);
            }

            System.out.println("Error: " + this.getMessage());
        }
    }
}

// Define parameter related exceptions
class BadParameter extends UsageError {
    Optional<Parameter> param;
    Optional<String> paramHint;

    public BadParameter(String message, Optional<Context> ctx, Optional<Parameter> param,
                        Optional<String> paramHint) {
        super(message, ctx);
        this.param = param;
        this.paramHint = paramHint;
    }

    @Override
    public String getMessage() {
        if (this.paramHint.isPresent()) {
            return "Invalid value for " + this.paramHint.get() + ": " + super.message;
        } else if (this.param.isPresent()) {
            return "Invalid value for " + this.param.get().getErrorHint(this.ctx) 
                + ": " + super.message;
        } else {
            return "Invalid value: " + super.message;
        }
    }
}

class MissingParameter extends BadParameter {
    Optional<String> paramType;

    public MissingParameter(Optional<String> message, Optional<Context> ctx, 
                            Optional<Parameter> param, Optional<String> paramHint,
                            Optional<String> paramType) {
        super(message.orElse(""), ctx, param, paramHint);
        this.paramType = paramType;
    }
}

class NoSuchOption extends UsageError {
    String optionName;
    Optional<String> possibilities;

    public NoSuchOption(String optionName, Optional<String> message, 
                        Optional<String> possibilities, Optional<Context> ctx) {
        super(message.orElse("No such option: " + optionName), ctx);
        this.optionName = optionName;
        this.possibilities = possibilities;
    }
}

class BadOptionUsage extends UsageError {
    String optionName;

    public BadOptionUsage(String optionName, String message, Optional<Context> ctx) {
        super(message, ctx);
        this.optionName = optionName;
    }
}

class BadArgumentUsage extends UsageError {
}

// Define file related exceptions
class FileError extends ClickException {
    String uiFilename;
    String filename;

    public FileError(String filename, Optional<String> hint) {
        super(hint.orElse("unknown error"));
        this.uiFilename = filename.replace("\\", "/");
        this.filename = filename;
    }

    @Override
    public String getMessage() {
        return "Could not open file '" + this.uiFilename + "': " + super.getMessage();
    }
}

class Abort extends RuntimeException {
}

class Exit extends RuntimeException {
    int exitCode;

    public Exit(int code) {
        this.exitCode = code;
    }
}

// End of Code
