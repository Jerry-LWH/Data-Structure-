import java.util.Scanner;
public class main {
	public static void main(String[] args) {
		Scanner keyboard = new Scanner(System.in);
		boolean going = true;
		Queue myQueue = new Queue(7);
		while(going) {
			System.out.print("please enter command: ");
			String command = keyboard.nextLine();
			if(command.equalsIgnoreCase("e")) {
				System.out.println("enter a number");
				int d = keyboard.nextInt();
				myQueue.enQueue(d);
			}else if (command.equalsIgnoreCase("d")) {
				myQueue.deQueue();
			}else if(command.equalsIgnoreCase("p")) {
				myQueue.printQueue();
			}else if(command.equalsIgnoreCase("q")) {
				going = false;
			}
		}//while
	}

}
