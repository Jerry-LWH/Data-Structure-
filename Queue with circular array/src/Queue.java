
public class Queue {
	int[] myQueue;
	int length;
	int head;
	int tail;
	
	public Queue(int length) {
		myQueue = new int[length];
		this.length = length;
		head=0;
		tail=0;
	}
	
	public boolean isEmpty() {
		return head==tail; //if head and tail pointing to the same element, empty
	}
	
	public boolean isFull() {
		return (tail+1)%length==head; //if tail catches up to head, its full
	}                                 //since we using circular array, we use mod to get
	                                  //the reminder,so if it over laps, we still get it

	public void enQueue(int data) {
		if(isFull()==false) {
			myQueue[tail]=data;       //add data to tail position
			tail = (tail+1) % length; //increment tail
		}else {
			System.out.println("Cannot enQueue because queue is full! ");
		}
	}

	public void deQueue() {
		if(isEmpty() == false) {
			System.out.println("You just deQueued: "+ myQueue[head]);
			head = (head +1)%length;
		}else {
			System.out.println("Cannot deQueue because queue is empty");
		}
	}
	
	public void printQueue() {
		if(isEmpty()==false) {
			int temphead = head;
			int temptail = tail;
			
			while(temphead !=temptail) {
				System.out.print(myQueue[temphead]+ " ");
				temphead = (temphead+1)%length;
			}
			System.out.println("");
		}
	}
}


