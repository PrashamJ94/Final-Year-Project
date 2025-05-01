
import java.util.Stack;

public class globals {
    private static ThreadLocal<Stack<Context>> contextThreadLocal = new ThreadLocal<Stack<Context>>() {
        @Override
        protected Stack<Context> initialValue() {
            return new Stack<>();
        }
    };

    private boolean color;

    public Context() {
        this.color = false;
    }

    public static Context getCurrentContext(boolean silent) throws RuntimeException {
        try {
            return contextThreadLocal.get().peek();
        } catch (Exception e) {
            if (!silent) {
                throw new RuntimeException("There is no active click context.", e);
            }
        }
        return null;
    }

    public static void pushContext(Context context) {
        contextThreadLocal.get().push(context);
    }

    public static void popContext() {
        contextThreadLocal.get().pop();
    }

    public static Boolean resolveColorDefault(Boolean color) {
        if (color != null) {
            return color;
        }

        Context ctx = getCurrentContext(true);

        if (ctx != null) {
            return ctx.color;
        }

        return null;
    }
}

// End of Code
