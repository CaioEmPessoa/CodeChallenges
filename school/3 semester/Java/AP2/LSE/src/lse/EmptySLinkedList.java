package lse;

public class EmptySLinkedList extends RuntimeException {

	private static final long serialVersionUID = 1L; // quick fix

	public EmptySLinkedList(String message) {
        super(message);
	}
}