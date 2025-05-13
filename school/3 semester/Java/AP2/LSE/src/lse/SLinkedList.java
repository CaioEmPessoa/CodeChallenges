package lse;

public class SLinkedList {

	protected Node head;
	protected Node tail;
	
	protected long size;
	
	public SLinkedList() {
		head = tail = null;
		size = 0;
	}
	
	public void addHead(String string) {
		Node temp = new Node(string, head);
		head = temp;
		if (tail == null) {
			tail = temp;
		}
		size += 1;
	}
	
	public void addTail(String string) {
		Node temp = new Node(string, null);
		if (tail == null) {
			tail = temp;
			head = temp;
		}
		else {
			tail.setNext(temp);	
			tail = temp;
		}
		size += 1;
	}
	
    public String toString() {
    	String s;
    	s = "[";
    	
    	Node current = head;
    	
    	while (current != null) {
    		s += current.getElement();
    		current = current.getNext();
    		if (current != null) {
    			s += ", ";
    		}
    	}
    	
    	s += "]";
    	
    	return s;
    }
    
    public void removeFirst() {
		if (head == null || size == 0) {
			throw new EmptySLinkedList("Nada a remover.");
		}
		else {
			head = head.getNext();
		}
		size -= 1;
	}
}

