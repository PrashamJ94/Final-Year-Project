package com.example;

import static org.junit.Assert.*;
import org.junit.Test;
import java.util.*;

public class HumanEval_55Test {

    @Test
    public void test_0() {
        Object expected = 55;
        assertEquals(expected, HumanEval_55.fib(10));
    }

    @Test
    public void test_1() {
        Object expected = 1;
        assertEquals(expected, HumanEval_55.fib(1));
    }

    @Test
    public void test_2() {
        Object expected = 21;
        assertEquals(expected, HumanEval_55.fib(8));
    }

    @Test
    public void test_3() {
        Object expected = 89;
        assertEquals(expected, HumanEval_55.fib(11));
    }

    @Test
    public void test_4() {
        Object expected = 144;
        assertEquals(expected, HumanEval_55.fib(12));
    }

    @Test
    public void test_5() {
        Object expected = 987;
        assertEquals(expected, HumanEval_55.fib(16));
    }

    @Test
    public void test_6() {
        Object expected = 0;
        assertEquals(expected, HumanEval_55.fib(0));
    }

    @Test
    public void test_7() {
        Object expected = 1;
        assertEquals(expected, HumanEval_55.fib(1));
    }

    @Test
    public void test_8() {
        Object expected = 2;
        assertEquals(expected, HumanEval_55.fib(3));
    }

    @Test
    public void test_9() {
        Object expected = 6557470319842L;
        assertEquals(expected, HumanEval_55.fib(63));
    }

    @Test
    public void test_10() {
        Object expected = 1;
        assertEquals(expected, HumanEval_55.fib(2));
    }

}