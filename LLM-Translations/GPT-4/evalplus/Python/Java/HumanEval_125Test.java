package com.example;
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

class HumanEval_125Test {
    @Test
    void test_0() {
        assertArrayEquals(new String[] {"Hello", "world!"}, HumanEval_125.splitWords("Hello world!"));
    }

    @Test
    void test_1() {
        assertArrayEquals(new String[] {"Hello", "world!"}, HumanEval_125.splitWords("Hello,world!"));
    }

    @Test
    void test_2() {
        assertArrayEquals(new String[] {"Hello", "world,!"}, HumanEval_125.splitWords("Hello world,!"));
    }

    @Test
    void test_3() {
        assertArrayEquals(new String[] {"Hello,Hello,world", "!"}, HumanEval_125.splitWords("Hello,Hello,world !"));
    }

    @Test
    void test_4() {
        assertEquals(3, HumanEval_125.splitWords("abcdef"));
    }

    @Test
    void test_5() {
        assertEquals(2, HumanEval_125.splitWords("aaabb"));
    }

    @Test
    void test_6() {
        assertEquals(1, HumanEval_125.splitWords("aaaBb"));
    }

    @Test
    void test_7() {
        assertEquals(0, HumanEval_125.splitWords(""));
    }

    @Test
    void test_8() {
        assertEquals(2, HumanEval_125.splitWords("Hello?"));
    }

    @Test
    void test_9() {
        assertArrayEquals(new String[] {"abc", "deg"}, HumanEval_125.splitWords("abc deg"));
    }

    @Test
    void test_10() {
        assertArrayEquals(new String[] {"aaa", "bbb"}, HumanEval_125.splitWords("aaa,bbb"));
    }

    @Test
    void test_11() {
        assertEquals(2, HumanEval_125.splitWords("wOWbbX"));
    }

    @Test
    void test_12() {
        assertEquals(2, HumanEval_125.splitWords("ababc123"));
    }
}
//End of Test
