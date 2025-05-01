
import java.util.*;
import java.util.stream.*;

class TextWrapper {
    private boolean breakLongWords;
    private String initialIndent = "";
    private String subsequentIndent = "";
    
    class ExtraIndent implements AutoCloseable {
        private String indent;
        
        public ExtraIndent(String indent) {
            this.indent = indent;
            initialIndent += indent;
            subsequentIndent += indent;
        }
        
        @Override
        public void close() {
            initialIndent = initialIndent.substring(0, initialIndent.length() - indent.length());
            subsequentIndent = subsequentIndent.substring(0, subsequentIndent.length() - indent.length());
        }
    }
    
    public void handleLongWord(List<String> reversedChunks, List<String> curLine, int curLen, int width) {
        int spaceLeft = Math.max(width - curLen, 1);
        
        if (breakLongWords) {
            String last = reversedChunks.get(reversedChunks.size() - 1);
            String cut = last.substring(0, spaceLeft);
            String res = last.substring(spaceLeft);
            curLine.add(cut);
            reversedChunks.set(reversedChunks.size() - 1, res);
        } else if (curLine.isEmpty()) {
            curLine.add(reversedChunks.remove(reversedChunks.size() - 1));
        }
    }
    
    public ExtraIndent extraIndent(String indent) {
        return new ExtraIndent(indent);
    }
    
    public String indentOnly(String text) {
        String[] lines = text.split("\n");
        return IntStream.range(0, lines.length)
            .mapToObj(i -> (i > 0 ? subsequentIndent : initialIndent) + lines[i])
            .collect(Collectors.joining("\n"));
    }
}

// End of Code
