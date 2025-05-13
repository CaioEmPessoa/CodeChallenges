package test;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

import calculadora.Calculadora;

class calcTest {

	@Test
	void testCalc() {
		Calculadora calc = new Calculadora();
		assertEquals(2.0, calc.soma(1.0, 1.0), "deve resultar 2");
		assertEquals(1.0, calc.subtrac(2.0, 1.0), "deve resultar 1");
		assertEquals(6.0, calc.mult(2.0, 3.0), "deve resultar 6");
		assertEquals(6.0, calc.div(12.0, 2.0), "deve resultar 6");
		assertEquals(9.0, calc.pot(3.0, 2.0), "deve resultar 9");
	}

}
