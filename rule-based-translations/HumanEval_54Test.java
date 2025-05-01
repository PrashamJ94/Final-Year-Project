package com.example;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

class HumanEval_54Test {
    
    @Test
    void testSameChars_0() {
        assertTrue(HumanEval_54.sameChars("eabcdzzzz", "dddzzzzzzzddeddabc"));
    }

    @Test
    void testSameChars_1() {
        assertTrue(HumanEval_54.sameChars("abcd", "dddddddabc"));
    }

    @Test
    void testSameChars_2() {
        assertTrue(HumanEval_54.sameChars("dddddddabc", "abcd"));
    }

    @Test
    void testSameChars_3() {
        assertFalse(HumanEval_54.sameChars("eabcd", "dddddddabc"));
    }

    @Test
    void testSameChars_4() {
        assertFalse(HumanEval_54.sameChars("abcd", "dddddddabcf"));
    }

    @Test
    void testSameChars_5() {
        assertFalse(HumanEval_54.sameChars("eabcdzzzz", "dddzzzzzzzddddabc"));
    }

    @Test
    void testSameChars_6() {
        assertFalse(HumanEval_54.sameChars("aabb", "aaccc"));
    }

    @Test
    void testSameChars_7() {
        assertFalse(HumanEval_54.sameChars("ab", "cd"));
    }

    @Test
    void testSameChars_8() {
        assertTrue(HumanEval_54.sameChars("123445", "5143241"));
    }

    @Test
    void testSameChars_9() {
        assertFalse(HumanEval_54.sameChars("ZYXWVUTSRQPONMLKJIHGFEDCBA", "ZjumpsYXWVUTSRQPONMLKJIHGFEDCBA"));
    }

    @Test
    void testSameChars_10() {
        assertFalse(HumanEval_54.sameChars("123445", ""));
    }

    @Test
    void testSameChars_11() {
        assertFalse(HumanEval_54.sameChars("foStrongrce", "gazelle!own"));
    }

    @Test
    void testSameChars_12() {
        assertTrue(HumanEval_54.sameChars("12345607890", "0987654321"));
    }

    @Test
    void testSameChars_13() {
        assertFalse(HumanEval_54.sameChars("524321", "5432"));
    }

    @Test
    void testSameChars_14() {
        assertFalse(HumanEval_54.sameChars("ZeZeZeZeZeZeZeZeZeZeZeZeZeZ,eZeZeZeZeZeZeZeZeZeZeZeZeZeZeZeZeZeZeZeZeZeZeZeZeZeZeZe", "ZeZeZeZeZeZeZeZeZeZeZeZeZeZeZeZeZeZeZeZeZeZeZeZeZeZeZeZeZeZeZeZeZeZeZeZeZeZeZe"));
    }

    @Test
    void testSameChars_15() {
        assertFalse(HumanEval_54.sameChars("", "the"));
    }
}
// End of Test

