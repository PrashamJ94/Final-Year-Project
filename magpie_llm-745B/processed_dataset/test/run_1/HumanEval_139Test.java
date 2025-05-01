package com.example;

import static org.junit.Assert.*;
import org.junit.Test;
import java.util.*;

public class HumanEval_139Test {

    @Test
    public void test_0() {
        Object expected = 288;
        assertEquals(expected, HumanEval_139.specialFactorial(4));
    }

    @Test
    public void test_1() {
        Object expected = 34560;
        assertEquals(expected, HumanEval_139.specialFactorial(5));
    }

    @Test
    public void test_2() {
        Object expected = 125411328000L;
        assertEquals(expected, HumanEval_139.specialFactorial(7));
    }

    @Test
    public void test_3() {
        Object expected = 1;
        assertEquals(expected, HumanEval_139.specialFactorial(1));
    }

    @Test
    public void test_4() {
        Object expected = 2;
        assertEquals(expected, HumanEval_139.specialFactorial(2));
    }

    @Test
    public void test_5() {
        Object expected = 12;
        assertEquals(expected, HumanEval_139.specialFactorial(3));
    }

    @Test
    public void test_6() {
        Object expected = 24883200;
        assertEquals(expected, HumanEval_139.specialFactorial(6));
    }

}