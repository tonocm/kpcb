import java.io.*;

class Contest{
  
  static BufferedReader stdIn = new BufferedReader(new InputStreamReader(System.in));
  
  public static void main(String[] args) throws IOException{
    
    int maxLength, value;
    boolean flag = true;
    char menu = 'z'; //arbitrartily chose z as the identifier for an error
    
    if(args.length != 1){
      System.out.println("Please specify the maximum length of your queue");
     maxLength = Integer.parseInt(stdIn.readLine());
    }
    else
      maxLength = Integer.parseInt(args[0]);
    
    
    Queue queue = new Queue(maxLength);
    
    while(flag){
      System.out.println("Would you like to:\n 1 - Enqueue an item\n 2 - Dequeue an item\n 3 - Print your queue\n 4 - Quit");
      
      menu = stdIn.readLine().toLowerCase().charAt(0);

      switch(menu){
        case '1':
        {
          menu = 'e';
        }
        break;
        case '2':
        {
          menu = 'd';
        }
        break;
        case '3':
        {
          menu = 'p';
        }
        break;
        case '4':
        case 'q':
        {
          menu = 'q';
          flag = false;
        }
        break;
        default:
          /* Empty Space */
        break;
      }
    
    switch(menu){
      
      case 'e':
      {
        if(queue.emptySpace <= 0) //PROBLEM SOMEWHERE HERE!!!!!!!!! <~~~~~~~~~~~~
          System.out.println("Sorry, you have exhausted your allocated space. You can either dequeue, print or exit");
        else{
          System.out.println("You still have " + queue.emptySpace + " spots left."); 
          System.out.println("Please enter the value you want to add to the queue");
          value = Integer.parseInt(stdIn.readLine());
          queue.enqueue(value);
        }
      }
      break;
      case 'd':
      {
        System.out.println("You still have " + queue.emptySpace + " spots left."); 
        System.out.println("Please enter the value you want to add to the queue");
        value = Integer.parseInt(stdIn.readLine());
        int temp = queue.dequeue();
      }
      break;
      case 'p':
      {
        queue.print();
      }
      break;
      case 'q':
      {
        System.out.println("Goodbye!");
      }
      break;
      default:{
        menu = 'z'; //arbitrartily chose z as the identifier for an error
        System.out.println("Something went wrong with your input, please try again...");
      }
    }
    }
    //else
      //System.out.println("Something went wrong with your input, please try again...");
  }
}