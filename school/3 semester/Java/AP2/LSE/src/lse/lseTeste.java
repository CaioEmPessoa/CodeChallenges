package lse;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertThrows;

import org.junit.jupiter.api.Test;

import lse.EmptySLinkedList;

import lse.SLinkedList;

class SLinkedListTest {

@Test

void testAdddHead() {

SLinkedList s = new SLinkedList();

assertEquals("[]", s.toString(), "Deve imprimir []");

s.addHead("BOS");

assertEquals("[BOS]", s.toString(), "Deve imprimir [BOS]");

s.addHead("ATL");

assertEquals("[ATL, BOS]", s.toString(), "Deve imprimir [ATL, BOS]");

s.addHead("MSP");

assertEquals("[MSP, ATL, BOS]", s.toString(), "Deve imprimir [MSP, ATL, BOS]");

s.addHead("LAX");

assertEquals("[LAX, MSP, ATL, BOS]", s.toString(), "Deve imprimir [LAX, MSP, ATL, BOS]");

}

@Test

void testAddTail() {

SLinkedList s = new SLinkedList();

assertEquals("[]", s.toString(), "Deve imprimir []");

s.addTail("MSP");

assertEquals("[MSP]", s.toString(), "Deve imprimir [MSP]");

s.addTail("ATL");

assertEquals("[MSP, ATL]", s.toString(), "Deve imprimir [MSP, ATL]");

s.addTail("BOS");

assertEquals("[MSP, ATL, BOS]", s.toString(), "Deve imprimir [MSP, ATL, BOS]");

s.addTail("MIA");

assertEquals("[MSP, ATL, BOS, MIA]", s.toString(), "Deve imprimir [MSP, ATL, BOS, MIA]");

}

@Test

void testRemoveFirst() {

SLinkedList s = new SLinkedList();

assertEquals("[]", s.toString(), "Deve imprimir []");

s.addTail("MSP");

assertEquals("[MSP]", s.toString(), "Deve imprimir [MSP]");

s.addTail("BOS");

assertEquals("[MSP, BOS]", s.toString(), "Deve imprimir [MSP, BOS]");

s.removeFirst();

assertEquals("[BOS]", s.toString(), "Deve imprimir [BOS]");

s.removeFirst();

assertEquals("[]", s.toString(), "Deve imprimir []");

assertThrows(EmptySLinkedList.class, () -> { s.removeFirst(); });

}

}